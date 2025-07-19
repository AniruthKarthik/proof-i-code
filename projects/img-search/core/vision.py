import cv2
import numpy as np
import mediapipe as mp
from ultralytics import YOLO

model = YOLO("yolov8n.pt")  # Ensure weights are downloaded first
mp_pose = mp.solutions.pose.Pose()
mp_face = mp.solutions.face_detection.FaceDetection()

def get_dominant_color(image):
    image = cv2.resize(image, (50, 50))
    pixels = image.reshape(-1, 3)
    counts = {}
    for px in pixels:
        key = tuple(px)
        counts[key] = counts.get(key, 0) + 1
    dominant = max(counts, key=counts.get)
    return f"rgb{dominant}"

def infer_emotion(face_img):
    gray = cv2.cvtColor(face_img, cv2.COLOR_BGR2GRAY)
    mean_intensity = np.mean(gray)
    return "happy" if mean_intensity > 120 else "sad"

def infer_climate(img):
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    brightness = np.mean(hsv[:, :, 2])
    return "sunny" if brightness > 160 else "indoor/dark"

def infer_activity(pose_landmarks):
    if not pose_landmarks: return "unknown"
    y_coords = [lmk.y for lmk in pose_landmarks.landmark]
    movement = max(y_coords) - min(y_coords)
    return "running" if movement > 0.4 else "standing"

def detect_faces_and_emotion(img):
    results = mp_face.process(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    emotions = []
    if results.detections:
        for det in results.detections:
            bbox = det.location_data.relative_bounding_box
            h, w = img.shape[:2]
            x1, y1 = int(bbox.xmin * w), int(bbox.ymin * h)
            x2, y2 = x1 + int(bbox.width * w), y1 + int(bbox.height * h)
            face_crop = img[y1:y2, x1:x2]
            emotions.append(infer_emotion(face_crop))
    return emotions

def analyze_image(image_path):
    img = cv2.imread(image_path)
    results = model(img)[0]
    objects = [model.names[int(cls)] for cls in results.boxes.cls]
    people_boxes = [b.xyxy[0].cpu().numpy().astype(int) for b in results.boxes if model.names[int(b.cls)] == "person"]

    people_info = []
    for box in people_boxes:
        x1, y1, x2, y2 = box
        person_img = img[y1:y2, x1:x2]
        pose_result = mp_pose.process(cv2.cvtColor(person_img, cv2.COLOR_BGR2RGB))
        activity = infer_activity(pose_result.pose_landmarks)
        dress_color = get_dominant_color(person_img)
        people_info.append({
            "activity": activity,
            "dress_color": dress_color
        })

    emotions = detect_faces_and_emotion(img)
    photo_type = "group" if len(people_info) > 1 else "selfie" if len(people_info) == 1 else "unknown"
    climate = infer_climate(img)

    return {
        "objects": list(set(objects)),
        "num_people": len(people_info),
        "people": people_info,
        "emotions": emotions,
        "photo_type": photo_type,
        "climate": climate
    }

