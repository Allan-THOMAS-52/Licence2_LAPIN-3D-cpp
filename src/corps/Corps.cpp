
#include "Corps.hpp"

void corps(float const& pRbas,float const& pRHaut,short int const& pNbPts,float const& pH,
		float const& pAngle,float const& pX,float const& pY,float const& pZ){

	Point PointCylindre2[2*pNbPts];
	int fCylindre2[pNbPts][4];

	float teta=(2*M_PI)/pNbPts;

	glPushMatrix();

		glTranslatef(pX,pY,pZ);

		if(pAngle==180)
			glScalef(1.0, -1.0, 1.0); //rotation selon l'axe X

		glColor3f(0.9,0.9,0.9);

		for(int i=0;i<2*pNbPts;i++){
			if (i<pNbPts){
				PointCylindre2[i].y = pH;
				PointCylindre2[i].x = pRHaut*cos(teta*i);
				PointCylindre2[i].z = pRHaut*sin(teta*i);
			}else{
				PointCylindre2[i].y = 0;
				PointCylindre2[i].x = pRbas* cos(teta*i);
				PointCylindre2[i].z = pRbas* sin(teta*i);
			}
		}

		for (int i = 0; i < pNbPts; i++){
			fCylindre2[i][0] = i;
			fCylindre2[i][1] = (i + 1) % pNbPts;
			fCylindre2[i][2] = (i + 1) % pNbPts + pNbPts;
			fCylindre2[i][3] = i + pNbPts;
		}

		//bouchon supérieur
		glBegin(GL_POLYGON);
			for(int i = 0; i < pNbPts; i++){
				glVertex3f(PointCylindre2[i].x, PointCylindre2[i].y, PointCylindre2[i].z);
			}
		glEnd();

		//faces centrale
			for (int i=0;i<pNbPts;i++){
				glBegin(GL_POLYGON);
					for (int j=0;j<4;j++){
						glVertex3f(PointCylindre2[fCylindre2[i][j]].x,PointCylindre2[fCylindre2[i][j]].y,PointCylindre2[fCylindre2[i][j]].z);
					}
				glEnd();
			}

		//bouchon inférieur
			glBegin(GL_POLYGON);
				for (int i = pNbPts; i < 2 * pNbPts; i++) {
					glVertex3f(PointCylindre2[i].x, PointCylindre2[i].y, PointCylindre2[i].z);
				}
			glEnd();

		glTranslatef(-pX,-pY,-pZ);

	glPopMatrix();
}
