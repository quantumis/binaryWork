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
        if (binary_a[i] == '1' && binary_b[i] == '1') {
            output[i] = '1';
        }
        else {
            output[i] = '0';
        }
    }

    output[bitsize] = 0;
}

int main() {
    setlocale(LC_ALL, "");

    const int bitsize = 8;
    char a[bitsize + 1];
    char b[bitsize + 1];
    char output[bitsize + 1];

    AB result = fileBinary(a, b, bitsize);
    int a_lenght = result.a;
    int b_lenght = result.b;

    //int a_lenght = inBinary(a);
    //int b_lenght = inBinary(b);

    if (!isBinary(a, a_lenght) || !isBinary(b, b_lenght)) { return -1; }

    addedBinary(a, a_lenght);
    addedBinary(b, b_lenght);

    conjuction(bitsize, a, b, output);

    std::ofstream out;
    out.open("result.txt");

    if (out.is_open())
    {
        out << "Конъюнкция введеных двоичных чисел:" << std::endl << std::endl;
        out << a << std::endl;
        out << b << std::endl;
        out << "--------" << std::endl;
        out << output << std::endl;
    }

    out.close();

    std::cout << std::endl << "Конъюнкция введеных двоичных чисел:" << std::endl << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << output << std::endl;
}