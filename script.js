// Smooth scrolling for navigation links
document.querySelectorAll('nav ul li a').forEach(anchor => {
    anchor.addEventListener('click', function(event) {
        event.preventDefault();
        const targetId = this.getAttribute('href').substring(1);
        document.getElementById(targetId).scrollIntoView({ behavior: 'smooth' });
    });
});

// Simple alert on project click
document.querySelectorAll('.project a').forEach(link => {
    link.addEventListener('click', function(event) {
        event.preventDefault();
        alert('Project details coming soon!');
    });
});

document.querySelector(".contact-form").addEventListener("submit", function(event) {
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const message = document.getElementById("message").value;

    if (!name || !email || !message) {
        event.preventDefault();  // Prevent form submission if any field is empty
        alert("Please fill out all fields.");
    }
});

// Keyboard navigation (Tab, Arrow keys, Enter key)
document.addEventListener('DOMContentLoaded', () => {
    const focusableElements = Array.from(document.querySelectorAll('button, a, input, .focusable')); // Collect all focusable elements

    let currentIndex = 0; // Track which element is currently focused

    // Function to update the focused element
    function updateFocus() {
        focusableElements.forEach((el, index) => {
            el.classList.remove('focused'); // Remove focus class from all elements
            if (index === currentIndex) {
                el.classList.add('focused'); // Add focus class to the current element
                el.focus(); // Set focus to the current element
            }
        });
    }

    // Event listener for keydown event
    document.addEventListener('keydown', (event) => {
        switch (event.key) {
            case 'ArrowDown':
            case 'ArrowRight':
                // Move to the next element (down or right)
                currentIndex = (currentIndex + 1) % focusableElements.length;
                updateFocus();
                break;
            case 'ArrowUp':
            case 'ArrowLeft':
                // Move to the previous element (up or left)
                currentIndex = (currentIndex - 1 + focusableElements.length) % focusableElements.length;
                updateFocus();
                break;
            case 'Enter':
                // Trigger the focused element's action (e.g., clicking a button or following a link)
                focusableElements[currentIndex].click();
                break;
            case 'Tab':
                // Ensure Tab key behavior is still active, just update the focus on tab
                event.preventDefault();
                currentIndex = (currentIndex + 1) % focusableElements.length;
                updateFocus();
                break;
        }
    });

    // Initialize by focusing on the first element
    updateFocus();
});