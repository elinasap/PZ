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
        cout << "No common elements";
    }
    else
    {
        cout << "Common elements: ";
        showVector(vec);
    }
}

int testInput(int n)
{
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "You can enter only numbers." << endl;
        return -1;
    }
    if (n <= 0)
    {
        cout << "Enter a non-negative number";
        return -1;
    }
    return 0;
}

int main()
{
    int n1, n2;
    cout << "Number of elements in first vector: ";
    cin >> n1;
    if (testInput(n1) == -1)
        return -1;
    cout << "Number of elements in second vector: ";
    cin >> n2;
    if (testInput(n2) == -1)
        return -1;
    vector <int> vector1(n1);
    vector <int> vector2(n2);
    vector1 = inputVector(vector1);
    vector2 = inputVector(vector2);
    showVector(vector1);
    showVector(vector2);
    cout << "Average of first vector: " << averageVector(vector1) << endl;
    cout << "Average of second vector: " << averageVector(vector2) << endl;
    compareVector(vector1, vector2);
}
