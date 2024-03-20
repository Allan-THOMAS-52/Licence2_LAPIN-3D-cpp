
#ifdef __APPLE__
#include <GLUT/glut.h> /* Pour Mac OS X */
#else
#include <GL/glut.h>   /* Pour les autres systemes */
#endif

#include "jambe/Jambe.h"
#include "corps/Corps.hpp"
#include "sphere/Sphere.h"
#include "oreille/Oreille.h"

float angle = 0.0;

char presse;
int anglex=0,angley=0,x,y,xold,yold;

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
void idle();

int main(int argc,char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(800,800);
	glutCreateWindow("Lapin Cretin");

	/* Initialisation d'OpenGL */
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(2.0);
	glEnable(GL_DEPTH_TEST);

	/* enregistrement des fonctions de rappel */
	glutDisplayFunc(affichage);
	glutKeyboardFunc(clavier);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	glutIdleFunc(idle);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	/* Entree dans la boucle principale glut */
	glutMainLoop();
	return 0;
}


void affichage(){

	/* effacement de l'image avec la couleur de fond */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//DEZOOM
		//glOrtho(-6.0,6.0,-1.0,11.0,-7.0,7.0);
	//ZOOM
		glOrtho(-5.0,5.0,-0.5,9.5,-8.0,8.0);
	//ZOOM++
		//glOrtho(-3.0,3.0,0.0,6.0,-6.0,6.0);
	//VU HAUTE
		//glOrtho(-3.0,3.0,4.0,10.0,-6.0,6.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(angley,1.0,0.0,0.0);
	glRotatef(anglex,0.0,1.0,0.0);

	//Repère
		//axe x en rouge
			glBegin(GL_LINES);
				glColor3f(1.0,0.0,0.0);
				glVertex3f(0, 0,0.0);
				glVertex3f(15, 0,0.0);
			glEnd();
		//axe des y en vert
			glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex3f(0, 0,0.0);
				glVertex3f(0, 15,0.0);
			glEnd();
		//axe des z en bleu
			glBegin(GL_LINES);
				glColor3f(0.5,0.5,1.0);
				glVertex3f(0, 0,0.0);
				glVertex3f(0, 0,15.0);
			glEnd();
		glColor3f(1.0,1.0,1.0);

	//JAMBES
		jambe(0.7,25,0.50,-0.80,0.0,0.0);
		jambe(0.7,25,0.50,0.80,0.0,0.0);

	//CORPS
		corps(1.55,1.2,25,0.2,180,0.0,0.5,0.0);
		corps(1.55,1.625,25,0.5,0.0,0.0,0.5,0.0);
		corps(1.625,1.63,25,0.15,0.0,0.0,1.0,0.0);
		corps(1.63,1.2,25,1.5,0.0,0.0,1.15,0.0);

	//COUP
		corps(1.2,1.2,25,0.15,0.0,0.0,2.65,0.0);

	//TETE

		//MOITIE BASSE DE LA TETE
			glPushMatrix();
				glColor3f(0.9,0.9,0.9);
				glScalef(1.0, 1.4, 1.0);
				glTranslatef(0.0,3.35,0.0);
				glutSolidSphere(1.8, 30, 30);
			glPopMatrix();

		//MOITIE SUPERIEURE DE LA TETE
			corps(1.7837,1.74,25,0.3,0.0,0.0,5.2,0.0);
			corps(1.74  ,1.60 ,25,0.5,0.0,0.0,5.5,0.0);

			corps(1.60,1.42,25,0.5,0.0,0.0,6,0.0);
			corps(1.42,1.2699 ,25,0.3,0.0,0.0,6.5,0.0);

		//HAUT BOMBE DE LA TETE
			glPushMatrix();
				glColor3f(0.9,0.9,0.9);
				glScalef(1.0, 0.43,1.0);
				glTranslatef(0.0,15.445,0.0);
				glutSolidSphere(1.31, 30, 30);
			glPopMatrix();

		//YEUX
			//OEIL GAUCHE
				//PAUPIERE
					sphere(0.52,20,20,-1.1,5.7,1.8,true);
					glPushMatrix();
						glColor3f(0.839, 0.627, 0.6);
						glTranslatef(-1.1, 5.7,1.79);
						glutSolidTorus(0.04,0.49,15,15);
					glPopMatrix();
				//OEIL
					sphere(0.46,17,17,-1.1,5.7,1.8,false);

			//OEIL DROIT
				//PAUPIERE
					sphere(0.52,20,20,1.1,5.7,1.8,true);
					glPushMatrix();
						glColor3f(0.839, 0.627, 0.6);
						glTranslatef(1.1, 5.7,1.79);
						glutSolidTorus(0.04,0.49,15,15);
					glPopMatrix();

				//OEIL
					sphere(0.46,20,20,1.1,5.7,1.8,false);

		//OREILLES
			//OREILLE DROITE
				glPushMatrix();

					glColor3f(0.9, 0.9, 0.9);

					glBegin(GL_POLYGON);
						glVertex3f( -1.18, 6.8,-0.282);
						glVertex3f( -1.085, 6.9,-0.20);
						glVertex3f( -1.82, 8.63,-0.20);
						glVertex3f( -1.934, 8.58,-0.282);
					glEnd();

					glBegin(GL_POLYGON);
						glVertex3f( -0.20, 7.18,-0.282);
						glVertex3f( -0.32, 7.13,-0.21);
						glVertex3f( -1.084, 8.94,-0.21);
						glVertex3f( -0.97, 8.99,-0.282);
					glEnd();

					glRotatef(23,0.0,0.0,1.0);

					glRotatef(180,0.0,1.0,0.0);

					glTranslatef(-2.1,-0.35,0.0);

					glPushMatrix();
						glRotatef(-18,0.0,1.0,0.0);
						oreille(0.55,0.55,20,2.0,2.5 ,0.0, 0.040,7.0,0.10,false);
					glPopMatrix();

					glPushMatrix();
						glRotatef(-26,0.0,1.0,0.0);
						oreille(0.45,0.45,20,2.0,3.3 ,0.0, 0.0,7.0,0.0,true);
					glPopMatrix();

				glPopMatrix();

			//OREILLE GAUCHE
				glPushMatrix();

					glColor3f(0.9, 0.9, 0.9);

					glBegin(GL_POLYGON);
						glVertex3f( 1.075, 6.9,-0.21);
						glVertex3f( 1.17, 6.8,-0.282);
						glVertex3f( 1.924, 8.58,-0.282);
						glVertex3f( 1.81, 8.63,-0.21);
					glEnd();

					glBegin(GL_POLYGON);
						glVertex3f( 0.19, 7.18,-0.282);
						glVertex3f( 0.31, 7.13,-0.20);
						glVertex3f( 1.074, 8.94,-0.20);
						glVertex3f( 0.96, 8.99,-0.282);
					glEnd();


					glRotatef(-23,0.0,0.0,1.0);

					glRotatef(180,0.0,1.0,0.0);

					glTranslatef(2.1,-0.35,0.0);

					glPushMatrix();
						glRotatef(-18,0.0,1.0,0.0);
						oreille(0.55,0.55,20,2.0,2.5 ,0.0, 0.040,7.0,0.10,false);
					glPopMatrix();

					glPushMatrix();
						glRotatef(-26,0.0,1.0,0.0);
						oreille(0.45,0.45,20,2.0,3.3 ,0.0, 0.0,7.0,0.0,true);
					glPopMatrix();

				glPopMatrix();

	//BRAS



	glutSwapBuffers();
}

void idle(){
	/*
	angle+=0.5;
	if (angle >= 360)
		angle = 0;
	glutPostRedisplay();
*/
}

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'p': /* affichage du carre plein */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'f': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
    case 's' : /* Affichage en mode sommets seuls */
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glutPostRedisplay();
      break;
    case 'd':
      glEnable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'D':
      glDisable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'a'://Les faces à l'envers s'affichent en fil de fer
      glPolygonMode(GL_FRONT,GL_FILL);
      glPolygonMode(GL_FRONT,GL_LINE);
      glutPostRedisplay();
    break;
    case '9'://Les faces à l'envers s'affichent en fil de fer
    	angle+=0.5;
    		if (angle >= 360)
    			angle = 0;
    		glutPostRedisplay();
	break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
    }
}

void reshape(int x,int y){
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else
    glViewport((x-y)/2,0,y,y);
}

void mouse(int button, int state,int x,int y){
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y){
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xold);
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
}
