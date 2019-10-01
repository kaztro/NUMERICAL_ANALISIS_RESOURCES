# encoding: utf-8

from sympy import * # Usaremos SymPy como herramienta para realizar manipulaciones simbólicas

# Las siguientes dos librerías serán utilizadas para graficar
import matplotlib.pyplot as plt;
import numpy as np

# Usaremos lo siguiente para mostrar los polinomios de forma bonita
from sympy.interactive import printing;
printing.init_printing(use_latex=True);
from IPython.display import display, Latex

x = Symbol('x')

#FUNCION 
def f(z):
    return cos(log(z)) + z + 2

#Nodos: 
xs = [1.8, 1.85, 1.90]
ys = [f(1.8), f(1.85), f(1.90)]

'''
Esta primera función calcula la combinación lineal. Es una traducción directa de la fórmula e 
invoca la función lagrangeBasisFunction para calcular las funciones base.
xs: arreglo con valores en x
ys: arreglo con valores en y
degree: grado del polinomio
'''
def lagrangePolynomial(xs, ys, degree):
    polynomial = 0.0;
    for i in range(0, degree + 1):
        polynomial += ys[i]*lagrangeBasisFunction(xs, degree, i)
    return polynomial    
   
'''
Esta función calcula la función base correspondiente. Es, también, una traducción directa de la fórmula.
xs: arreglo con valores en x
degree: grado del polinomio, índice superior del producto
k: índice de la función base 
'''    
def lagrangeBasisFunction(xs, degree, k):
    L = 1.0
    for i in range(0, degree + 1):
        if i == k:
            continue
        else:
            L *= (x - xs[i])/(xs[k] - xs[i])
    return L        

degree = 2 #ES EL GRADO DEL POLINOMIO
pol = lagrangePolynomial(xs, ys, degree)
print('p_{degree}(x) =\t', pol, '\t<POLINOMIO/>') #DESCOMENTA ESTO PARA VER COMO ES EL POLINOMIO!!!!!!!
#display(Latex('$$ p_{degree}(x) = '+ latex(simplify(pol.evalf())) + '$$'))


'''
Para evaluar algun punto xd: 

#NO OLVIDES CAMBIAR EL PUNTO EN EL QUE SE EVALUA!!!
polii = pol.subs(x, 0.45).evalf() #En el polinomio...
funcii = f(0.45).evalf() #En la funcion...
print('error absoluto: ', abs(funcii - polii))
'''
'''
SI DESEAS VER LA GRAFICA DESCOMENTA ESTO!!!!!!!!!!!!!!!!!!!!
Graficar:

fig, ax = plt.subplots(figsize=(10, 10));

lambdaf = lambdify(x, pol)

xv = np.linspace(0, 2, 50);
ax.plot(xv, lambdaf(xv), color='green'); #Este es el color del polinomio de interpolacion...
ax.plot(xv, np.sin(np.pi*xv), color = 'orange') #Este es el color de la funcion
ax.scatter(xs, ys, color='blue', marker='o'); #Este es el color de los nodos
plt.show(); 
'''