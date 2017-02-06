#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long fact(int n, int r=1) {
    if (n <= r) return 1;
    return n * fact(n-1,r);
}

unsigned long long Comb(int n, int r) {
    if (r == 0) return 1;
    if (n-r > r)
        return fact(n,n-r) / fact(r);
    return fact(n,r) / fact(n-r);
}

bool isPrime(unsigned long long n) {
    for (unsigned long long i=2; i*i <= n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

unsigned long long getCombs(int N) {
    if (N < 4) return 1;
    unsigned long long combinations = 0;
    for (int i=0; i <= N/4; i++) {
        combinations += Comb(N-3*i, i);
    }
    return combinations;
}

int main() {
    int T, N;
    int primeCount;
    cin >> T;
    unsigned long long combs;
    while (T--) {
        primeCount = 0;
        cin >> N;
        combs = getCombs(N);

        for (unsigned long long i=2; i<= combs; i++) {
            if (isPrime(i)) primeCount++;
        }
        cout << primeCount << endl;
    }
    return 0;
}

