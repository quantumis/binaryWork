#include <iostream>
#include <fstream>
#include <string>


class Binary {
public:
    static const int bitsize = 8;
    char value[bitsize + 1];
    int lenght;

    Binary() {
        for (int i = 0; i < bitsize; i++) { value[i] = '0'; }
        value[bitsize] = 0;
        lenght = std::strlen(value);
    }

    Binary(std::string param) {
        for (int i = 0; i < param.length(); i++) { value[i] = param[i]; }
        value[bitsize] = 0;
        lenght = param.length();
    }

    //Binary(const Binary &a) {
    //    lenght = 7;
    //    for (int i = 0; i < lenght; i++) { value[i] = a.value[i]; }
    //}

    void fileBinary(std::string path) {
        std::string line;
        std::ifstream in(path);

        if (in.is_open())
        {
            if (std::getline(in, line)) {
                for (int i = 0; i < line.length(); i++) {
                    std::cout << line[i] << std::endl;
                    value[i] = line[i];
                }
            }
        }
        in.close();
        value[line.length() - 1] = 0;
        lenght = std::strlen(value);
    }

    void consoleBinary() {
        std::cout << "Введите двоичное число (максимум 8 символов)" << std::endl;
        std::cin >> value;
        lenght = std::strlen(value);
    }

    bool isBinary() {
        for (int i = 0; i < lenght; i++) {
            if (value[i] != '0' && value[i] != '1') {
                std::cout << "Число не является двоичным" << std::endl;
                return false;
            }
        }
        return true;
    }

    void addedBinary() {
        if (lenght < bitsize) {
            for (int i = lenght; i >= 0; i--) {
                value[i + bitsize - lenght] = value[i];
            }
            for (int i = 0; i < bitsize - lenght; i++) {
                value[i] = '0';
            }
        }
    }

    Binary conjuction(Binary b) {
        Binary tmp;
        for (int i = 0; i < bitsize; i++) { tmp.value[i] = value[i] == '1' && b.value[i] == '1' ? tmp.value[i] = '1' : tmp.value[i] = '0'; }
        value[bitsize] = 0;
        return tmp;
    }
};


std::string createAnswer(Binary a, Binary b, Binary output) {
    std::string str = "\nКонъюнкция введеных двоичных чисел:\n\n";
    str += a.value; str += "\n";
    str += b.value; str += "\n";
    str += "--------\n";
    str += output.value; str += "\n";

    return str;
}

void dialogEvent(Binary& a) {
    size_t answer;

    std::cout << "Выберите желаемое действие (соответствующую цифру в консоль):" << std::endl;
    std::cout << "1. Работа в консоли" << std::endl;
    std::cout << "2. Работа с файлом" << std::endl;
    std::cin >> answer;

    switch (answer) {
    case 1:
        a.consoleBinary();
        break;
    case 2:
        a.fileBinary("binary.txt");
        break;
    default:
        std::cout << "Неверное действие. Попробуйте еще раз" << "\n";
        exit(-1);
    }
}

int main() {
    setlocale(LC_ALL, "");

    Binary a, b, c("11111111"), output;

    dialogEvent(a);
    dialogEvent(b);

    std::ofstream out;

    if (!a.isBinary() || !b.isBinary()) { exit(-1); }

    a.addedBinary();
    b.addedBinary();

    output = a.conjuction(b);

    std::cout << createAnswer(a, b, output);
    out.open("result.txt");
    if (out.is_open()) { out << createAnswer(a, b, output); }
    out.close();

    exit(0);
}

// Ввести динамические массивы
// Конструктор копирования
// Деструктор
// Подумать над приватными полями