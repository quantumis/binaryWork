def is_binary(arr):
    return all(x in {'0', '1'} for x in arr)
def added_binary(a, length):
    return ['0'] * (length - len(a)) + a
def conjunction(a, b):
    return ['1' if x == '1' and y == '1' else '0' for x, y in zip(a, b)]
def output(a, b, c):
    return f"{''.join(a)}\n{''.join(b)}\n{'-'*len(c)}\n{''.join(c)}"
def get_binary_input():
    value = input("Введите число: ").strip()
    if is_binary(value):
        return list(value)
    print("Число не является двоичным")
    exit(-1)
def read_from_file(filename):
    try:
        with open(filename, 'r') as file:
            data = file.readline().strip()
            if not is_binary(data):
                print("Число не является двоичным")
                exit(-1)
            return list(data)
    except:
        print(f"Ошибка при чтении файла")
        exit(-1)
def dialog_event():
    print("Выберите желаемое действие (соответствующую цифру в консоль):")
    print("1. Работа в консоли")
    print("2. Работа с файлом")
    choice = input().strip()

    if choice == '1':
        return get_binary_input()
    elif choice == '2':
        return read_from_file("binary.txt")
    else:
        print("Неверное действие. Попробуйте еще раз")
        exit(-1)


if __name__ == "__main__":
    a = dialog_event()
    b = dialog_event()

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
