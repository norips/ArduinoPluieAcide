class ObjetAffichable {
 
    public:
      ObjetAffichable () ;
      virtual ~ObjetAffichable()=0;
      int getPosX();
      int getPosY();
      int getPosXPrecedente();
      
      int getPosYPrecedente();
      void setPosX(int);
      void setPosY(int);
      
    private:
      void setPosXPrecedente(int);
      void setPosYPrecedente(int);
      void setTabPhysique(int*,int)//tab + tailleTab
      int posX;
      int posY;
      int posXPrecedente;
      int posYPrecedente;
      int *tabPhysique
     
  
  
};
