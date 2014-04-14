#include "ObjetAffichable.h"

ObjetAffichable::ObjetAffichable(){

}

ObjetAffichable::~ObjetAffichable(){

}
void ObjetAffichable::setTabPhysiqueX(char tab[],char tailleTab){
    tabPhysiqueX=new int [tailleTab];
   for(int i=0;i<tailleTab;i++)  
     tabPhysiqueX[i]=tab[i];
     
}

void ObjetAffichable::setTabPhysiqueY(char tab[],char tailleTab){
    tabPhysiqueY=new int [tailleTab];
   for(int i=0;i<tailleTab;i++)  
     tabPhysiqueY[i]=tab[i];
     
}
int ObjetAffichable::getPosX()
{
  return posX;
}
int ObjetAffichable::getPosY()
{
  return posY; 
}
int ObjetAffichable::getPosXPrecedente()
{
   return posXPrecedente; 
}
int ObjetAffichable::getPosYPrecedente()
{
   return posYPrecedente; 
  
}
void ObjetAffichable::setPosXPrecedente(int X){
 posXPrecedente=X;  
}
void ObjetAffichable::setPosYPrecedente(int Y){
 posYPrecedente=Y;  
}



void ObjetAffichable::setPosX(int x)
{
   setPosXPrecedente(posX);
   posX=x;
}  
void ObjetAffichable::setPosY(int y)
{
   setPosYPrecedente(posY); 
   posY=y;
}

void ObjetAffichable::Dessiner(char taille){
    EsploraTFT.stroke(255,255,255);
    for(int i=0;i<taille;i++)
      EsploraTFT.point(posX+tabPhysiqueX[i],posY+tabPhysiqueY[i]);
}
void ObjetAffichable::Effacer(char taille){
  if((posXPrecedente != posX) || (posYPrecedente != posY)){
    EsploraTFT.stroke(0,0,0);
    for(int i=0;i<taille;i++)
      EsploraTFT.point(posXPrecedente+tabPhysiqueX[i],posYPrecedente+tabPhysiqueY[i]);
  }
}


boolean ObjetAffichable::Touche(int){}
boolean ObjetAffichable::Tomber(int){}
boolean ObjetAffichable::IsFall(){}
