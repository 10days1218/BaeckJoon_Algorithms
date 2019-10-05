def solution(goods, boxes):
    goods.sort()
    boxes.sort()
    answer = 0
    i, j = 0, 0

    while i < len(goods) and j < len(boxes):
        if goods[i] <= boxes[j]:
            answer += 1
            i += 1
            j += 1
        else:
            j += 1

    print(answer)
    return answer


good = [3, 8, 6]
box = [5, 6, 4]

solution(good, box)

