def anagram(s:str,t:str)-> bool:
    if len(s)!=len(s):
        return False

    count=[0]*26;
    for a,b in zip(s,t):
        count[ord(a)-ord('a')]+=1
        count[ord(b)-ord('a')]-=1
    if all(c==0 for c in count):
        return True
    return False

l1="laaal"
l2="aalla"
