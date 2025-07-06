import requests
import time

DOI = "10.1145/2016904.2016908"
LIMIT = 100
offset = 0
paper_ids = []
MAX_PAPERS = 1125  # as per your requirement
OUTPUT_FILE = "abstracts.txt"

# Step 1: Collect all citing paper IDs
while True:
    url = (
        f"https://api.semanticscholar.org/graph/v1/paper/DOI:{DOI}/citations"
        f"?fields=citingPaper.paperId"
        f"&limit={LIMIT}&offset={offset}"
    )
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Error fetching citations at offset {offset}: {response.status_code}")
        break

    data = response.json().get("data", [])
    if not data:
        break

    for entry in data:
        pid = entry.get("citingPaper", {}).get("paperId")
        if pid:
            paper_ids.append(pid)

    offset += LIMIT
    if offset >= MAX_PAPERS:
        break

print(f"Collected {len(paper_ids)} paper IDs.\n")

# Step 2: Fetch and save abstracts to a file
with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    for i, pid in enumerate(paper_ids, 1):
        url = f"https://api.semanticscholar.org/graph/v1/paper/{pid}?fields=title,abstract"
        response = requests.get(url)
        if response.status_code != 200:
            print(f"Error fetching paper {pid}")
            continue

        paper = response.json()
        title = paper.get("title", "No title")
        abstract = paper.get("abstract", "No abstract available")

        f.write(f"{i}. {title}\n")
        f.write(f"Abstract:\n{abstract}\n")
        f.write(f"{'-'*80}\n")

        print(f"Saved abstract {i}/{len(paper_ids)}")
        time.sleep(1.0)

