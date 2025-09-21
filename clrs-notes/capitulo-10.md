# Elementary data structures

## Colas y pilas (stacks and queues)
Son conjuntos dinámicos, sus operaciones de inserción y eliminación de elementons están pre-especificadas.

En una **pila** el elemento borrado es el más reciente en ser insertado. Sigue la política **LIFO** (*last-in, first-out*). En cambio, en una **cola** se borra el elemento que más tiempo lleva insertado, sigue una política **FIFO** (*first-in, first-out*).

En una **pila** a la función de inserción se le conoce como `push`, y a la de eliminación como `pop`. Una pila puede ser representada como un array $S[1..n]$ con un atributo $S.top$ que indexa el elemento más reciente en ser insertado. Una pila por lo tanto consiste en los elementos $S[1...S.top]$ donde $S[1]$ es el "fondo" y $S[S.top]$ es el tope. El tope es igual a cero si la pila está vacía.

```
stack-empty(S)
    if S.top == 0
        return TRUE
    else
        return FALSE
```

```
push(S, x)
    S.top = S.top + 1
    S[S.top] = x
```

```
pop(S)
    if stack-empty(S)
        error "Stack underflow"
    else
        S.top = S.top - 1
        return S[S.top + 1]
```

Estas tres operaciones toman un tiempo constante en ser ejecutadas: $O(1)$.

A la operación de insertar en una cola se le conoce como `enqueue` y a la de eliminar `dequeue`. Las colas tienen un atributo `head` y un atributo `tail`. Cuando un nuevo elemento es insertado se coloca en la cola (tail), cuando uno es eliminado es el elemento de la cabeza (head). Cuando la cabeza y la cola están en el mismo lugar significa que la cola está vacía. Si la cabeza es igual a la `cola + 1`, entonces la cola está llena.

```
enqueue(Q, x)
    Q[Q.tail] = x
    if Q.tail == Q.length
        Q.tail = 1
    else
        Q.tail = Q.tail + 1
```

```
dequeue(Q)
    x = Q[Q.head]
    if Q.head == Q.length
        Q.head = 1
    else
        Q.head = Q.head + 1
    return x
```

Cada una de estas operaciones consume un tiempo constante $O(1)$.

## Listas ligadas (linked lists)
Es una estructura en la que sus elementos están colocados de manera lineal, cada elemento apunta al siguiente.

En una lista doblemente enlazada, tenemos que cada nodo posee un atributo $key$, uno $prev$ y uno $next$. Dado un elemento $x$, $x.next$ apunta a su sucesor en la lista y $x.prev$ apunta a su predecesor. Si $x.prev == NIL$ significa que el elemento es el primero de la lista (cabeza, *head* de la lista). Y si $x.next == NIL$, significa que el elemento es el último de la lista (cola, *tail* de la lista).

Existen también las listas ligadas simples (no cuenta con el atributo $prev$) y las listas circulares (donde la cola apunta a la cabeza y viceversa).

Para hallar un elemento en una lista enlazada con clave $key$ se hace una búsqueda lineal simple.

```
list-search(L, k)
    x = L.head
    while x != NIL and x.key != k
        x = x.next
    return x
```

En el peor de los casos este algoritmo tiene un tiempo $O(n)$. 

Dado un elemento $x$ que ya posee su atributo $key$, se inserta al inicio de la lista.

```
list-insert(L, x)
    x.next = L.head
    if L.head != NIL
        L.head.prev = x
    L.head = x
    x.prev = NIL
```

El tiempo para insertar en una lista ligada es constante $O(1)$.

Para eliminar un elemento $x$ de una lista ligada $L$ se debe contar con un apuntador a $x$, para simplemente "empalmar" los apuntadores correspondientes. Si se quiere eliminar un elemento dada una clave primero se tien que llamar a `list-search`.

```
list-delete(L, x)
    if x.prev != NIL
        x.prev.next = x.next
    else
        L.head = x.next
    if x.next != NIL
        x.next.prev = x.prev
```

## Implementando apuntadores y objetos
Es común utilizar múltiples arreglos para representar una lista ligada. Donde $x$ es un índice en común para los arreglos: $key$, $prev$ y $next$.

Aprovechando que en memoria los objetos se almacenan de manera contigua, utilizar *offsets* para poder accesar a $prev$, $next$ y $key$.

## Árboles binarios (binary trees)
Cada nodo del árbol está representado por un objeto, cada nodo contiene un atributo $key$, los restantes son apuntadores a otros nodos, estos apuntadores son los atributos $p$, $left$ y $right$.

Si $x.p == NIL$ entonces $x$ es la raíz (*root*). Si el nodo $x$ no tiene hijo izquierdo, entonces $x.left == NIL$, caso similar cuando no tiene hijo derecho. La raíz del árbol está siendo apuntada por $T.root$, si $T.root == NIL$ entonces el árbol está vacío.

Se puede extender este esquema para poder representar cualquier clase de árboles en el cual el número de hijos está dado por una constante $k$. Existe una representación que utiliza solo $O(n)$ en espacio para cualquier árbol con $n$-nodos, se le conoce como representación ***left-child, right-sibling***, cada nodo cuenta con dos apuntadores:
1. ***$x.left-child$*** apunta al hijo de más a la izquierda de $x$.
2. ***$x.right-sibling$*** apunta al hermano inmediato de $x$ en la derecha.
