#3009
list_x = []
list_y = []
x = 0
y = 0
for i in range(0,3):
    x,y = input().split(' ')
    list_x.append(int(x))
    list_y.append(int(y))

for i in range(0,3):
    if(list_x.count(list_x[i]) == 1):
        x = list_x[i]
    
    if(list_y.count(list_y[i]) == 1):
        y = list_y[i]

print(str(x) + " " + str(y))    