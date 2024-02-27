#include <NewPing.h>	// Library untuk sensor

#define TRIGGER_PIN 11	// Pin yang akan digunakan 
#define ECHO_PIN 12

#define MAX_DISTANCE 200	// Jarak maksimum

NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);	// Deklarasi sensor baru

void setup() {	// Kode di dalam sini akan dijalankan sekali saat program dimulai
  Serial.begin(9600);
}

void loop() {	// Kode di dalam sini akan dijalankan terus menerus
  delay (500);	// Delay selama 500 millisecond

  unsigned int distance = sonar.ping_cm();	// Mendeteksi jarak dari sensor

  Serial.print ("Jarak = ");//
  Serial.print (distance);  //	Menampilkan Jarak yang sudah diukur
  Serial.println (" cm");   //
}
