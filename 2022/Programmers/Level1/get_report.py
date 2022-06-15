def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report_dict = {}
    id_dict = {}
    ban_dict = {}

    for i, id_str in enumerate(id_list):
        id_dict[id_str] = i 
    
    for r in report:
        user_id, report_id = map(str, r.split())
        if user_id not in report_dict:
            report_dict[user_id] = [report_id]
        
        elif report_id not in report_dict[user_id]:
            report_dict[user_id].append(report_id)

    for r in report_dict:
        ban_list = report_dict[r]
        for ban in ban_list:
            if ban not in ban_dict:
                ban_dict[ban] = 1
            else:
                ban_dict[ban] += 1

    for report_id in ban_dict:
        if ban_dict[report_id] >= k:
            for r in report_dict:
                if report_id in report_dict[r]:
                    index = id_dict[r]
                    answer[index] += 1

    return answer



if __name__ == "__main__":

    
    id_list = ["muzi", "frodo", "apeach", "neo"]
    report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
    k = 2

    answer = solution(id_list, report, k)
    print(answer)