#include <iostream>
#include <map>
#include <fstream>

using namespace std;


int readData()
{
    char fname[40];
    string ndata;
    map <string, int> data;
    map <string, int> ::iterator it;
    cout << "Enter the file name: ";
    cin.getline(fname, 40);
    fstream file;
    file.open(fname, ios::in);
    if (errorFileOpen(file) == -1)
        return -1;
    while (!file.eof())
    {
        file >> ndata;
        it = data.find(ndata);
        if (it == data.end())
        {
            data.insert(make_pair(ndata, 1));
        }
        else
        {
            it->second++;
        }
    }
    file.close();
    showMap(data);
    return 0;
}


void showMap(map <string, int> data)
{
    map <string, int> ::iterator it = data.begin();
    for (int i = 0; it != data.end(); it++, i++)
    {
        cout << "The string: " << it->first << " occurs " << it->second << " times·" << endl;
    }

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
