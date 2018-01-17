
void Joystick(char &Jx, char &Jy,char &Ent, char &Ch)
{
  int xy;
  Ch=0;
  xy=analogRead(JOY_PIN);    //lee el valor analogo del pin del joystick
  
  if(xy<200){Jy=-1;Ch=1;} //hacia arriba 51% 
  else{ 
        if(xy<220){Jx=-1;Ch=1;} // hacia la izquierda 3%
        else{
            if(xy<240){Jy=1;Ch=1;} // hacia abajo 34% 
            else{
                 if(xy<270){Ent=1;Ch=1;} // en el centro 14%
                 else{
                      if(xy<510){Jx=1;Ch=1;} // hacia la derecha 73%
                 }
            }
      }
  }
  if(xy>1000){Jx=0; Jy=0; Ent=0; Ch=0;} // sin tocar 98%
             
}
