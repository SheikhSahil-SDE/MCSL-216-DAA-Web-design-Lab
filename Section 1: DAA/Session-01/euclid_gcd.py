# Euclid's Algorithm Implementation

def gcd(a, b):
    mod_count = 0
    assignment_count = 0

    while b != 0:
        mod_count += 1  # Counting the modulo operation
        a, b = b, a % b
        assignment_count += 2  # Counting the two assignments

    return a, mod_count, assignment_count

# Example usage
a, b = 15265, 15
gcd_value, mod_operations, assignment_operations = gcd(a, b)

print(f"GCD of {a} and {b} is: {gcd_value}")
print(f"Number of modulo operations: {mod_operations}")
print(f"Number of assignment operations: {assignment_operations}")
