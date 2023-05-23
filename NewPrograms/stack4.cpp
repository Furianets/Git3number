#include<iostream>
using namespace std;

struct stack {
	int inf;
	stack* next;
};

void push(stack*& h, int x) {
	stack* r = new stack;     // ������ ����� �������
	r->inf = x;               // ��������� ��� �������������� ����
	r->next = h;              // ��������� ��������� ����
	h = r;
}

int pop(stack*& h) {
	int i = h->inf; // �������� ��������������� ���� ������ h, �.�. ������� ��������
	stack* r = h;   // ������ ��������� �� ������
	h = h->next;    // ��������� ��������� h �� ��������� �������
	delete r;       // ������� ������ �������
	return i;       // ���������� ��������
}

void reverse(stack*& h) {
	stack* head1 = NULL;

	while (h)
		push(head1, pop(h));

	h = head1;
}

stack* result(stack*& h) {
	stack* odd = NULL;   // ���� ��� �������� �����
	stack* even = NULL;  // ���� ��� ������ �����
	stack* res = NULL;   // �������������� ����

	while (h) {
		int x = pop(h);
		if (x % 2 == 0)
			push(even, x); // ��������� ���� ��� ������ �����
		else
			push(odd, x);  // ��������� ���� ��� �������� �����
	}



	stack* temp = NULL;  // ��������� ���� ��� ���������� �������


	while (even) {       // ��������� ��������� ����
		push(temp, pop(even));
	}                     

	while (odd) {        // ��������� ��������� ����
		push(temp, pop(odd));
	}

	reverse(temp); // �������������� ��������� ����, ����� ������������ �������

	// ��������� �������� ����� � ������ ����� � �������������� �����
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
