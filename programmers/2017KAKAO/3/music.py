def solution(m, musicinfos):
    answer = "None"
    musics = []
    total = []
    l = 0
    shop = m.count("#")
    music_long = 0

    for i in musicinfos:
        musics.append(i.split(","))

    for i in musics:
        start, end = i[0].split(":"), i[1].split(":")
        hour, minute = int(end[0]) - int(start[0]), int(end[1]) - int(start[1])
        song = list(i[3])
        for k, tune in enumerate(song):
            if tune == "#":
                song[k - 1] += "#"
                del song[k]
        for j in range(0, hour * 60 + minute):
            total.append(song[l])
            l += 1
            if l == len(song):
                l = 0

        for idx in range(len(total) - len(m) + shop + 1):
            comp = total[idx : idx + len(m) - shop]
            comp = "".join(comp)
            if comp == m and music_long < len(total):
                answer = i[2]
                music_long = len(total)
                break

        total, l = [], 0

    return answer


music = ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]
# ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]
# ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]
M = "ABC"
# "ABCDEFG"
# "CC#BCC#BCC#BCC#B"
print(solution(M, music))
