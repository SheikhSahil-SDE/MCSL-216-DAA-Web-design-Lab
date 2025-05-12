// Here is the JavaScript code to change the color of the <h2> element to green when the "Change Color" button is clicked


<h2 id="heading">This is a heading</h2>
// The <h2> element has an id of "heading"
<button onclick="changeColor()">Change Color</button>   
// The button has an onclick attribute that calls the changeColor() function when clicked.
<script>
    function changeColor() {            
    // The changeColor() function uses getElementById to select the <h2> element and changes its color style property to "green".

        document.getElementById("heading").style.color = "green";
    }
</script>


