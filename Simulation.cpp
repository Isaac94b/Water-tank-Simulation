#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <gnuplot-iostream.h>


const double PI = 3.141592654;

double WaterLevel,MaxLevel,InstantLevel,Time,Reyon,Hieght,Input1,Input2,Hole;


std::vector<double> WaterLevel;
std::vector<double> Input1;
std::vector<double> Input2;

int frameNumber = 0;

void DrawPosition();
void Tank();
double CalculateWaterLevel();

void fps()
{
	static int fps = 0;
	static float previousTime  = 0.0f;
	static char  strFPS[20]    = {0};
	float currentTime = (glutGet(GLUT_ELAPSED_TIME) * 0.001f);
    	++fps;
	if( currentTime - previousTime > 1.0f )
	{
		previousTime = currentTime;
		sprintf(strFPS, "FPS: %d ----  TP WaterTank Simulation ----", fps);
		glutSetWindowTitle(strFPS);
		fps = 0.0f;
	}
}

void OnReshape(int w, int h)
{
	if (h==0)
		h=1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	// clear any previous transforms
	//mettre l’identité au sommet de pile
	glLoadIdentity();
	gluPerspective(45,(float)w/h,0.1,100);
	glMatrixMode(GL_MODELVIEW);
}

void OnDraw()
{

	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glLoadIdentity();

	gluLookAt(	9,10,15,	c,0,0,0,1,0);
    //DrawPosition();
	
	

		glutSwapBuffers();
	// afficher le nombre de FPS
	fps();
	
}


void OnInit()
 {
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
 // glEnable(GL_LIGHT0);
	
	
 }

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27) 
		exit(0);


}



int main(int argc,char** argv)
 {



	//La fonction glutInit initialise la bibliothèque GLUT . Elle traite également les lignes
	//de commandes qui sont propres à chaque système de fenêtrage
	glutInit(&argc,argv);

	//Cette fonction spécifie le mode d'affichage de la fenêtre. Le mode d'affichage est
    //utilisé pour créer les fenêtres et les sous-fenêtres. Le mode GLUT_RGBA permet 
	//d'obtenir une fenêtre utilisant le modèle de couleur RGB
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);

	//permettent de créer une fenêtre, de la positionner sur l'écran et d'en spécifier la taille.
	glutInitWindowSize(640,480);

	// permet d'ajouté nom de la fenêtre dans la barre de titre de la fenêtre
	glutCreateWindow(" ----  TP WaterTank Simulation ----");

	//La fonction glutDisplayFunc établit la fonction de rappel pour la fenêtre courante.
	//Quand GLUT détermine que la fenêtre doit être réafficher, la fonction de rappel
	//d'affichage est appelée.
	glutDisplayFunc(OnDraw);

	//redimensionnement de la fenêtre courante
	glutReshapeFunc(OnReshape);
	
	// configuration des touches du clavier
	glutKeyboardFunc(processNormalKeys);

	OnInit();

	 glutIdleFunc( OnDraw );

	 //Cette fonction permet d'entrer dans la boucle de GLUT de traitement des
	//événements. Cette fonction est appelée seulement une fois dans une application.
	glutMainLoop();

	return 0;
}

void DrawPosition(){

			glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);
		glColor3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,50,0);
		glColor3f(0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(0,0,50);	
	glEnd();
}

void Tank(){

///Initial Volume of a Cylinder (i.e. the water tank): V = πr2h

 		MaxLevel = PI*Reyon*Reyon*Hieght;
 		InstantLevel = 0;
        WaterLevel = CalculateWaterLevel();



}

double CalculateWaterLevel(){

 ///Height of Fluid in the Cylindrical Tank at Time t: h = (current volume at time t) / (πr2)
   return (InstantLevel /(PI*Reyon*Reyon));


}

