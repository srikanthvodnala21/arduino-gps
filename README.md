# Arduino GPS Tracker using NEO-6M and OLED Display

A simple Arduino project that reads real-time GPS coordinates from a NEO-6M GPS module and displays the latitude and longitude on a 0.91" OLED display.

This project is ideal for beginners who want to learn:

* Arduino programming
* GPS communication
* Serial communication
* OLED display interfacing
* Embedded systems development

---

## Demo

This project continuously receives GPS data from the NEO-6M module and displays:

* Latitude
* Longitude

on a 128x32 OLED display.

When GPS data is unavailable, a status message is shown.

---

## Components Required

| Component                    | Quantity  |
| ---------------------------- | --------- |
| Arduino Uno R3               | 1         |
| NEO-6M GPS Module            | 1         |
| 0.91" OLED Display (SSD1306) | 1         |
| Breadboard                   | 1         |
| Jumper Wires                 | As needed |
| USB Cable                    | 1         |

---

## Wiring Diagram

### GPS Module → Arduino

| GPS Module | Arduino |
| ---------- | ------- |
| VCC        | 5V      |
| GND        | GND     |
| TX         | Pin 4   |
| RX         | Pin 3   |

### OLED Display → Arduino

| OLED | Arduino |
| ---- | ------- |
| VCC  | 5V      |
| GND  | GND     |
| SDA  | A4      |
| SCL  | A5      |

---

## Required Libraries

Install the following libraries using Arduino Library Manager:

### TinyGPS++

Used for parsing GPS NMEA data.

### Adafruit SSD1306

Used for controlling the OLED display.

### Adafruit GFX

Graphics library required by SSD1306.

---

## Installation

### 1. Clone Repository

```bash
git clone https://github.com/srikanthvodnala21/arduino-gps.git
```

### 2. Open Arduino IDE

Open the `.ino` file.

### 3. Install Required Libraries

Go to:

```text
Sketch → Include Library → Manage Libraries
```

Install:

* TinyGPS++
* Adafruit SSD1306
* Adafruit GFX

### 4. Upload Code

Select:

```text
Board: Arduino Uno
Port: COM Port of Arduino
```

Upload the sketch.

---

## How It Works

1. Arduino communicates with the NEO-6M GPS module through SoftwareSerial.
2. GPS data is received in NMEA format.
3. TinyGPS++ decodes the GPS information.
4. Latitude and Longitude values are extracted.
5. Coordinates are displayed on the OLED display.
6. If GPS lock is unavailable, a waiting message is shown.

---

## Example Output

```text
Lat: 17.385044
Lng: 78.486671
```

or

```text
Waiting for GPS...
Go outside!
```

---

## Notes

* GPS modules require a clear view of the sky.
* Initial GPS lock may take several minutes.
* Indoor environments may prevent the module from receiving satellite signals.
* For faster GPS fixes, test outdoors.

---

## Applications

* Vehicle Tracking
* Location Logging
* Navigation Projects
* IoT Devices
* Asset Tracking
* Student Learning Projects

---

## Future Improvements

* Show satellite count
* Display GPS accuracy
* Save coordinates to SD card
* Upload coordinates to cloud platforms
* Integrate with Google Maps
* Add GSM module for remote tracking

---

## Video Tutorial

Watch the complete project tutorial on YouTube:

```text
https://youtu.be/9dqCtk7MN-U
```

---

## Repository

Source code available here:

```text
<GitHub Repository Link>
```

---

## License

This project is released under the MIT License.

Feel free to modify, improve, and share.
