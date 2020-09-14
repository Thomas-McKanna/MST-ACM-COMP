#include <stdio.h>
#include <algorithm>

using namespace std;

int64_t n, k, speeds[20000];

bool can_drive(int64_t time) {
    int64_t people_left = n, num_trips;
    for (int i = 0; i < min(n, k); i++) {
        num_trips = time / speeds[i];
        num_trips = (num_trips + 1) / 2;
        people_left -= 4 * num_trips;
        if (num_trips > 0) people_left--;
    }
    return people_left <= 0;
}

int main() {
    scanf("%ld %ld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%ld", speeds + i);
    sort(speeds, speeds + n);

    // upper limit: 20,000 cards * 1,000,000 second trip
    int64_t hi = 20000LL * 1000000LL, lo = 0, mid; 
    while (hi - lo > 1) {
        mid = (lo + hi) / 2;
        if (can_drive(mid))
            hi = mid;
        else
            lo = mid;
    }
    
    printf("%ld\n", hi);
    return 0;
}
