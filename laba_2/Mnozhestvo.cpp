#include "Mnozhestvo.h"
#include <iostream>
#include <iomanip>
#include <math.h>

// break убрать
using namespace std;

namespace My_Set
{   
    int Set::id = 0;

    void Quicksort(int* arr, int size) 
    {
        for (int i = 0; i < size; i++) 
        {
            for (int j = i + 1; j < size; j++) 
            {
                if (arr[i] > arr[j]) 
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    int Sort_and_Unique(int* arr, int& size) 
    {
        Quicksort(arr, size); // cортировка массива
        int k=0;
        for (int i = 0; i < size; i++) 
        {
            if (arr[i] != arr[i + 1]) 
            {
                arr[k++] = arr[i];
            }
        }
        return k;
    }

    Set::Set(int size) // конструктор для создания пустого множества
    {
        cout << "\n Создано пустое множество " << endl;
        if (size <= 0)
            throw logic_error{" Размер множества не может быть таким числом!!! Ошибка в множестве № " + to_string(id)};
        size = 0;
        data = nullptr;
    }

    Set::Set(int size, const int* array):Set(size) // конструктор с входными параметрами
    {
        this->id++;
        cout << "\n Создано множество № " << id << endl;
        this->size=size;
        this->data = new int [size];
        for( int i = 0; i<size; i++)
            data[i] = array[i];
        this->size = Sort_and_Unique(data, size);
    }

    Set::Set(const Set &D) // конструктор копирования
    {
        this->id++;
        cout << "\nКонструктор копирования создан\n" << endl;
        if ((this != &D)) // случай, если размеры не равны 
		{
            if (this->size!=D.size)
            {
                this->size = D.size;
			    this->data = new int[this->size];
            }
            for (int i = 0; i < this->size; i++) 
			    this->data[i] = D.data[i];
		}
    }

    Set::Set(Set &&D) // конструктор перемещение
    {
        cout << "\nКонструктор перемещения" << endl;
        if (this != &D) // если объект не равны
		{
			swap(this->size, D.size);
			swap(this->data, D.data);
        }
    }

    Set::~Set() // деструктор
    {
        cout << "\n Деструктор убил множество № " << id << endl;
        id--;
        if (this->data != nullptr) // случай если множество пустое
        {
            delete[] this->data;
            this->size = 0;
        }
    }

    bool Set::Is_Empty() const // проверка на пустоту 
    {
        return (this->data!=nullptr);
    }

    bool Set::Match_Check(int x) const // поиск схожего элемента
    {
        for (int i = 0; i < this->size; i++)
            if (this->data[i] == x)
                return true;
        return false;
    }

    bool Set::Strict_Clusion(const Set& D) const // нестрогое включение
    {
        bool strictly_includes = true; // предположим, что A строго включено в B

        for (int i = 0; i < this->size; i++) 
        {
            bool found = false; // предположим, что у нас нет совпадений, значение false
            for (int j = 0; j < D.size; j++) 
                if (this->data[i] == D.data[j]) // проверка на совпадение 
                {
                    found = true;
                    break;
                }
            if (!found) 
            {
                strictly_includes = false;
                break;
            }
        }
        return strictly_includes;
    }

    bool Set::Unstrict_Clusion(const Set& D) const // строгое включение
    {
        for (int i = 0; i < this->size; i++) 
        {
            for (int j = 0; j < D.size; j++) 
                if (this->data[i] == D.data[j]) // проверка на совпадение 
                    return true;
        }
        return false;
    }

	ostream& operator<<(ostream& strm, const Set& D) // переопределение оператора вывода
	{
        cout << "{ ";
		for (int i = 0; i < D.size; i++) 
		{
            if(i == D.size - 1) // для красивого вывода элементов (если мы дошли до последнего элемента, то выводим его без точки с запятой)
                strm << D.data[i];
            else
		        strm << D.data[i] << ";  ";
		}
        cout << "}";
		return strm;
	}

    Set& Set::operator=(Set&& D) // оператор перемещения
    {
        if (this != &D) // если объект не равны
		{
			swap(this->size, D.size);
			swap(this->data, D.data);
        }
        return *this;
    }

    Set& Set::operator=(const Set& D) // оператор присваивания
    {
        if (this != &D)
		{
            if (this->size!=D.size) // если размеры не равны
            {
                delete[] this->data;
			    this->size = D.size;
			    this->data = new int[this->size];
            }
            for (int i = 0; i < this->size; i++) 
			    this->data[i] = D.data[i];
		}
		return *this; 
    }

    int Set::operator[](int i)
    {
        if ((i <= 0)&&(i <= this->size-1))
            throw logic_error{"Неправильный индекс!!! Ошибка в множестве № " + to_string(id)};
        return this->data[i];
    }

    bool Set::operator==(const Set& D) const // равенство
    {
        if (this->size != D.size) 
            return false; // если разные размеры
        else // если одинаковые, сравниваем элементы множеств
        {
            for (int i = 0; i < this->size; i++)
                for (int j = 0; j < D.size; j++)
                    if (this->data[i] != D.data[j]) 
                        return false; // если хотя бы один элемент не равен, тогда возвращаем значение false
            return true;
        }
    }

    bool Set::operator!=(const Set& D) const // не равенство
    {
        if (this->size != D.size) 
            return true; // если разные размеры
        else // если одинаковые, сравниваем элементы множеств
        {
            for (int i = 0; i < this->size; i++)
                for (int j = 0; j < D.size; j++)
                    if (this->data[i] != D.data[j]) 
                        return true; // если хотя бы один элемент не равен, тогда возвращаем значение true
            return false;
        }
    }

    Set& Set::operator*=(const Set& D) // оператор дезьюнкции
    {
        int n = 0;
        for (int i = 0; i < D.size; i++)
            for (int j = 0; j < this->size; j++)
                if (D.data[i] == this->data[j]) // если совпадение есть, заносим в новый массив элемент, который совпал и делаем остановку
                {
                    n++;
                    break;
                } 

        int k = 0; 

        int* array = new int[n]; // создаём новый массив
         
        for (int i = 0; i < D.size; i++)
            for (int j = 0; j < this->size; j++)
                if (D.data[i] == this->data[j]) // если совпадение есть, заносим в новый массив элемент, который совпал и делаем остановку
                { 
                    while (k<=n)
                    {
                        array[k] = this->data[j]; 
                        break;
                    } 
                    k++;
                    break;
                }
        // пересоздаём данные, чтобы внести туда результат 
        delete[] this->data;
        this -> size = n;
        this -> data = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->data[i] = array[i];
		return *this; 
    }

    Set& Set::operator+=(const Set& D) // оператор коньюкции
    {
        int n = this->size + D.size;
        int* array = new int[n];

        for (int i = 0; i < this->size; i++) // заносим данные с объекта
            array[i] = this->data[i];
        
        for (int j = 0; j < D.size; j++) // заносим данные с другого объекта 
            for (int i = 0; i < this->size; i++) 
                if(D.data[j]) 
                    array[i + this->size] = D.data[i];

        int unique_n = Sort_and_Unique(array, n); // сортируем и удаляем одинаковые элементы

        // перезаписываем данные объекта
        delete[] this->data;
        this -> size = unique_n;
        this -> data = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->data[i] = array[i];
		return *this; 
    }

    bool Check_In(int element, int array[], int size) // проверка на совпадение ( для оператора -=) 
    {
        for (int i = 0; i < size; i++)
            if (array[i] == element) return true;
        return false;
    }

    Set& Set::operator-=(const Set& D) // A без В
    {
        int n = 0; 
        for (int i = 0; i < this->size; i++) // заносим в массив данные, которых нет в другом множестве
            if (!Check_In(this->data[i], D.data, D.size))
                n++; 
        
        int* array = new int[n]; 
        int k = 0; 

        for (int i = 0; i < this->size; i++) // заносим в массив данные, которых нет в другом множестве  
            if (!Check_In(this->data[i], D.data, D.size))
            {
                while (k<=n)
                {
                    array[k] = this->data[i];  
                    break;
                }
                k++; 
            }
        delete[] this->data;
        this -> size = n;
        this -> data = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->data[i] = array[i];
		return *this; 
    }

    Set operator+(const Set& A, const  Set& B) // оператор коньюкции
	{	
		// создаём объект класса С и копируем в данный объект дынные матрицы А
		Set C(A);
		C+=B;
		return C;
	}

    Set operator*(const Set&A, const Set&B) // оператор дезьюнкции
    {
        Set C(A);
        C*=B;
        return C;
    }

    Set operator-(const Set&A, const Set&B) // оператор А без В
    {
        Set C(A);
        C-=B;
        return C;
    }
}