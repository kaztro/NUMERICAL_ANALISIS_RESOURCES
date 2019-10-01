#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

//y' es decir la derivada
	//para probar:
		//return (0.5)*(1+x)*pow(y,2);
		//return 2*x*y
long double yprima(long double x, long double y){
	return (sin(100*x)-y)/0.01;
}

//funcion real para obtener datos exactos
	//Para probar:
		//return -(4/(pow(x,2)+(2*x)-4));
		//return exp(pow(x,2)-1);
long double f(long double x){
	return (sin(100.0*x)-0.01*0.5);
}

//Función para el método de Euler
void Euler(long double a,long double b,long double h,long double x,long double y){
	
	long double n, yreal, error; 

	n = (b-a)/h+1;		
	
	yreal = f(x);
	error = (yreal-y)/yreal;

	cout<<" xi"<<"\t\t"<<'y'<<"\t\t"<<"y real"<<"\t\t"<<"Error"<<endl;
	cout<<x<<"\t\t"<<y<<"\t\t"<<yreal<<"\t\t"<<error<<endl;
	for(int i = 1; i <= n; i++){
		y = y + (h * yprima(x,y));
		x = x+h;		
		yreal = f(x);
		error = (yreal-y)/yreal;		
		cout<<setprecision(8)<<x<<"\t\t"<<y<<"\t\t"<<yreal<<"\t\t"<<error<<endl;		
	}
}

void modEuler(long double a,long double b,long double h,long double x,long double y){
	long double n, yreal, error, xnext; 

	n = (b-a)/h+1;		
	
	yreal = f(x);
	error = (yreal-y)/yreal;

	cout<<" xi"<<"\t\t"<<'y'<<"\t\t"<<"y real"<<"\t\t"<<"Error"<<endl;
	cout<<x<<"\t\t"<<y<<"\t\t"<<yreal<<"\t\t"<<error<<endl;
	for(int i = 1; i <= n; i++){
		xnext = x+h;
		y = y + ((h/2) * (yprima(x,y)+yprima(xnext, y + h * yprima(x,y))));
		x = x+h;		
		yreal = f(x);
		error = (yreal-y)/yreal;		
		cout<<setprecision(8)<<x<<"\t\t"<<y<<"\t\t"<<yreal<<"\t\t"<<error<<endl;		
	}
}

int main(){
	long double a,b,x,y,h;
	
	//Límite inferior
	a = 0;
	//Límite superior
	b = 10;
	//Paso h
	h = 0.0001;

	//y inicial
	y = 0.5;
	//x inicial
	x=b;
	

	//Llamada a la funcion
	modEuler(a,b,h,x,y);
	
	return 0;
}
