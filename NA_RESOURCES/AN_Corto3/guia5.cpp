#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

inline long double f (long double x){
    return pow(x,(7.0/2.0) - 1) * exp(-x);
}

long double ctrapezlum(long double a, long double b, int n){
    long double h=(b-a)/n;
    long double sum = 0.0;
    for (int i =1; i<n; i++) sum += f(a+i*h);
    return(f(a)+2.0*sum+f(b))*(h/2.0);
}

long double csimpson(long double a, long double b, int n){
    long double h=(b-a)/n;
    long double sum1 = 0.0;
    long double sum2 = 0.0;
    for (int i =1; i<n/2; i++) sum1 += f(a+2.0*i*h);
    for (int i =1; i<=n/2; i++) sum2 += f(a+(2.0*i-1)*h);
    return (h/3.0)*(f(a)+2.0*sum1+4.0*sum2+f(b));
}

int main(){
    cout << setprecision(10) << "E3 " <<"Simpson: " << csimpson(0.0,2000.0,40000.0) << endl;
    //cout << setprecision(10) << "Trapezoidal: " << ctrapezlum(0,3,1000) << endl;
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
