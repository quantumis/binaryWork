a = [x for x in input()]
b = [x for x in input()]

for x in a:
    if x != '0' and x != '1':
        print("Число не является двоичным")

for x in b:
    if x != '0' and x != '1':
        print("Число не является двоичным")

if len(a) > len(b):
    for i in range(len(b) - len(a)):
        b.insert(0, '0')

if len(b) > len(a):
    for i in range(len(a) - len(b)):
        a.insert(0, '0')

print(a)
print(b)

