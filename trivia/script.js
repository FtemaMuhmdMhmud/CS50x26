document.addEventListener('DOMContentLoaded', function() {
    let correctButton = document.querySelector('.correct');
    let incorrectButtons = document.querySelectorAll('.incorrect');
    let feedback1 = document.querySelector('#feedback1');
    correctButton.addEventListener('click', function() {
        correctButton.style.backgroundColor = 'green';
        correctButton.style.color = 'white';
        feedback1.textContent = 'Correct!';
        feedback1.style.color = 'green';
    });
incorrectButtons.forEach(function(button) {
        button.addEventListener('click', function() {
            button.style.backgroundColor = 'red';
            button.style.color = 'white';
            feedback1.textContent = 'Incorrect';
            feedback1.style.color = 'red';
        });
    });
    let checkButton = document.querySelector('#check-btn');
    let feedback2 = document.querySelector('#feedback2');
    checkButton.addEventListener('click', function() {
        let userInputValue = document.querySelector('#answer-input').value.trim().toLowerCase();
        if (userInputValue === 'hg'){
            document.querySelector('#answer-input').style.backgroundColor = 'green';
            feedback2.textContent = 'Correct!';
            feedback2.style.color = 'green';
        } else {
            document.querySelector('#answer-input').style.backgroundColor = 'red';
            feedback2.textContent = 'Incorrect';
            feedback2.style.color = 'red';
        }
    });
});
