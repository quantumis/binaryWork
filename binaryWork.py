def is_binary(arr):
    return all(x in {'0', '1'} for x in arr)
def added_binary(a, len):
    return ['0'] * (len - len(a)) + a
def conjuction(a, b):
    return ['1' if x == '1' and y == '1' else '0' for x, y in zip(a, b)]


a = list(input().strip())
b = list(input().strip())
out = []

if not is_binary(a):
    print("Первое число не является двоичным")
    exit(-1)
if not is_binary(b):
    print("Второе число не является двоичным")
    exit(-1)

max_len = max(len(a), len(b))
a = added_binary(a, max_len)
b = added_binary(b, max_len)

out = conjuction(a, b)

print(''.join(a))
print(''.join(b))
print(''.join(out))
