# Dynamic programming

Al igual que la metodolgía *divide-and-conquer* combina soluciones a subproblemas. En este contexto **programación** hace referencia a aplicar el método tabular y no a codificar en sí.

*Divide-and-conquer* aplica para subproblemas disjuntos, en contraste la programación dinámica es aplicable para subproblemas que se superponen, es decir, un subproblema comparte sub-subproblemas. En este contexto, *divide-and-conquer* resuelve múltiples veces un mismo subproblema mientras que la progrmación dinámica solo lo hace una vez y guarda el resultado en una tabla.

La programación dinámica típicamente se aplica a problemas de optimización. Estos problemas tienen múltiples soluciones posibles, cada solución tiene un valor y queremos hallar el valor óptimo (ya sea mínimo o máximo). Cuando desarrollamos un algoritmo de programación dinámica seguimos los siguientes pasos:
1. Describir las características de una solución óptima.
2. Verificar recursivamente el valor para una solución óptima.
3. Calcular el valor de una solución óptima.
4. Construir una solución óptima de la información obtenida.

Podemos omitir el paso número cuatro si solo requerimos del valor de una solución óptima.

## Rod cutting

El problema ***rod cutting*** (cortes de varilla) se define como: dada una varilla de longitud $n$ y una tabla de precios $p_i$ para $i = 1, 2, ..., n$ se debe determinar la máxima ganancia $r_n$ obtenida de cortar la varilla y vender las piezas. Puede que una solución óptima no requiera cortar la varilla.

Tabla de longitudes y sus respectivos precios:
|  i|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| pi|  1|  5|  8|  9| 10| 17| 17| 20| 24| 30|

Por ejemplo: cuando $n=4$ cortar la varilla en dos varillas de longitud 2 produce $p_2 + p_2 = 10$ que es óptimo. Se puede cortar una varilla de longitud $n$ en $2^{n-1}$ formas diferentes.

Se puede descomponer la forma de cortar una varilla como una suma: $7 = 2 + 2 + 3$, esto quiere decir que una varilla de longitud $7$ se corta en tres partes: dos de longitud 2 y una de longitud 3.

Si cortamos la varilla en $k$ piezas con: $1 \leq k \leq n$, se descompone en: $n = i_1 + i_2 + ... + i_k$ que generan una ganacia: $r_n = p_{i_1} + p_{i_2} + ... + p_{i_k}$.

Se pueden formular los valores $r_n$ para $n \geq 1$ en términos de varillas más cortas: $r_n = max(p_n, r_1 + r_{n-1}, r_2 + r_{n-2}, ..., r_{n-1} + r_1 )$. Donde $p_n$ corresponde a una varilla sin cortes, los otros elementos corresponde a maximizar la ganancia de hacer un corte inicial y dividir la pieza en dos: una de tamaño $i$ y la otra de tamaño $n-i$, con $i = 1, 2, ..., n-1$.

Podemos notar que al resolver un problema de tamaño $n$ resolvemos problemas del mismo tipo pero más pequeños. Decimos entonces que este problema muestra una **subestructura óptima** porque una solución óptima a un problema incorpora soluciones óptimas a subproblemas relacionados que podemos resolver independientemente.

Otra forma de ver el problema es tener una pieza de longitud $i$ y otra de longitud $n-i$ que será dividida, es decir, estamos descomponiendo la pieza restante, con esto podemos simplificar la expresión: $r_n = max_{1 \leq i \leq n} (p_i + r_{n-i})$.

### Implementación recursiva

```
cut-rod(p, n)
    if n == 0
        return 0
    
    q = -infinity
    for i = 1 to n
        q = max(q, p[i] + cut-rod(p, n-i))
    
    return q
```

Esta implementación es ineficiente porque se llama a si misma con los mismos parámetros, es decir, resuelve los mismos subproblemas repetidamente. El tiempo de ejecución de este algoritmo es exponencial: $2^n$ lo que sentido pues consideramos las $2^{n-1}$ maneras de cortar la varilla.

Usando programación dinámica podemos convertir este procedimiento en un algoritmo eficiente. Queremos resolver cada subproblema solo una vez. La programación dinámica utiliza espacio de memoria adicional para reducir el tiempo de ejecución. Se puede pasar de una solución exponencial a una polinómica.

Existen dos maneras de implementar programación dinámica:
1. ***top-down*** con *memoization* (memorización). Escribimos un procedimiento recursivo pero ahora guardamos el resultado de cada subproblema. Ahora primero se revisa si la solución ya existe, si así es el caso se retorna el valor guardado, sino se procesa el valor de la forma *tradicional*.
2. ***bottom-up***. Aquí resolver el problema depende de resolver subproblemas más pequeños. Ordenamos los subproblemas del más pequeño al más grande en tamaño. Cuando queremos resolver cierto subproblema ya hemos resuelto los subproblemas que son pre-requisito.

```
memoized-cut-rod(p, n)
    let r[0...n] be a new array

    for i = 0 to n
        r[i]= -infinity
    
    return memoized-cut-rod-aux(p, n, r)
```

```
memoized-cut-rod-aux(p, n, r)
    if r[n] >= 0
        return r[n]
    
    if n == 0
        q = 0
    else
        q = -infinity
        for i = 1 to n
            q = max(q, p[i] + memoized-cut-rod-aux(p, n-i, r))
        
    r[n] = q
    return q
```

Se inicializa un array auxiliar $r[0..n]$ con el valor $-\infty$ y se llama a `memoized-cut-rod-aux` que primero revisa si el valor deseado ya se conoce, de serlo se retorna, caso contrario se calcula de la manera *usual*.

```
bottom-up-cut-rod(p, n)
    let r[0...n] be a new array
    r[0] = 0

    for j = 1 to n
        q = -infinity
        
        for i = 1 to j
            q = max(q, p[i] + r[j - i])
        r[j] = q

    return r[n]
```

Un problema de tamaño $i$ es más pequeño que uno de tamaño $j$. Se utiliza tambien un array auxiliar y se inicializa $r[0]$ con $0$, pues no hay ganancia. Se resuelven los problemas de tamaño $j$ para $j = 1, 2, ..., n$. No se hacen llamadas recursivas, en su lugar, se obtiene la respuesta de un elemento del array.

Ambos métodos tienen un tiempo de ejecución de $\Theta(n^2)$ debido al doble *for* aninado.

### Reconstruyendo una solución

Hasta ahora se retorna el valor de una solución óptima pero no una solución como tal, que en este caso sería una lista de tamaños de piezas.

Se requiere una versión extendida del `bottom-up-cut-rod` que además de calcular la ganancia máxima también calcule el tamaño óptimo para cortar la pieza.

```
extended-bottom-up-cut-rod(p, n)
    let r[0...n] and s[0...n] be new arrays
    r[0] = 0

    for j = 1 to n
        q = -infinity
        for i = 1 to j
            if q < p[i] + r[j - i]
                q = p[i] + r[j - i]
                s[j] = i
        r[j] = q

    return r and s
```
