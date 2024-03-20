
#include "Jambe.h"


void jambe(float const& pRayon,short int const& pPoints,float const& pH,float const& pX,float const& pY,float const& pZ){

	const short int n = pPoints;

	Point pCylindre[n*2];
	int fCyl[n][4];

	glPushMatrix();

		glTranslatef(pX,pY,pZ);

		for(int i=0;i<(n*2);i++){
			pCylindre[i].x = pRayon*cos((i*2*M_PI)/n);
			if(i<n)
				pCylindre[i].y = 0.0;
			else
				pCylindre[i].y = pH;
			pCylindre[i].z = pRayon*sin((i*2*M_PI)/n);

			pCylindre[i].r = 0.7;
			pCylindre[i].g = 0.7;
			pCylindre[i].b = 0.7;
		}

		for(int i=0;i<(n);i++){
			fCyl[i][0] = i;
			fCyl[i][1] = i+n;
			fCyl[i][2] = n+(i+1)%n;
			fCyl[i][3] = (i+1)%n;
		}


		glBegin(GL_POLYGON);

			glColor3f(0.839,0.627,0.6);

			for (int i=0;i<(n);i++){
					glVertex3f(pCylindre[i].x,pCylindre[i].y,pCylindre[i].z);
			}

		glEnd();

		glColor3f(0.9,0.9,0.9);

		for (int i=0;i<n;i++){
			glBegin(GL_POLYGON);
				glVertex3f(pCylindre[fCyl[i][0]].x,pCylindre[fCyl[i][0]].y,pCylindre[fCyl[i][0]].z);
				glVertex3f(pCylindre[fCyl[i][1]].x,pCylindre[fCyl[i][1]].y,pCylindre[fCyl[i][1]].z);
				glVertex3f(pCylindre[fCyl[i][2]].x,pCylindre[fCyl[i][2]].y,pCylindre[fCyl[i][2]].z);
				glVertex3f(pCylindre[fCyl[i][3]].x,pCylindre[fCyl[i][3]].y,pCylindre[fCyl[i][3]].z);
			glEnd();
		}

		glTranslatef(-pX,-pY,-pZ);

	glPopMatrix();
}
