
str = input()

for i in range(0, len(str)):
    print(str[i],end='')

    if( i % 10 == 9):
        print()

print()