a = 2**10
for i in range(0,2):
   a = a**10
sum = 0
for i in str(a):
    sum += int(i)

print(sum)