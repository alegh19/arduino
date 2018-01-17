#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
 // 'alejo_mono80x48'
const unsigned char alejo [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xe1, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc3, 0xe0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xc7, 0xc0, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x67, 0x8f, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x8e, 0xc0, 0x00, 0x07, 
  0xc0, 0x00, 0x00, 0x00, 0x03, 0x8f, 0x1d, 0x80, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x07, 0x1f, 
  0x39, 0x80, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x0e, 0x1e, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x3c, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x76, 0x01, 
  0xf0, 0x1e, 0x07, 0xc0, 0x00, 0x1c, 0x73, 0xfc, 0xfe, 0x07, 0xf0, 0x7e, 0x1f, 0xc0, 0x00, 0x3f, 
  0xff, 0xff, 0xfc, 0x0f, 0x71, 0xfe, 0x3f, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x1c, 0xf7, 0xfe, 
  0x7f, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x39, 0xe7, 0xdc, 0xfd, 0xe0, 0x00, 0x7f, 0xff, 0xfd, 
  0xe0, 0x7b, 0x87, 0x1c, 0xf3, 0xe0, 0x00, 0x0e, 0x03, 0xc1, 0xc0, 0xf7, 0x00, 0x19, 0xe3, 0xc0, 
  0x00, 0x1c, 0x03, 0xc1, 0xc0, 0xfc, 0x00, 0x39, 0xe3, 0xc0, 0x00, 0x38, 0x07, 0xc3, 0xc1, 0xf0, 
  0x30, 0x31, 0xc3, 0xb0, 0x00, 0x70, 0x07, 0x81, 0xc3, 0xf0, 0x70, 0x77, 0xc3, 0xf0, 0x01, 0xe0, 
  0x0f, 0x81, 0xe7, 0xf9, 0xe0, 0x6d, 0xcf, 0xc0, 0x07, 0xc0, 0x0f, 0x31, 0xfc, 0xff, 0xc0, 0xf9, 
  0xfe, 0x00, 0x0f, 0x80, 0x0f, 0xe1, 0xf8, 0x7f, 0x00, 0xf0, 0xfc, 0x00, 0x0f, 0x00, 0x0f, 0x80, 
  0xe0, 0x3c, 0x01, 0xe0, 0x78, 0x00, 0x1e, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 
  0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char tempIco16x32 [] PROGMEM = {
  0x00, 0x00, 0x03, 0xe0, 0x07, 0xf0, 0x06, 0x70, 0x06, 0x30, 0x06, 0x30, 0x07, 0xb0, 0x07, 0xb0, 
  0x07, 0xb0, 0x07, 0xb8, 0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb8, 0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb8, 
  0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb0, 0x07, 0xb0, 0x07, 0xb0, 0x0f, 0xb0, 0x1f, 0xf8, 0x1f, 0xf8, 
  0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00
};

int valor=0;
float mv_sensor=0;
float c_sensor=0;
int ledPin = 8;
int valorsensor = 0;
volatile int tempconfig = 30; //temperatura configurada

const int arribaPin = A1;
const int abajoPin = A2;

void setup(){
  Serial.begin(9600);
  display.begin();
  display.setContrast(60);
  display.clearDisplay();
  display.drawBitmap(2, 0,  alejo, 80, 48, 1);
  display.display();
  delay(2000);
  pinMode(ledPin, OUTPUT);
  pinMode(arribaPin, INPUT);
  pinMode(abajoPin, INPUT);
}

void loop(){
  valor = analogRead(A0);
  mv_sensor = (valor / 1024.0) * 5000;
  c_sensor= mv_sensor/10;
  Serial.println(c_sensor);
  imprimir();
  if (c_sensor>tempconfig){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  for (int i=0;i<5;i++){
    lecturaBotones();
    delay(200);
  }
}


void lecturaBotones(){
  if (digitalRead(arribaPin)==LOW && tempconfig<=1000){
    tempconfig++;
    imprimir();
    Serial.println(tempconfig);
  }
  if (digitalRead(abajoPin)==LOW && tempconfig>=0){
    tempconfig--;
    Serial.println(tempconfig);
    imprimir();
  }
}

void imprimir(){
  display.clearDisplay();
  display.drawBitmap(0, 16,  tempIco16x32, 16, 32, 1);
  display.display();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print("Temperatura:");
  display.setCursor(72,0);
  display.print(tempconfig);
  display.drawCircle(72, 29, 2, BLACK);
  display.setCursor(76,27);
  display.print("C");
  display.setTextSize(2);
  display.setCursor(20,20);
  display.println(c_sensor,1);
  display.display();
}