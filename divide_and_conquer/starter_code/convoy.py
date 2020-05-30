n, k = map(int, input().split())

speeds = [] # driver i can travel to the stadium in speeds[i] seconds
for _ in range(n):
    speeds.append(int(input()))
speeds.sort()

def can_drive(time):
    # TODO: if can drive in time, return true. Otherwise return false.
    return True


hi = ?? # TODO: what is upper bound?
lo = ?? # TODO: what is lower bound?

# TODO: bisection method here

print(hi)
