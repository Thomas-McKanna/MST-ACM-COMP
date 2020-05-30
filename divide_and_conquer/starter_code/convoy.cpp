#include <stdio.h>
#include <algorithm>

using namespace std;

int64_t n, k, speeds[20000];

bool can_drive(int64_t time) {
    // TODO: if can drive in time, return true. Otherwise return false.
    return true;
}

int main() {
    scanf("%ld %ld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%ld", speeds + i);
    sort(speeds, speeds + n - 1);

    int64_t hi = ??; // TODO: what is upper bound? 
    int64_t lo = ??; // TODO: what is lower bound?
    int64_t mid; 

    // TODO: bisection method here

    printf("%ld\n", hi);
    return 0;
}
