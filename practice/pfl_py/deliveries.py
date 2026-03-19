from functools import reduce


deliveries = [
    ("08:00", 15, "Completed"),
    ("09:30", 20, "Completed"),
    ("08:00", 10, "Completed"),
    ("10:15", 25, "Pending"),
    ("09:30", 30, "Completed"),
    ("08:00", 12, "Completed"),
]

cleaned = list(
    filter(lambda r: len(r) == 3 and r[2] == "Completed" and r[1] > 0, deliveries)
)

pairs = list(map(lambda r: (r[0], 1), cleaned))

counts = reduce(
    lambda acc, pair: {**acc, pair[0]: acc.get(pair[0], 0) + pair[1]}, pairs, {}
)

maxc = max(counts.values())

res = sorted(
    [(t, c) for t, c in counts.items() if c == maxc], key=lambda x: x[1], reverse=True
)

print(res)
