def solution(words, queries):
    answer = [0 for i in range(len(queries))]
    tmp = ""
    start = 0

    for index, j in enumerate(queries):
        for idx, k in enumerate(j):
            if k != "?":
                if tmp == "":
                    start = idx
                tmp += k
        for i in words:
            if len(j) == len(i) and i[start : start + len(tmp)] == tmp:
                answer[index] += 1
        tmp = ""
    return answer


test_word = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
test_qu = ["fro??", "????o", "fr???", "fro???", "pro?"]
solution(test_word, test_qu)

