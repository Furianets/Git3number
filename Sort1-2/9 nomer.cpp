#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include <iomanip> 
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main(){
    

    string line;

    int n, gap, f = 0;

    cout << "n = "; cin >> n;

    int* b = new int[n]; // объявление массива
    int** a = new int* [n]; // объявление массива
    for (int i = 0; i < n; i++) // создание двумерности в массиве
        a[i] = new int[n];

    for (int i = 0; i < n; i++) //заполнение массива
    {
        in >> line;
        for (int j = 0; j < n; j++)
            a[i][j] = (int)line[j] - (int)'0';
    }

    // ---------------------

    for (int i = 0; i < n; i++)
    {
        f++;
        if (f % 3 != 0)
        {
            for (int w = 0; w < n; w++)
                b[w] = a[w][i];

            gap = n / 1.247;

            while (gap >= 1)
            {
                if (gap < 1)
                    gap = 1;

                for (int j = 0; j < n - gap; j++)
                    if (b[j] > b[j + gap])
                        swap(b[j], b[j + gap]);

                gap /= 1.247;
            }

            for (int q = 0; q < n; q++)
                a[q][i] = b[q];

        }
        else
        {
            for (int w = 0; w < n; w++)
                b[w] = a[w][i];

            gap = n / 1.247;

            while (gap >= 1)
            {
                if (gap < 1)
                    gap = 1;

                for (int j = 0; j < n - gap; j++)
                    if (b[j] > b[j + gap])
                        swap(b[j], b[j + gap]);

                gap /= 1.247;
            }

            for (int u = 0; u < n / 2; u++)
                swap(b[u], b[n - 1 - u]);

            for (int q = 0; q < n; q++)
                a[q][i] = b[q];
        }
    }

    // ---------------------

    for (int i = 0; i < n; i++) // вывод массива
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "  ";

        cout << endl;
    }
    return 0;
}