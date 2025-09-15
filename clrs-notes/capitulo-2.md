# Getting started.

## Insertion sort
*Similar a la forma en la que se ordenarían cartas en un juego de cartas, empezamos con un mazo vacío, tomamos la primera carta, cartas posteriores serán insertadas donde corresponde, comparándolas de derecha a izquierda.*

Pseudocódigo:
```
insertion-sort(A)
    for j = 2 to A.length
        key = A[j]
        i = j - 1
        while i > 0 and A[i] > key
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
```

## Invariantes de ciclo
Se utilizan para determinar porqué un algoritmo es correcto. Son:
- Verdaderos antes de la primera iteración.
- Si es verdadero previo a una iteración del ciclo permanece verdadero antes de la siguiente iteración.
- Cuando el ciclo termina nos dan propiedades útiles para demostrar que un algoritmo es correcto.

## Conceptos para el análisis de algoritmos
- **Input size.** El número de elementos que tiene la entrada (input).
- **Running time.** Número de pasos ejecutados y el tiempo que tarda cada uno: el "*costo*" de ser ejecutado.

## Orden de crecimiento
Es una abstracción que simplifica los "costos", es decir, se ignoran:
- Términos de bajo orden.
- Términos constantes.

Esto porque son insignificantes, pueden despreciarse. Entonces: 
$$
\frac{n^3}{100} + 100n + 3 \to n^3
$$

## Divide y vencerás
Consta de tres pasos:
- **Divide.** El problema se divide en sub-problemas (instancias más pequeñas del mismo problema).
- **Conquista.** Los sub-problemas se resuelven recursivamente. Si tienen un tamaño lo suficientemente pequeño se resuelven de manera directa.
- **Combina.** Las soluciones a los sub-problemas se combinan para formar una solución para el problema original.

### Ejemplo: Merge sort
1. Se divide la secuencia de n-elementos en dos sub-secuencias de $\frac{n}{2}$-elementos.
2. Se ordenan las sub-secuencias recursivamente utilizando merge sort.
3. Se mezclan las dos sub-secuencias para producir la respuesta.

* Cuando una sub-secuencia tiene tamaño 1, ya está ordenada.
* Se utiliza un función auxiliar llamada **merge** para *"combinar"*. Recibe el array $A$, e índices de dicho arreglo:  $p, q, r$, tal que: $p \le q \lt r$.
    * Se asume que $A[p...q]$ y $A[q+1...r]$ están ya ordenados, entonces **merge** se encarga de combinar estos sub-arrays para obtener un solo array ordenado $A[p...r]$.
    * Tiene complejidad $\theta(n)$, donde $n = r - p + 1$ que es el número total de elementos en el array.

*Imagina dos pilas de cartas ya ordenadas, comparas las dos cartas de hasta arriba, tomando y colocando boca abajo la más pequeña, esto se repite hasta que ordenas todas.*

Pseudocódigo:
```
merge(A, p, q, r)
    m1 = q - p + 1
    m2 = r - q

    let L[1...m1+1] and R[1...m2+1] be new arrays
    for i = 1 to m1
        L[i] = A[p + 1 - i]
    for j = 1 to m2
        R[j] = A[q + j]
    L[m1 + 1] = infinity
    R[m2 + 1] = infinity

    i = 1
    j = 1
    for k = p to r
        if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else if L[i] > R[j]
            A[k] = R[j]
            j = j + 1
```
```
merge-sort(A, p, r)
    if p < r
        q = (p + r) / 2
        merge-sort(A, p, q)
        merge-sort(A, q + 1, r)
        merge(A, p, q, r)
```

## Analizando algoritmos **divide-and-conquer**
Cuando un algoritmo se llama a sí mismo de manera recursiva su **running time** esta dado por una **recurrencia** o también llamada **ecuación de recurrencia**.

Sea $T(n)$ el **running time** de n-elementos (para el caso donde el problema sea lo suficientemente pequeño la solución toma tiempo constanste: $\theta(1)$), suponiendo que la división del problema genera $a$ sub-problemas de tamaño $\frac{n}{b}$ (para merge sort: $a=2$ y $b=2$).
Entonces se están resolviendo $a$-subproblemas de tamaño $\frac{n}{b}$, esto se puede expresar como: $aT(\frac{n}{b})$, además se considera el tiempo destinado para dividir el problema: $D(n)$ y para combinar los sub-problemas: $C(n)$.
Resultando en:
$$
T(n) = 
\begin{cases}
    \theta(1) & \text{si } n \leq c \\
    aT(\frac{n}{b}) + D(n) + C(n) & \text{en otro caso}
\end{cases}
$$

En el caso particular de **merge sort**: 
- Dividir el problema toma tiempo constante, solo es calcular el índice $q$, entonces: $D(n) = \theta(1)$.
- Resolver los sub-problemas toma: $2T(\frac{n}{2})$, porque: $a=2$ y $b=2$.
- Para hacer el **merge**, es decir, combinar los sub-problemas toma: $C(n)=\theta(n)$, porque se consulta cada elemento del problema.

Resultando esto en la ecuación de recurrencia para el peor caso de merge sort:
$$
T(n)=
\begin{cases}
    \theta(1) & \text{si n = 1} \\
    2T(\frac{n}{2}) + \theta(n) & \text{si n > 1}
\end{cases}
$$

Si se elabora un árbol de recurrencia, se tiene que dicho árbol tiene $log_2(n) + 1$ niveles, siendo que cada nivel suma: $cn$, podemos obtener la complejidad temporal de merge sort:
$$
cn(log_2(n) + 1) = cnlog_2(n)+cn \to \theta(nlog_2(n))
$$
