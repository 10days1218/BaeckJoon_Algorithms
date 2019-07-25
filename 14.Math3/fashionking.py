#9375

n = int(input())
cloth = {}
answer = 1
s = ''
for i in range(0,n):
    t = int(input())
    for j in range(0,t):
        str = input().split(' ')

        if str[1] in cloth:
            cloth[str[1]] +=1
        else:
            s = str[1]
            cloth[s] = 1

    l = cloth.values()
    for i in l:
        answer = answer * ( i + 1 )
    print(answer - 1)
    answer = 1
    cloth = {}