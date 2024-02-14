const express = require('express');
const bodyParser = require('body-parser');
const axios = require('axios');

const app = express();
const port = process.env.PORT || 3000;
const esp8266Address = process.env.ESP8266_ADDRESS;

// Middleware to parse JSON request body
app.use(bodyParser.json());

// ESP8266's IP address and port

// Route to handle turning on the LED strip
app.post('/turnOn', async (req, res) => {
    try {
        await axios.post(`${esp8266Address}/turnOn`);
        res.send('Command sent to turn on LED strip');
    } catch (error) {
        console.error('Error sending command:', error);
        res.status(500).send('Error sending command');
    }
});

// Route to handle turning off the LED strip
app.post('/turnOff', async (req, res) => {
    try {
        await axios.post(`${esp8266Address}/turnOff`);
        res.send('Command sent to turn off LED strip');
    } catch (error) {
        console.error('Error sending command:', error);
        res.status(500).send('Error sending command');
    }
});

// Route to handle changing the color of the LED strip
app.post('/changeColor', async (req, res) => {
    try {
        const { color } = req.body;
        await axios.post(`${esp8266Address}/changeColor`, { color });
        res.send(`Command sent to change color to ${color}`);
    } catch (error) {
        console.error('Error sending command:', error);
        res.status(500).send('Error sending command');
    }
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
