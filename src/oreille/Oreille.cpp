#include "Oreille.h"

void oreille(float const& pRbas,float const& pRHaut,short int const& pNbPts,float const& pH,
		float const& pDiv,float const& pAngle,float const& pX,float const& pY,
		float const& pZ,bool const& pCol){

	Point PointCylindre2[2*pNbPts];
	int fCylindre2[pNbPts][4];

	float teta=(2*M_PI)/pNbPts;

	glPushMatrix();

		glTranslatef(pX,pY,pZ);

		if(pCol)
			glColor3f(0.839, 0.627, 0.6);
		else
			//glColor3f(0.6, 0.6, 0.6);
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
			fCylindre2[i][1] = i + pNbPts;
			fCylindre2[i][2] = (i + 1) % pNbPts + pNbPts;
			fCylindre2[i][3] = (i + 1) % pNbPts;
		}


		//faces centrale

			float diviseur = (pDiv <= 0) ? 1 : pDiv;

			for (int i=0;i<( pNbPts/diviseur );i++){
				glBegin(GL_POLYGON);
					for (int j=0;j<4;j++){
						glVertex3f(PointCylindre2[fCylindre2[i][j]].x,PointCylindre2[fCylindre2[i][j]].y,PointCylindre2[fCylindre2[i][j]].z);
					}
				glEnd();
			}

		glTranslatef(-pX,-pY,-pZ);


	glPopMatrix();
}
