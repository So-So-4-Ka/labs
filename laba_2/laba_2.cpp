#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "Mnozhestvo.h"

using namespace std;
using namespace My_Set;
int j=0;

int *Create_Array(int *arr, int size);

int main()
{
    try
    {
        int size;
        int* array;
        cout << "\nКакой размер множества хотите задать? (В последствие чего программа уберёт одинаковые элементы в множестве, если они были)\n Для множества А размер будет равен = ";
        cin >> size;      
        array = Create_Array(array, size);// заполнение множества (+ учёт уникальности эллемента (одинаковые смещаются в хвост и массив уменьшается)) 
        Set A(size, array);
        delete []array;
        cout << "\nДля множества B размер будет равен = ";
        cin >> size; 
        array = Create_Array(array, size);// заполнение множества (+ учёт уникальности эллемента (одинаковые смещаются в хвост и массив уменьшается)) 
        Set B(size, array);
        delete []array;

        cout<<" A = " << A << endl;
        cout<<" B = " << B << endl;

        Set A_copy(A);
        A+=B;
        cout << " A+B = " << A << endl;
        A = A_copy; 
        A-=B;
        cout << " A без B = " << A << endl;  
        A = A_copy;
        A*=B;
        cout << " A*B = " << A << endl;
        A = A_copy;

        cout << "Cтрогое: " << A.Strict_Clusion(B) << endl;
        cout << "Нестрогое: " << A.Unstrict_Clusion(B) << endl;



        cout << "Программу выполнил Плещев Данил 431-3 группа." << endl;
    }

    catch(const exception& e)
    {
        cerr << "\nПойман:\n"  << e.what() << endl;
        cerr << "\nТип:\n" << typeid(e).name() << endl;
    }

    return 0;
}

int *Create_Array(int *arr, int size)
{
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand()%100;

    return arr;
}