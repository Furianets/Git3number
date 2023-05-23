// Сортировки 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


void heapify(int* arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    fin >> n;
    int** m = new int* [n];
    for (int i = 0; i < n; i++) {         //заполняем двумерный массив
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> m[i][j];
        }
    }
    
    int* mst = new int[n];
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            mst[j] = m[j][i]; // записываем столбец массива как строку
        }
        heapSort(mst,n);
        for (int j = 0; j < n; j++) {
            m[j][i] = mst[j];
        }
    }
    
    fout << "Счет столбцов идет с 0!" << endl;
    //for (int i = 0; i < n; i++) fout << m[i] << " ";
    for (int i = 0; i < n; i++) {        //выводим отсортированный массив
        for (int j = 0; j < n; j++) {
            fout << m[i][j] << " ";
        }
        fout << endl;
    }
    fin.close();
    fout.close();
}
