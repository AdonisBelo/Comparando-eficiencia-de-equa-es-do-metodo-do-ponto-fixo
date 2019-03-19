#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	clock_t Ticks[6];
	Ticks[0] = clock();
	printf("Metodo do ponto fixo\n\n");
	printf("O ponto inicial eh: x0 = 1,5 e y0 = 3,5\n");
	printf("O erro estimado eh: 10^-3 ou 0,001\n\n");
	
	printf("Equacao X: Xi+1 = (10 - Xi*Yi)^(1/2)\n");
	printf("Equacao Y: Yi+1 = ( (57 - Yi)/(3* Xi+1) )^(1/2)\n\n");
	int i=0;
	float x, x2, y, y2, e, ex, ey;
	x=1.5;
	y=3.5;
	e=0.001;
	do{
		x2 = sqrt( 10 - (x*y) );
		y2 = sqrt( (57-y)/(3*x2) );
		
		ex = fabs( (x2-x)/x2 );
		ey = fabs( (y2-y)/y2 );
	    
	    printf("iteracao: %d\t", i);
		printf("Xi: %.6f\t", x);
		printf("Yi: %.6f\n", y);
		printf("Xi+1: %.6f\t", x2);
		printf("Yi+1: %.6f\n", y2);
		printf("erro x: %.6f\t", ex);
		printf("erro y: %.6f\n\n", ey);
	    x=x2;
	    y=y2;
		
	    i++;
	    
	}while( (ex >= e) && (ey >= e) );
	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n\n", Tempo);
    
    Ticks[2] = clock();
    
    printf("Equacao X: Xi+1 = (10 - Xi * Yi+1)^(1/2)\n");
	printf("Equacao Y: Yi+1 = ( (57 - Yi)/(3* Xi) )^(1/2)\n\n");
    i=0;
	x=1.5;
	y=3.5;
	e=0.001;
	do{
		y2 = sqrt( (57-y)/(3*x) );
		x2 = sqrt( 10 - (x*y2) );
		
		ex = fabs( (x2-x)/x2 );
		ey = fabs( (y2-y)/y2 );
	    
	    printf("iteracao: %d\t", i);
		printf("Xi: %.6f\t", x);
		printf("Yi: %.6f\n", y);
		printf("Xi+1: %.6f\t", x2);
		printf("Yi+1: %.6f\n", y2);
		printf("erro x: %.6f\t", ex);
		printf("erro y: %.6f\n\n", ey);
	    x=x2;
	    y=y2;
		
	    i++;
	    
	}while( (ex >= e) && (ey >= e) );
	
    Ticks[3] = clock();
    Tempo = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n\n", Tempo);
	
	Ticks[4] = clock();
	
	printf("Equacao X: Xi+1 = 10 / (Xi+Yi)\n");
	printf("Equacao Y: Yi+1 = 57 / (3*Xi+1*Yi + 1)\n\n");
    i=0;
	x=1.5;
	y=3.5;
	e=0.001;
	do{
		
		x2 = 10 / (x+y);
		y2 = 57/(3*x2*y + 1);
		
		ex = fabs( (x2-x)/x2 );
		ey = fabs( (y2-y)/y2 );
	    
	    printf("iteracao: %d\t", i);
		printf("Xi: %.6f\t", x);
		printf("Yi: %.6f\n", y);
		printf("Xi+1: %.6f\t", x2);
		printf("Yi+1: %.6f\n", y2);
		printf("erro x: %.6f\t", ex);
		printf("erro y: %.6f\n\n", ey);
	    x=x2;
	    y=y2;
		
	    i++;
	    
	}while( (ex >= e) && (ey >= e) );
	
    Ticks[5] = clock();
    Tempo = (Ticks[5] - Ticks[4]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n\n", Tempo);
}
