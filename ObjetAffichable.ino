#include "ObjetAffichable.h"

ObjetAffichable::ObjetAffichable(){
  
}
void ObjetAffichable::setTabPhysique(int *tab,int tailleTab){
    tabPhysique=new int [tailleTab];
   for(int i=0;i<tab;i++)  
     tabPhysique[i]=tab;
     
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
