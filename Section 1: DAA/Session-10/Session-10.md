<!-- Session 10: Chained Matrix Multiplication -->

Q1.

i   0       1   2    3    4     5   6   7
pi       0.04 0.06 0.08 0.02 0.10 0.12 0.14
qi  0.06 0.06 0.06 0.06 0.05 0.05 0.05 0.05

Q2.

I   0     1    2  3    4    5
pi      0.15 0.10 0.05 0.10 0.20
qi 0.05 0.10 0.05 0.05 0.05 0.1


Q3 Implement the optimal binary search tree algorithm on your system and study the performance of the algorithm on different problem instances.

```python
import sys

def optimal_bst(keys, freq, n):
    cost = [[0 for x in range(n)] for y in range(n)]

    for i in range(n):
        cost[i][i] = freq[i]

    for L in range(2, n + 1):
        for i in range(n - L + 1):
            j = i + L - 1
            cost[i][j] = sys.maxsize

            for r in range(i, j + 1):
                c = (cost[i][r - 1] if r > i else 0) + \
                    (cost[r + 1][j] if r < j else 0) + \
                    sum(freq[i:j + 1])

                if c < cost[i][j]:
                    cost[i][j] = c

    return cost[0][n - 1]

if __name__ == "__main__":
    keys1 = [0, 1, 2, 3, 4, 5]
    freq1 = [0.15, 0.10, 0.05, 0.10, 0.20]
    n1 = len(keys1)

    keys2 = [0, 1, 2, 3, 4, 5, 6]
    freq2 = [0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14]
    n2 = len(keys2)

    print("Optimal cost for first problem instance:", optimal_bst(keys1, freq1, n1))
    print("Optimal cost for second problem instance:", optimal_bst(keys2, freq2, n2))

