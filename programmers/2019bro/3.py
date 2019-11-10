import math


def solution(prices, discounts):
    answer = 0
    discounts.sort(reverse=True)
    prices.sort(reverse=True)
    length = len(prices)
    for i in range(0, length):
        if i < len(discounts):
            # print((prices[i]) * (100 - discounts[i]) / 100)
            answer += (prices[i]) * (100 - discounts[i]) / 100
        else:
            answer += prices[i]
    math.floor(answer)
    return answer


p = [13000, 88000, 10000]
d = [30, 20]
solution(p, d)
