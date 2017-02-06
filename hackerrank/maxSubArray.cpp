#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long max_element(long arr[], unsigned long len) {
    long max = arr[0];
    for (unsigned long i=1; i<len;i++) {
        if (arr[i] > max)   max = arr[i];
    }
    return max;
}

long sum_contiguous(long arr[], unsigned long len) {
    long max = max_element(arr, len);
    if (max <= 0)
        return max;
    long sum = 0;
    long max_sum = 0;

    for (unsigned long i=0; i < len; i++) {
        sum += arr[i];

        if (sum < 0) { 
            sum = 0;
            continue;
        }
        if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
}


long sum_noncontiguous(long arr[], unsigned long len) {
    long max = max_element(arr, len);
    if (max <= 0)
        return max;
    long sum = 0;
    for (unsigned long i=0; i < len; i++) {
        if (arr[i] > 0)
            sum += arr[i];
    }
    return sum;
}


int main() {
    unsigned int T;
    unsigned long N;
    long a[100000];
    cin >> T;
    for(int j = 0; j < T; j++) {
        cin >> N;
        for (unsigned long i=0; i < N; i++) {
            cin >> a[i];
        }
        cout << sum_contiguous(a, N) << " " << sum_noncontiguous(a, N) << endl;
    }
    return 0;
}
