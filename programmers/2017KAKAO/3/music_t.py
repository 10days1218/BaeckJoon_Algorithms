def changShop(notes):
    notes = notes.replace("C#", "H")
    notes = notes.replace("D#", "I")
    notes = notes.replace("F#", "J")
    notes = notes.replace("G#", "K")
    notes = notes.replace("A#", "L")

    return notes


def solution(m, musicinfos):
    answer = "(None)"
    musics = []
    Music = ""
    music_long = 0
    l = 0

    m = changShop(m)
    for i in musicinfos:
        musics.append(i.split(","))

    for i in musics:
        start, end = i[0].split(":"), i[1].split(":")
        hour, minute = int(end[0]) - int(start[0]), int(end[1]) - int(start[1])
        i[3] = changShop(i[3])
        for j in range(hour * 60 + minute):
            Music += i[3][l]
            l += 1
            if l == len(i[3]):
                l = 0

        if m in Music and len(Music) > music_long:
            answer, music_long = i[2], len(Music)

        Music, l = "", 0

    return answer


music = ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]
# ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]
# ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]
M = "CC#BCC#BCC#BCC#B"
# "ABC"
# "ABCDEFG"
print(solution(M, music))
