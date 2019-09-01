import re

p = re.compile(r"(\D+)(\d+)")


def solution(files):
    file_list = [i for i in files]
    file_list.sort(key=com)
    return file_list


def com(file):
    m = p.match(file)
    return (m.group(1).lower(), int(m.group(2)))


files = [
    # "F-5 Freedom Fighter",
    # "B-50 Superfortress",
    # "A-10 Thunderbolt II",
    # "F-14 Tomcat"
    ##################
    # "img12.png",
    # "img10.png",
    # "img02.png",
    # "img1.png",
    # "IMG01.GIF",
    # "img2.JPG",
    ####################
    # "A1.png",
    # "a3.png",
    # "A3.png",
    # "a2"
    #####################
    "foo9.txt",
    "foo010bar020.zip",
    "F-15",
    #####################
    # "muzi1.txt",
    # "MUZI1.txt",
    # "muzi001.txt",
    # "muzi1.TXT",
]
# print(solution(files))
print(solution(files))
