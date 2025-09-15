# Divide and conquer

## Recurrencias
Es una ecuación que describe una función en términos de su valor con entradas más pequeñas.

## Método de sustitución
Tiene los siguientes pasos:
1. Suponer la forma de la solución.
2. Usar inducción matemática para demostrar que la solución funciona.

Ejemplo:
Tenemos la recurrencia: 
$$
T(n) = 2T(\frac{n}{2}) + n
$$
Y suponemos que la solución es:
$$
T(n) = O(nlog_2(n))
$$
Se debe probar:
$$
T(n) \leq cnlog_2(n) \text{, para un } c > 0
$$ 
Suponemos que lo anterior se cumple para un $k<n$, si $k = \frac{n}{2}$:
$$
T(\frac{n}{2}) = c\frac{n}{2}log_2(\frac{n}{2})
$$
Sustituimos en la recurrencia:
$$
T(n) = 2(c\frac{n}{2}log_2(\frac{n}{2})) + n \leq cnlog(n) \to \\[0.5cm]
cnlog_2(\frac{n}{2})+n \leq cnlog_2(n) \to \\[0.5cm]
cnlog_2(n) - cn + n \leq cnlog_2(n) \\[0.5cm]
\text{ siempre que } c \geq 1
$$

## Método árbol de recursión
En estos árboles cada nodo representa el coste para cada uno de los subproblemas, costes que son sumados por nivel para obtener el **coste por nivel**. Después, se pueden sumar estos costos por nivel para calcular el **costo total** de todos los niveles de la recursión.

Este método es usado para generar una suposición que puede ser verificada después utilizando el método de sustitución.

## Método *master*
Este método ayuda a resolver recurrencias del tipo:
$$
T(n)=aT(\frac{n}{b}) + f(n) \text{, donde: } a \geq 1, b \gt 1 \text{ y } f(n) \text{ es asintóticamente positiva}
$$

Esto último quiere decir que para un valor de $n$ los suficientemente grande la función $f(n)$ toma valores postivos.

Existen tres casos del *master theorem*:
1. Si: $f(n) \in O(n^{log_b(a - \epsilon)}) \text{ para alguna constante } \epsilon > 0 \text{ entonces, } T(n) \in \Theta(n^{log_b(a)})$
2. Si: $f(n) \in \Theta(n^{log_b(a)}) \text{ entonces, } T(n) \in \Theta(n^{log_b(a)}log_2(n))$
1. Si: $f(n) \in \Omega(n^{log_b(a + \epsilon)}) \text{ para alguna constante } \epsilon > 0 \text{ y si: } af(\frac{n}{b}) \leq cf(n) \text{ con: } c > 1 \text{ y } n \text{ lo suficientemente grande } \text{ entonces, } T(n) \in \Theta(f(n))$

*En todos los casos lo que se debe hacer es comparar la función $f(n)$ con la función $n^{log_b(a)}$ si $f(n)$ es más pequeña utiliza el caso 1, si es más grande se ocupa el caso 3 y si son iguales el caso 2.*

Ejemplos:
1. 
$$
T(n)=9T(\frac{n}{3}) + n \\[0.5cm]
a=9, b=3 \text{ y } f(n)=n \text{, entonces: } \\[0.5cm]
n^{log_b(a)} = n^{log_3(9)} = n^2
$$
La función $n^{log_b(a)}$ es más grande que $f(n)$, por lo que: $T(n)=\Theta(n^2) \\[1cm]$

2. 
$$
T(n) = T(\frac{2n}{3}) + 1 \\[0.5cm]
a=1, b=\frac{3}{2} \text{ y } f(n)=1 \text{, entonces: } \\[0.5cm]
n^{log_b(a)} = n^{log_\frac{3}{2}(1)} = n^0 = 1
$$
La función $n^{log_b(a)}$ es igual que $f(n)$, por lo que: $T(n)=\Theta(log_2(n)) \\[1cm]$

3.
$$
T(n) = 3T(\frac{n}{4}) + nlog_2(n) \\[0.5cm]
a=3, b=4 \text{ y } f(n)=nlog_2(n) \text{, entonces: } \\[0.5cm]
n^{log_b(a)} = n^{log_4(3)} \approx n^{0.79}
$$
La función $n^{log_b(a)}$ es igual que $f(n)$. Revisamos también que: $af(\frac{n}{b}) \leq cf(n)$
$$
3f(\frac{n}{4}) \leq cf(n) \to 3\frac{n}{4}log_2(\frac{n}{4}) \leq \frac{3}{4}nlog_2(n) \text{ se cumple para } c = 3/4
$$
Por lo que: $T(n)=\Theta(nlog_2(n))$
