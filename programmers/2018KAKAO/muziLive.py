def solution(food_times, k):
    answer = -1
    food_len = len(food_times)
    food = [[food_times[i], i] for i in range(0, food_len)]
    food.sort()
    time = 0
    prev = 0
    prev_time = 0
    for i in range(0, food_len):
        time = (food[i][0] - prev) * (food_len - i)
        if time <= k:
            k -= time
            prev = food[i][0]
        else:
            k %= food_len - i
            food = food[i:]
            food.sort(key=lambda f: f[1])
            answer = food[k][1] + 1
            break
    return answer


solution([2, 2, 2], 5)

