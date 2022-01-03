import re


def solution(emails):
    answer = 0
    p = re.compile("^[a-z\.]+@[a-z]+/.[com|org|net]$")
    # ("^[a-z]+@[a-z]+\.[com,net,org]$")
    for i in emails:
        m = p.match(i)
        if m:
            answer += 1

    print(answer)
    return answer


email = ["d@co@m.com", "a@abc.com", "b@def.com", "c@ghi.net"]
solution(email)
