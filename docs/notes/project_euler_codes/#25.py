def prod(arr1,arr2):
    return [[arr1[0][0]*arr2[0][0]+arr1[0][1]*arr2[1][0],arr1[0][0]*arr2[0][1]+arr1[0][1]*arr2[1][1]],[arr1[1][0]*arr2[0][0]+arr1[1][1]*arr2[1][0],arr1[1][0]*arr2[0][1]+arr1[1][1]*arr2[1][1]]]

def power(n):
    M = [[1,1],[1,0]]
    if n == 0 or n == 1:
        return M
    elif n%2 == 1:
        return(prod(prod(power(n//2),power(n//2)),M))
    else:
        return(prod(power(n//2),power(n//2)))
i = 1
while True:
    i += 1
    if len(str(power(i)[0][0])) == 1000:
        print(i+1)
        break
    else:
        continue
