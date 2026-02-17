#include <stdio.h>
#include <stdlib.h>

// Структура для представления точки
typedef struct {
    long long x, y;
} Point;

// Функция для вычисления ориентации трёх точек
// Возвращает:
// 0, если точки коллинеарны
// 1, если поворот по часовой стрелке
// 2, если поворот против часовой стрелки
int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Коллинеарны
    return (val > 0) ? 1 : 2; // По или против часовой стрелки
}

// Функция для нахождения выпуклой оболочки
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Выпуклая оболочка не существует\n");
        return;
    }

    // Находим самую левую точку (и самую нижнюю, если таких несколько)
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x ||
            (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) {
            leftmost = i;
            }
    }

    int p = leftmost, q;
    int hull[100000], hull_size = 0;

    do {
        hull[hull_size++] = p;
        q = (p + 1) % n;

        // Находим следующую точку на выпуклой оболочке
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;
    } while (p != leftmost); // Пока не вернёмся к начальной точке

    // Выводим результат
    printf("%d\n", hull_size);
    for (int i = 0; i < hull_size; i++) {
        printf("%lld %lld\n", points[hull[i]].x, points[hull[i]].y);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    return 0;
}
