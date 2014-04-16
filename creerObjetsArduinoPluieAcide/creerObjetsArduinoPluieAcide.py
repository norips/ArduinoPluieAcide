from Tkinter import *
from PIL import Image,ImageTk
import tkFileDialog
import Tkinter
import Image

class Application :
    def __init__(self,master,tailleX,tailleY):
        self.frame=Frame(master)
        self.master=master
        self.frame.pack()
        barreMenu=Menu(self.master)
        menuOutils=Menu(barreMenu)
        menuOutils.add_command(label="Vers objet",command=self.tabToMatricePluieAcide)
        
        barreMenu.add_cascade(label="Outils",menu=menuOutils)
        self.master.config(menu=barreMenu)

        self.tailleX=tailleX
        self.tailleY=tailleY
        self.nombreDeCaseX=50
        self.nombreDeCaseY=50
        self.construireTableau(self.nombreDeCaseX,self.nombreDeCaseY);
        self.canvasPrincipal=Canvas(self.frame,width=tailleX,height=tailleY)
        self.canvasPrincipal.pack()
        self.canvasPrincipal.bind("<B1-Motion>",self.mettrePoint)
        self.canvasPrincipal.bind("<Button-1>",self.mettrePoint)
        self.rafraichirCanvas()
    def construireTableau(self,x,y):
        self.tab=[[0 for y1 in range(y)] for x1 in range(x)]
        print(self.tab)
    def setFondCanvas(couleur):
        self.canvasPrincipal.create_rectangle(0,0,self.tailleX,self.tailleY,fill="white")
                
    def getNombreElementsTab(self,tab):
        cmpt=0
        for x in range(len(tab)):
            for y in range(len(tab[0])):
                if(tab[x][y]==1):
                    cmpt+=1
        return cmpt
    def tabToMatricePluieAcide(self):
        self.tabToMatrice(self.tab,1)
    def tabToMatrice(self,tab,element):
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

