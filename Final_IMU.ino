#include <FirebaseESP32.h>
#include <WiFi.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#define WIFI_SSID "ROGERS"
#define WIFI_PASSWORD "20770976"
#include <eloquent.h>
#include <EloquentTinyML.h>
#include <MPU6050.h>
#include "Classifier.h"
#include <ArduinoJson.h>
#include <iostream>
#include <ctime>
#if defined(ESP32)
#endif

MPU6050 imu1;
MPU6050 imu2(0x69);

#define WIFI_SSID "ROGERS"
#define WIFI_PASSWORD "20770976"
#define DATABASE_URL "https://physiohand-test-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define API_KEY "AIzaSyDwOz2XxL_58qXMN6LKfotyoFaOXhuJIu0" 
#define USER_EMAIL "anshumanrunnydec@gmail.com"
#define USER_PASSWORD "wamcnbocopqzrqgb"

FirebaseData firebaseData; // Firebase data object
FirebaseAuth auth;
FirebaseConfig config;

unsigned long gestureStartTime = 0;
const unsigned long gestureDuration = 5000;
bool signupOK = false;

int16_t ax1, ay1, az1, gx1, gy1, gz1;
int16_t ax2, ay2, az2, gx2, gy2, gz2;



// Initialize WiFi
void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
void print_raw(){
  Serial.print("IMU1: ");
  Serial.print(ax1);
  Serial.print(",");
  Serial.print(ay1);
  Serial.print(",");
  Serial.print(az1);
  Serial.print(",");
  Serial.print(gx1);
  Serial.print(",");
  Serial.print(gy1);
  Serial.print(",");
  Serial.print(gz1);
  Serial.print("\t");

  Serial.print("IMU2: ");
  Serial.print(ax2);
  Serial.print(",");
  Serial.print(ay2);
  Serial.print(",");
  Serial.print(az2);
  Serial.print(",");
  Serial.print(gx2);
  Serial.print(",");
  Serial.print(gy2);
  Serial.print(",");
  Serial.println(gz2);
}

void setup() {
  Serial.begin(115200);
//delay(2000);
//  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//  Serial.print("Connecting to Wi-Fi");
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    Serial.print(".");
//    delay(300);
//  }
//  Serial.println();
//  Serial.print("Connected with IP: ");
//  Serial.println(WiFi.localIP());
//  Serial.println();

//  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  Wire.begin();
  imu1.initialize();
  imu2.initialize();

  Serial.println("MPU6050 sensors initialized");
 
//  // Connect to Wi-Fi
//  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(300);
//    Serial.println("Connecting to WiFi...");
//  }

  // Initialize WiFi
  initWiFi();

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Assign the user sign in credentials
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.reconnectWiFi(true);
  firebaseData.setResponseSize(4096);

  /* Sign up */
//  if (Firebase.signUp(&config, &auth, "", "")){
//    Serial.println("ok");
//    signupOK = true;
//  }
//  else{
//    Serial.printf("Errror in siging up");
//  }

  Firebase.begin(&config,&auth);
  Firebase.reconnectWiFi(true);       
}

//void loop() {
//  
//  if (millis() - gestureStartTime >= gestureDuration) { 
//    gestureStartTime = millis();
//
//    // Read data from both sensors
//    imu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
//    imu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);
//    print_raw();
//    // Perform feature extraction for both sensors (combine or process data as needed)
//    float features[] = {ax1, ay1, az1, gx1, gy1, gz1, ax2, ay2, az2, gx2, gy2, gz2};
//
//    char predictedGesture[128];  // Adjust the array size as needed
//    strcpy(predictedGesture, forest.predictLabel(features).c_str());
//
//    // Create a JSON object to hold your data
//    FirebaseJson json;
//    json.add("PredictedGesture", predictedGesture);
//
//    // Send data to Firebase
//    //Serial.println(Firebase.pushJSON(firebaseData, "/data", json2));
//    
//    if (Firebase.pushJSON(firebaseData, "/data", json)) 
//      Serial.println("Data sent to Firebase");  
//    else {
//      Serial.println("Data send failed");
//      Serial.println(firebaseData.errorReason());
//    }
//    
//    Serial.print("Predicted gesture: ");
//    Serial.print(predictedGesture);
//
//
//    Serial.println();
//    
//  }
////}
//
//void loop() {
//  
//  if (millis() - gestureStartTime >= gestureDuration) { 
//    gestureStartTime = millis();
//
//    // Read data from both sensors
//    imu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
//    imu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);
//    print_raw();
//    // Perform feature extraction for both sensors (combine or process data as needed)
//    float features[] = {ax1, ay1, az1, gx1, gy1, gz1, ax2, ay2, az2, gx2, gy2, gz2};
//
//    char predictedGesture[128];  // Adjust the array size as needed
//    strcpy(predictedGesture, forest.predictLabel(features).c_str());
//
//    // Specify the constant key where you want to store the data
//    const char* firebasePath = "/data"; // Replace "your_constant_key" with the desired key
//
//    // Create a JSON object to hold your data
//    FirebaseJson json;
//    json.set("PredictedGesture", predictedGesture);
//    json.set("CurrentTime", asctime(current_time)); // Add the current time
//
//    // Set the JSON data at the specified path with the manually generated constant key
//    if (Firebase.setJSON(firebaseData, firebasePath, json)) {
//       Serial.println("Data sent to Firebase");  
//    } else {
//       Serial.println("Data send failed");
//       Serial.println(firebaseData.errorReason());
//    }
//
//    Serial.print("Predicted gesture: ");
//    Serial.println(predictedGesture);
//
//    Serial.println();
//  }
//}
//
void loop() {
  if (millis() - gestureStartTime >= gestureDuration) {
    gestureStartTime = millis();

    // Get the current time
    std::time_t now = std::time(0);
    std::tm* current_time = std::localtime(&now);

    // Read data from both sensors
    imu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
    imu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);
    print_raw();

    // Perform feature extraction for both sensors (combine or process data as needed)
    float features[] = {ax1, ay1, az1, gx1, gy1, gz1, ax2, ay2, az2, gx2, gy2, gz2};

    char predictedGesture[128];  // Adjust the array size as needed
    strcpy(predictedGesture, forest.predictLabel(features).c_str());

    // Specify the constant key where you want to store the data
    const char* firebasePath = "/data"; // Replace "your_constant_key" with the desired key

    // Create a JSON object to hold your data
    FirebaseJson json;
    json.set("PredictedGesture", predictedGesture);
    
    // Format the current time and add it to the JSON
    char formattedTime[20]; // Adjust the array size as needed
    snprintf(formattedTime, sizeof(formattedTime), "%04d-%02d-%02d %02d:%02d:%02d",
             current_time->tm_year + 2023, current_time->tm_mon + 1, current_time->tm_mday,
             current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    json.set("CurrentTime", formattedTime);

    // Set the JSON data at the specified path with the manually generated constant key
    if (Firebase.setJSON(firebaseData, firebasePath, json)) {
      Serial.println("Data sent to Firebase");  
    } else {
      Serial.println("Data send failed");
      Serial.println(firebaseData.errorReason());
    }

    Serial.print("Predicted gesture: ");
    Serial.println(predictedGesture);

    Serial.println();
  }
}
