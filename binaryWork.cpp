#include <iostream>
#include <fstream>
#include <string>

size_t inBinary(char binary[]) {
    std::cout << "Введите двоичное число (максимум 8 символов)" << std::endl;
    std::cin >> binary;

    return std::strlen(binary);
}

void isBinary(char binary[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            std::cout << "Число не является двоичным" << std::endl;
            return;
        }
    }
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

    int a_lenght = inBinary(a);
    int b_lenght = inBinary(b);

    isBinary(a, a_lenght);
    isBinary(b, b_lenght);

    addedBinary(a, a_lenght);
    addedBinary(b, b_lenght);

    conjuction(bitsize, a, b, output);

    std::cout << std::endl << "Конъюнкция введеных двоичных чисел:" << std::endl << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << output << std::endl;
}