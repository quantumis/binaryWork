#include <iostream> 

int main() {
    setlocale(LC_ALL, "");

    const int bitsize = 8;

    char a[bitsize + 1];
    char b[bitsize + 1];
    char output[bitsize + 1];

    std::cout << "Введите первое двоичное число (максимум 8 символов)" << std::endl;
    std::cin >> a;

    int a_lenght = std::strlen(a);

    std::cout << "Введите второе двоичное число (максимум 8 символов)" << std::endl;
    std::cin >> b;

    int b_lenght = std::strlen(b);

    for (int i = 0; i < a_lenght; i++) {
        if (a[i] != '0' && a[i] != '1') {
            std::cout << "Первое число не является двоичным" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < b_lenght; i++) {
        if (b[i] != '0' && b[i] != '1') {
            std::cout << "Второе число не является двоичным" << std::endl;
            return 1;
        }
    }

    if (a_lenght < 8) {
        for (int i = a_lenght; i >= 0; i--) {
            a[i + 8 - a_lenght] = a[i];
        }

        for (int i = 0; i < 8 - a_lenght; i++) {
            a[i] = '0';
        }
    }

    if (b_lenght < 8) {
        for (int i = b_lenght; i >= 0; i--) {
            a[i + 8 - b_lenght] = a[i];
        }

        for (int i = 0; i < 8 - b_lenght; i++) {
            b[i] = '0';
        }
    }

    for (int i = 0; i < bitsize; i++)
    {
        if (a[i] == '1' && b[i] == '1') {
            output[i] = '1';
        }
        else {
            output[i] = '0';
        }
    }

    output[bitsize] = 0;

    std::cout << std::endl << "Конъюнкция введеных двоичных чисел:" << std::endl << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << output << std::endl;
}