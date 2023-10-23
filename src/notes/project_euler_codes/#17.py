dict1 = { 0:'', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}
dict2 = { 0:'', 2:'twenty', 3:'thirty', 4:'forty', 5:'fifty', 6:'sixty', 7:'seventy', 8:'eighty', 9:'ninety'}
dict3 = { 10:'ten', 11:'eleven', 12:'twelve', 13:'thirteen', 14:'fourteen', 15:'fifteen', 16:'sixteen', 17:'seventeen', 18:'eighteen',19:'nineteen'}

def l(number):
    string = ''
    if len(number) == 3:
        string += dict1[int(number[0])] + 'hundred'
        if int(number[1]) == 1:
            string += 'and' + dict3[int(number)%100]
            return len(string)
        elif int(number[1]) == 0 and int(number[2]) == 0:
            return len(string)
        else:
            string += 'and' + dict2[int(number[1])] + dict1[int(number[2])]
            return len(string)
    elif len(number) == 2:
        if int(number[0]) == 1:
            string += dict3[int(number)]
            return len(string)
        else:
            string = string + dict2[int(number[0])] + dict1[int(number[1])]
            return len(string)
    else:
        string += dict1[int(number)]
        return len(string)
sum1 = 0
for i in range(1,1000):
    sum1 += l(str(i))

print(sum1+11)