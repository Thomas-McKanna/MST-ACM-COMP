import heapq

from math import sqrt, pow

class UnionFind:
    def __init__(self, N):
        self.n = N
        self.rank = [0 for _ in range(N)]
        self.p = [i for i in range(N)]

    def find_set(self, i):
        if self.p[i] == i:
            return i
        else:
            temp = self.find_set(self.p[i])
            self.p[i] = temp
            return self.p[i]

    def is_same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i , j):
        if not self.is_same_set(i, j):
            self.n -= 1
            x = self.find_set(i)
            y = self.find_set(j)
            if self.rank[x] > self.rank[y]:
                self.p[y] = x
            else:
                self.p[x] = y
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1

    def number_sets(self):
        return self.n
        
def distance(p1, p2):
    d1 = p1[0] - p2[0]
    d2 = p1[1] - p2[1]
    return sqrt(pow(d1, 2) + pow(d2, 2))

n, e, p = map(int, input().split())

# Consider the open land to be node 0
uf = UnionFind(n + 1)

houses = [None]
for i in range(n):
    x, y = map(float, input().split())
    houses.append((x, y))
    # Nodes connected to open land
    if e > 0:
        uf.union_set(0, i + 1)
        e -= 1

edges = []
# Get and sort edges
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        dist = distance(houses[i], houses[j])
        heapq.heappush(edges, (dist, (i, j)))

# Existing connections
for i in range(p):
    a, b = map(int, input().split())
    uf.union_set(a, b)

# Kruskal's algorithm
ans = 0.0
while uf.number_sets() != 1:
    cur_edge = heapq.heappop(edges)
    dist, edge = cur_edge
    if not uf.is_same_set(edge[0], edge[1]):
        uf.union_set(edge[0], edge[1])
        ans += dist

print(ans)