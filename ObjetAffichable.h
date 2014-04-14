#ifndef OBJETAFFICHABLE_H
#define OBJETAFFICHABLE_H

class ObjetAffichable {
    public:
      ObjetAffichable();
      ~ObjetAffichable();
      int getPosX();
      int getPosY();
      int getPosXPrecedente();
      void Dessiner(char);
      virtual void Effacer(char);
      int getPosYPrecedente();
      void setPosX(int);
      void setPosY(int);
      void setTabPhysiqueX(char[],char);//tab + tailleTab
      void setTabPhysiqueY(char[],char);//tab + tailleTab
      virtual boolean Tomber(int);
      virtual boolean IsFall();
      virtual boolean Touche(int);
      
    protected:
      void setPosXPrecedente(int);
      void setPosYPrecedente(int);
      int posX;
      int posY;
      int posXPrecedente;
      int posYPrecedente;
      int *tabPhysiqueX;
      int *tabPhysiqueY;
  
  
};


#endif
