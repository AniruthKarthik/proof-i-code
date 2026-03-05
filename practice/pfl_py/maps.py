import functools
from toolz import curry


a = [2.2, 12, 12.1, 122]
b = map(round, a)
c = map(lambda x: x + 1, a)
print(list(b))
print(list(c))
a = [12, 1, 14, 121]
it = iter(a)
print(it)
print(next(it))
print(next(it))


class Custom:
    chars = "abcde"

    def __init__(self):
        self.chars = "X"
        self.pos = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.pos < len(self.chars):
            c = self.chars[self.pos]
            self.pos += 1
            return c
        else:
            raise StopIteration


for c in Custom():
    print(c)

a = ("red", "ed", "wdwd")
for i, s in enumerate(a):
    print(i, s)

a = (1, 2, 3, 4)
b = (2, 3, 4, 5)
z = zip(a, b)
restored = zip(*z)
print(list(restored))

a = [12, 2]
print(functools.reduce(lambda x, y: x * y, a, 10))
k = [12, 43, 2, 18]
a = [round(x / 5) * 5 for x in k]
print(a)
