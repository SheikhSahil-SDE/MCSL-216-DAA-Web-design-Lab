// Book base class
class Book {
    constructor(title, author, copyrightDate, ISBN, numPages, timesCheckedOut, discarded = false) {
        this.title = title;
        this.author = author;
        this.copyrightDate = copyrightDate;
        this.ISBN = ISBN;
        this.numPages = numPages;
        this.timesCheckedOut = timesCheckedOut;
        this.discarded = discarded;
    }
}

// Manual class (child of Book)
class Manual extends Book {
    constructor(title, author, copyrightDate, ISBN, numPages, timesCheckedOut, discarded = false) {
        super(title, author, copyrightDate, ISBN, numPages, timesCheckedOut, discarded);
    }
    // Method to check if manual should be discarded (after 5 years)
    checkIfOutdated(currentYear) {
        const duration = currentYear - this.copyrightDate;
        if (duration > 5) {
            this.discarded = true;
        }
        return duration;
    }
}

// Novel class (child of Book)
class Novel extends Book {
    constructor(title, author, copyrightDate, ISBN, numPages, timesCheckedOut, discarded = false) {
        super(title, author, copyrightDate, ISBN, numPages, timesCheckedOut, discarded);
    }
    // Method to check if novel should be discarded (checked out more than 100 times)
    checkIfOutdated() {
        if (this.timesCheckedOut > 100) {
            this.discarded = true;
        }
        return this.timesCheckedOut;
    }
    // Method to update checkout count
    checkout() {
        this.timesCheckedOut++;
        this.checkIfOutdated();
    }
}

// Example objects
const manual1 = new Manual("JavaScript Guide", "Mozilla", 2018, "1234567890", 350, 10);
const novel1 = new Novel("The Great Adventure", "John Smith", 2020, "0987654321", 250, 101);

// Check if books should be discarded and print duration/checkout count
const currentYear = 2025;
console.log(`Manual duration: ${manual1.checkIfOutdated(currentYear)} years, Discarded: ${manual1.discarded}`);
console.log(`Novel checked out: ${novel1.checkIfOutdated()} times, Discarded: ${novel1.discarded}`);
