// Wait until the DOM is fully loaded before initializing the chart
document.addEventListener("DOMContentLoaded", function() {
    const ctx = document.getElementById('usageChart').getContext('2d');
    
    // Initialize the chart with initial data
    const usageChart = new Chart(ctx, {
        type: 'line',  // Line chart to show CPU and Memory usage
        data: {
            labels: [],  // Time (labels for x-axis)
            datasets: [{
                label: 'CPU Usage (%)',
                borderColor: 'rgba(75, 192, 192, 1)',
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                fill: true,
                data: []
            },
            {
                label: 'Memory Usage (%)',
                borderColor: 'rgba(153, 102, 255, 1)',
                backgroundColor: 'rgba(153, 102, 255, 0.2)',
                fill: true,
                data: []
            }]
        },
        options: {
            scales: {
                x: {
                    type: 'linear',
                    position: 'bottom',
                    ticks: {
                        autoSkip: true,
                        maxTicksLimit: 20
                    }
                },
                y: {
                    beginAtZero: true,
                    max: 100
                }
            },
            responsive: true
        }
    });

    // Function to fetch data and update the chart
    function fetchDataAndUpdateChart() {
        fetch('data/usage_data.txt')  // Assumes usage data is written to this file by the C++ program
            .then(response => response.text())
            .then(data => {
                const lines = data.split("\n");
                const lastLine = lines[lines.length - 2];  // Get the last non-empty line
                
                if (lastLine) {
                    const [cpuUsage, memUsage] = lastLine.split("\t").map(val => parseFloat(val.split(":")[1].trim().replace('%', '')));
                    const currentTime = Date.now();

                    // Update chart data
                    if (usageChart.data.labels.length > 100) {  // Limit the number of data points
                        usageChart.data.labels.shift();
                        usageChart.data.datasets[0].data.shift();
                        usageChart.data.datasets[1].data.shift();
                    }

                    usageChart.data.labels.push(currentTime);
                    usageChart.data.datasets[0].data.push(cpuUsage);
                    usageChart.data.datasets[1].data.push(memUsage);

                    usageChart.update();  // Refresh the chart
                }
            })
            .catch(error => console.error('Error fetching data:', error));
    }

    // Update the chart every 1 second
    setInterval(fetchDataAndUpdateChart, 1000);
});
