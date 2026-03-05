# for memoization
# from functools import lru_cache


def flatten(x):
    if x == []:
        return x
    if not isinstance(x, list):
        return [x]
    return flatten(x[0]) + flatten(x[1:])


def decorator(func):
    def wrapper(x, y):
        print("inside wrapper")
        func(x, y)
        print("exiting wrapper")

    return wrapper


@decorator
def guru(x, y):
    print(x, " is the number u gave")
    x = x + y
    print(x, " x is altered")


def makePrint(start, end):
    def printin(x):
        print(start + x + end)

    return printin


brack = makePrint("<", ">")
print(brack("HLO"))


guru(1212, 1212)
print(flatten([122, [1212, 121, 12, [12, 12]]]))
