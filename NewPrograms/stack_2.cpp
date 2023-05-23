#include <iostream>
#include <queue>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // очереди
    queue <int> q({ 2, 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2, 1 });
    queue <int> qq({ 2, 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2, 1 });
    queue <int> w;

    int end, max = 0;

    //end = q.back(); // последнее нечетное число

    cout << "Начальная очередь: " << endl << endl;

    while (!q.empty()) // максимальное число
    {
        w.push(q.front());
        q.pop();
        if (w.back() > max)
            max = w.back();

        if (w.back() % 2 != 0) end = w.back();

        cout << w.back() << "  "; // вывод начальной очереди
    }

    while (!w.empty())
        w.pop();

    cout << endl << endl << "Измененая очередь: " << endl << endl;

    while (!qq.empty()) // добавление максимального элемента после чисел, равных последнему
    {
        w.push(qq.front());
        qq.pop();

        cout << w.back() << "  "; // вывод измененной очереди

        if (w.back() == max)
        {
            w.push(end);
            cout << w.back() << "  "; // вывод измененной очереди
        }
    }



}