#2292
#  2 +   6(1*6) -1 = 7  2번
#  8 +  12(2*6) -1 = 19 3번
# 20 + 18(3*6) -1 = 37 4번
# 38 + 24(4*6) -1 = 61 5번

num = int(input())
total = 2
index = 1
while True:

    if num == 1:
        print('1')
        break
    else:
        total = total + 6 * index
        if total > num:
            print(index + 1)
            break
        index += 1
        


