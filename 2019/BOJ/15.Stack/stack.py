#10828
num = int(input())
stack = []
command = []
top = -1

for i in range(0, num):
    string = input()
    command.append(string)
    
for i in range(0, num):
    cmd = command[i].split(' ')
    if cmd[0] == 'push':
        stack.append(int(cmd[1]))
        top += 1
    
    if cmd[0] == 'pop':
        if top == -1:
            print('-1')
        else:
            print(stack.pop())
            top -= 1
    
    if cmd[0] == 'size':
        print(top + 1)

    if cmd[0] == 'empty':
        if top == -1:
            print('1')
        else:
            print('0')

    if cmd[0] == 'top':
        if top == -1:
            print('-1')
        else:
            print(stack[top])