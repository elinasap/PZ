
#include <iostream>
#include <string.h>
#include <malloc.h>
using namespace std;


class Mas
{
private:
    int* a;
    int size;
public:
Mas(int sizemas)
{
    size = sizemas;
    a = (int*)malloc(size * sizeof(int));
}

Mas(Mas&o)
{
    a = new int[o.size];
    size = o.size;
    for (int i = 0; i < o.size; i++)
    {
        a[i] = o.a[i];
        
    }
}


~Mas()
{
    free (a);
}

int Create()
{
    cout << "Введите элементы массива: "<<endl;
    for (int i = 0; i < size; i++)
    {
	    if (test(a[i]) == -1)
        {
            cout << "Ошибка! Элемент a[" << i << "] = " << a[i] << " не входит в диапазон допустимых значений" << endl;
            return -1;
        }
        cout << "a[" << i << "] = ";
        cin >> a[i];
        if (testtwo() == -1)
            return -1;
        

    }
}



int Push(int n)
{
    if (test(n) == -1)
    {
        cout << "Ошибка! Элемент a[" << size << "] = " << n << " не входит в диапазон допустимых значений" << endl;
        return -1;;
    }
    size++;
    a = (int*)realloc(a, size * sizeof(int)); 
    a[size - 1] = n;
    return size;
}


void Plus(Mas&d)
{
    cout << "Сложение массивов: " << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] + d.a[i];
        cout << a[i] << " ";
    }
    cout << endl;
}

void Minus(Mas&d)
{
    cout << "Вычитание массивов: " << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = 8*a[i] - d.a[i];
        cout << a[i] << " ";
    }
    cout << endl;
}

int test(int p)
{
        if ((p > 100) || (p < -100))
        {
            return -1;
        }
    return 0;
}

int testtwo()
{
    if (cin.fail()) 
    {
        cin.clear(); 
        cin.ignore(32767, '\n');
        cout << "Можно вводить только цифры. " << endl;
        return -1;
    }
}

void Output()
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
}
}; 

int main()
{
    setlocale (LC_ALL, "Russian");
    int sizemas;
    int n;
    cout << "Введите размер массива: ";
    cin >> sizemas; 
    Mas mas(sizemas);
    if (mas.testtwo() == -1)
        return -1;
    if (mas.Create() == -1)
        return -1;
    mas.Output();
    cout << "Введите элемент для добавления в массив: ";
    cin >> n;
    sizemas=mas.Push(n);
    if (sizemas == -1)
        return -1;
    mas.Output();
    cout << endl;
	Mas nmas = mas;
    mas.Plus(nmas);
    mas.Minus(nmas);
    cout << "Скопированный массив: " << endl;
    nmas.Output();
    
    return 0;
}

