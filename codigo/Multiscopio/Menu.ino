int Menu(char* Menu[],int Menu_Size,int Max_screen){
  int Menu_Start=1;
  int Index =1;
  int i,j=1;
  char Jx,Jy,Ent,Ch;
  nokia.clearDisplay();
  nokia.setTextSize(1);
  while(1){
    nokia.setCursor(0,0);
    for(i=Menu_Start;i<(Menu_Start+Max_screen);i++){
      if (i==Index){nokia.setTextColor(WHITE, BLACK);}
      else nokia.setTextColor(BLACK, WHITE);
      nokia.println(Menu[i]);
    }
    nokia.display();
    do{
     Joystick(Jx,Jy,Ent,Ch);
    }while(Ch==0);
    delay(200);
    Index=Index+Jy;
    if(Menu_Size>5){
        if(Index>Menu_Start+Max_screen-2){Menu_Start++;} //je déplace la zone visible lorsque je sort de l'encadrement. Le moins 2 est là pour toujours mettre l'élément en surbrillance a 1 ligne de la fin
        if(Index<Menu_Start+1){Menu_Start--;} //idem mais dans l'autre sens
        Menu_Start=constrain(Menu_Start,1,(Menu_Size-Max_screen+1)); //je contrant les valeur du menu start apres ce qui permet de sélectionner le dernier éléments comme le premier
      }   
    Index=constrain(Index,1,Menu_Size);
    
    if(Ent==1){return Index; break;}
  }
}

