def solve(u, b):
    
    x = [0 for _ in range(len(b))]

    for i in range(1, len(b) + 1):
        row = len(b) - i;

        dot_product = dot(u[row], x)

        x[row] = float(b[row] - dot_product) / float(u[row][row])

    return x


def dot(a, b):
    total = 0;
    for i in range(len(a)):
        total += float(a[i]) * float(b[i])
    return total

u = [
    [2, -3.1, 1],
    [0, 1, 3],
    [0, 0, 4],
]

b = [1, -2.1, 3]

print(solve(u, b))
