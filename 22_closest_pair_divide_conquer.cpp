#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
    double x, y;
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

double distance(Point a, Point b) {

    return sqrt(
        (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y)
    );
}

double bruteForce(Point p[], int left, int right) {

    double best =
        numeric_limits<double>::max();

    for (int i = left; i <= right; i++) {

        for (int j = i + 1; j <= right; j++) {

            best = min(
                best,
                distance(p[i], p[j])
            );
        }
    }

    return best;
}

double closestPair(
    Point p[],
    int left,
    int right
) {

    if (right - left <= 2)
        return bruteForce(p, left, right);

    int mid = (left + right) / 2;

    double d1 =
        closestPair(p, left, mid);

    double d2 =
        closestPair(p, mid + 1, right);

    double d = min(d1, d2);

    double midX = p[mid].x;

    Point strip[1000];
    int k = 0;

    for (int i = left; i <= right; i++) {

        if (abs(p[i].x - midX) < d)
            strip[k++] = p[i];
    }

    sort(strip, strip + k, compareY);

    for (int i = 0; i < k; i++) {

        for (int j = i + 1;
             j < k &&
             strip[j].y - strip[i].y < d;
             j++) {

            d = min(
                d,
                distance(strip[i], strip[j])
            );
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;

    Point p[1000];

    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    sort(p, p + n, compareX);

    cout << "Closest distance = "
         << closestPair(p, 0, n - 1);

    return 0;
}
