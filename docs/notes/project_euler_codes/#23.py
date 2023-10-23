def abun_nums():
    i = 1
    while i < 28123:
        sum_div = 0
        for j in range(1,i):
            if i%j == 0:
                sum_div += j
        if sum_div > i:
            yield i
        else:
            yield 0
        i += 1

num_list = {i for i in range(1,28124)}
abun_num_list = []
for i in abun_nums():
    if i != 0:
        abun_num_list.append(i)
#print(abun_num_list)

for i in range(0,len(abun_num_list)):
    for j in range(i,len(abun_num_list)):
        if abun_num_list[i] + abun_num_list[j] in num_list:
            num_list.remove(abun_num_list[i]+abun_num_list[j])

#print(num_list)
sum = 0
for i in num_list:
    sum += i

print(sum)
