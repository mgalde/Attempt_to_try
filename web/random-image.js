// random-image.js

// Select the image container element
const imageContainer = document.querySelector('#image-container');

// Generate a random image URL
const imageUrl = `https://picsum.photos/id/${Math.floor(Math.random() * 1000)}/200/300`;

// Create an img element
const img = document.createElement('img');

// Set the img element's src attribute to the random image URL
img.src = imageUrl;

// Append the img element to the image container
imageContainer.appendChild(img);
