#4673
total_set = set(range(1, 10001))
gen_set = set()

for i in range(1, 10001):
    for j in str(i):
        i += int(j)
    gen_set.add(i)

for i in sorted(total_set - gen_set):
    print(i)
