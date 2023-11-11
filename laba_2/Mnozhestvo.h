#include <iostream>

using namespace std;

namespace My_Set
{
    class Set
    {
        private:
            static int id;
            int size;
            int* data;
        public:
            explicit Set(int size);// конструктор пустого множества (Работает)
            Set(int size, const int* array);// входные параметры (Работает)
            Set(const Set &D);// копирование (Работает)
            Set(Set &&Other);// перемещение (Работает)
            ~Set();// деструктор (Работает)
            int Get_Size() const;
            int Get_Data(int i) const;
            bool Is_Empty() const;// проверка на пустоту (Работает)
            bool Strict_Clusion(const Set& D) const;// строгое и нестрогое включение (Работает)
            bool Unstrict_Clusion(const Set& D) const;// строгое и нестрогое включение (Работает)
            bool Match_Check(int x) const;// проверка на вхождение числа в множество (Работает)
            friend ostream& operator<<(ostream& strm, const Set& D);// Переопределение оператора << (Работает)
            int operator[](int i); 
            Set& operator=(Set&& D);// оператор перемещения (Работает)
            Set& operator=(const Set& D);// оператор присваивания (Работает)
            bool operator==(const Set& B) const;// Равенство (Работает)
            bool operator!=(const Set& B) const;// Неравенство (Работает)
            Set& operator*=(const Set& D);// оператор коньюкции (Работает)
            Set& operator+=(const Set& D);// оператор дезьюнкции (Работает)
            Set& operator-=(const Set& D);// одно множество без другово А без В (Работает)
    };
    Set operator+(const Set& A, const Set& B);// оператор коньюкции (Работает)
    Set operator*(const Set& A, const Set& B);// оператор коньюкции (Работает)
    Set operator-(const Set& A, const Set& B);// одно множество без другово А без В (Работает)
}