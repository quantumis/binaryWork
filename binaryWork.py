class Binary:
    def __init__(self, str= None):
        if str is not None:
            if all(x in '01' for x in str):
                self.value = list(str)
            else:
                print("Число не является двоичным")
                exit(-1)
        else:
            self.value = []
    def __and__(self, other):
        max_len = max(len(self.value), len(other.value))
        self.added_binary(max_len)
        other.added_binary(max_len)
        
        temp = Binary()
        temp.value = ['1' if x == '1' and y == '1' else '0' for x, y in zip(self.value, other.value)]
        return temp
    def __gt__(self, other):
         return int("".join(self.value)) > int("".join(other.value))
    def __lt__(self, other):
        return int("".join(self.value)) < int("".join(other.value))
    def __str__(self):
        return ''.join(self.value)

    def added_binary(self, length):
        self.value = ['0'] * (length - len(self.value)) + self.value
    def conjunction(self, b):
        max_len = max(len(self.value), len(b.value))
        self.added_binary(max_len)
        b.added_binary(max_len)
        
        temp = Binary()
        temp.value = ['1' if x == '1' and y == '1' else '0' for x, y in zip(self.value, b.value)]
        return temp

def output(a, b, c):
    return f"{a}\n{b}\n{'-'*len(c.value)}\n{c}"
def dialog_event():
    print("Выберите желаемое действие (соответствующую цифру в консоль):")
    print("1. Работа в консоли")
    print("2. Работа с файлом")
    choice = input()

    if choice == '1':
        return Binary(input("Введите число: "))
    elif choice == '2':
        try:
            with open('binary.txt', 'r') as file:
                return Binary(file.readline())
        except:
            print("Ошибка при чтении файла")
            exit(-1)
    else:
        print("Неверный выбор")
        exit(-1)

if __name__ == "__main__":
    a = dialog_event()
    b = dialog_event()
    out = a.conjunction(b)

    print(output(a, b, out))
    try:
        with open('result.txt', 'w') as file:
            file.write(output(a, b, out))
    except:
        print("Ошибка записи в файл")
