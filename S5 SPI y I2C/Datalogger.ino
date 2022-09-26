#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>
#define LEDW 32
// Lecturas desde el sensor de barometrico
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
File readings;
File read_me;
char payload[50]; //Datos a escribir en SD y Serial
void setup() {
Serial.begin(115200);
pinMode(LEDW,OUTPUT);
bmp.begin(0x77); // Inicializar comunicacion I2C con el sensor barometrico
SD.begin(); //Inicializar SD

//README
read_me = SD.open("README.txt",FILE_WRITE);
read_me.print("Archivo de lecturas del sensor BMP280.\n"\ 
"Temperatura [C], Presion [Pa]");
read_me.close();
}

void loop() {
//sprintf(payload,"temp:%.2f,press:%.2f",bmp.readTemperature(),bmp.readPressure());
sprintf(payload,"temp:%.2f,press:%.2f",bmp.readTemperature(),bmp.readPressure());
Serial.println(payload);
digitalWrite(LEDW,HIGH);
readings = SD.open("/read.csv",FILE_APPEND);
readings.println(payload);
readings.close();
digitalWrite(LEDW,LOW);
delay(5000);
}
