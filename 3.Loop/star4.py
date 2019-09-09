
a = int(input())

star = '*' * a
space = ' ' * (a - 1)

for i in range(0, a):
    print(space [a - i -1 : a], end = '')
    print(star [i : a], end='')
    print()



