# Medians and Order Statistics

## Mínimos y máximos
Podemos hallar el elemento más grande en $n-1$ comparaciones, suponiendo un array $A$ donde $A.length = n$:

```
minimum(A):
    min = A[1]
    for i = 2 to A.length
        if min > A[i]
            min = A[i]
    return min
```

Algunas veces se requiere hallar el mínimo y máximo simultáneamente, si son $n$ elementos, entonces el tiempo de ejecución es $\Theta(n)$. Si para hallar el mínimo y máximo hacemos $n-1$ comparaciones, en total tendremos: $2n - 2$

## Selección en tiempo linear
El problema de selección general parece más difícil que hallar un mínimo o un máximo. Sin embargo, su tiempo de ejecución también es $\Theta(n)$. Esto debido al algoritmo utilizado, basado en la idea central del `quicksort`, el algoritmo es recursivo, pero a diferencia del `quicksort`, `randomized-select` solo trabaja con un lado de la partición, es decir, sólo un subarray. Por ello el $\Theta(n)$, asumiendo que sus elementos son distintos.

El siguiente procedimiento retorna el $i$-ésimo elemento más pequeño:

```
randomized-select(A, p, r, i)
    if p == r
        return A[p]
    q = randomized-partition(A, p, r)
    k = q - p + 1
    if i == k
        return A[q]
    elseif i < k
        return randomized-select(A, p, q - 1, i)
    else
        return randomized-select(A, q + 1, r, i - k)
```

La primera consideración es el caso base, cuando el subarray tiene un solo elemento. En el caso contrario, hacemos la partición generando así dos subarrays $A[p...q-1]$ y $A[q+1...r]$. Después comprobamos si el pivote es el elemento a buscar, si no lo es discriminamos con qué subarray tenemos que seguir trabajando. 

En el peor de los casos este algoritmo tiene un desempeño $\Theta(n^2)$.
