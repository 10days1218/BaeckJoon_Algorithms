string = input()
alphabet = []

for i in range(97, 123):
    alphabet.append(string.find(chr(i)))

for i in alphabet:
    print(i, end=' ')

print()