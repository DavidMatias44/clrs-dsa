# Sorting in linear time

## Counting sort
Este método asume que cada elemento de la entrada es un entero en el rango de $0$ a $k$. Logrando ordenar en tiempo $\Theta(n)$.

Entonces para cada elemento $x$ se determina el número de elementos menores a $x$ y con ello saber en qué posición colocar a este elemento.

La entrada es un array $A[1..n]$, con $n = A.length$. Se requiere de otros dos arrays: $B[1..n]$ y $C[0...k]$, el primero tendrá el arreglo ordenado y el segundo se utiliza para almacenamiento temporal.

```
counting-sort(A, B, k)
    let C[0..k] be a new array

    for i = 0 to k
        C[i] = 0
    
    for j = 1 to A.length
        C[ A[j] ] = C[ A[j] ] + 1;

    for i = 1 to k
        C[i] = C[i] + C[i - 1]

    for j = A.length downto 1
        B[ C[ A[j] ] ] = A[j]
        C[ A[j] ] = C[ A[j] ] - 1
```
*Primero reservamos un array de k-elementos, lo rellenamos del número de veces que número $i$ ocurre en el arreglo $A$, es decir, el índice tiene el numero de ocurrencias.
Posteriormente se recalcula en la posición $i$ el número de elementos menores o iguales a dicho elemento $i$.
Finalmente, cada elemento de $A$ se coloca en la posición que le corresponde en el arreglo $B$, decrementar $C[A[j]]$ coloca el siguiente elemento con el mismo valor en la posición anterior.*

## Algoritmos de ordenamiento estables
Cuando el algoritmo no cambia el orden realativo de los elementos que son iguales.

## Radix sort
De manera intuitiva uno pensaría en ordenar número utilizando su dígito *más significativo*, este método lo hace de manera contraintuitiva. Ordena primero los dígitos *menos significativos*, vuelve a ordenar pero ahora utiliza los segundos dígitos menos significativos.

Para que este método funcione el ordenamiento debe ser estable. Se asume que cada elemento en el array $A$ tiene el mismo número de digitos.

```
radix-sort(A, d)
    for i = 1 to d
        use stable sort to sort Array A on digit i.
```

## Bucket sort
Este método asume que las entradas tienen una distribución uniforme. Tiene un tiempo de ejecución $O(n)$. La entrada está en el intervalo $[0, 1)$. Por ello este algoritmo divide dicho intervalo en n-subintervalos del mismo tamaño (buckets) para distribuir los $n$ números de entrada en ella.

Se asume también que la entrada es un array $A$ con n-elementos y que cada elemento $A[i]$ cumple: $0 \leq A[i] \lt 1$. Se hace uso de un array $B[0...n-1]$ de listas enlazadas.

```
bucket-sort(A)
    let B[0...n-1] be a new array
    n = A.length
    for i = 0 to n -1
        make B[i] an empty list
    for i = 1 to n
        insert A[i] into list B[n*A[i]]
    for i = 0 to n - 1
        sort list B[i] with insertion sort
    Concatenate the lists B[0], ..., B[n-1] together in order.
```
