// calculator.js

// Select the button element
const button = document.querySelector('#open-calculator');

// Handle button clicks
button.addEventListener('click', () => {
  // Open the calculator app in a new window or tab
  window.open('calculator://');
});
