import sys

N = int(sys.stdin.readline())
count = 0
answer = 665

while(count != N):
    answer += 1

    if "666" in str(answer):
        count += 1

print(answer)
