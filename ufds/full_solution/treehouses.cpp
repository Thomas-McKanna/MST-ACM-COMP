#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;

class UnionFind {
private: 
    vector<int> p, rank;
    int n;
public:
    UnionFind(int N) {
        n = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) 
            p[i] = i;
    }

    int findSet(int i) { 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            n--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }   
        } 
    }

    int numberSets() {
        return n;
    }
};

double distance(dd p1, dd p2) {
    double d1 = p1.first - p2.first, d2 = p1.second - p2.second;
    return sqrt(pow(d1, 2) + pow(d2, 2));
}

int main() {
    int n, e, p, a, b, i, j;
    double x, y, dist;

    dd houses[1001];

    scanf("%d %d %d", &n, &e, &p);

    // Consider the open land to be node 0
    UnionFind uf = UnionFind(n + 1);

    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        houses[i + 1] = dd(x, y);
        // Nodes connected to open land
        if (e-- > 0)
            uf.unionSet(0, i + 1);
    }

    priority_queue<dii, vector<dii>, greater<dii> > edges;
    // Get and sort edges
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            dist = distance(houses[i], houses[j]);
            edges.push(pair<double, ii>(dist, ii(i, j)));
        }
    }

    // Existing connections
    for (i = 0; i < p; i++) {
        scanf("%d %d", &a, &b);
        uf.unionSet(a, b);
    }

    // Kruskal's algorithm
    double ans;
    ii curEdge;
    while (uf.numberSets() != 1) {
        curEdge = edges.top().second;
        if (!uf.isSameSet(curEdge.first, curEdge.second)) {
            uf.unionSet(curEdge.first, curEdge.second);
            ans += edges.top().first;
        }
        edges.pop();
    }

    printf("%lf", ans);

    return 0;
}