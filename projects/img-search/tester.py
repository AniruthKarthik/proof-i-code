import os
from core.vision import analyze_image

image_folder = "photos"

for filename in os.listdir(image_folder):
    if filename.lower().endswith((".jpg", ".png", ".jpeg")):
        path = os.path.join(image_folder, filename)
        print(f"Analyzing: {filename}")
        features = analyze_image(path)
        print(features)
        print("-" * 60)

