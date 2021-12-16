#include <iostream>
#include <vector>

using namespace std;

vector <int> inputVector(vector <int> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        vec.at(i) = -100 + rand() % 200;
    }
    return vec;
}

void showVector(vector <int> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

double averageVector(vector <int> vec)
{
    int n = vec.size();
    double aver = 0;
    for (int i = 0; i < n; i++)
    {
        aver = aver + vec.at(i);
    }
    aver = aver / n;
    return aver;
}

void compareVector(vector <int> vec1, vector <int> vec2)
{
    int n1 = vec1.size();
    int n2 = vec2.size();
    vector <int> vec;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (vec1[i] == vec2[j])
            {
                vec.push_back(vec1[i]);
            }
        }
    if (vec.empty())
    {
        cout << "Общих элементов нет";
    }
    else
    {
        cout << "Общие элементы: ";
        showVector(vec);
    }
}

int testInput(int n)
{
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Ошибка: могу быть введены только цифры." << endl;
        return -1;
    }
    if (n <= 0)
    {
        cout << "Ошибка: введите положительное число";
        return -1;
    }
    return 0;
}

int main()
{
    int n1, n2;
    cout << "Количество элементов в первом векторе: ";
    cin >> n1;
    if (testInput(n1) == -1)
        return -1;
    cout << "Количество элементов во втором векторе: ";
    cin >> n2;
    if (testInput(n2) == -1)
        return -1;
    vector <int> vector1(n1);
    vector <int> vector2(n2);
    vector1 = inputVector(vector1);
    vector2 = inputVector(vector2);
    showVector(vector1);
    showVector(vector2);
    cout << "Среднее арифметическое первого вектора: " << averageVector(vector1) << endl;
    cout << "Среднее арифметическое второго вектора: " << averageVector(vector2) << endl;
    compareVector(vector1, vector2);
}