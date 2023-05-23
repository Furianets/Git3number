#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // очереди
    queue <int> q({ 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5 });
    queue <int> qq({ 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5 });
    queue <int> w;
    queue <int> res;
    vector <int> vec;
    int x = 0;
    bool f = false;

    cout << "Начальная очередь: " << endl << endl;

    while (!qq.empty())
    {
        cout << qq.front() << "  ";
        qq.pop();
    }
    cout << endl << endl;

    cout << "Измененная очередь: " << endl << endl;

    while (!q.empty())
    {
        //vec.push_back(w.back());
        //w.push(q.front());

        //q.pop();
        if (!f)
        {
            w.push(q.front());
            f = true;
        }
        if (w.back() == q.front())
            q.pop();

        else
        {
            w.push(q.front());
            q.pop();
        }
        

        cout << w.back() << "  "; // вывод измененной очереди

    }




}