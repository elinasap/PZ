#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int readData()
{
    char fname[40];
    int ndata, n;
    stack <int> myStack;
    cout << "Enter the file name: ";
    cin.getline(fname, 40);

    fstream file;/
    file.open(fname, ios::in);
    if (errorFileOpen(file) == -1)
        return -1;
    file >> n;
    int** mas = new int* [n];
    for (int i = 0; i < n; i++)
    {
        mas[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> mas[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
    int* ver = new int[n];
    cout << endl;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            ver[i] = 0;
        myStack.push(k);
        int node;
        while (!myStack.empty())
        {
            node = myStack.top();
            myStack.pop();
            if (ver[node] == 2)
                continue;
            ver[node] = 2;
            for (int j = n - 1; j >= 0; j--)
            {
                if ((mas[node][j] == 1) && (ver[j] != 2))
                {
                    myStack.push(j);
                    ver[j] = 1;
                }
            }
            arr[k][node] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete mas[i];
    delete[] mas;
    for (int i = 0; i < n; i++)
        delete arr[i];
    delete[] arr;
    return 0;
}

int errorFileOpen(fstream& file)
{
    if (!file)
    {
        cout << "\nFile opening error";
        return -1;
    }
    else
        return 0;
}

int main()
{
    if (readData() == -1)
        return -1;
}
