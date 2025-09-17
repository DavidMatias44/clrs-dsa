# Heapsort

## Heap
Heap o binary heap es una estructura de datos de tipo array que puede ser vista como un árbol binario casi completo. Donde cada elemento del array corresponde a un nodo del árbol.

Aunque el array tenga longitud $A.length$, los elementos válidos del heap están dados por $A.heap-size$ donde: $ 0 \leq A.heap-size \leq A.length$.

La raíz del árbol es $A[1]$ y dado el índice $i$ se puede calcular el índice de su padre, así como el de sus hijos:

```
parent(i)
    return i / 2
```

```
left(i)
    return 2i
```

```
right(i)
    return 2i + 1
```

Existen dos tipos de heaps:
1. **max-heap**, se cumple la **max-heap-property** que dice que para cada nodo $i$ que no es la raíz: $A[parent(i)] \geq A[i]$.
*El valor de un nodo es a lo más el valor de su padre, entonces, el valor máximo en el heap está en la raíz.*

2. **min-heap**, se organiza de la manera opuesta, la **min-heap-property** dice que para cada nodo $i$ diferente a la raíz: $A[parent(i)] \leq A[i]$.
*Entonces el elemento más pequeño está en la raíz.*

Para mantener la propiedad **max-heap** se llama al procedimiento `max-heapify` que recibe un array $A$ y un índice $i$, permite que el valor $A[i]$ encuentre su lugar para que la propiedad **max-heap** siga cumpliéndose.

```
max-heapify(A, i)
    l = left(i)
    r = right(i)

    if l <= A.heap-size and A[l] > A[i]
        largest = l
    else
        largest = i
    if r <= A.heap-size and A[r] > A[largest]
        largest = r
    
    if largest != i
        exchange A[i] with A[largest]
        max-heapify(A, largest)
```
*Se quiere saber cuál es el elemento más grande entre $A[i]$, $A[left(i)]$ y $A[right(i)]$*.

Si $A[i]$ es más grande que sus hijos entonces se cumple la propiedad **max-heap**. En caso contrario, uno de los hijos es el más grande, por ello $A[i]$ se intercambia con $A[largest]$, lo que puede generar que este "sub-árbol" no cumpla la propiedad **max-heap**, razón por la cual se hace la llamada recursiva.

Se puede utilizar este procedimiento para convertir un array $A[1...n]$, donde: $n = A.length$ en un **max-heap**:
```
build-max-heap(A)
    A.heap-size = A.length
    for i = A.length/2 downto 1
        max-heapify(A, i)
```
Se considera a los elementos $A[(n/2)+1...n]$ como hojas del árbol, el procedimiento `build-max-heap` recorre los nodos restantes del árbol aplicando `max-heapify`.

## El algoritmo heapsort
Primero utilizamos el procedimiento `build-max-heap` para la entrada $A[1...n]$, donde: $n = A.length$. Sabemos que el elemento más grande está en $A[1]$ (la raíz) y se intercambia con el elemento $A[n]$ con esto colocamos al elemento más grande donde corresponde. Decrementamos $A.heap-size$ puesto que un elemento ya fue ordenado. Ahora la nueva raíz no cumple la propiedad **max-heap** por ello se llama a `max-heapify`.
```
heapsort(A)
    build-max-heap(A)
    for i = A.length downto 2
        exchange A[1] with A[i]
        A.heap-size = A.heap-size - 1
        max-heapify(A, 1)
```

## Colas de prioridad
Una cola de prioridad es una estructura de datos que contiene un conjunto $S$ de elementos cada uno asociado a un valor **key**.

Tiene las siguientes operaciones: *insert*, *maximum*, *extract-maximum* y *increase-key*, o bien *minimum*, *extract-minimum* y *decrease-key*.

Se puede utilizar un heap como cola de prioridad, éstas pueden ser de prioridad máxima o prioridad mínima.

```
heap-maximum(A)
    return A[1]
```

```
heap-extract-maximum(A)
    if A.heap-size < 1
        error "heap underflow"
    
    max = A[1]
    A[1] = A[A.heap-size]
    A.heap-size = A.heap-size - 1
    max-heapify(A, 1)

    return max
```

```
heap-increase-key(A, i, key)
    if key < A[i]
        error "new key is smaller than current key"

    A[i] = key
    while i > 1 and A[parent(i)] < A[i]
        exchange A[i] with A[parent(i)]
        i = parent(i)
```

```
max-heap-insert(A, key)
    A.heap-size = A.heap-size + 1
    A[A.heap-size] = -infinity
    heap-increase-key(A, A.heap-size, key)
```

Un heap puede llevar a cabo cualquier operación de una cola de prioridad de un conjunto de $n$ elementos en $O(lg(n))$.