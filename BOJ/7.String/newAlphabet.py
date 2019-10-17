#2941
list = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=',  'z=']
string = input()

for i in list:
    string = string.replace(i,'*')

print(len(string))