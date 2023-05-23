#include <iostream>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // стэки
    stack <int> q({ 2, 8, 4, 1, 2, 8, 8, 1, 2, 8 });
    stack <int> qq({ 2, 8, 4, 1, 2, 8, 8, 1, 2, 8 });
    stack <int> w;
    stack <int> ww;
    int min = 0, max = 0, k = 0;
    bool m = false;

    cout << "Начальный стэк" << endl << endl;

    while (!qq.empty())
    {
        ww.push(qq.top());
        qq.pop();
    }

    while (!ww.empty())
    {
        qq.push(ww.top());
        ww.pop();

        cout << qq.top() << "  ";

    }

    while (!q.empty())
    {
        w.push(q.top());
        q.pop();

        if (!m)
        {
            min = w.top();
            max = w.top();
            m = true;
        }

        if (w.top() < min)
            min = w.top();

        if (w.top() > max)
            max = w.top();
    }

    cout << endl << endl << "Измененный стэк" << endl << endl;

    while (!w.empty())
    {
        q.push(w.top());
        w.pop();

        cout << q.top() << "  ";

        if (q.top() == max)
            k++;

        if (q.top() == max && k == 1 || k == 4)
        {
            q.push(min);

            cout << q.top() << "  ";
        }
    }



}