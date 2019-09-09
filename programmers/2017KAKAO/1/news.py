import re
from collections import Counter

def solution(str1, str2):

    answer = 0

    p = re.compile('^[a-z]*$')
    list1 = []
    list2 = []
    
    str1 = str1.lower()
    str2 = str2.lower()

    len1 = len(str1)
    len2 = len(str2)

    for i in range(0,len1-1):
        tmp = str1[i] + str1[i+1]
        m = p.match(tmp);
        if m :
            list1.append(tmp)
    
    for i in range(0, len2-1):
        tmp = str2[i] + str2[i+1]
        m = p.match(tmp)
        if m:
            list2.append(tmp) 
    
    m1 = Counter(list1)
    m2 = Counter(list2)
    inter = list((m1 & m2).elements())
    i_size = len(inter)
    u_size = len(list1) + len(list2) - i_size

    if u_size == 0:
        answer = 65536
    else:
        answer = int(i_size / u_size  * 65536)
    
    return answer

str1 = "abc"
str2 = "efd"
print(solution(str1,str2))