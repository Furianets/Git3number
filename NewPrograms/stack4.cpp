#include<iostream>
using namespace std;

struct stack {
	int inf;
	stack* next;
};

void push(stack*& h, int x) {
	stack* r = new stack;     // создаём новый элемент
	r->inf = x;               // заполняем его информационное поле
	r->next = h;              // заполняем ссылочное поле
	h = r;
}

int pop(stack*& h) {
	int i = h->inf; // значение информационного поля головы h, т.е. первого элемента
	stack* r = h;   // создаём указатель на голову
	h = h->next;    // переносим указатель h на следующий элемент
	delete r;       // удаляем первый элемент
	return i;       // возвращаем значение
}

void reverse(stack*& h) {
	stack* head1 = NULL;

	while (h)
		push(head1, pop(h));

	h = head1;
}

stack* result(stack*& h) {
	stack* odd = NULL;   // Стек для нечетных чисел
	stack* even = NULL;  // Стек для четных чисел
	stack* res = NULL;   // Результирующий стек

	while (h) {
		int x = pop(h);
		if (x % 2 == 0)
			push(even, x); // Заполняем стек для четных чисел
		else
			push(odd, x);  // Заполняем стек для нечетных чисел
	}



	stack* temp = NULL;  // Временный стек для сохранения порядка


	while (even) {       // Заполняем временный стек
		push(temp, pop(even));
	}                     

	while (odd) {        // Заполняем временный стек
		push(temp, pop(odd));
	}

	reverse(temp); // Переворачиваем временный стек, чтобы восстановить порядок

	// Соединяем нечетные числа и четные числа в результирующем стеке
	while (temp) {
		push(res, pop(temp));
		if (even)
			push(res, pop(even));
	}

	return res;
}

int main() {
	setlocale(LC_ALL, "RUS");

	int n;
	cout << "n = ";
	cin >> n;
	cout << endl;

	stack* head = NULL;
	int x;
	cout << "Input elements: \n";
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, x);
	}

	reverse(head);

	stack* res = result(head);
	cout << "Answer:" << endl;
	while (res)
		cout << pop(res) << " ";
	cout << endl;

	system("Pause");
	return 0;
}
