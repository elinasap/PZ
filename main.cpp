#include <iostream>
#include <string.h>
#include <malloc.h>
#include <typeinfo>
#include <math.h>
using namespace std;

template <typename T>

int Int(T);
template<>
int Int<int>(int p)
{
    return p;
}


template <class T>
class Mas
{
private:
    T* a;
    int size;
public:

    Mas(T sizemas)
    {
        size = sizemas;
        a = (int*)malloc(size * sizeof(int));
        if (!a)
        {
            throw bad_alloc();
        }
    }

    Mas(Mas& o)
    {
        a = new T[o.size];
        if (!a)
        {
            throw bad_alloc();
        }
        size = o.size;
        for (int i = 0; i < o.size; i++)
        {
            a[i] = o.a[i];
        }
    }
    ~Mas()
    {
        free(a);
    }
    Mas& operator =(Mas& mas)
    {
        if (sizeof(a) >= sizeof(mas.a))
        {
            for (int i = 0; i < size; i++)
            {
                a[i] = mas.a[i];
            }
        }
        else
            throw bad_alloc("����� �� ������� �������");
    }
    friend std::ostream& operator<<(std::ostream& out, Mas <T>& mas) 
    {
        out << "���������� ��������� ������"<<endl;
        for (int i = 0; i < mas.size; i++)
        {
            out << mas.a[i] << " ";
        }
        return out;
    }
    double distance (Mas& o)
    {
        if (typeid(o.a[0]) != typeid(int) or typeid(a[0]) != typeid(int))
        {
            throw error_l("�������� ��� ������");
        }
        double d = 0;
        for (int i = 0; i < size; i++)
        {
            d = (a[i] - o.a[i]) * (a[i] - o.a[i]) + d;
        }
        return sqrt(d);
    }
};

template <typename T>
int Mas <T>::create()
{
    cout << "������� " << size << " ��������� �������: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
            if ((test(a[i]) == -1) ||(testtwo() == -1))
            {
                cout << "O����� �����: ����� �� ������� ���������" << endl;
                throw bad_value ("�������� �������� ���������");
            }
    }
    return 0;
}


template <typename T>
int Mas<T>::push(int n)
{
        if ((test(n) == -1)||(testtwo()==-1))
        {
            cout << "������� a[" << size << "] ������� �� �������� ��������" << endl;
            throw bad_value("����� �� ������� ���������");
        }
    size++;
    a = (int*)realloc(a, size * sizeof(int)); //��������� ������ ��� ����� ������� ������
    a[size - 1] = n;
    return size;
}

template <typename T>
void Mas<T>::add(Mas& d)
{
    cout << "�������� ��������" << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] + d.a[i];
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Mas<T>::sub(Mas& d)
{
    cout << "��������� ��������" << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = 8 * a[i] - d.a[i];
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
int Mas<T>::test(int c)
{
    if ((c > 100) || (c < -100))
    {
        return -1;
    }
    return 0;
}

template <typename T>
int Mas<T>::testtwo()
{
    if (cin.fail()) 
    {
        cin.clear(); 
        cin.ignore(32767, '\n'); 
        return -1;
    }
    return 0;
}

template <typename T>
void Mas<T>::output()
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");
    int sizemas;
    int n;
    cout << "������� ������ �������: ";
    cin >> sizemas;
    try
    {
        if (sizemas < 0)
        {
            throw out("������ ������� �� ����� ���� ������ 0");
        }
    }
    catch (out exception)
    {
        cout << "���������� " << exception.what() << endl;
        exit(-1);
    }
    Mas <int> mas(sizemas);
    try 
    {
        mas.create();
    }
    catch (bad_value exception)
    {
        cout << "���������� " << exception.what() << endl;
        exit(-1);
    }
    mas.output();
    cout << "������� ����� �������: ";
    cin >> n;
    try
    {
        sizemas = mas.push(n);
    }
    catch (bad_value exception)
    {
        cout << "���������� " << exception.what() << endl;
        exit(-1);
    }
    cout << "������ � ����������� ���������" << endl;
    mas.output();
    cout << endl;
    try
    {
        Mas <int> nmas = mas;
    }
    catch (bad_alloc exception)
    {
        cout << "���������� " << exception.what() << endl;
        exit(-1);
    }
    Mas <int> nmas = mas;
    cout << "������������� ������" << endl;
    nmas.output();
    mas.add(nmas);
    mas.sub(nmas);
    cout << nmas;
    double d;
    try
    {
        d = mas.distance(nmas);
    }
    catch (error_l exception)
    {
        cout << "���������� " << exception.what() << endl;
        exit(-1);
    }
    d = mas.distance(nmas);
    cout << "\n���������� ����� ���������: " << d;
    return 0;
}
