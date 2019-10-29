def checkBracket(str):
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


def makeUV(str):
    result = ""
    rU, rV = "", ""

    if str == "":
        return str

    for i, string in enumerate(str):
        rU += string
        if rU.count("(") > 0 and rU.count("(") == rU.count(")"):
            rV = str[i + 1 :]
            break

    if checkBracket(rU):
        string = makeUV(rV)
        if string == "":
            return rU
        else:
            result = rU + string
            return result

    else:
        v = makeUV(rV)
        u = ""
        tmp_u = rU[1 : len(rU) - 1]
        for i in range(0, len(tmp_u)):
            if tmp_u[i] == "(":
                u += ")"
            else:
                u += "("
        result = "(" + v + ")" + u
        return result


def solution(p):
    answer = ""
    if checkBracket(p):
        answer = p
    else:
        answer = makeUV(p)

    print(answer)
    return answer


input_p = "()))((()"
# "))))(((("
solution(input_p)
