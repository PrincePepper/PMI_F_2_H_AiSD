//
// Created by User on 22.06.2020.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct point {
    int y;
    int x;
} point;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int N, x0, y0, x1, y1;
    fin >> N >> x0 >> y0 >> x1 >> y1;

    string grid_mass[N];
    for (int i = 0; i < N; i++) {
        string _temp;
        fin >> _temp;
        grid_mass[i] = _temp;
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int distance[N][N];// массив расстояний
    int head, tail;// указатели очереди
    point queue[N * N];// очередь

    // обнуляем массив расстояний
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            distance[i][j] = 0;
    distance[y0 - 1][x0 - 1] = 1;// расстояние до начальной клетки равно 1

    // инициализируем очередь
    head = tail = 0;
    queue[tail].y = y0 - 1;
    queue[tail++].x = x0 - 1;// заносим в очередь начальную клетку

    while (head < tail)// цикл пока очередь не пуста
    {
        point p = queue[head++];// берем следующую позицию из очереди
        for (int i = 0; i < 4; i++)// цикл по соседним клеткам
        {
            point new_point;
            new_point.y = p.y + dy[i];
            new_point.x = p.x + dx[i];
            // проверяем, что такая клетка есть
            if (0 <= new_point.y && new_point.y < N && 0 <= new_point.x && new_point.x < N)
                // проверяем, что она свободна и ранее ее не посещали
                if (grid_mass[new_point.y][new_point.x] != '#' && distance[new_point.y][new_point.x] == 0) {
                    distance[new_point.y][new_point.x] = distance[p.y][p.x] + 1;// находим расстояние
                    queue[tail++] = new_point;// заносим позицию в очередь
                }
        }
    }

    fout << distance[y1 - 1][x1 - 1] - 1;
}
