def path(x,y):
    if x == 0 and y == 0:
        return 0
    elif x == 0 and y != 0:
        return y
    elif y == 0 and x != 0:
        return x
    else:
        return path(x-1,y) + path(x,y-1)

print(path(20,20))

##from math import comb
##print(comb(40,20))
