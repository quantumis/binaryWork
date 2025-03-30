a = list(input().strip())
b = list(input().strip())
out = []

if not all(x in {'0', '1'} for x in a):
    print("Первое число не является двоичным")
if not all(x in {'0', '1'} for x in b):
    print("Второе число не является двоичным")

max_len = max(len(a), len(b))
a = ['0'] * (max_len - len(a)) + a
b = ['0'] * (max_len - len(b)) + b

out = ['1' if x == '1' and y == '1' else '0' for x, y in zip(a, b)]

print(''.join(a))
print(''.join(b))
print(''.join(out))
