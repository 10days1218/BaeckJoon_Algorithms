import datetime


def solution(numServer, logs):
    answer = []
    roundrobin(numServer, logs)
    return answer


def roundrobin(numServer, logs):

    for log in logs:
        l = log.split(" ")
        start = datetime.datetime.strptime(l[0], "%H:%M:%S.%f")
        end = float(l[1])
        print(start)


Logs = [
    "12:00:00.100 0.400",
    "12:00:00.200 0.500",
    "12:00:00.300 0.100",
    "12:00:00.400 0.600",
    "12:00:00.500 0.200",
    "12:00:00.600 0.400",
]
solution(2, Logs)
