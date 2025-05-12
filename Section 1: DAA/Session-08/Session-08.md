<!-- Session 8: Implementation of Binomial Coefficient Algorithm -->

    Summary:
    Divide and Conquer: O(2^n) (Exponential)
    Dynamic Programming: O(n * k) (Polynomial)
    Let me know if you need further clarification! - This results in a binary recursion tree where each node makes two recursive calls.

    The height of the recursion tree is n, and the total number of nodes in the tree is approximately 2^n.
    Time Complexity:
    The time complexity is O(2^n), which is exponential. This is because the same subproblems are recomputed multiple times.
    2. Dynamic Programming
    In the DP approach, we use a 2D table (dp[n+1][k+1]) to store intermediate results.
    We fill the table in a bottom-up manner, iterating over all values of i from 0 to n and j from 0 to min(i, k).
    The total number of entries in the table is (n+1) * (k+1).
    Time Complexity:
    The time complexity is O(n * k), which is polynomial. This is much more efficient than the divide-and-conquer approach.
    Summary:
    Divide and Conquer: O(2^n) (Exponential)
    Dynamic Programming: O(n * k) (Polynomial)

Q1. Implement a binomial coefficient problem using Divide and Conquer technique

```python
def binomial_coefficient_dc(n, k):
    # Base cases
    if k == 0 or k == n:
        return 1
    # Recursive case
    return binomial_coefficient_dc(n - 1, k - 1) + binomial_coefficient_dc(n - 1, k)

# Example usage
if __name__ == "__main__":
    n = 5
    k = 2
    print(f"Binomial Coefficient C({n}, {k}) using Divide and Conquer: {binomial_coefficient_dc(n, k)}")
```

Q2. Implement a binomial coefficient problem using Dynamic Programming technique

```python
def binomial_coefficient_dp(n, k):
    # Create a 2D array to store results of subproblems
    dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]

    # Calculate binomial coefficient using bottom-up approach
    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            # Base cases
            if j == 0 or j == i:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]

    return dp[n][k]

# Example usage
if __name__ == "__main__":
    n = 5
    k = 2
    print(f"Binomial Coefficient C({n}, {k}) using Dynamic Programming: {binomial_coefficient_dp(n, k)}")
```

Q3. Study the performance of both implementations using five problem instances in terms of the efficiency of both the approaches for large and small values of n and k in the problem instances.

```python
import time

def measure_performance():
    problem_instances = [
        (5, 2),  # Small n and k
        (10, 5), # Moderate n and k
        (15, 7), # Larger n and k
        (20, 10), # Even larger n and k
        (25, 12)  # Large n and k
    ]

    print("Performance Analysis:\n")
    for n, k in problem_instances:
        print(f"Problem Instance: C({n}, {k})")

        # Measure time for Divide and Conquer
        start_time = time.time()
        result_dc = binomial_coefficient_dc(n, k)
        end_time = time.time()
        print(f"  Divide and Conquer Result: {result_dc}, Time: {end_time - start_time:.6f} seconds")

        # Measure time for Dynamic Programming
        start_time = time.time()
        result_dp = binomial_coefficient_dp(n, k)
        end_time = time.time()
        print(f"  Dynamic Programming Result: {result_dp}, Time: {end_time - start_time:.6f} seconds")

        print()

if __name__ == "__main__":
    measure_performance()
```