/* CPP  Program to find approximation 
   of a ordinary differential equation 
   using euler method.*/
#include <iostream> 
#include <string>
#include <cmath>
#include<stdio.h> 
#include <iomanip> 
using namespace std; 
  
// Consider a differential equation 
// dy/dx=(x + y + xy) 
float func(float x, float y) 
{ 
    return -(5*y)+(5*pow(x,2))+2*x; 
} 
  
// Function for Euler formula 
void euler(float x0, float y, float h, int a, int b) 
{ 
    float temp = -0; 
  
	int n= (int)((b-a) / h); 
    // Iterating till the point at which we 
    // need approximation
	x0=a;
    for(int i=0;i<n;i++){ 
        temp = y; 
        y = y + h * func(x0, y); 
        x0 = x0 + h;
        cout<<y<<endl;
    } 
  
    // Printing approximation 
    cout << "Approximate solution at x = "
         << "  is  " << y << endl; 
} 
  
// Driver program 
int main() 
{ 
    // Initial Values 
    float x0 = 0; 
    float y0 = 0.33333333333;
	int a=0,b=1;
    float h = 0.1; 
  
    // Value of x at which we need approximation 
    float x = 0.1; 
  
    euler(x0, y0, h, a,b); 
    return 0; 
} 