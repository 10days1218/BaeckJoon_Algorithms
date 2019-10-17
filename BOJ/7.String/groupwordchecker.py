string = []
count = 0
prev_char = ''
char_list = []
index = 0
check = True

num = int(input())
for i in range(0,num):
    string.append(input())

for i in range(0, num):
    for j in string[i]:
        if prev_char != j:
            try:
                index = char_list.index(j)
            except ValueError:
                char_list.append(j)
                index = -1
        if index != -1:
            check = False
        prev_char = j

    if check == True:
        count += 1
    prev_char = ''
    char_list = []
    check = True

print(count)

            



        
