/*

 Esplora TFT Pong
 
 This example for the Esplora with an Arduino TFT screen reads 
 the value of the joystick to move a rectangular platform
 on the x and y axes. The platform can intersect with a ball
 causing it to bounce. The Esplora's slider adjusts the speed
 of the ball.
 
 This example code is in the public domain.
 
 Created by Tom Igoe DeTAILLEcember 2012
 Modified 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/EsploraTFTPong
 
 */

#include <Esplora.h>
#include <TFT.h>
#include <SPI.H>

#include "Perso.h"
#include "Monstre.h"
#include "ObjetAffichable.h"
#define BOTTOM 123
#define TAILLE 20
extern void Triangle(int ax,int ay,int bx,int by,int cx,int cy);
const char taille=24;
const char taillePluie=20;
char pointPersoX[taille]={-1,-2,-3,1,2,3,0,0,-1,1,-1,1,1,-1,1,0,-1,1,0,0,1,-1,2,-2};
char pointPersoY[taille]={0,0,-1,0,0,1,-1,-2,-2,-2,-3,-3,-2,-3,-3,-4,-4,-4,1,2,3,3,4,4};
char pointPluieX[taillePluie]={0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
char pointPluieY[taillePluie]={0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
int paddleX = 0;
int paddleY = BOTTOM;
int oldPaddleX, oldPaddleY;
boolean descendre=false;
byte etatBouton;
byte etatBoutonUp;
byte etatPrecedentBoutonUp;
int myWidth = EsploraTFT.width();
int myHeight = EsploraTFT.height(); 
boolean touche[TAILLE]={false};

int oldposmonstre[TAILLE];


void setup() {
  Serial.begin(9600);
  
  // initialize the display
  EsploraTFT.begin(); 
  // set the background the black
  EsploraTFT.background(0,0,0); 
  randomSeed(analogRead(11));
}

byte etatPrecedentBouton=LOW;
int j=0;
void loop() {
  int choix=-1;
  int poscurseY[3]={0,30,60};
  int pos=0;
  while(choix<0){
    
    EsploraTFT.stroke(255,255,255);
    EsploraTFT.setTextSize(2);
    EsploraTFT.text("Easy", 40, 20);
    EsploraTFT.text("Normal", 40, 50);
    EsploraTFT.text("Hard", 40, 80);
    if(Esplora.readJoystickY() < -256){
      if(pos==0){}
      else{
      EsploraTFT.stroke(0,0,0);
      Triangle(10,20+poscurseY[pos],30,25+poscurseY[pos],10,30+poscurseY[pos]);
      EsploraTFT.stroke(255,255,255);
      pos--;
      }
    }
    if (Esplora.readJoystickY() > 256){
      if(pos==2){}
      else{
      EsploraTFT.stroke(0,0,0);
      Triangle(10,20+poscurseY[pos],30,25+poscurseY[pos],10,30+poscurseY[pos]);
      EsploraTFT.stroke(255,255,255);
      pos++;
      }
    }
    while(Esplora.readJoystickY()>256 || Esplora.readJoystickY()<-256){}
    Triangle(10,20+poscurseY[pos],30,25+poscurseY[pos],10,30+poscurseY[pos]);
    etatBouton = Esplora.readButton(SWITCH_DOWN);
    if(etatBouton != etatPrecedentBouton && etatBouton == LOW ) 
      choix=pos; 

    etatPrecedentBouton = etatBouton;
  }
  
  EsploraTFT.background(0,0,0);
  int vitesse=choix+1; 
  boolean mort=false;
  ObjetAffichable **tab;
  tab= new ObjetAffichable*[10];
  Perso *mario;
  mario = new Perso;
  Monstre *Pluie[9];
  tab[0]=mario;
  tab[0]->setPosY(BOTTOM);
  tab[0]->setTabPhysiqueX(pointPersoX,taille);//tab + tailleTab
  tab[0]->setTabPhysiqueY(pointPersoY,taille);//tab + tailleTab
  for(int i=1;i<10;i++){
  tab[i]= new Monstre;
  tab[i]->setTabPhysiqueX(pointPluieX,taillePluie);//tab + tailleTab
  tab[i]->setTabPhysiqueY(pointPluieY,taillePluie);//tab + tailleTab
  }
  
  while(!mort){
  paddleX = map(Esplora.readSlider(), 1023, 0, 0, myWidth); 
  if(paddleX > 159){
    (paddleX = 155);
  }

  if(paddleX < 2){
    (paddleX = 4);
  }
   tab[0]->Effacer(taille);
  etatBouton = Esplora.readButton(SWITCH_DOWN);
  if(etatBouton != etatPrecedentBouton && etatBouton == LOW ){
    mario->Sauter(1,50);
  }
  if (tab[0]->getPosY() != BOTTOM && descendre == false){
    descendre = mario->Sauter(1,50);
  }
  if(descendre){
    descendre = mario->Descendre(1);
  }
  
  for(int i=1;i<10;i++){
    tab[i]->Effacer(taillePluie);
    tab[i]->Tomber(vitesse);
    tab[i]->Dessiner(taillePluie);
    if(tab[i]->Touche(paddleX))
    mort=true;
    if(tab[i]->IsFall()){
       tab[i]->Effacer(taillePluie);
       delete tab[i];
       tab[i]=new Monstre;   
    }
    
  }
  tab[0]->setPosX(paddleX);
  mario->Dessiner(taille);
  
  etatPrecedentBouton = etatBouton;
  }
  delete mario;
  while(true){
  EsploraTFT.background(0,0,255);
  EsploraTFT.stroke(255,255,255);
  EsploraTFT.setTextSize(1);
  EsploraTFT.text("dGame Over", EsploraTFT.width()/2-30, EsploraTFT.height()/2 );
  delay(10000);
  }
  delete mario;
}


void Triangle(int ax,int ay,int bx,int by,int cx,int cy){
  EsploraTFT.line(ax, ay, bx, by);
  EsploraTFT.line(bx, by, cx, cy);
  EsploraTFT.line(cx, cy, ax, ay);
}
