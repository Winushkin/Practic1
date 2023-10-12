#include "iostream"

using namespace std;

union fl {
    int numI;
    float numF;
};

union db{
    double numD;
    int arr [2];
};

union fl fl;
union db db;
unsigned int mask;
int order;

void pr1() {
    cout <<
        "Выделенное кол-во памяти(в байтах) на разные типы данных:\n"
        "int: " << sizeof(int) << "\n" <<
        "short int: " << sizeof(short int) << "\n" <<
        "long int: " << sizeof(long int) << "\n" <<
        "float: " << sizeof(float) << "\n" <<
        "double: " << sizeof(double) << "\n" <<
        "long double: " << sizeof(long double) << "\n" <<
        "char: " << sizeof(char) << "\n" <<
        "bool: " << sizeof(bool) << "\n\n";
}


void pr2(int num){
    cout << "\nДвоичное представление числа " << num << ":\n";
    order = sizeof(int) * 8;
    mask = 1 << (order - 1);

    for (int i = 0; i < order; ++i){
        cout << ((num & mask)? 1 : 0);
        mask >>= 1;
        if (!i || !((i + 1) % 8)){
            cout << " ";
        }
    }
    cout << "\n\n";
}


void pr3(union fl num){
    cout << "\nДвоичное представление числа " << num.numF << ":\n";
    order = sizeof(num.numF) * 8;
    mask = 1 << (order - 1);

    for (int i = 0; i < order; ++i){
        cout << ((num.numI & mask)? 1 : 0);
        mask >>= 1;
        if (!i){
            cout << " ";
        }
    }
    cout << "\n\n";
}


void pr4(union db num){
    cout << "\nДвоичное представление числа " << num.numD << ":\n";
    order = sizeof(num.numD) * 8;
    mask = 1 << (order - 1);

    for (int i = 0; i < order / 2; ++i){
        cout << ((num.arr[1] & mask)? 1 : 0);
        mask >>= 1;
        if (!i || i == 11){
            cout << " ";
        }
    }

    mask = 1 << (order - 1);

    for (int i = 0; i < order / 2; ++i){
        cout << ((num.arr[0] & mask)? 1 : 0);
        mask >>= 1;
    }
    cout << "\n\n";
}


int main() {
    int problem;
    for (int repeat = 0; repeat < 10; ++repeat)
    {
        cout << "Номер задания: ";
        cin >> problem;

        switch (problem) {
            case 1:
                pr1();
                break;

            case 2:
                int num;
                cout << "Введите целое число: ";
                cin >> num;
                pr2(num);
                break;

            case 3:
                cout << "Введите вещественное число: ";
                cin >> fl.numF;
                pr3(fl);
                break;

            case 4:
                cout << "Введите вещественное число: ";
                cin >> db.numD;
                pr4(db);
                break;

            default:
                cout << "Доступно только 4 задания\n\n";
        }
    }
}
