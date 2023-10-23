def sum(i):
    sum1 = 0
    for j in range(1,i):
        if i%j == 0:
            sum1 += j
    if i != sum1:
        return sum1
    return 0


def amic():
    i = 10000
    while i > 1:
        if i == sum(sum(i)):
            yield i
        i -= 1

finalsum = 0
nums = []
for i in amic():
    nums.append(i)
    print(i,sum(i))
    finalsum += i

print(nums, finalsum)
