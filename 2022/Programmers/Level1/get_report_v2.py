def solution(id_list, report, k):
    answer = [0] * len(id_list)
    ban_dict = {x : 0 for x in id_list}
    
    for r in set(report):
        ban_dict[r.split()[1]] += 1

    for r in set(report):
        if ban_dict[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] +=1

    return answer



if __name__ == "__main__":

    
    id_list = ["muzi", "frodo", "apeach", "neo"]
    report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
    k = 2

    answer = solution(id_list, report, k)
    print(answer)