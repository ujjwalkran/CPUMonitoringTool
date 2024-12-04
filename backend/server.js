const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();
const port = 3000;
const cors = require('cors');

app.use(express.static('public'));
app.use(cors());
// Serve log data from resource_log.txt
app.get('/api/logs', (req, res) => {
    const logFilePath = path.join(__dirname, 'logs', 'resource_log.txt');
    fs.readFile(logFilePath, 'utf8', (err, data) => {
        if (err) {
            return res.status(500).json({ error: 'Error reading log file' });
        }
        const logs = data.split('\n').filter(line => line.length > 0);
        res.json({ logs });
    });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
