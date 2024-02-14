# LED Strip Controller

Designed to control LED Strips remotely over the internet and custom lighting functionality.

## Setup
The API is designed to be hosted on an AWS EC2 instance. If using the same setup, you must set an environment variable ESP8266_ADDRESS to your esp8266 address.

One way to do this is using AWS Lambda:

```aws lambda update-function-configuration --function-name your-function-name --environment Variables={ESP8266_ADDRESS=http://your-esp8266-address}</code></pre></div>```

## Features
- ESP8266 controlled LED Strip
- API for seamless remote communication
- App to control the LED Strip