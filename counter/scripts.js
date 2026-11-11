let count = 0;
let counterDisplay = document.querySelector("#counter");
let plusBtn = document.querySelector("#plus");
let minusBtn = document.querySelector("#minus");
plusBtn.addEventListener("click", () => {
    count++;
    counterDisplay.textContent = count;
});
minusBtn.addEventListener("click", () => {
    count--;
    counterDisplay.textContent = count;
});
