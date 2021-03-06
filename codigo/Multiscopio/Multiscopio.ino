#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include <avr/pgmspace.h>

// definicion del programa
#define  JOY_PIN A0
#define  SERVO_PIN 6 //servo
#define  OSC_LOGIQUE_PIN 0 //PIN logico osciloscopio
#define  OSC_PIN1 A1 //analogo1
#define  OSC_PIN2 A2 //analogo2
#define  OSC_PIN3 A3 //analogo3
#define  OSC_PIN4 A4 //analogo4
#define  TEMP_PIN  A5 //temperatura
#define  FREC_PIN  7

#define PIN_DC    8  // LCD Dat/Com. Pin 5
#define PIN_RESET 9  // LCD RST .... Pin 1
#define PIN_SCE   10  // LCD CS  .... Pin 3
#define PIN_SDIN  11  // LCD SPIDat . Pin 6
#define PIN_SCLK  13  // LCD SPIClk . Pin 4

//Adafruit_PCD8544 display = Adafruit_PCD8544(PIN_SCLK, PIN_SDIN, PIN_DC, PIN_SCE, PIN_RESET);

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 nokia = Adafruit_PCD8544(PIN_DC, PIN_SCE, PIN_RESET);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!

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

byte Index_menu; //index du menu choisi pour les interruptions
char Jx, Jy, Ent,Ch;

void setup() {
  nokia.begin();
  nokia.setContrast(60);
  nokia.clearDisplay();
  nokia.drawBitmap(2, 0,  alejo, 80, 48, 1);
  nokia.display();
  pinMode(SERVO_PIN,OUTPUT);
  pinMode(JOY_PIN,INPUT);
  pinMode(OSC_PIN1,INPUT);
  pinMode(OSC_PIN2,INPUT);
  pinMode(OSC_PIN3,INPUT);
  pinMode(OSC_PIN4,INPUT);
  pinMode(TEMP_PIN,INPUT);
  pinMode(FREC_PIN,INPUT);
}

void loop() {
  char Jx,Jy,Ent,Ch;
  char* menu_main[]={
    "Menu",
    "Osciloscopio", //1
    "valores Ana", 
    "Termometro",  
    "Servo Test",
    "Acerca"
    }; 
  
  void (*menu_main_funcs[])(void) = {
     Oscilloscope,
     ValoresAna,
     Temperatura,
     Servo_Test,
     Acerca
     };
  while(1)       // Ce menu étant la racine on ne peut pas en sortir
     { 
       Index_menu= Menu(menu_main,5,5)-1;     
      (*menu_main_funcs[Index_menu])();
     };
  // put your main code here, to run repeatedly:
  //Index_menu=Menu(menu_main,5,5)-1;
}

void Oscilloscope(){
  
}
void ValoresAna(){
  
}
void Servo_Test(){
  
}

