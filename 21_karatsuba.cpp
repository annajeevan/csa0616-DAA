#include <iostream>
using namespace std;

long long karatsuba(long long x, long long y) {

    if (x < 10 || y < 10)
        return x * y;

    long long power = 1;
    long long temp = max(x, y);

    while (temp >= 10) {
        temp /= 10;
        power *= 10;
    }

    long long a = x / power;
    long long b = x % power;

    long long c = y / power;
    long long d = y % power;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);

    long long adbc =
        karatsuba(a + b, c + d)
        - ac - bd;

    return ac * power * power
           + adbc * power
           + bd;
}

int main() {
    long long x, y;

    cin >> x >> y;

    cout << "Product = "
         << karatsuba(x, y);

    return 0;
}
