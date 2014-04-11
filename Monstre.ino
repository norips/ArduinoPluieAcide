#include <Esplora.h>
#include <TFT.h> 
#include <SPI.h>

#include "Monstre.h"

Monstre::Monstre(){
  x=random(4,156);
  y=1;
}

Monstre::~Monstre()
{
  
}
void Monstre::Nouveau(){
  x=random(4,156);
  y=0;
}
int Monstre::Position(){
  return y;
}
int Monstre::PositionX(){
  return x;
}
void Monstre::Dessiner(){
 EsploraTFT.fill(0,255,0);
 EsploraTFT.rect(x,y, 5, 5);   
}

void Monstre::Effacer(int pos){
 EsploraTFT.stroke(0,0,0);
 EsploraTFT.fill(0,0,0);
 EsploraTFT.rect(x,pos, 5, 5); 
}
void Monstre::Effacer(){
 EsploraTFT.stroke(0,0,0);
 EsploraTFT.fill(0,0,0);
 EsploraTFT.rect(x,y, 5, 5); 
}
void Monstre::Tomber(float vitesse){
  y+=vitesse;
  delay(10);
}

boolean Monstre::IsFall(){
 if (y==BOTTOM)
    return true;
else 
    return false;
  
}
  
boolean Monstre::Touche(int persox){
    if((x<=persox+2 && x>=persox-2)&& y > (BOTTOM - 10) )
        return true;
    else 
        return false;  
  
}
