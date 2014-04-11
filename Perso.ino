#include "Perso.h"
#include <Esplora.h>
#include <TFT.h> 
#include <SPI.h>
#define HAUTEURSAUT 113


Perso::Perso(){
  x=EsploraTFT.width()/2;
  y=BOTTOM;
}

Perso::Perso(int X,int Y){
  x=X;
  y=Y;
}

Perso::~Perso(){}
void Perso::X(int X){
  x=X;
}
void Perso::Position(){}
void Perso::Effacer(){
  EsploraTFT.stroke(0,0,0);
  //bras
  EsploraTFT.point(x-1,y);
  EsploraTFT.point(x-2,y);
  EsploraTFT.point(x-3,y-1);
  EsploraTFT.point(x+1,y);
  EsploraTFT.point(x+2,y);
  EsploraTFT.point(x+3,y+1);
  //Tete
  EsploraTFT.point(x,y-1);
  EsploraTFT.point(x,y-2);
  EsploraTFT.point(x-1,y-2);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x,y-4);
  EsploraTFT.point(x-1,y-4);
  EsploraTFT.point(x+1,y-4);
  //Pieds
  EsploraTFT.point(x,y+1);
  EsploraTFT.point(x,y+2);
  EsploraTFT.point(x+1,y+3);
  EsploraTFT.point(x-1,y+3);
  EsploraTFT.point(x+2,y+4);
  EsploraTFT.point(x-2,y+4);
  
}

void Perso::Effacer(int x,int y){
  EsploraTFT.stroke(0,0,0);
  //bras
  EsploraTFT.point(x-1,y);
  EsploraTFT.point(x-2,y);
  EsploraTFT.point(x-3,y-1);
  EsploraTFT.point(x+1,y);
  EsploraTFT.point(x+2,y);
  EsploraTFT.point(x+3,y+1);
  //Tete
  EsploraTFT.point(x,y-1);
  EsploraTFT.point(x,y-2);
  EsploraTFT.point(x-1,y-2);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x,y-4);
  EsploraTFT.point(x-1,y-4);
  EsploraTFT.point(x+1,y-4);
  //Pieds
  EsploraTFT.point(x,y+1);
  EsploraTFT.point(x,y+2);
  EsploraTFT.point(x+1,y+3);
  EsploraTFT.point(x-1,y+3);
  EsploraTFT.point(x+2,y+4);
  EsploraTFT.point(x-2,y+4);
  
}

void Perso::Dessiner(){
  EsploraTFT.stroke(255,255,255);
  //bras
  EsploraTFT.point(x-1,y);
  EsploraTFT.point(x-2,y);
  EsploraTFT.point(x-3,y-1);
  EsploraTFT.point(x+1,y);
  EsploraTFT.point(x+2,y);
  EsploraTFT.point(x+3,y+1);
  //Tete
  EsploraTFT.point(x,y-1);
  EsploraTFT.point(x,y-2);
  EsploraTFT.point(x-1,y-2);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x,y-4);
  EsploraTFT.point(x-1,y-4);
  EsploraTFT.point(x+1,y-4);
  //Pieds
  EsploraTFT.point(x,y+1);
  EsploraTFT.point(x,y+2);
  EsploraTFT.point(x+1,y+3);
  EsploraTFT.point(x-1,y+3);
  EsploraTFT.point(x+2,y+4);
  EsploraTFT.point(x-2,y+4);
  
}


/*void Perso::Dessiner(){
  EsploraTFT.stroke(255,255,255);
  //bras
  EsploraTFT.point(x-1,y);
  EsploraTFT.point(x-2,y);
  EsploraTFT.point(x-3,y-1);
  EsploraTFT.point(x+1,y);
  EsploraTFT.point(x+2,y);
  EsploraTFT.point(x+3,y+1);
  //Tete
  EsploraTFT.point(x,y-1);
  EsploraTFT.point(x,y-2);
  EsploraTFT.point(x-1,y-2);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x+1,y-2);
  EsploraTFT.point(x-1,y-3);
  EsploraTFT.point(x+1,y-3);
  EsploraTFT.point(x,y-4);
  EsploraTFT.point(x-1,y-4);
  EsploraTFT.point(x+1,y-4);
  //Pieds
  EsploraTFT.point(x,y+1);
  EsploraTFT.point(x,y+2);
  EsploraTFT.point(x+1,y+3);
  EsploraTFT.point(x-1,y+3);
  EsploraTFT.point(x+2,y+4);
  EsploraTFT.point(x-2,y+4);
}*/

 int Perso::Sauter(boolean& descendre){
   if (y > HAUTEURSAUT)
     y--;
   else if(y==HAUTEURSAUT)
     descendre=true;
     
   return y;
}

int Perso::Descendre(boolean& descendre){
  if( y < BOTTOM)
    y++;
  else if (y==BOTTOM)
    descendre=false;
  return y;
} 
