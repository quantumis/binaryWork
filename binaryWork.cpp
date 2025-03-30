#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Binary {
private:
    char* value;
    int lenght;

    void str_to_mas(string str){
        lenght = str.length();
        value = new char[lenght];

        for (int i = 0; i < lenght; i++){
            if (str[i] != '0' && str[i] != '1') {
                cout << "Число не является двоичным" << endl;
                exit(-1);
            }
            value[i] = str[i];
        }
        value[lenght] = 0;
    }
public:
    Binary() { value = 0; lenght = 0; }
    Binary(string str) { str_to_mas(str); }
    Binary(const Binary &a) { 
        lenght = a.lenght;
        value = new char[lenght];
        for (int i = 0; i < lenght; i++) { value[i] = a.value[i]; }
        value[lenght] = 0;
    }
    ~Binary() {delete[] value; }

    char* getValue() { return value; }
    int getLenght() { return lenght; }
    void print(){ cout << value << endl;}

    void fileBinary(string path) {
        string line;
        ifstream in(path);
        if (in.is_open()) { if (getline(in, line)) { str_to_mas(line); } }
        in.close();
    }

    void consoleBinary() {
        cout << "Введите двоичное число" << endl;
        string str;
        cin >> str;
        str_to_mas(str);
    }

    void addedBinary(Binary& b, bool first) {
        if (first){
            for (int i = b.lenght; i >= 0; i--) {
                b.value[i + lenght - b.lenght] = b.value[i];
            }
            for (int i = 0; i < lenght - b.lenght; i++) {
                b.value[i] = '0';
            }
            b.lenght = lenght;
        }else {
            for (int i = lenght; i >= 0; i--) {
                value[i + b.lenght - lenght] = value[i];
            }
            for (int i = 0; i < b.lenght - lenght; i++) {
                value[i] = '0';
            }
            lenght = b.lenght;
        }
    }
    
    Binary conjuction(Binary& b) {
        if (lenght > b.lenght){
            addedBinary(b, true);
        }else if(b.lenght > lenght){
            addedBinary(b, false);
        }

        Binary tmp(string(lenght, '0'));
        for (int i = 0; i < lenght; i++) { tmp.value[i] = value[i] == '1' && b.value[i] == '1' ? tmp.value[i] = '1' : tmp.value[i] = '0'; }
        tmp.value[lenght] = 0;
        return tmp;
    }
};


string createAnswer(Binary& a, Binary& b, Binary& output) {
    string str = "\nКонъюнкция введеных двоичных чисел:\n\n";
    str += a.getValue(); str += "\n";
    str += b.getValue(); str += "\n";
    str += string(output.getLenght(), '-'); str += "\n";
    str += output.getValue(); str += "\n";

    return str;
}

void dialogEvent(Binary& a) {
    size_t answer;

    cout << "Выберите желаемое действие (соответствующую цифру в консоль):" << endl;
    cout << "1. Работа в консоли" << endl;
    cout << "2. Работа с файлом" << endl;
    cin >> answer;

    switch (answer) {
    case 1:
        a.consoleBinary();
        break;
    case 2:
        a.fileBinary("binary.txt");
        break;
    default:
        cout << "Неверное действие. Попробуйте еще раз" << "\n";
        exit(-1);
    }
}

int main() {
    setlocale(LC_ALL, "");
    Binary a, b;

    dialogEvent(a);
    dialogEvent(b);

    Binary output = a.conjuction(b);

    cout << createAnswer(a, b, output);

    ofstream out;
    out.open("result.txt");
    if (out.is_open()) { out << createAnswer(a, b, output); }
    out.close();

    exit(0);
}