const animals = [
    { name: 'Dog' },
    { name: 'Cat' },
    { name: 'Rabbit' },
    { name: 'Elephant' }
];

function getAnimalByIndex() {
    const index = parseInt(prompt('Enter the index of the animal you want to see:'));
    console.log(`User entered index: ${index}`); // Always log the entered index

    try {
        if (isNaN(index) || index < 0 || index >= animals.length) {
            throw new TypeError('Invalid index. No animal found at this index.');
        }
        console.log(`Animal at index ${index}: ${animals[index].name}`);
    } catch (error) {
        console.error(`Error: ${error.message}`);
    }
}

// Call the function to test
getAnimalByIndex();
