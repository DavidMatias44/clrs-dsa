# Binary search trees

## Binary search tree
Organizado en un árbol binario, cada nodo es un objeto que además de su $key$ y *satellite-data* contiene los atributos: $left$, $right$ y $p$. Que apuntan a su hijo izquierdo, hijo derecho y padre respectivamente. Si no hay hijos o padre el valor que poseen es $NIL$.

Las claves en un binary search tree están almacenadas de tal manera que se satisface la propiedad *binary-search-tree*: Sea un nodo $x$ en un binary search tree. Si $y$ es un nodo en la izquierda de $x$, entonces $y.key \leq x.key$. Si $y$ es un nodo en la derecha, entonces $y.key \geq x.key$.

Esta propiedad permite imprimir las claves de un binary search tree de forma ordenada aplicando `inorder-tree-walk`, este método primero imprime el nodo de la izquierda, después la raíz del subárbol y finalmente el nodo de la derecha. De manera similar existe el *preorder-tree-walk* y *postorder-tree-walk*.

```
inorder-tree-walk
    if x != NIL
        inorder-tree-walk(x.left)
        print x.key
        inorder-tree-walk(x.right)
```

Para un árbol binario con $n$-nodos este algoritmo toma $\Theta(n)$.

## Consultando un binary search tree
Además de la operación *search* un binary search tree ofrece consultas como: `minimum`, `maximum`, `successor`.

Para la búsqueda se utiliza un procedimiento que recibe un apuntador a la raíz del árbol y una clave $k$ a buscar:

```
tree-search(x, k)
    if x == NIL or k == x.key
        return x
    if k < x.key
        return tree-search(x.left, k)
    else
        return tree-search(x.right, k)
```

## Minimum y maximum
Se puede hallar el elemento mínimo de un binary search tree siempre siguiendo a los apuntadores de la izquierda y parar cuando nos encontremos con NIL:

```
tree-minimum(x)
    while x.left != NIL
        x = x.left
    return x
```

Para hallar el máximo se sigue la misma idea pero para la derecha:

```
tree-maximum(x)
    while x.right != NIL
        x = x.right
    return x
```

## Successor
Dado un nodo en un binary search tree, algunas veces se quiere encontrar su sucesor determinado por *inorder tree walk*. Si todas las claves son distintas el sucesor de un nodo $x$ es la clave mínima más grande que $x.key$.

```
tree-successor(x)
    if x.right != NIL
        return tree-minimum(x.right)
    y = x.p
    while y != NIL and x == y.right
        x = y
        y = y.p
    return y
```

Este procedimiento se puede dividir en dos casos:
1. Si el subárbol de la derecha no está vacío entonces el sucesor de $x$ es el nodo de más a la izquierda del subárbol de la derecha.
2. Si el subárbol de la derecha está vacío, se avanza "hacia arriba" en el árbol, hasta hallar a un "padre" que sea sucesor, si es que lo hay.

Estos métodos dependen de la altura del árbol, por lo que el tiempo es $\Theta(h)$.

## Insertion and deletion
Estas operaciones generan cambios en un binary search tree, el árbol debe adaptarse para poder seguir cumpliendo con la propiedad de esta estructura de datos.

### Insertion
Para insertar un nuevo valor $v$ en un binary seach tree $T$ se crea un nuevo nodo $z$, donde: $z.key=v$, $z.left = NIL$ y $z.right = NIL$. El nodo $z$ debe ser insertado en la posición correcta en el árbol.

```
tree-insert(T, z)
    y = NIL
    x = T.root
    while x != NIL
        y = x
        if z.key < x.key
            x = x.left
        else
            x = x.right

    z.p = y
    if y == NIL
        T.root = z
    else if z.key < y.key
        y.left = z
    else
        y.right = z
```

El proceso comienza en la raíz del árbol utilizando el apuntador $x$, $x$ desciende por el árbol buscando el valor $NIL$ para poder reemplazarlo por el nuevo nodo $z$. Se utiliza otro apuntador: $y$ para ir "un paso atrás", es decir, siempre apuntará al padre del nodo al que está apuntando $x$. Éstos apuntadores avanzan hacia la izquierda o derecha dependiendo de la comparación entre $z.key$ y $x.key$.

Este procedimiento se ejecuta en un tiempo $O(h)$ donde $h$ es la altura del árbol.

### Deletion
El procedimiento para eliminar un nodo $z$ de un binary search tree $T$ lista cuatro casos a considerar:
1. El nodo $z$ no cuenta con sus dos hijos: $z$ no tiene hijo izquierdo, entonces se reemplaza $z$ con su hijo derecho, éste puede ser igual a NIL.
2. El nodo $z$ no cuenta con sus dos hijos: $z$ solo tiene a su hijo izquierdo, entonces este hijo toma el lugar del nodo $z$.
3. El nodo $z$ cuenta con ambos hijos: se busca al sucesor del nodo $z$ denotado por $y$ y resulta ser hijo directo del nodo $z$, entonces solo intercambiamos al nodo $z$ por el nodo $y$.
4. El nodo $z$ cuenta con ambos hijos: se busca al sucesor del nodo $z$ denotado por $y$ y no es hijo directo del nodo $z$, es decir, está presente en el subárbol derecho, entonces primero se intercambia $y$ por su hijo derecho y posteriormente se intercambia al nodo $y$ por el nodo $z$.

Para poder "mover" subárboles dentro de un binary search tree se define la subrutina `transplant` la cual intercambia un subárbol con otro subárbol.

```
transplant(T, u, v)
    if u.p == NIL
        T.root = v
    else if u == u.p.left
        u.p.left = v
    else 
        u.p.right = v
    
    if v != NIL
        v.p = u.p
```

Primero se quiere determinar que $u$ sea la raíz del árbol (no tiene padre), después se determina si bien $u$ es el hijo izquiero o derecho para que $v$ sea apuntado por el padre de $u$, $v$ puede ser igual a $NIL$, pero en caso de que no lo sea se actualiza su padre para que sea igual al padre de $u$.

```
tree-delete(T, z)
    if z.left == NIL
        transplant(T, z, z.right)
    else if z.right == NIL
        transplant(t, z, z.left)
    else
        y = tree-minimum(z.right)
        if y.p != z
            transplant(T, y, y.right)
            y.right = z.right
            y.right.p = y
        transplant(T, z, y)
        y.left = z.left
        y.left.p = y
```

Las primeras dos comparaciones son para comprobar el caso donde el nodo a eliminar no tiene dos hijos, si los tiene se busca al sucesor, que es el mínimo en el subárbol derecho. Ahora solo se debe intercambiar $y$ con $z$, pero primero debemos comprobar que $y$ sea hijo directo de $z$, de no serlo se hace un intercambio previo.

Cada línea de esta función se ejecuta en tiempo constante, exceptuando la llamada a `tree-minimum` que provoca que el tiempo de ejecución de esta función pase a ser $O(h)$, donde $h$ es la altura del árbol.
