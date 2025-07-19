import hashlib
import piexif
from PIL import Image
from datetime import datetime
import os

def compute_file_hash(filepath):
    hasher = hashlib.sha256()
    with open(filepath, 'rb') as f:
        while chunk := f.read(8192):
            hasher.update(chunk)
    return hasher.hexdigest()

def extract_metadata(filepath):
    try:
        img = Image.open(filepath)
        exif_bytes = img.info.get("exif")
        exif_data = piexif.load(exif_bytes) if exif_bytes else {}

        zeroth = exif_data.get("0th", {})
        gps = exif_data.get("GPS", {})
        exif = exif_data.get("Exif", {})

        # Get datetime
        datetime_bytes = exif.get(piexif.ExifIFD.DateTimeOriginal) or zeroth.get(piexif.ImageIFD.DateTime)
        date = datetime_bytes.decode() if datetime_bytes else None

        # Get GPS data
        def dms_to_deg(dms, ref):
            degrees, minutes, seconds = dms
            deg = degrees[0]/degrees[1] + minutes[0]/(minutes[1]*60) + seconds[0]/(seconds[1]*3600)
            if ref in [b'S', b'W']:
                return -deg
            return deg

        gps_lat = gps_lon = None
        if gps:
            lat = gps.get(piexif.GPSIFD.GPSLatitude)
            lat_ref = gps.get(piexif.GPSIFD.GPSLatitudeRef)
            lon = gps.get(piexif.GPSIFD.GPSLongitude)
            lon_ref = gps.get(piexif.GPSIFD.GPSLongitudeRef)

            if lat and lat_ref and lon and lon_ref:
                gps_lat = dms_to_deg(lat, lat_ref)
                gps_lon = dms_to_deg(lon, lon_ref)

        location = f"{gps_lat},{gps_lon}" if gps_lat and gps_lon else None

        return {
            "photo_id": os.path.basename(filepath),
            "hash": compute_file_hash(filepath),
            "date": date,
            "location": location
        }

    except Exception as e:
        print(f"⚠️ Error extracting from {filepath}: {e}")
        return {
            "photo_id": os.path.basename(filepath),
            "hash": None,
            "date": None,
            "location": None
        }

