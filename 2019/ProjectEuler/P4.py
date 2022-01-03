# http://euler.synap.co.kr/prob_detail.php?id=4

a, b = 100, 100
answer = 0
for i in range(900):
    for j in range(900):
        c = a * b
        s = str(c)
        if len(s) == 5 and s[0] == s[4] and s[1] == s[3]:
            answer = max(answer, c)
            print(a, b)
            print(answer)
        if len(s) == 6 and s[0] == s[5] and s[1] == s[4] and s[2] == s[3]:
            answer = max(answer, c)
            print(a, b)
            print(answer)
        b += 1
    a += 1
    b = 100
