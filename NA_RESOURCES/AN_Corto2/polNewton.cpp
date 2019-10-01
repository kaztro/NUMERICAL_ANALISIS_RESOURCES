double x[10],fx[10];
double t[10][11];
double xint,fxint;
int n;

void lee_datos();
void tabla();
void int_newton();

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

main ()
{ /* Principal */

int i,j;

lee_datos();
tabla();

/* Impresi¢n de la tabla de diferencias divididas y del resultado */

printf(" TABLA DE DIFERENCIAS DIVIDIDAS :\n");
printf("\n");
printf(" x\t\t f(x)\t\t DIFERENCIAS\n");
for(i=0; i<=n; i++)
{
printf("%10.4f%10.4f",x[i],fx[i]);
for(j=0; j<=n; j++)
printf("%10.5f",t[i][j]);
printf("\n");
}
printf("\n");
int_newton();
printf(" PARA  x = %10.5f la interpolacion es  f(x) = %10.5f\n",xint,fxint);
getch();


FILE *archivo;
archivo=freopen("Diferencia.txt","w",stdout);
printf(" TABLA DE DIFERENCIAS DIVIDIDAS :\n");
printf("\n");
printf(" x\t\t f(x)\t\t DIFERENCIAS\n");
for(i=0; i<=n; i++)
{
printf("%10.4f%10.4f",x[i],fx[i]);
for(j=0; j<=n; j++)
printf("%10.5f",t[i][j]);
printf("\n");
}
printf("\n");
int_newton();
printf(" PARA x = %10.5f la interpolacion es f(x) = %10.5f\n",xint,fxint);


fclose(archivo); 
freopen( "CON", "w", stdout );
fflush(stdin);      
system("PAUSE");
}   //fin main


void lee_datos()

{
int i;

/* Las siguientes instrucciones permiten leer datos desde
el teclado */
      printf("/****************   DIFERENCIAS  DIVIDIDAS  ******************/\n\n\n\n");
      printf("Se creara en el directorio actual un archivo llamado Diferencias.txt\nEn este estaran los datos de la tabla\nCada vez que se corra se sobreescribiran los datos\n\n");
printf("  Ingrese la cantidad -1 de los puntos que van ha ser calculados en la tabla:  "); scanf("%d",&n);
printf("\n");
for(i=0; i<=n; i++)
{
printf(" x(%d) = ",i); scanf("%lf",&x[i]);
printf(" y(%d) = ",i); scanf("%lf",&fx[i]);
}
printf("Valor de x para interpolar "); scanf("%lf",&xint);
}


/* Se construye la tabla de diferencias divididas. */

void tabla()

{
int i,j,k;

for(i=0; i<=n; i++)
for(j=0; j<=n; j++)
t[i][j]=0.0;
for(j=0; j<=n-1; j++)
t[j+1][0]=(fx[j+1]-fx[j])/(x[j+1]-x[j]);
for(k=1; k<=n-1; k++)
for(i=k; i<=n-1; i++)
t[i+1][k]=(t[i+1][k-1]-t[i][k-1])/(x[i+1]-x[i-k]);
}

void int_newton()
{
int l,j;
double p1;

fxint=fx[0];
for(l=0; l<=n-1; l++)
{
p1=1;
for(j=0; j<=l ;j++)
p1=p1*(xint-x[j]);
fxint=fxint+p1*t[l+1][l];
}
}