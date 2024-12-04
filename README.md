# Real-Time Resource Monitoring Tool 🚀

A Linux-based real-time resource monitoring tool developed using C++ and Node.js. This project monitors CPU and memory usage, logs the data, and provides a web interface to visualize and track resource usage over time.

## Features 🌟

- **Real-Time CPU and Memory Usage Monitoring**: Continuously tracks system resources.
- **Logging**: Logs CPU and memory statistics into a file for historical analysis.
- **Web Interface**: Displays logs in real-time with a graphical representation of CPU and memory usage.
- **Chart Visualization**: Visualizes CPU and memory usage with charts using [Chart.js](https://www.chartjs.org/).
- **Cross-Platform**: Can be run on Linux systems and accessed through a web interface.

## Prerequisites ⚙️

Before you begin, make sure you have the following installed on your machine:

- **Linux System** (Ubuntu or similar distribution)
- **C++ Compiler**: For compiling the monitoring application.
- **Node.js**: For the backend server that serves the logs and the web interface.
- **Git**: For version control.

## Installation 🛠️

### 1. Clone the repository:

```bash
git clone https://github.com/ujjwalkran/CPUMonitoringTool.git
cd CPUMonitoringTool
```
### 2. Build the C++ Monitoring Application

Navigate to the `src` directory and compile the C++ files:

```bash
cd src
make
```
### 3. Run the Resource Monitoring Tool
Start the monitoring tool:

```bash
../build/resource_monitor
```
This will begin logging CPU and memory usage to `backend/logs/resource_log.txt.`

### 4. Set up the Web Interface
Navigate to the frontend directory and install required dependencies:

```bash
cd frontend
npm install
```

### 5. Run the Node.js Backend
Navigate to the root directory and start the Node.js server:

```bash
cd ..
npm start
```
This will start a web server at `http://localhost:3000`.
***

## Usage 🖥️

- The backend (Node.js) will provide the resource logs through an API at `http://localhost:3000/api/logs`.
- The frontend will fetch the logs every 2 seconds and display them on the webpage.
- The logs include CPU and memory usage percentages, which are logged every second.

## Technologies Used ⚡

- **C++**: For CPU and memory monitoring logic.
- **Node.js**: For backend server to serve the logs.
- **Chart.js**: For visualizing CPU and memory usage as charts.
- **HTML/CSS**: For the web interface.
- **JavaScript**: For frontend functionality.


## File Structure 🗂️

```plaintext
CPUMonitoringTool/
├── backend
│   ├── logs
│   ├── node_modules
│   ├── package-lock.json
│   ├── package.json
│   └── server.js
├── build
├── data
│   └── usage_data.txt
├── frontend
│   ├── index.html
│   ├── script.js
│   └── style.css
├── logs
│   └── resource_log.txt
├── scripts
│   ├── logs
│   ├── start.sh
│   └── stop.sh
├── src
│   ├── C++
│   │   ├── cpu_monitor.cpp
│   │   ├── cpu_monitor.h
│   │   ├── logger.cpp
│   │   ├── logger.h
│   │   ├── main.cpp
│   │   ├── memory_monitor.cpp
│   │   └── memory_monitor.h
├── LICENSE
└── README.md
```
`This will format your file structure properly in Markdown.`

## Contributing 🤝

We welcome contributions to improve the project! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -am 'Add feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request to merge your changes.

## License 📝

This project is licensed under the `MIT License` - see the LICENSE file for details.

