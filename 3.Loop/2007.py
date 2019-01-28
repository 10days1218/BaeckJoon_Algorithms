
input1,input2 = input().split()

month = [0 ,31 , 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
total = 0

for i in range(0, int(input1)):
    total += month[i]

print(day[ (total + int(input2)) % 7])


    