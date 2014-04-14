/* Class Perso

Personnage

*/
#ifndef PERSO_H
#define PERSO_H
#include "ObjetAffichable.h"

class Perso : public ObjetAffichable{
 public:
   Perso();
   ~Perso();
   boolean Sauter(int,int);
   boolean Descendre(int);
 private:
   
};

#endif
