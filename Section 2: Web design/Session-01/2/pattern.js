function printPattern() {
    let result = '';
    for (let i = 1; i <= 10; i++) {
        result += (i.toString().repeat(i) + '\n'); // Repeat the number 'i' for 'i' times
    }
    console.log(result); // Print the pattern
}

printPattern();
