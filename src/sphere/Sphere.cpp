
#include "Sphere.h"

void sphere(float const& pRayon,short int const& pPara,short int const& pMer,float const& pX,
		float const& pY,float const& pZ,bool const& pPaupiere){

	// Nombre de points : nbParalleles * nbMeridiens
	Point pSphere[pPara * pMer];

	/*
	 * Tableau 3D pour stocker les indices des faces
	 * 1ere dimension [pPara - 1] : nombre de paralleles - 1 car il y a nbParalleles-1 sections horizontales
	 * 		 qui connectent les paralleles
     * 2eme dimension [pMer * 2] : nombre de meridiens multiplie par 2 car chaque meridien a 2 faces
     * 3eme dimension [4] : stocke les 4 arretes qui font chaque face
	 */
	int fSphere[pPara - 1][pMer * 2][4];

	float theta = (2 * M_PI) / pMer;
	float phi = -(M_PI / 2);

	glPushMatrix();

		//On se place la ou on veut dessiner la sphere
		glTranslatef(pX, pY, pZ);

		if(pPaupiere){
			glRotatef(270,1.0,0.0,0.0);
		}

		/*
		 * Calcul des coordonnees x,y,z des arretes en utilisant les parraleles ( pPara ) et meridiens ( pMer )
		 * et definition des couleurs r,g,b pour ces memes arretes.
		 * On calcule les coordonnees x,y,z avec des coordonnees spheriques.
		 * cos() et sin() convertissent les coordonnees spheriques en cartesiennes.
		 * Avec theta l'angle d'azimut et phi l'angle polaire.
		 */
		for (int j = 0; j < pPara; j++) {
			for (int i = 0; i < pMer; i++) {
				pSphere[i + j * pMer].x = pRayon * cos(theta * i) * cos(phi + ((j * M_PI) / (pPara - 1)));
				pSphere[i + j * pMer].y = pRayon * sin(theta * i) * cos(phi + ((j * M_PI) / (pPara - 1)));
				pSphere[i + j * pMer].z = pRayon * sin(phi + ((j * M_PI) / (pPara - 1)));

				if(pPaupiere){
					pSphere[i + j * pMer].r = 0.839;
					pSphere[i + j * pMer].g = 0.627;
					pSphere[i + j * pMer].b = 0.6;
				}else{
					pSphere[i + j * pMer].r = 1.0;
					pSphere[i + j * pMer].g = 1.0;
					pSphere[i + j * pMer].b = 1.0;
				}

			}
		}

		/*
		 * Calcul des indices des faces
		 */
		for (int j = 0; j < pPara - 1; j++) {
			for (int i = 0; i < pMer; i++) {

				// Calcul des indices pour les paralleles connectes
				fSphere[j][i * 2][0] = i + j * pMer;
				fSphere[j][i * 2][1] = (i + 1) % pMer + j * pMer;
				fSphere[j][i * 2][2] = (i + 1) % pMer + (j + 1) * pMer;
				fSphere[j][i * 2][3] = i + (j + 1) * pMer;

				// Calcul de indices pour les poles de la sphere
				fSphere[j][i * 2 + 1][0] = (i + 1) % pMer + j * pMer;
				fSphere[j][i * 2 + 1][1] = (i + 1) % pMer + (j + 1) * pMer;
				fSphere[j][i * 2 + 1][2] = i + j * pMer;
				fSphere[j][i * 2 + 1][3] = i + (j + 1) * pMer;
			}
		}



		// Si la sphere est une paupiere, alors on n'affiche que la moitie
		short int intervI = (pPaupiere) ? pMer : pMer * 2 ;

		/*
		 * Affichage de la sphere avec les couleurs correspondantes
		 * 3 boucles "for" car fSphere est en 3D
		 * cf ( int fSphere[pPara - 1][pMer * 2][4]; )
		 */
		for (int j = 0; j < pPara - 1 ; j++) {
			for (int i=0; i < intervI ; i++) {
				glBegin(GL_POLYGON);
				for (int k = 0; k < 4; k++) {
					glColor3f(pSphere[fSphere[j][i][k]].r, pSphere[fSphere[j][i][k]].g, pSphere[fSphere[j][i][k]].b);
					glVertex3f(pSphere[fSphere[j][i][k]].x, pSphere[fSphere[j][i][k]].y, pSphere[fSphere[j][i][k]].z);
				}
				glEnd();
			}
		}

		// On reviens au point de depart
		glTranslatef(-pX, -pY, -pZ);

	glPopMatrix();

}






