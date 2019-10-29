# https://programmers.co.kr/learn/courses/30/lessons/60058
def check(str):
    stack = []
    for i in str:
        if i == "(":
            stack.append("(")
        else:
            if len(stack) != 0:
                stack.pop()
            else:
                return False

    return True if len(stack) == 0 else False


def sperate(str):
    u, v = "", ""

    if str == "":
        return str

    for i, j in enumerate(str):
        u += j
        if len(u) != 0 and u.count("(") == u.count(")"):
            v = str[i + 1 :]
            break

    if check(u):
        t = sperate(v)
        if t == "":
            return u
        else:
            return u + t

    else:
        v = sperate(v)
        s = "("
        s = s + v + ")"
        u = u[1:-1]
        for i in u:
            if i == "(":
                s += ")"
            else:
                s += "("
        return s


def solution(p):
    answer = ""
    if check(p):
        answer = p
    else:
        answer = sperate(p)
    print(answer)
    return answer
