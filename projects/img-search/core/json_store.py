import json
import os

OUTPUT_FILE = "output/results.json"

def load_json():
    if not os.path.exists(OUTPUT_FILE):
        return []
    try:
        with open(OUTPUT_FILE, "r") as f:
            return json.load(f)
    except json.JSONDecodeError:
        return []

def save_json(data):
    os.makedirs(os.path.dirname(OUTPUT_FILE), exist_ok=True)
    with open(OUTPUT_FILE, "w") as f:
        json.dump(data, f, indent=4)

def update_json_with_metadata(new_metadata):
    data = load_json()

    # Match by hash or photo_id
    existing = next((item for item in data if (
        item.get("hash") == new_metadata.get("hash")
        or item.get("photo_id") == new_metadata.get("photo_id")
    )), None)

    if existing:
        existing.update(new_metadata)
    else:
        data.append(new_metadata)

    save_json(data)

