string = input()
alph = []
count = []
index_list = 0

for i in string:
    try:
        index_list = alph.index(i.upper())
        count[index_list] += 1
    except ValueError as e:
        alph.append(i.upper())
        count.append(1)

count_max = max(count)
index_list = count.index(count_max)
max_count = 0

for i in count:
    if i == count_max:
        max_count +=1

if max_count == 1:
    print(alph[index_list])
else:
    print('?')
