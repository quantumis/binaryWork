#include <iostream>
#include <fstream>
#include <string>

typedef struct {
    size_t a;
    size_t b;
} AB;

AB fileBinary(char binary_a[], char binary_b[], int bitsize) {
    std::string line;
    std::ifstream in("binary.txt");
    AB result;

    if (in.is_open())
    {
        if (std::getline(in, line)) {
            std::strncpy(binary_a, line.c_str(), bitsize);
        }

        if (std::getline(in, line)) {
            std::strncpy(binary_b, line.c_str(), bitsize);
        }
    }
    in.close();

    result.a = std::strlen(binary_a);
    result.b = std::strlen(binary_b);

    return result;
}

size_t inBinary(char binary[]) {
    std::cout << "Введите двоичное число (максимум 8 символов)" << std::endl;
    std::cin >> binary;

    return std::strlen(binary);
}

bool isBinary(char binary[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            std::cout << "Число не является двоичным" << std::endl;
            return false;
        }
    }
    return true;
}

void addedBinary(char binary[], int lenght) {
    if (lenght < 8) {
        for (int i = lenght; i >= 0; i--) {
            binary[i + 8 - lenght] = binary[i];
        }

        for (int i = 0; i < 8 - lenght; i++) {
            binary[i] = '0';
        }
    }
}

void conjuction(int bitsize, char binary_a[], char binary_b[], char output[]) {
    for (int i = 0; i < bitsize; i++)
    {
        output[i] = binary_a[i] == '1' && binary_b[i] == '1' ? output[i] = '1' : output[i] = '0';
    }

    output[bitsize] = 0;
}

void workFunction(char a[], char b[], int bitsize, int a_lenght, int b_lenght, char output[]) {
    if (!isBinary(a, a_lenght) || !isBinary(b, b_lenght)) { exit(-1); }

    addedBinary(a, a_lenght);
    addedBinary(b, b_lenght);

    conjuction(bitsize, a, b, output);
}

std::string createAnswer(char a[], char b[], char output[]){
    std::string str = "\nКонъюнкция введеных двоичных чисел:\n\n";
    str += a; str += "\n";
    str += b; str += "\n";
    str += "--------\n";
    str += output; str += "\n";

    return str;
}

int main() {
    setlocale(LC_ALL, "");

    const int bitsize = 8;
    char a[bitsize + 1];
    char b[bitsize + 1];
    char output[bitsize + 1];
    int a_lenght, b_lenght;
    std::ofstream out;
    size_t answer;

    std::cout << "Выберите желаемое действие (соответствующую цифру в консоль):" << std::endl;
    std::cout << "1. Работа в консоли" << std::endl;
    std::cout << "2. Работа с файлом" << std::endl;
    std::cin >> answer;

    switch (answer){
        case 1:
            a_lenght = inBinary(a);
            b_lenght = inBinary(b);
            workFunction(a, b, bitsize, a_lenght, b_lenght, output);
            std::cout << createAnswer(a, b, output);

            exit(0);
        case 2:
            AB result = fileBinary(a, b, bitsize);
            a_lenght = result.a;
            b_lenght = result.b;
            workFunction(a, b, bitsize, a_lenght, b_lenght, output);
            out.open("result.txt");
            if (out.is_open()) { out << createAnswer(a, b, output); }
            out.close();

            exit(0);
        default:
            std::cout << "Неверное действие. Попробуйте еще раз" << "\n";
            exit(-1);
    }
}