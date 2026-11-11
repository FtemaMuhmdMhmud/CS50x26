let form = document.querySelector("#admissionForm");
let nameInput = document.querySelector("#name");
let ageInput = document.querySelector("#age");
let scoreInput = document.querySelector("#score");
let resultBox = document.querySelector("#result");
form.addEventListener("submit", function(event) {
    event.preventDefault();
    let name = nameInput.value.trim();
    let age = Number(ageInput.value);
    let score = Number(scoreInput.value);
    if (name === "" || ageInput.value === "" || scoreInput.value === "") {
        resultBox.textContent = "Please fill in all fields.";
        resultBox.style.color = "orange";
    }
    else if (age >= 18 && score >= 70) {
        resultBox.textContent = `Welcome ${name}, you are accepted.`;
        resultBox.style.color = "green";
    }
    else {
        resultBox.textContent = `Sorry ${name}, try again.`;
        resultBox.style.color = "red";
    }
});
