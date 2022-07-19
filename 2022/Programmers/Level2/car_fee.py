from math import ceil


def solution(fees, records):
    answer = []
    total_time = []
    car_num_time_dict = {}

    basic_time, basic_fee, cri_time, cri_fee = fees[0], fees[1], fees[2], fees[3]

    for r in records:
        time, car_num, in_out = r.split()

        if car_num not in car_num_time_dict:
            car_num_time_dict[car_num] = [time]

        else:
            car_num_time_dict[car_num].append(time)

    car_num_time_dict = sorted(car_num_time_dict.items())
    print(car_num_time_dict)

    for car_info, time_line in car_num_time_dict:
        total = 0
        # 출차한 기록이 없을 경우
        if len(time_line) % 2 != 0:
            for i in range(0, len(time_line) - 1, 2):
                start_h, start_m = map(int, time_line[i].split(":"))
                end_h, end_m = map(int, time_line[i + 1].split(":"))
                # 시간 계산
                total += (end_h * 60 + end_m) - (start_h * 60 + start_m)

            start_h, start_m = map(int, time_line[-1].split(":"))
            total += (23 * 60 + 59) - (start_h * 60 + start_m)

        else:
            for i in range(0, len(time_line), 2):
                start_h, start_m = map(int, time_line[i].split(":"))
                end_h, end_m = map(int, time_line[i + 1].split(":"))
                # 시간 계산
                total += (end_h * 60 + end_m) - (start_h * 60 + start_m)

        total_time.append(total)

    for time in total_time:
        if time <= basic_time:
            total_fee = basic_fee

        else:
            total_fee = basic_fee + ceil((time - basic_time) / cri_time) * cri_fee

        answer.append(total_fee)
    return answer
