count = 0
def collatz(n):
    global count
    if n == 1:
        var = count
        count = 0
        return var
    elif n%2 == 0:
        count += 1
        return collatz(n//2)
    else:
        count += 1
        return collatz(3*n+1)


var = [3,collatz(3)]
for i in range(1,10**6):
    if collatz(i) > var[1]:
        var = [i,collatz(i)]
    else:
        continue

print(var)
