def prime_factor(num):
    factor = 2
    while not num == 1:
        if num % factor == 0:
            print(num, factor)
            num = num / factor
        else:
            factor += 1
    return factor


number = 600851475143
print(prime_factor(number))
