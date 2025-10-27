# 🏥 Smart Physiotherapy: Wrist Movement Assessment using TinyML
*Real-time Monitoring of Distal Carpal Kinematics with IMU Sensors and Machine Learning*

## Abstract

This work proposes an intelligent physiotherapeutic system for real-time wrist movement assessment utilizing TinyML and inertial measurement unit (IMU) sensors. The system comprises two MPU-6050 IMU sensors connected to an ESP32 microcontroller affixed to a wristband, capturing accelerometer and gyroscope data during wrist movements.

**Key Features:**
- 🎯 **TinyML-Powered Edge Processing** with Decision Tree model (97.43% accuracy)
- 📱 **Mobile App Integration** for real-time movement assessment tracking
- ☁️ **Cloud Connectivity** via Wi-Fi for remote monitoring
- 🔄 **Six-Level Assessment Scale** from "Wrong" to "Perfect"
- ⚡ **Real-time Feedback** with on-device ML inference

**Technical Specifications:**
- Dual MPU-6050 IMU sensors (1000Hz sampling rate)
- ESP32 microcontroller with WiFi
- 12-feature dataset (3-axis accelerometer + 3-axis gyroscope per sensor)
- Strategic sensor placement on dorsal palm and radiocarpal joint

The system provides an objective, efficient approach to wrist extension and flexion evaluation for physiotherapy, eliminating the need for frequent healthcare visits while ensuring reliable and unbiased assessments through automated movement analysis.


## Citation
```
@INPROCEEDINGS{10872021,
  author={Sahoo, Anshuman and Sharma, Sidharth and Pattnaik, Suprava},
  booktitle={2024 IEEE 4th International Conference on Applied Electromagnetics, Signal Processing, & Communication (AESPC)}, 
  title={Smart Physiotherapy: Monitoring Distal Carpal Kinematics using TinyML}, 
  year={2024},
  doi={10.1109/AESPC63931.2024.10872021},
  publisher={IEEE}
}
```
