# Growth of functions

## Notación asintótica
Cuando nos interesan entradas lo suficientemente grandes para que el orden de crecimiento de la función sea relevante, entonces se dice que se estudia la eficiencia asintótica de los algoritmos.

Se utiliza la notación asintótica para describir el tiempo de ejecución (running time) de los algoritmos.

## Notación $\Theta$
Se cumple: $
f(n) \in \Theta(g(n)) \text{ si existen } c_1, c_2 > 0, n_0 > 0 \text{ tales que } 0 \leq c_1g(n) \leq f(n) \leq c_2g(n) \quad \forall n \geq n_0
$
*Existen constantes $c_1$ y $c_2$ que "acotan" a $f(n)$, para un $n$ lo suficientemente grande.*

Se dice que $g(n)$ es un **limite asintóticamente ajustado** para $f(n)$.

## Notación $O$
Se cumple: $
f(n) \in O(g(n)) \text{ si existen } c > 0, n_0 > 0 \text{ tales que } 0 \leq f(n) \leq cg(n) \quad \forall n \geq n_0, \Theta(n) \subseteq O(n)
$

*Cualquier función en $\Theta$ está también en $O$*.

Esta notación describe un **límite superior**.

## Notación $\Omega$
Se cumple: $
f(n) \in \Omega(g(n)) \text{ si existen } c > 0, n_0 > 0 \text{ tales que } 0 \leq cg(n) \leq f(n) \quad \forall n \geq n_0
$

Esta notación describe un **límite inferior**.

## Notación $o$
Se cumple: $
f(n) \in o(g(n)) \text{ si para todo } c > 0 \text{ existe } n_0 > 0 \text{ tales que } 0 \leq f(n) \lt cg(n) \quad \forall n \geq n_0
$

Usada para denotar un **límite superior pero que no es asintóticamente ajustado**. Por ejemplo: $
100n \in o(n^2) \text{, pero } 100n^2 \notin o(n^2)
$

## Notación $\omega$
Se cumple: $
f(n) \in \omega(g(n)) \text{ si para todo } c > 0 \text{ existe } n_0 > 0 \text{ tales que } 0 \leq cg(n) \lt f(n) \quad \forall n \geq n_0
$

Usada para denotar un **límite inferior que no es asintótiamente ajustado**. Por ejemplo: $
\frac{n}{2} \in \omega(n) \text{, pero } \frac{n^2}{2} \notin \omega(n^2)
$
