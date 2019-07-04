scale = input().split(' ')
scale = [int(i) for i in scale]
ascending = [1, 2, 3, 4, 5, 6, 7, 8]
descending = [8, 7, 6, 5, 4, 3, 2, 1]

if ((scale == ascending) == True):
    print("ascending")
if ((scale == descending) == True):
    print("descending")
elif ((scale == ascending) != True and (scale == descending) != True):
    print("mixed")
