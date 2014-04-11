/* Class Perso

Personnage

*/
#ifndef PERSO_H
#define PERSO_H


class Perso {
 public:
   Perso();
   Perso(int X,int Y);
   ~Perso();
   void X(int);
   int Sauter(boolean&);
   void Dessiner();
   int  Descendre(boolean&);
   void Effacer();
   void Effacer(int oldx,int oldy);
   void Position();
   int x;
   int y;
  
};

#endif
