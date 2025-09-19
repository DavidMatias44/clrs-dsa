# Quicksort

Este algoritmo también utiliza el principio **divide-and-conquer**:
- **Divide**. Se particiona el array $A[p...r]$ en dos subarrays, que pueden estar vacíos $A[p...q-1]$ y $A[q+1...r]$, de tal manera que cada elemento en el primer subarray $A[p...q-1]$ sea menor o igual a $A[q]$ y en el segundo subarray sea cada elemento mayor o igual.
- **Conquer**. Se ordenan los subarrays llamando de forma recursiva a quicksort.
- **Combine**. Debido a que los subarrays ya están ordenados no hay necesidad de hacer una mezcla o combinación.

```
quicksort(A, p, r)
    if p < r
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)
```

La clave de este algoritmo es el procedimiento `partition`.
```
partition(A, p, r)
    x = A[r]
    i = p - 1
    for j = p to r - 1
        if A[j] <= x
            i = i + 1
            exchange A[i] with A[j]
    exchange A[i + 1] with A[r]
    return i + 1
```

## Desempeño de quicksort
Todo depende de qué tan bien esté balanceada la partición. Si no es buena, el tiempo de ejecución es igual al de `insertion-sort`, caso contrario, su desempeño es tan bueno como el de `merge-sort`.

El peor caso en el particionamiento ocurre cuando generamos un subarray de $n-1$ elementos y otro vacío. Sabemos que particionar nos toma $\Theta(n)$, entonces la recurrencia se representa: $T(n)=T(n-1) + \Theta(n) = \Theta(n^2)$. Esto ocurren cuando el arreglo ya está ordenado.

El mejor caso ocurren cuando el particionamiento genera dos subarrays de no más $\frac{n}{2}$ elementos, en este caso tenemos: $T(n)=2T(\frac{n}{2}) + \Theta(n) = \Theta(nlg(n))$

El caso promedio es mucho más cercano al mejor caso que al peor caso.

## Una versión randomizada del quicksort
Se utiliza una técnica conocida como **muestreo aleatorio** (*random sampling*), con esto en lugar de utilizar siempre a $A[r]$ com pivote se elige al azar entre los elementos $A[p...r]$.

Con esto se espera que el balanceo esté razonablemente bien en promedio.
```
randomized-partition(A, p, r)
    i = random(p, r)
    exchange A[r] with A[i]
    return partition(A, p, r)
```

```
randomized-quicksort(A, p, r)
    if p < r
        q = randomized-partition(A, p, r)
        randomized-quicksort(A, p, q - 1)
        randomized-quicksort(A, q + 1, r)
```

La versión randomizada y la "normal" solo difieren en la forma en la que se elige al pivote, en el resto son iguales:
- Peor caso es $\Theta(n^2)$
- Mejor caso es $\Theta(nlg(n))$

## Selección por mediana
Es una manera de mejorar el `randomized-quicksort`, el pivote es elegido de manera más cuidadosa.

Un método para lograr esto es ***median-of-3*** que consiste en elegir el elemento de "en medio" (la mediana) de tres elementos elegidos de manera aleatoria.
