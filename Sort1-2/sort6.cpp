#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;


ifstream in("input1.txt");
ofstream out("output1.txt");





struct date {//дата
	int dd, mm, yy;
};

bool Bigger(string str1, string str2) {
	if (str1.compare(str2) > 0) return true;
	else return false;
}


struct people {//данные о человеке
	string Surname; 
	date DateOfBirth; 
	int Salary; 
	int Staj;
	string Dolj;
};

int Status(string str) {
	if (str == "Cleaner") return 1;
	if (str == "Seller") return 2;
	if (str == "Director") return 3;
	return -100;
}

date Str_to_Date(string str) {//из строки в дату

	date x;
	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());
	return x;

}

vector<people> inFile() {//ввод из файла
	if (in.is_open()) {
		cout << "Открылся файл ввода" << endl;
		vector<people> x;
		people temp;
		while (!in.eof()) {
			in >> temp.Surname;//фамилия
			cout << temp.Surname << endl;
			string tmp;//дата рождения
			in >> tmp;
			temp.DateOfBirth = Str_to_Date(tmp);
			in >> temp.Salary;//зарплата
			in >> temp.Staj;
			in >> temp.Dolj;
			cout << temp.Dolj << endl;
			x.push_back(temp);
		}
		return x;
	}
	else {
		cout << "Файл ввода не открылся" << endl;
	}

}

void oglav() {
	out << "Фамилия" << "        ";//по левому краю, 10 позиций для фамилии
	out << "Дата           ";
	out << "Зарплата  ";//запрлата
	out << "Стаж  ";//стаж
	out << "Должность" << endl;//должность

}

void print(people x) {//вывод в файл

	out << setw(13) << left << x.Surname << "  ";//по левому краю, 10 позиций для фамилии
	if (x.DateOfBirth.dd < 10) out << left << "0" << x.DateOfBirth.dd << ".";//добавляем 0
	else out << left << x.DateOfBirth.dd << ".";
	if (x.DateOfBirth.mm < 10) out << "0" << x.DateOfBirth.mm << ".";
	else out << x.DateOfBirth.mm << ".";
	out << x.DateOfBirth.yy << "     ";//на год 6 позиций
	out << x.Salary << "     ";//запрлата
	out << x.Staj << "     ";//стаж
	out << x.Dolj << endl;//должность

}


bool operator < (people a, people b) {//переопределяем оператор < в соотвествии с условием
	if (!Bigger(a.Surname, b.Surname) || (a.Surname.compare(b.Surname) == 0 && Status(a.Dolj) < Status(b.Dolj))) return true;
	return false;
}

bool operator > (people a, people b) {//переопределяем оператор > в соотвествии с условием
	if (Bigger(a.Surname, b.Surname) || (a.Surname.compare(b.Surname) == 0 && Status(a.Dolj) > Status(b.Dolj))) return true;
	return false;
}



void ShellSort(vector<people>& mass)
{

	int gap = mass.size() / 2; // шаг

	while (gap > 0) {
		for (int value = gap; value < mass.size(); value++) {
			people curr_value = mass[value];
			int position = value;

			while (position >= gap && mass[position - gap] > curr_value) {
				mass[position] = mass[position - gap];
				position -= gap;
				mass[position] = curr_value;
			}
		}
		gap /= 2;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<people> x;
	x = inFile();
	ShellSort(x);
	oglav();
	for (people item : x) {
		print(item);
	}




}