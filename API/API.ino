#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

// Buat variabel yang diperlukan
const char* ssid = "realme C11 2021"; // ganti dengan nama SSID
const char* password = "nsaf123,,"; // ganti dengan kata sandi
ESP8266WebServer server(80); // buat objek server dengan port 80

Servo myservo;
const int rotasi = 2;

int motordc = 4;

void relai(int aktif){
  digitalWrite(motordc, aktif);
}

// Buat fungsi untuk menghandle request dari klien
void handleNyala() {
 server.send(200, "text/plain", "success nyala");
 myservo.write(90);
 relai(0);
 delay(3000);
 relai(1);
}

void handleMati() {
 server.send(200, "text/plain", "success mati");
// digitalWrite(led1, LOW);
 myservo.write(0);
 relai(0);
 delay(3000);
 relai(1);
}

void setup() {
 Serial.begin(115200); // Mulai komunikasi serial
 WiFi.begin(ssid, password); // Mulai koneksi WiFi
 pinMode(motordc, OUTPUT);
 myservo.attach(rotasi);

 // Tunggu sampai terhubung dengan WiFi
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
 }

 // Print informasi IP di serial monitor
 Serial.println("");
 Serial.println("WiFi terhubung");
 Serial.print("Alamat IP: ");
 Serial.println(WiFi.localIP());

 // Buat endpoint API
 server.on("/nyala", handleNyala);
 server.on("/mati", handleMati);

 // Mulai server
 server.enableCORS(true);
 server.begin();
 Serial.println("Server berjalan");
}

void loop() {
 server.handleClient(); // Panggil fungsi handleClient untuk menangani klien yang mengakses API
}
