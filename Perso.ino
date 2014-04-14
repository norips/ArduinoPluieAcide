#include "Perso.h"
#include "ObjetAffichable.h"
#include <Esplora.h>
#include <TFT.h> 
#include <SPI.h>
#define HAUTEURSAUT 113


Perso::Perso(): ObjetAffichable::ObjetAffichable(){
  setPosX(20);
  setPosY(BOTTOM);
}



Perso::~Perso(){}




boolean Perso::Sauter(int saut,int hauteurmax){
   if (getPosY() > EsploraTFT.height()-hauteurmax){
    setPosY(getPosY()-saut);
    return false;
   }
   else if(getPosY()== hauteurmax)
     return true;
}

boolean Perso::Descendre(int saut){
  if( getPosY()< BOTTOM){
    setPosY(getPosY()+saut);
    return true;
  }
  else if (getPosY()==BOTTOM){
    setPosY(getPosY());
    return false;
  }
} 
