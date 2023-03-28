# Air-Quality-and-Sunlight-Exposure-Monitoring-System
<b> Smart IoT Webserver Based for Air Quality and Sunlight Exposure Monitoring System for Agriculture Monitoring using ESP32 </b>

This project uses the ESP32 and two sensors, including the DHT11 sensor and the photodiode sensor, to monitor air quality, such as temperature and humidity, as well as the quality of sunlight exposure needed by plants to grow and develop optimally. The output of the sensor readings can then be viewed on a webserver that is integrated with ESP32.

<p align="center">
<img width=400px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228170858-cb973db6-955c-463a-baa9-3e6d4726651e.png">
</p>

The program code written in Arduino IDE is available in the file listed. The schematic diagram of the system to be designed is made in the Proteus software, as follows:
<p align="center">
<img width=400px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228171513-ca9a0d5a-c343-4695-b923-b5de4e267a6e.png">
</p>

The output of the sensor readings can then be viewed on a webserver that is integrated with ESP32, using the IP address of ESP32 contained on the serial monitor, and input the IP address to the browser you usually use. Data from sensors can be viewed on the webserver in real-time.
<p align="center">
<img width=500px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228173039-409ca0b7-eb56-401a-b8c5-3ab34d6e9ee3.png">
</p>

To optimize data analysis and visualization, sensor readings are stored in a data logger in the form of a Google Spreadsheet which is integrated using IFTTT Maker Webhooks. This following image is the data logger from sensor readings in Google Spreadsheets.

<p align="center">
<img width=500px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228190690-e05da269-bffc-4e7b-8346-44e81860ee1b.png">
</p>

This following image is the results of data visualization in graphical form from the results of the previous data logger
<p align="center">
<img width=500px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228190903-ddc434de-a975-4dad-b02c-fd8fa23c7e42.png">
<img width=500px height=auto alt="image" src="https://user-images.githubusercontent.com/78911479/228191061-d9fd68a3-aae5-48e7-b28b-e6328c2609fa.png">
</p>
