const unsigned char tempIco16x32 [] PROGMEM = {
  0x00, 0x00, 0x03, 0xe0, 0x07, 0xf0, 0x06, 0x70, 0x06, 0x30, 0x06, 0x30, 0x07, 0xb0, 0x07, 0xb0, 
  0x07, 0xb0, 0x07, 0xb8, 0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb8, 0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb8, 
  0x07, 0xb8, 0x07, 0xb0, 0x07, 0xb0, 0x07, 0xb0, 0x07, 0xb0, 0x0f, 0xb0, 0x1f, 0xf8, 0x1f, 0xf8, 
  0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00
};

unsigned long Temp_Millis;

void Temperatura(){
  char Jx,Jy,Ent,Ch;
  char Exit=0;
  
  char* temp_menu[]={"Temp 'C","Timing (1min)","Back","Reset","Retour","Exit"};
  char* temp_t_str[] = {"Timing","1min ","5min ","15min","30min"};
  long temp_t[] = {60000,300000,900000,1800000};
  
  int valor=0;
  int tempconfig=30;
  float mv_sensor=0;
  float c_sensor=0;
  Temp_Millis = 0;
  
  while(Exit<1) {
    Joystick(Jx,Jy,Ent,Ch);
    if (Temp_Millis < millis()){
      Temp_Millis=Temp_Millis+500;
      valor = analogRead(A5);
      c_sensor = (valor / 1024.0) * 500;
      //c_sensor= mv_sensor/10;
//      nokia.clearDisplay();
//      nokia.setCursor(0,0);
//      nokia.println("Temp:");
//      nokia.setCursor(20,20);
//      nokia.print(c_sensor);
//      nokia.display();
      nokia.clearDisplay();
      nokia.drawBitmap(0, 16,  tempIco16x32, 16, 32, 1);
      nokia.display();
      nokia.setTextSize(1);
      nokia.setTextColor(BLACK);
      nokia.setCursor(0,0);
      nokia.print("Temperatura:");
      nokia.setCursor(72,0);
      nokia.print(tempconfig);
      nokia.drawCircle(72, 29, 2, BLACK);
      nokia.setCursor(76,27);
      nokia.print("C");
      nokia.setTextSize(2);
      nokia.setCursor(20,20);
      nokia.println(c_sensor,1);
      nokia.display();
    }
    if(Ent==1) Exit=1;
  }
}

