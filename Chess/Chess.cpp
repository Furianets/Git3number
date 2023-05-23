#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 8;
// Варианты смещения коня по клеткам
int dx[N] = { 2, 2, 1, 1, -1, -1, -2, -2 }; 
int dy[N] = { 1, -1, 2, -2, 2, -2, 1, -1 }; 

struct Position {
    // Координаты и расстояние до необходимой позиции 
    int x, y, dist;
    // Путь до текущей позиции
    string path;
    Position(int x, int y, int dist, string path) : x(x), y(y), dist(dist), path(path) {}
};


// Функция для поиска кратчайшего пути между двумя позициями
void shortestPath(string start, string end) {
    // // Массив для отслеживания посещенных позиций
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Position> q;
    int startX = start[0] - 'A', startY = start[1] - '1';
    int endX = end[0] - 'A', endY = end[1] - '1';
    Position startPos(startX, startY, 0, start);
    visited[startX][startY] = true;
    q.push(startPos);

    while (!q.empty()) {
        Position currPos = q.front();
        q.pop();
        // получаем координаты, расстояние и путь для текущей позиции из currPos
        int currX = currPos.x, currY = currPos.y, currDist = currPos.dist;
        string currPath = currPos.path;

        if (currX == endX && currY == endY) {
            cout << "Shortest path: " << currPath << endl;
            return;
        }

        for (int i = 0; i < N; i++) {
            int newX = currX + dx[i], newY = currY + dy[i];
            if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY]) {
                visited[newX][newY] = true;
                string newPath = currPath + " " + char(newX + 'A') + char(newY + '1');
                Position newPos(newX, newY, currDist + 1, newPath);
                q.push(newPos);
            }
        }
    }
    cout << "No path found" << endl;
}

int main() {
    string start, end;
    cout << "Enter starting position (e.g. A2): ";
    cin >> start;
    cout << "Enter ending position (e.g. E6): ";
    cin >> end;
    shortestPath(start, end);
    return 0;
}
