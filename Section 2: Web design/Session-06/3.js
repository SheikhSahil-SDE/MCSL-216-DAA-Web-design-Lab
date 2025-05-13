// 3. Which method should be used to add a new HTML child element?

parentElement.appendChild(newChildElement);

// Explanation:
    // appendChild:
    //          This method is used to add a new child element to 
    //          the end of a parent element's child list.
    // Parameters:
    //          parentElement: The parent element to which the 
    //          new child will be appended.
    //          newChildElement: The new element to be added as a child.

// Example:
    // Create a new paragraph element
        const newParagraph = document.createElement("p");
        newParagraph.textContent = "This is a new paragraph.";

        // Append the new paragraph to the body
        document.body.appendChild(newParagraph);