def q1(nums, op):
    if len(nums) == 1:
        return nums[0]
    return op(nums[0], q1(nums[1:], op))


a = [10, 20]
op1 = q1(a, lambda x, y: x + y)
op2 = q1(a, lambda x, y: x * y)
print(op1)
print(op2)


def revstr(s):
    if s == "":
        return ""
    return revstr(s[1:]) + s[0]


print(revstr("aav"))


def countcase(s):
    if s == "":
        return (0, 0)
    up, low = countcase(s[1:])
    if s[0].islower():
        low += 1
    if s[0].isupper():
        up += 1
    return (up, low)


s = "aA"
q31, q32 = countcase(s)
print(q31, q32)
