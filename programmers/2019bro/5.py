def solution(history):
    answer = []
    Refrigerator = [0 for i in range(5)]
    (
        Refrigerator[0],
        Refrigerator[1],
        Refrigerator[2],
        Refrigerator[3],
        Refrigerator[4],
    ) = (5, 100, 10, 5, 2)

    for h in history:
        cost = 0
        eat = float(h)

        if eat == 1.0 or eat == 1.5 or eat == 2.0 or eat == 2.5:
            Refrigerator[0] -= eat * 4
            while Refrigerator[0] < 0:
                Refrigerator[0] += 10
                cost += 10000

            Refrigerator[1] -= eat * 50
            while Refrigerator[1] < 0:
                Refrigerator[1] += 100
                cost += 3000

            Refrigerator[2] -= eat * 10
            while Refrigerator[2] < 0:
                Refrigerator[2] += 30
                cost += 1000

            Refrigerator[3] -= eat * 10
            while Refrigerator[3] < 0:
                Refrigerator[3] += 50
                cost += 2000

            if eat == 1.5 or eat == 2.5:
                Refrigerator[4] -= eat * 2
                while Refrigerator[4] < 0:
                    Refrigerator[4] += 10
                    cost += 1000

            else:
                Refrigerator[4] -= eat * 4
                while Refrigerator[4] < 0:
                    Refrigerator[4] += 10
                    cost += 1000
            answer.append(cost)

        else:
            answer.clear()
            answer.append(-1)
            break

    return answer
