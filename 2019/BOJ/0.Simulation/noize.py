n1 = input()
oper = input()
n2 = input()
ans = "1"

if oper == "+":
    if len(n1) == len(n2):
        f1, f2 = int(n1[0]), int(n2[0])
        f1 = f1 + f2
        ans = str(f1) + n1[1:]
    else:
        if len(n1) > len(n2):
            ans = n1[0 : len(n1) - len(n2)] + n2
        else:
            ans = n2[0 : len(n2) - len(n1)] + n1

if oper == "*":
    ans = ans + n1[1:] + n2[1:]


print(ans)
