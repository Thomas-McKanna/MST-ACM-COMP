#include <stdio.h>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, world_width, world_height, start_x, start_y, num_b;
ii b[11]; // array of beeper positions
vvi dist = vvi(11, vi(11)); // distance matrix
int memo[11][2048]; // max of 10 beepers plus start location; 2**11 = 2048

int tsp(int pos, int mask) {
    if (mask == pow(2, num_b + 1) - 1) // num_b + 1 to account for start location
        return dist[pos][0];
    else {
        if (memo[pos][mask] != -1)
            return memo[pos][mask];
        int ans = 99999, nxt;
        for (nxt = 0; nxt <= num_b; nxt++)
            if (nxt != pos && (mask & 1 << nxt) == 0)
                ans = min(ans, dist[pos][nxt] + tsp(nxt, mask | 1 << nxt));
        return memo[pos][mask] = ans; // trick: set memo and return it in same line
    }     
}

int main() {
    scanf("%d", &N);
    while (N--) {
        memset(memo, -1, sizeof memo);
        scanf("%d %d", &world_width, &world_height); // not used
        scanf("%d %d", &start_x, &start_y);
        b[0] = ii(start_x, start_y); // use index 0 to store start location
        scanf("%d", &num_b);

        int i, j, k;
        for (i = 0; i < num_b; i++) {
            scanf("%d %d", &j, &k);
            b[i + 1] = ii(j, k);
        }

        for (i = 0; i <= num_b; i++)
            for (j = 0; j <= num_b; j++)
                if (i == j)
                    dist[i][i] = 0;
                else
                    dist[i][j] = abs(b[i].first - b[j].first) + abs(b[i].second - b[j].second);

        printf("%d\n", tsp(0, 1)); // 0 is start position, 1 to indicate start has been visited
    }
    return 0;
}