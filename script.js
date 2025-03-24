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

