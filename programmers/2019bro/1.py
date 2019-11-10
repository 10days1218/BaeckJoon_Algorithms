def solution(restaurant, riders, k):
    answer = 0
    for r in riders:
        x, y = r[0], r[1]
        if (x - restaurant[0]) ** 2 + (y - restaurant[1]) ** 2 <= k ** 2:
            answer += 1
    return answer
