#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double funcion(double x){
    return sin(x);
}

//rows=numeroDerivada; h=h, n=x
void difProgresivas(int rows,double h,double n,bool central){

    vector<int> pascal;
    vector<double> evaluaciones;

    for (int i = 0; i < rows+1; i++)
    {
        int val = 1;
        for (int k = 0; k <= i; k++)
        {
            if(i==rows){
                pascal.push_back(val);
            }
            val = val * (i - k) / (k + 1);
        }
    }

    double contador = 0;

    if (central){
        contador=(double)rows/2;
    } else{
        contador=rows;
    }

    for (int j = 0; j < pascal.size(); ++j) {
        evaluaciones.push_back(pascal.at(j)*funcion(n+(contador*h)));
        contador = contador-1;
    }

    bool bandera = true;
    double numerador=0;

    for (int l = 0; l < evaluaciones.size(); ++l) {
        if(bandera==true){
            numerador=numerador+evaluaciones.at(l);
            bandera=false;
        }else{
            numerador=numerador-evaluaciones.at(l);
            bandera=true;
        }
    }
    cout<< numerador/pow(h,rows);
}

int main() {
    difProgresivas(3,0.001,M_PI,false);
    return 0;
}

/*
log(x) / log(base)
acon
log10
pow
7 ^ 3 = pow (7.0, 3.0)

M_E
The base of natural logarithms.

M_LOG2E
The logarithm to base 2 of M_E.

M_LOG10E
The logarithm to base 10 of M_E.

M_LN2
The natural logarithm of 2.

M_LN10
The natural logarithm of 10.

M_PI
Pi, the ratio of a circle’s circumference to its diameter.

M_PI_2
Pi divided by two.

M_PI_4
Pi divided by four.

M_1_PI
The reciprocal of pi (1/pi)

M_2_PI
Two times the reciprocal of pi.

M_2_SQRTPI
Two times the reciprocal of the square root of pi.

M_SQRT2
The square root of two.

M_SQRT1_2
The reciprocal of the square root of two (also the square root of 1/2).
*/
