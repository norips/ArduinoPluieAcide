from Tkinter import *
from PIL import Image,ImageTk
import tkFileDialog
import Tkinter
import Image

class Application :
    def __init__(self,master,tailleX,tailleY):
        #Initialisation de la fenetre et sauvegarde du root
        self.frame=Frame(master)
        self.master=master
        self.frame.pack()

        #Construction du menu 
        self.construireMenu()
        

        #Construction de la grille de cube .
        self.construireGrille()
        
        #Construction du canvas principal (contenant la grille de cube)
        self.construireCanvasPrincipal()

        #On affiche les cubes de la grille dans le canvas principal
        self.rafraichirCanvas()
    
    def construireCanvasPrincipal():
        self.canvasPrincipal=Canvas(self.frame,width=self.tailleX,height=self.tailleY)
        self.canvasPrincipal.pack()
        self.canvasPrincipal.bind("<B1-Motion>",self.mettrePoint)
        self.canvasPrincipal.bind("<Button-1>",self.mettrePoint)
    def construireGrille():
        self.tailleX=tailleX
        self.tailleY=tailleY
        self.nombreDeCaseX=50
        self.nombreDeCaseY=50
        self.construireTableau(self.nombreDeCaseX,self.nombreDeCaseY);

    def construireMenu(self):
        #Menu principal
        barreMenu=Menu(self.master)
        
        #Sous menus
        menuFichier=Menu(barreMenu)
        menuOutils=Menu(barreMenu)

        #Elements des sous menu
        menuOutils.add_command(label="Vers objet",command=self.tabToMatricePluieAcide)
        menuFichier.add_command(label="Charger Obj.",command=self.chargerObjet)

        #Liaison menuPrincipal et sous menus.
        barreMenu.add_command(label="Fichiers",menu=menuFichier)
        barreMenu.add_cascade(label="Outils",menu=menuOutils)

        #Affichage
        self.master.config(menu=barreMenu)

    def construireTableau(self,x,y):
        #Construction du tableau contenant les cases à affichers 
        # x = nombre de cases en abscisse
        # y = nombre de cases en ordonnée 

        self.tab=[[0 for y1 in range(y)] for x1 in range(x)]
        print(self.tab)
    def setFondCanvas(couleur):
        #Mise en blanc du canvas principal
        self.canvasPrincipal.create_rectangle(0,0,self.tailleX,self.tailleY,fill=couleur)
                
    def getNombreElementsTab(self,tab):
        cmpt=0
        for x in range(len(tab)):
            for y in range(len(tab[0])):
                if(tab[x][y]==1):
                    cmpt+=1
        return cmpt
    def getNomFichier(self):
        ftypes=[("Fichiers ObjetsAffichable",".objAff"),("All files","*")]
        dlg = tkFileDialog.Open(self.frame,filetypes = ftypes)
        nomfichier= dlg.show()
        return nomfichier
    def chargerObjet(self):
        print(self.getNomFichier())
        
    def tabToMatricePluieAcide(self):
        self.tabToMatrice(self.tab,1)
    def tabToMatrice(self,tab,element):
        #Transforme la grille en chemin utilisable par la classe objetAffichable
        nbElement=self.getNombreElementsTab(self.tab)
        tabRetour=[[0 for x in range(nbElement)] for x2 in range(2)]
        xMoyen=int(len(tab)/2)
        yMoyen=int(len(tab[0])/2)
        curseur=0
        for x in range(len(tab)):
            for y in range(len(tab[0])):
                if(tab[x][y]==element):
                    tabRetour[0][curseur]=x-xMoyen
                    tabRetour[1][curseur]=y-yMoyen
                    curseur+=1
        print(tabRetour)
    def rafraichirCanvas(self):
        xMoyen=len(self.tab)/2
        yMoyen=len(self.tab[0])/2
        

        for i in range(len(self.tab)):
            for y in range(len(self.tab[0])):
                if(self.tab[i][y]==1):
                    
                    if(i==xMoyen and y==yMoyen):
                        self.canvasPrincipal.create_rectangle((self.tailleX/self.nombreDeCaseX)*i,(self.tailleY/self.nombreDeCaseY)*y,(self.tailleX/self.nombreDeCaseX)*(i+1),(self.tailleY/self.nombreDeCaseY)*(y+1),fill="blue")
                    else:
                        self.canvasPrincipal.create_rectangle((self.tailleX/self.nombreDeCaseX)*i,(self.tailleY/self.nombreDeCaseY)*y,(self.tailleX/self.nombreDeCaseX)*(i+1),(self.tailleY/self.nombreDeCaseY)*(y+1),fill="black")

                else:
                    if(i==xMoyen and y==yMoyen):
                        self.canvasPrincipal.create_rectangle((self.tailleX/self.nombreDeCaseX)*i,(self.tailleY/self.nombreDeCaseY)*y,(self.tailleX/self.nombreDeCaseX)*(i+1),(self.tailleY/self.nombreDeCaseY)*(y+1),fill="red")
                    else:
                        self.canvasPrincipal.create_rectangle((self.tailleX/self.nombreDeCaseX)*i,(self.tailleY/self.nombreDeCaseY)*y,(self.tailleX/self.nombreDeCaseX)*(i+1),(self.tailleY/self.nombreDeCaseY)*(y+1),fill="white")
      

    def mettrePoint(self,event):
        #Mise de la case de la grille a 1 si l'on clique dessus
        #%2 permet de l'enlever a chaque fois si on reclique dessus.
        x=event.x/(self.tailleX/self.nombreDeCaseX)
        y=event.y/(self.tailleY/self.nombreDeCaseY)
        self.tab[x][y]=(self.tab[x][y]+1)%2
        self.rafraichirCanvas()
            


root=Tk()
application=Application(root,600,600)
tabTest=[[0 for x in range(2)] for x in range(2)]
print(tabTest)
tabTest[0][0]=1
print(tabTest)
root.mainloop()
root.destroy()

