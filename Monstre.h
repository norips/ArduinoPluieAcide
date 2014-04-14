/* Class Monstre 

Monstre

*/
#ifndef MONSTRE_H
#define MONSTRE_H
#include "ObjetAffichable.h"

class Monstre : public ObjetAffichable{
 public:
   Monstre();
   ~Monstre();
   void Effacer(char);
   boolean Tomber(int);
   boolean IsFall();
   boolean Touche(int);
 private:
   
};

#endif
