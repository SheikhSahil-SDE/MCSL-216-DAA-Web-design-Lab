// Function to perform arithmetic operations
function performArithmeticOperations(num1, num2) {
    if (num1 < 10 || num1 > 99 || num2 < 10 || num2 > 99) {
        console.log("Please enter two-digit numbers only.");
        return;
    }

    console.log(`Addition: ${num1} + ${num2} = ${num1 + num2}`);
    console.log(`Subtraction: ${num1} - ${num2} = ${num1 - num2}`);
    console.log(`Multiplication: ${num1} * ${num2} = ${num1 * num2}`);
    if (num2 !== 0) {
        console.log(`Division: ${num1} / ${num2} = ${(num1 / num2).toFixed(2)}`);
    } else {
        console.log("Division by zero is not allowed.");
    }
}

// Example usage
performArithmeticOperations(25, 15);
