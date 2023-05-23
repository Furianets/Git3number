#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string surname;
    string position;
    int birthDay;
    int birthMonth;
    int birthYear;
    int experience;
    int salary;
};

void countingSort(vector<Employee>& arr, int range) {
    vector<int> count(range + 1, 0);  //создаём массив нулей
    for (const auto& emp : arr) {
        count[emp.birthYear]++;
    }
    for (int i = 1; i <= range; ++i) {       //заполняем его датами рождения 
        count[i] += count[i - 1];
    }
    vector<Employee> result(arr.size());          //рузультат
    for (int i = arr.size() - 1; i >= 0; --i) {
        result[count[arr[i].birthYear] - 1] = arr[i];
        count[arr[i].birthYear]--;
    }
    arr = result;
}

int main() {
    ifstream inputFile("employees.txt");
    vector<Employee> employees;         //создаём вектор
    string surname, position;
    int birthDay, birthMonth, birthYear, experience, salary;
    while (inputFile >> surname >> position >> birthDay >> birthMonth >> birthYear >> experience >> salary) {
        employees.push_back({ surname, position, birthDay, birthMonth, birthYear, experience, salary });              //считываем все данные
    }
    countingSort(employees, 2023); // вызываем функцию
    ofstream outputFile("sorted_employees.txt");    //выводим в файл
    outputFile << "Фамилия    ";
    outputFile << "Должность   ";
    outputFile << "Дата рождения   ";
    outputFile << "Стаж работы \n ";


    for (const auto& emp : employees) {
        outputFile << emp.surname << "\t" << emp.position << "\t" << emp.birthDay << "." << emp.birthMonth << "." << emp.birthYear << "             " << emp.experience << "\t" << endl;  //выводим в файл данные которые получились
    }
    return 0;
}

