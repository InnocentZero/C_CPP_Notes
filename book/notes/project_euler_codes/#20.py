def fact(x):
    if  x == 1:
        return 1
    else:
        return x*fact(x-1)
sum = 0
for i in str(fact(100)):
    sum += int(i)

print(sum)