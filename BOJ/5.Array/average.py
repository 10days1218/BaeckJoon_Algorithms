#10039
score = []
for i in range(0, 5):
    score.append(int(input()))
total = 0

for i in score:
    if i < 40:
        total += 40
    else:
        total += i
print(int(total / 5))
