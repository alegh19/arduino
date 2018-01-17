void Acerca(void){
  char Jx,Jy,Ent,Ch;
  
  nokia.clearDisplay();
  nokia.setCursor(0,0);
  nokia.println("Multiscope");
  nokia.println("Hecho por:");
  nokia.println("Alejo.");
  nokia.display();
  //delay(5000);
  while(1) {
    Joystick(Jx,Jy,Ent,Ch);
    if(Ent==1) break;
  }
}
