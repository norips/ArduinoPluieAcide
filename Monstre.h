/* Class Monstre

Personnage

*/
#ifndef MONSTRE_H
#define MONSTRE_H


class Monstre {
 public:
   Monstre();
   ~Monstre();
   void Nouveau();
   void Dessiner();
   void Effacer(int pos);
   void Effacer();
   void Tomber(float vitesse);
   boolean Touche(int x);
   boolean IsFall();
   int Position();
   int PositionX();
 private:
   int x;
   int y;
};

#endif
