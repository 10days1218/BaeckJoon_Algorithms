#10866
num =  int(input())
command = []
Deque = []
for i in range(0, num):
    command.append(input())

for i in range(0, num):
    string = command[i].split(' ')
    if string[0] == 'push_back':
        Deque.append(int(string[1]))

    if string[0] == 'push_front':
        Deque.insert(0,int(string[1]))

    if string[0] == 'pop_front':
        size = len(Deque)
        if size == 0:
            print(-1)
        else:
            print(Deque[0])
            del Deque[0]

    if string[0] == 'pop_back':
        size = len(Deque)
        if size == 0:
            print(-1)
        else:
            print(Deque[size -1])
            del Deque[size -1]

    if string[0] == 'size':
        print(len(Deque))

    if string[0] == 'empty':
        if len(Deque) == 0:
            print(1)
        else:
            print(0)

    if string[0] == 'front':
        if len(Deque) == 0:
            print(-1)
        else:
            print(Deque[0])

    if string[0] == 'back':
        if len(Deque) == 0:
            print(-1)
        else:
            print(Deque[len(Deque) - 1])


# push_back 1
# push_front 2
# front
# back
# size
# empty
# pop_front
# pop_back
# pop_front
# size
# empty
# pop_back
# push_front 3
# empty
# front
