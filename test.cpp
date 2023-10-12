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

struct unions{
    union fl flUnion;
    union db dbUnion;
    int numI;

};

union fl fl;
union db db;
struct unions uns;
unsigned int mask;
int order;
int changeBit, newNum, num;




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
    cout << "\n";
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
    cout << "\n";
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
    cout << "\n";
}


void idz(struct unions funs, int problemNum){
    cout << "\nКакие биты изменить(вводить поочередно, по завершении -1)?: \n";

    switch (problemNum) {
        case 2:
            while (true){
                cout << "Введите номер бита: ";
                cin >> changeBit;
                if (changeBit == -1){
                    break;
                }else if (changeBit < 0 || changeBit >= 32){
                    cout << "Неверный ввод\n";
                }else{
                    newNum = pow(2, changeBit);
                    funs.numI ^= newNum;
                }
            }
            mask = 1 << 31;

            cout << "\n";
            for (int i = 0; i < order; ++i){
                cout << ((funs.numI & mask) ? 1 : 0);
                mask >>= 1;
                if (!i || !((i + 1) % 8)){
                    cout << " ";
                }
            }
            cout << "\n\n";

            break;

        case 3:
            while (true){
                cout << "Введите номер бита: ";
                cin >> changeBit;
                if (changeBit == -1){
                    break;
                }else if (changeBit < 0 || changeBit >= 32){
                    cout << "Неверный ввод\n";
                }else{
                    newNum = pow(2, changeBit);
                    funs.flUnion.numI ^= newNum;
                }
            }
            mask = 1 << 31;

            cout << "\n";
            for (int i = 0; i < order; ++i){
                cout << ((funs.flUnion.numI & mask) ? 1 : 0);
                mask >>= 1;
                if (!i){
                    cout << " ";
                }

            }
            cout << "\n\n";
            break;

        case 4:
            while (true){
                cout << "Введите номер бита: ";
                cin >> changeBit;
                if (changeBit == -1){
                    break;
                }else if (changeBit < 0 || changeBit >= 64){
                    cout << "Неверный ввод\n";
                }else{
                    if (changeBit <= 31) {
                        newNum = pow(2, changeBit);
                        funs.dbUnion.arr[0] ^= newNum;
                    }else{
                        newNum = pow(2, changeBit - 32);
                        funs.dbUnion.arr[1] ^= newNum;
                    }
                }
            }
            mask = 1 << 31;

            cout << "\n";
            for (int i = 0; i < 32; ++i){
                cout << ((funs.dbUnion.arr[1] & mask)? 1 : 0);
                mask >>= 1;
                if (!i || i == 11){
                    cout << " ";
                }
            }

            mask = 1 << 31;
            cout << " ";

            for (int i = 0; i < 32; ++i){
                cout << ((funs.dbUnion.arr[0] & mask)? 1 : 0);
                mask >>= 1;
            }
            cout << "\n\n";

            break;


    }
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
                cout << "Введите целое число: ";
                cin >> uns.numI;
                pr2(uns.numI);
                idz(uns, 2);

                break;

            case 3:
                cout << "Введите вещественное число: ";
                cin >> uns.flUnion.numF;
                pr3(uns.flUnion);
                idz(uns, 3);
                break;

            case 4:
                cout << "Введите вещественное число: ";
                cin >> uns.dbUnion.numD;
                pr4(uns.dbUnion);
                idz(uns, 4);
                break;

            default:
                cout << "Доступно только 4 задания\n\n";
        }
    }
}
