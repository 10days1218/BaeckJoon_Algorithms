def solution(n, t, m, p):
    answer = ""
    tube = ""
    num = 0
    while len(tube) <= t * m:
        tube += convert(num, n)
        num += 1
    turn = p - 1
    for i in range(0, t):
        answer += tube[turn]
        turn += m
    return answer


def convert(n, base):
    T = "0123456789ABCDEF"
    q, r = divmod(n, base)
    if q == 0:
        return T[r]
    else:
        return convert(q, base) + T[r]

n, t, m, p = 2, 4, 2, 1
print(solution(n, t, m, p))
