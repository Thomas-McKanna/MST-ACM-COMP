n, k = map(int, input().split())

speeds = [] # driver i can travel to the stadium in speeds[i] seconds
for _ in range(n):
    speeds.append(int(input()))
speeds.sort()

def can_drive(time):
    people_left = n
    for i in range(min(k, n)):
        num_trips = time // speeds[i]
        num_trips = (num_trips + 1) // 2
        people_left -= 4 * num_trips
        if num_trips > 0:
            people_left -= 1
    return people_left <= 0

# TODO: bisection method here
