void Acerca(void){
  char Jx,Jy,Ent,Ch;
  char Exit=0;
  
  nokia.clearDisplay();
  nokia.setTextColor(BLACK);
  nokia.setCursor(0,0);
  nokia.println("Multiscopio");
  nokia.println("Hecho por:");
  nokia.println("AI");
  nokia.display();
  //delay(5000);
  while(Exit<1) {
    Joystick(Jx,Jy,Ent,Ch);
    if(Ent==1) Exit=1;
  }
}
