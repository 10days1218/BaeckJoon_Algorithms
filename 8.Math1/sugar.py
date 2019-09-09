
a = int(input())

if a % 5 == 0:
    print(int(a / 5))
   

if a % 5 == 3:
    print(int( a / 5 )+ 1)

if a % 3 == 0:
    print( int(a / 3))

if a % 3 == 2 and a > 5:
    print( int(a / 3))

else:
    print( - 1)