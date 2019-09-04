def solution(words):
    answer = 0
    words_len = len(words)
    words.sort()
    for i in range(0, words_len):
        if i == 0:
            left, right = "", words[i + 1]
        if i == words_len - 1:
            left, right = words[i - 1], ""
        if i > 0 and i < words_len - 1:
            left, right = words[i - 1], words[i + 1]
        for j in range(1, len(words[i]) + 1):
            answer += 1
            if left.find(words[i][0:j]) != 0 and right.find(words[i][0:j]) != 0:
                break
    return answer


word_list = ["word", "war", "warrior", "world"]
# ["go", "gone", "guild"]
# ["abc", "def", "ghi", "jklm"]
print(solution(word_list))
