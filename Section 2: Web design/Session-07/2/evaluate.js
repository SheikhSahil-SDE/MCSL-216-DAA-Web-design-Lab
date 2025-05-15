// 2. A teacher has created a gradeLabs function that verifies if student programming labs work. This function loops 
// over an array of JavaScript objects that should contain a student property and runLab property. The runLab property 
// is expected to be a function containing the student's code. The runLab function is called and the result is compared 
// to the expected result. If the result and expected result don't match, then the lab is considered a failure.


function gradeLabs(labs) {
    for (let i = 0; i < labs.length; i++) {
        const lab = labs[i];
        try {
            if (typeof lab.runLab !== 'function') {
                throw new Error(`Lab ${i + 1} does not have a valid runLab function.`);
            }
            const result = lab.runLab();
            if (result !== lab.expected) {
                console.log(`Lab ${i + 1} failed. Expected: ${lab.expected}, but got: ${result}`);
            } else {
                console.log(`Lab ${i + 1} passed.`);
            }
        } catch (error) {
            console.log(`Lab ${i + 1} encountered an error: ${error.message}`);
        }
    }
}

// Example usage
const labs = [
    {
        student: 'Alice',
        runLab: function() { return 3 + 2; },
        expected: 5
    },
    {
        student: 'Bob',
        runLab: function() { return 2 * 2; },
        expected: 4
    },
    {
        student: 'Charlie',
        runLab: function() { throw new Error('Code error'); },
        expected: 0
    }
];

gradeLabs(labs);