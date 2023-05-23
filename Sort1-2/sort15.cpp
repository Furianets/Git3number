#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in ("input.txt");
ofstream out ("output.txt");
struct Sotr {
	string surname;
	int staj;
	int godrod;
	void input();
	void print();
};


void sort(Sotr *arr, int n) {
	Sotr temp;
	int i, j;
	for (int i = 2; i <= n; i++) {
		j = i;
		while (arr[j].surname < arr[j - 1].surname || (arr[j].surname == arr[j - 1].surname && arr[j].staj > arr[j - 1].staj) || (arr[j].surname == arr[j - 1].surname && arr[j].staj == arr[j - 1].staj && arr[j].godrod < arr[j - 1].godrod)) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		} 
	}
}

int main() {
	
	int n;
	in >> n;
	Sotr *arr = new Sotr[n+1];
	arr[0].surname = "0";
	arr[0].staj = -1e10;
	arr[0].godrod = -1e10;
	for (int i = 1; i < n + 1; i++) {
		in >> arr[i].surname >> arr[i].staj >> arr[i].godrod;
	}
	sort(arr, n);
	for (int i = 1; i < n + 1; i++) {
		out << arr[i].surname << " " << arr[i].staj << " " << arr[i].godrod << endl;
	}
}