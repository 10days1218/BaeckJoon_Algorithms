#5430
n = int(input())
li = []
front = back = 0
reverse =  False

for i in range(0,n):
    reverse = False
    command = list(input())
    length = int(input())
    li = input()
    if length == 0:
        li = []
        front = back = -1

    else:
        li = li[1:len(li)  - 1].split(',')
        li = [int(i) for i in li]
        front = 0
        back = length - 1

    len_s = len(command)
    for j in range(0,len_s):
        if command[j] == 'R':
            tmp = front
            front = back
            back = tmp
            reverse = not reverse

        if command[j] == 'D':
            if front != -1 and front != length:
                if back > front:
                    front +=1
                else:
                    front -=1

            if front == -1 or front == length:
                li = -1
                j = len_s

    if li != -1:
        if front == -1:
            print('[]')
        else:
            print('[', end = '')
            if reverse:
                for i in range(front, back -1, -1):
                    print(li[i], end = '')
                    if i != back:
                        print(',', end = '')
                print(']')

            else:
                for i in range(front, back +1,1):
                    print(li[i], end = '')
                    if i != back :
                        print(',', end = '')
                print(']') 

    else:
        print("error")      
    