#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long getOverallSum(unsigned long arr[], unsigned int len) {
    unsigned long long sum=0;
    for (unsigned int i=0; i<len; i++) {
        sum += arr[i];
    }
    return sum;
}


unsigned int calcScore(unsigned long arr[], unsigned int start, unsigned int end, unsigned long long arrSum,                                     unsigned int score) {
    if (arrSum % 2) return score;

    unsigned long long sum = 0;
    unsigned long long lscore, rscore;

    for (unsigned int i=start; sum <= arrSum/2; i++) {
        sum += arr[i];
        if (sum == arrSum/2) {
            score++;

            lscore = calcScore(arr, start, i, sum, score);
            rscore = calcScore(arr, i+1, end, sum, score);
            
            (lscore > rscore ) ? return lscore : return rscore;
        }
    }
    
    return score;
}


int main() {
    unsigned int T;
    cin >> T;
    
    unsigned long A[20000];
    unsigned int N;
    unsigned int score;
    unsigned long long total_sum = 0;

    for(int j=0; j<T; j++) {
        cin >> N; 
        for(unsigned int i=0; i < N; i++) {
            cin >> A[i];
        }
        total_sum = getOverallSum(A, N);
        if (total_sum == 0) {
            score = N-1;
        } else {
            score = calcScore (A, 0, N, total_sum, 0);
        }
        cout << score << endl;
    }
    
    return 0;
}
