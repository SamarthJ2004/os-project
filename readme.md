# 🚀 IoT OS Project: Lightweight Embedded OS based on Contiki

This project is a lightweight IoT operating system based on **Contiki OS**, tailored for **resource-constrained IoT devices** like the ESP32. It includes a **custom MAC protocol**, support for **MQTT and CoAP**, and is optimized for **low power and efficient wireless communication**.

---

## 📁 Project Structure

contiki/ # Contiki OS source <br/>
contiki-mqtt/ # MQTT protocol implementation <br/>
customFiles/ # Custom MAC driver and protocol code <br/>
esp-idf/ # ESP32 toolchain and SDK

---

## ⚙️ Key Features

✅ Custom lightweight MAC protocol (`custom-mac.c`)  
✅ MQTT protocol support for cloud communication  
✅ CoAP protocol support for RESTful IoT messaging  
✅ ESP32 hardware optimization  

---

## 🔧 Setup Instructions

### 1. Clone This Repo
```bash
git clone https://github.com/yourusername/iot-os-project.git
cd iot-os-project

In contiki/Makefile.include, add:
CONTIKI_SRC += ../customFiles/custom-mac.c

In your IoT application Makefile, add:
CFLAGS += -DNETSTACK_CONF_MAC=custom_mac_driver

cd contiki/examples/your-example
make TARGET=native
./your-example.native

. $IDF_PATH/export.sh
idf.py set-target esp32
idf.py build
idf.py flash

