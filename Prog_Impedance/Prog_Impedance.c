#include <stdio.h>
#include <stdlib.h>

#include "..\Primitives_CNC.h"

/*--------------------------------------------------------------------------*/
/*														Variables globales														*/	
/*--------------------------------------------------------------------------*/

FILE * pFile;
float Vmax = 600;
float Vfraisage = 250;
float Vpercage = 100;
float D_fraise = 2.5;
float Z_max = 2;

float Pfloat_X[50];
float Pfloat_Y[50];


/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

void Init_traj(void)
{
	Pfloat_X[0] = 6 + D_fraise/2;				Pfloat_Y[0] = 6 + D_fraise/2;
	Pfloat_X[1] = 10 - D_fraise/2;			Pfloat_Y[1] = 6 + D_fraise/2;
	Pfloat_X[2] = 10 - D_fraise/2;			Pfloat_Y[2] = 8 + D_fraise/2;
	Pfloat_X[3] = 15 + D_fraise/2;			Pfloat_Y[3] = 8 + D_fraise/2;
	Pfloat_X[4] = 15 + D_fraise/2;			Pfloat_Y[4] = 6 + D_fraise/2;
	Pfloat_X[5] = 20 - D_fraise/2;			Pfloat_Y[5] = 6 + D_fraise/2;
	Pfloat_X[6] = 20 - D_fraise/2;			Pfloat_Y[6] = 15 - D_fraise/2;
	Pfloat_X[7] = 18 - D_fraise/2;			Pfloat_Y[7] = 15 - D_fraise/2;
	Pfloat_X[8] = 18 - D_fraise/2;			Pfloat_Y[8] = 17 + D_fraise/2;
	
	Pfloat_X[9] = 20 - D_fraise/2;			Pfloat_Y[9] = 17 + D_fraise/2;
	Pfloat_X[10] = 20 - D_fraise/2;			Pfloat_Y[10] = 29 - D_fraise/2;
	Pfloat_X[11] = 19 - D_fraise/2;			Pfloat_Y[11] = 29 - D_fraise/2;
	Pfloat_X[12] = 19 - D_fraise/2;			Pfloat_Y[12] = 37 + D_fraise/2;
	Pfloat_X[13] = 20 - D_fraise/2;			Pfloat_Y[13] = 37 + D_fraise/2;
	Pfloat_X[14] = 20 - D_fraise/2;			Pfloat_Y[14] = 46 - D_fraise/2;
	Pfloat_X[15] = 15 + D_fraise/2;			Pfloat_Y[15] = 46 - D_fraise/2;
	Pfloat_X[16] = 15 + D_fraise/2;			Pfloat_Y[16] = 44 - D_fraise/2;
	Pfloat_X[17] = 10 - D_fraise/2;			Pfloat_Y[17] = 44 - D_fraise/2;
	Pfloat_X[18] = 10 - D_fraise/2;			Pfloat_Y[18] = 46 - D_fraise/2;
	Pfloat_X[19] = 6 + D_fraise/2;			Pfloat_Y[19] = 46 - D_fraise/2;

	Pfloat_X[20] = 6 + D_fraise/2;;			Pfloat_Y[20] = 37 + D_fraise/2;
	Pfloat_X[21] = 8 + D_fraise/2;;			Pfloat_Y[21] = 37 + D_fraise/2;
	Pfloat_X[22] = 8 + D_fraise/2;;			Pfloat_Y[22] = 29 - D_fraise/2;
	Pfloat_X[23] = 6 + D_fraise/2;;			Pfloat_Y[23] = 29 - D_fraise/2;

	Pfloat_X[24] = 6 + D_fraise/2;;			Pfloat_Y[24] = 17 + D_fraise/2;
	Pfloat_X[25] = 8 + D_fraise/2;;			Pfloat_Y[25] = 17 + D_fraise/2;
	Pfloat_X[26] = 8 + D_fraise/2;;			Pfloat_Y[26] = 13 - D_fraise/2;
	Pfloat_X[27] = 6 + D_fraise/2;;			Pfloat_Y[27] = 13 - D_fraise/2;

}

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

