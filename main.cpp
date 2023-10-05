#include "iostream"
using namespace std;

int main(){
    for(int i = 1; i < 10; ++i){
        int num;
        cout << "\nВведите номер задания: ";
        cin >> num;
        switch (num) {
            case 1:
                cout <<
                     "Выделенное кол-во памяти на разные типы данных:\n"
                     "int: " << sizeof(int) << "\n" <<
                     "short int: " << sizeof(short int) << "\n" <<
                     "long int: " << sizeof(long int) << "\n" <<
                     "float: " << sizeof(float) << "\n" <<
                     "double: " << sizeof(double) << "\n" <<
                     "long double: " << sizeof(long double) << "\n" <<
                     "char: " << sizeof(char) << "\n" <<
                     "bool: " << sizeof(bool) << "\n";
                break;

            case 2:
                int n;
                cout << "Введите число: ";
                cin >> n;
                int order1;
                int mask1;
                order1 = sizeof(int) * 8 - 1;
                mask1 = 1 << order1;
                cout << "num = " << n << ", адрес - " << &n << "\n";
                cout << "Двоичное представление числа " << n << ":\n";
                for (int i = 0; i <= order1; ++i) {
                    cout << ((n & mask1) ? 1 : 0);
                    mask1 >>= 1;
                    //Это просто нормальный вывод
                    if (i <= 7) {
                        if (!i || i == 7) {
                            cout << " ";
                        }
                    } else {
                        if (!((i + 1) % 8)) {
                            cout << " ";
                        }
                    }

                }
                cout << "\n";
                break;

            case 3:{

                union {
                    int varI;
                    float varF;
                };


                cout << "Введите вещ. число: ";
                cin >> varF;

                cout << "varI = " << varI << ", адрес - " << &varI << endl;
                cout << "varF = " << varF << ", адрес - " << &varF << endl;

                int order3 = sizeof(varF) * 8 - 1;
                unsigned int mask3;
                mask3 = 1 << order3;

                for (int i = 0; i <= order3; ++i) {
                    cout << ((mask1 & varI) ? 1 : 0);
                    if (!i || i == 8) {
                        cout << " ";
                    }
                }

                break;
            }
            case 4:
                union{
                    int arr[2];
                    double varD;
                };
                cout << "Введите вещественное число: ";
                cin >> varD;
                int order4 = sizeof(varD) * 8 - 1;
                unsigned int mask4;
                mask4 = 1 << order4;

                for (int i = 0; i <= order4 / 2; ++i){
                    cout << ((mask4 & arr[0])? 1 : 0);
                    mask4 >>= 1;
                    if (!i or i == 8){
                        cout << " ";
                    }
                }

                for (int i = 0; i <= order4 / 2; ++i){
                    cout << ((mask4 & arr[1])? 1 : 0);
                    mask4 >>= 1;
                }






        }
    }
    return 0;
}




