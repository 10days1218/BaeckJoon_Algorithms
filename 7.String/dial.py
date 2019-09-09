#5622
string = input()
time = 0
for i in string:
    if i == 'A' or i == 'B' or i == 'C':
        time += 3
    if i == 'D' or i == 'E' or i == 'F':
        time += 4
    if i == 'G' or i == 'H' or i == 'I':
        time += 5
    if i == 'J' or i == 'K' or i == 'L':
        time += 6
    if i == 'M' or i == 'N' or i == 'O':
        time += 7
    if i == 'P' or i == 'Q' or i == 'R' or i ==  'S':
        time += 8
    if i == 'T' or i == 'U' or i == 'V':
        time += 9
    if i == 'W' or i == 'X' or i == 'Y' or i ==  'Z':
        time += 10
    if i == '1':
        time += 2
    if i == '0':
        time += 11

print(time)