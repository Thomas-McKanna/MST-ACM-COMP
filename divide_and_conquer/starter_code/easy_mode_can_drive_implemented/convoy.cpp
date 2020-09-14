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
    sort(speeds, speeds + n - 1);

    // TODO: bisection method here
    
    return 0;
}
