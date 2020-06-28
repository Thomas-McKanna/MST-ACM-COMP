b = [-1 for i in range(11)] # array of beeper positions
dist = [[-1 for i in range(11)] for j in range(11)]

def tsp(pos, mask):
    if mask == 2**(num_b + 1) - 1: # num_b + 1 to account for start location
        return dist[pos][0]
    else:
        if memo[pos][mask] != -1:
            return memo[pos][mask]
        ans = 99999
        for nxt in range(num_b + 1):
            if nxt != pos and (mask & 1 << nxt) == 0:
                ans = min(ans, dist[pos][nxt] + tsp(nxt, mask | 1 << nxt))
        memo[pos][mask] = ans
        return ans

N = int(input())
while N:
    # max of 10 beepers plus start location; 2**11 = 2048
    memo = [[-1 for i in range(2048)] for j in range(11)] 
    _, _ = map(int, input().split()) # world width and height not used
    start_x, start_y = map(int, input().split())
    b[0] = (start_x, start_y) # use index 0 to store start location
    num_b = int(input())

    for i in range(num_b):
        j, k = map(int, input().split())
        b[i + 1] = (j, k)

    for i in range(num_b + 1):
        for j in range(num_b + 1):
            if i == j:
                dist[i][i] = 0
            else:
                dist[i][j] = abs(b[i][0] - b[j][0]) + abs(b[i][1] - b[j][1])

    print(tsp(0, 1)) # 0 is start position, 1 to indicate start has been visited
    N -= 1
