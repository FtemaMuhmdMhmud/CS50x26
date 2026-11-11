function sayHello() {
    alert("Hello! Thanks for visiting my page.");
}
function showMessage(event) {
    event.preventDefault();
    document.getElementById("my-text").innerText = "Thank you! Your message was received.";
}
