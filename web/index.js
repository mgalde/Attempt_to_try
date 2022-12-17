// index.js

// Select the form element
const form = document.querySelector('#pcap-form');

// Select the network map container
const mapContainer = document.querySelector('#network-map');

// Handle form submissions
form.addEventListener('submit', event => {
  // Prevent the form from refreshing the page
  event.preventDefault();

  // Get the selected PCAP file
  const file = document.querySelector('#pcap-file').files[0];

  // Read the PCAP file using the FileReader API
  const reader = new FileReader();
  reader.readAsArrayBuffer(file);

  // Generate the network map when the file has been read
  reader.onload = () => {
    // Parse the PCAP file using d3-pcap
    const pcap = d3.pcap.parse(reader.result);

    // Generate the network map using d3-pcap
    d3.select(mapContainer)
      .datum(pcap)
      .call(d3.pcap.networkMap()
        .height(500)
        .linkDistance(60)
        .charge(-300));
  };
});
