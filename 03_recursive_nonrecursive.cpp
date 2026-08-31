#include <iostream>
using namespace std;

long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

long long factorialNonRecursive(int n) {
    long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

int main() {
    int n;
    cin >> n;

    cout << "Recursive = " << factorialRecursive(n) << endl;
    cout << "Non-Recursive = " << factorialNonRecursive(n) << endl;

    return 0;
}
