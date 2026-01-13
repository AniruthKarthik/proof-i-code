# check whether the given string is an anagram
def anagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    count = [0] * 26
    for a, b in zip(s, t):
        count[ord(a) - ord("a")] += 1
        count[ord(b) - ord("a")] -= 1

    return all(c == 0 for c in count)


l1 = "laaal"
l2 = "aalla"

print(anagram(l1, l2))