int main () 
{
	unsigned char i,j;
	
	unsigned char n;
	
	unsigned char n2;
	
	//Init_traj();
	
	//FILE * pFile;
	
	pFile = fopen ( "d:\\Tech\\CNC\\Code\\Prog_Impedance\\Prog_Impedance.nc" , "wb" );
	if (pFile==NULL) {fputs ("Filllle error",stderr); exit (1);}
	else printf("creation OK\n");

	//char Mode_open[15] = "wb";
	
	Init_File();//,Mode_open);
	
	Up_Down(3);
	
	Posi(-D_fraise/2,-D_fraise/2);
	
	Creuse_Y(6.7, -D_fraise/2, 50 + D_fraise/2, 38.05, -1, -2, 1);
	
	Machine_Stop();
	
	//percage coin
	Posi(6.7, 38.05);
	Up_Down(-2.5);
	Up_Down(1);
	
	Machine_Stop();
	
	//Passage des pogos
	Posi(32+D_fraise/2,26.75 + D_fraise/2);
	for(i=0;i<3;i++)
	{
		Up_Down(-3.5 - 1.5*i);
		Fraise(42-D_fraise/2,26.75+D_fraise/2);
		Fraise(42-D_fraise/2,32.5-D_fraise/2);
		Fraise(32+D_fraise/2,32.5-D_fraise/2);
		Fraise(32+D_fraise/2,26.75+D_fraise/2);
	}
	Up_Down(1);
	
	
	//Creuse_Y(32,26.75,42,32.5,-1,-2,1);
	
	Up_Down(1);

	//passage des pins de connecteurs de bord de carte
	Posi(10.81, -D_fraise/2);
	Up_Down(-3);
	Fraise(10.81,17-D_fraise/2);
	Up_Down(-4);
	Fraise(10.81,-D_fraise/2);
	Up_Down(1);
	
	//Suite degagement pins connecteurs
	Posi(48.7, 9+D_fraise/2);
	Up_Down(-3);
	Fraise(48.7,16-D_fraise/2);
	Up_Down(-4);
	Fraise(48.7,9+D_fraise/2);
	Up_Down(1);


	Posi(42+D_fraise/2, 27+D_fraise/2);
	Creuse_Y(42,27,50,34, -3,-4,1);	
	Up_Down(1);
	
	//Passage entretoise carte
	Posi(10,26.75);
	Trou(10,26.75, 3.2, -3.5,-6.5,1.5);
	Up_Down(1);
	
//Percage fixation carte	
	//percage
	Posi(3,3);
	Up_Down(-6.5);
	Up_Down(1);
	
	//percage
	Posi(47,3);
	Up_Down(-6.5);
	Up_Down(1);
	
	//percage
	Posi(47,69);
	Up_Down(-6.5);
	Up_Down(1);
	
	//percage
	Posi(3,69);
	Up_Down(-6.5);
	Up_Down(1);

	Detourage(0, 0, 50, 72, -0.5, -5, 1.5);

	Up_Down(1);
	
	Posi(0 - D_fraise/2, 0 - D_fraise/2);
	
	Up_Down(-6.5);
	Fraise(50 + D_fraise/2, -D_fraise/2);
	Up_Down(-4.5);
	Posi(50 + D_fraise/2, 7);
	
	Up_Down(-6.5);
	Fraise(50 + D_fraise/2, 65 - D_fraise/2);
	Up_Down(-4.5);
	Posi(50 + D_fraise/2, 72 + D_fraise/2);
	
	Up_Down(-6.5);
	Fraise(0 - D_fraise/2, 72 + D_fraise/2);
	Up_Down(-4.5);
	Posi(0 - D_fraise/2, 65 - D_fraise/2);
	
	Up_Down(-6.5);
	Fraise(0 - D_fraise/2, 7);
	
	Up_Down(3);

	Machine_Stop();
	End_file();
	
	fclose (pFile);

	return 0;
}
