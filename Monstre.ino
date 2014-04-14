#include "Monstre.h"
#include "ObjetAffichable.h"
#include <Esplora.h>
#include <TFT.h> 
#include <SPI.h>
#define HAUTEURSAUT 113




Monstre::Monstre(){
 setPosY(0);
 setPosX(random(4,156));
}



Monstre::~Monstre(){}
  
  
boolean Monstre::Tomber(int vitesse){
  setPosY(getPosY()+vitesse); 
}

boolean Monstre::IsFall(){
 if (getPosY()>=BOTTOM)
    return true;
else 
    return false;
  
}


void Monstre::Effacer(char taille){
  if((posXPrecedente != posX) || (posYPrecedente != posY)){
    EsploraTFT.stroke(0,0,0);
    for(int i=0;i<taille;i++)
      EsploraTFT.point(posX+tabPhysiqueX[i],posYPrecedente+tabPhysiqueY[i]);
  }
}

boolean Monstre::Touche(int persox){
    if((posX<=persox+2 && posX>=persox-2)&& posY > (BOTTOM - 10) )
        return true;
    else 
        return false;  
  
}
