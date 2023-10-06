#include "iostream"
using namespace std;

int main(){
    for(int i = 1; i < 10; ++i){

        int num;
        cout << "\nВведите номер задания: ";
        cin >> num;

        if (num >= 1 && num <= 4){

            if (num == 1)
            {
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
            }
            else if (num == 2) {
                int n;
                int order1;
                int mask1;

                order1 = sizeof(int) * 8 - 1;
                mask1 = 1 << order1;


                for (int i = 1; i > -1; ++i) {
                    cout << "Введите число типа int: ";
                    cin >> n;

                    cout << "num = " << n << ", адрес - " << &n << "\n";
                    cout << "Двоичное представление числа " << n << ":\n";

                    for (int i = 0; i <= order1; ++i) {
                        cout << ((n & mask1) ? 1 : 0);
                        n <<= 1;
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
                }
            }
            else if (num == 3)
            {
                union {
                    int varI;
                    float varF;
                };

                cout << "Введите вещ. число типа float: ";
                cin >> varF;

                cout << "varI = " << varI << ", адрес - " << &varI << endl;
                cout << "varF = " << varF << ", адрес - " << &varF << endl;

                int order3 = sizeof(varF) * 8 - 1;
                unsigned int mask3;
                mask3 = 1 << order3;

                cout << "Двоичное представление в памяти числа " << varF << " типа Double\n";

                for (int i = 0; i <= order3; ++i) {
                    cout << ((mask3 & varI) ? 1 : 0);
                    mask3 >>= 1;
                    if (!i || i == 8) {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
            else if (num == 4)
            {
                union {
                    int arr[2];
                    double varD;
                };

                int order4 = sizeof(varD) * 8 - 1;
                unsigned int mask4;
                mask4 = 1 << 31;

                cout << "Введите вещественное число типа double: ";
                cin >> varD;

                cout << "Двоичное представление в памяти числа " << varD << " типа Double\n";


                for (int i = 0; i <= (order4 / 2); ++i) {
                    cout << ((mask4 & arr[1]) ? 1 : 0);
                    mask4 >>= 1;
                    if (!i or i == 11) {
                        cout << " ";
                    }
                }

                mask4 = 1 << 31;

                for (int i = 0; i <= (order4 / 2); ++i) {
                    cout << ((mask4 & arr[0]) ? 1 : 0);
                    mask4 >>= 1;
                }

                cout << "\n";
            }

        }
        else
        {
            cout << "Всего 4 задания";
        }


    }
    return 0;
}
