#1110
num = int(input())
count = 0
new = 0
num_t = num
while True:
    count += 1
    num1 = int(num_t / 10)
    num2 = num_t % 10
    new = num2 * 10 + (num1 + num2) % 10
    if (new == num):
        break
    num_t = new

print(count)
