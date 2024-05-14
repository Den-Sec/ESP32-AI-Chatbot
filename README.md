# ESP32-AI-Chatbot
Simple LLM Assistant Chatbot using Ollama API For ESP32. It offers a simple command-line interface to send questions and receive responses from the Ollama Large Language Model.

## Features

- **Dynamic Preprompt Customization:** Users can modify the preprompt context to change the AI's behavior or persona, making the interactions as flexible as needed.
- **Secure Configuration Management:** Utilizes environment variables to manage API configuration securely, ensuring sensitive information is kept out of the source code.
- **Robust Error Handling:** Includes mechanisms to gracefully handle network issues and API errors, ensuring the application remains responsive under various conditions.

## Requirements

- WiFi Library
- HTTPClient Library
- ArduinoJson Library
- Internet connection to access the Ollama LLM API.

## Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Den-Sec/ESP32-AI-Chatbot/
   cd ESP32-AI-Chatbot/

2. **Install Libraries**
Install the required libraries via the Arduino IDE:
    ```text
    Navigate to Sketch > Include Library > Manage Libraries 
4. **Set Environment Variables**
Update the following constants at the top of your code:
    ```text
    OLLAMA_URL=http://your-ollama-url:port
    MODEL_NAME=your-model-name
    ssid=your-ssid
    password=your-password

Replace `http://your-ollama-url:port` and `your-model-name` with your actual Ollama API URL and model name.

## Usage

  -  Upload the script to your ESP32.
  -  Open the Serial Monitor.
  -  Send messages by typing them into the monitor.

To end the session, type 'exit'.

## Contributing

Contributions to this project are more than welcome!

## License

Distributed under the MIT License. See LICENSE for more information.

