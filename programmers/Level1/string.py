def solution(s):
    answer = False

    if len(s) == 4 or len(s) == 6:
        answer = True
        for i in s:
            if ord(i) < ord("0") or ord(i) > ord("9"):
                answer = False
                break

    return answer
