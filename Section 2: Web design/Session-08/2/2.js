// Product object with properties
const product = {
    ID: 101,
    Name: "Wireless Mouse",
    Description: "A high-precision wireless mouse with ergonomic design.",
    Price: 1200,
    // Method to calculate discounted price
    CalculateDisc: function(percentage) {
        return this.Price - (this.Price * (percentage / 100));
    },
    // Method to display product details
    displayProductDetails: function(discountPercentage) {
        const discountedPrice = this.CalculateDisc(discountPercentage);
        console.log(`Product Name: ${this.Name}`);
        console.log(`Description: ${this.Description}`);
        console.log(`Discounted Price: Rs. ${discountedPrice}`);
    }
};

// Example usage:
// product.displayProductDetails(20); // Displays details with 20% discount
