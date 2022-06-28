def solution(lottos, win_nums):
    answer = []
    win_dict = {7 - x: x for x in range(1, 7)}
    win_dict[0] = 6

    result = set(lottos) & set(win_nums)

    answer = [win_dict[len(result) + lottos.count(0)], win_dict[len(result)]]

    return answer


if __name__ == "__main__":
    lottos = [0, 0, 0, 0, 0, 0]
    # = [45, 4, 35, 20, 3, 9]
    # = [44, 1, 0, 0, 31, 25]

    win_nums = [38, 19, 20, 40, 15, 25]
    #  = [20, 9, 3, 45, 4, 35]
    # = [31, 10, 45, 1, 6, 19]

    print(solution(lottos, win_nums))
