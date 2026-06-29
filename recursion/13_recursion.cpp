//Febonacci series using recursion(with memoization)
#include <iostream>
using namespace std;

int F[10];

int mfib(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    }

    if (F[n - 2] == -1) {
        F[n - 2] = mfib(n - 2);
    }

    if (F[n - 1] == -1) {
        F[n - 1] = mfib(n - 1);
    }

    return F[n - 2] + F[n - 1];
}

int main() {
    int n = 11;

    for (int i = 0; i < 10; i++) {
        F[i] = -1;
    }

    cout << n << "th Fibonacci number is: " << mfib(n - 1) << endl;

    return 0;
}