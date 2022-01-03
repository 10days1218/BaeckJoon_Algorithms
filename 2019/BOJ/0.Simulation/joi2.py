joi = []

for i in range(5):
    joi.append(int(input()))

water = joi[4]

totalA = water * joi[0]
totalB = 0

if water <= joi[2]:
    totalB = joi[1]

else:
    totalB += joi[1] + (water - joi[2]) * joi[3]

print(min(totalA, totalB))
