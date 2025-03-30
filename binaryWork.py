def is_binary(arr):
    return all(x in {'0', '1'} for x in arr)
def added_binary(a, length):
    return ['0'] * (length - len(a)) + a
def conjunction(a, b):
    return ['1' if x == '1' and y == '1' else '0' for x, y in zip(a, b)]
def output(a, b, c):
    return f"{''.join(a)}\n{''.join(b)}\n{'-'*len(c)}\n{''.join(c)}"

if __name__ == "__main__":
    a = list(input("Введите первое двоичное число: ").strip())

    try:
        with open('binary.txt', 'r') as file:
            b = list(file.readline().strip())
    except:
        print("Ошибка при чтении файла")
        exit(-1)

    if not is_binary(a):
        print("Первое число не является двоичным")
        exit(-1)
    if not is_binary(b):
        print("Второе число не является двоичным")
        exit(-1)

    max_len = max(len(a), len(b))
    a = added_binary(a, max_len)
    b = added_binary(b, max_len)

    out = conjunction(a, b)

    print(output(a, b, out))

    try:
        with open('result.txt', 'w') as file:
            file.write(output(a, b, out))
    except:
        print("Ошибка записи в файл")
