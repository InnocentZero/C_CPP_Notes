from math import sqrt,floor

def main():
    i = 1
    while True:
        yield i*(i+1)//2
        i += 1

def count(x):
    count = 0
    if sqrt(x) == float(floor(sqrt(x))):
        for i in range(1,int(sqrt(x))):
            if x%i == 0:
                count += 2
        count += 1
        return count
    else:
        for i in range(1,int(sqrt(x))):
            if x%i == 0:
                count += 2
        return count

for i in main():
    if count(i) > 500:
        print(i)
        break
