# Red-Black Trees

Un *red-black tree* es un binary search tree con un atributo más: color. Este color puede ser rojo o negro, de ahí el nombre de esta estructura de datos. 

Restringiendo el color de los nodos en cada uno de los caminos desde la raíz hasta alguna hoja se asegura que ningún camino es dos veces más grande que otro, por lo tanto se dice que la altura de este árbol está *aproximadamente balanceada*.

Los *red-black trees* satisfacen las siguientes propiedades:
1. Cada nodo es negro o rojo.
2. La raíz es negra.
3. Cada hoja es negra.
4. Si un nodo es rojo, sus hijos deben ser negros.
5. Para cada nodo, todos los caminos desde dicho nodo a sus hojas debe tener el mismo número de nodos negros.

Para esta estructura se utiliza un valor sentinela (un nuevo atributo del árbol) para representar $NIL$, entonces todos los apuntadores a $NIL$ son reemplazados por $T.nil$, $T.nil$ se trata como otro hijo.

Dado un nodo $x$, el número de nodos negros desde este nodo hasta alguna hoja se cuentan sin tomar en cuenta a $x$ y se denota por $black-heght$, $bh(x)$.

## Rotaciones
Las operaciones de inserción y eliminación en estos árboles toman $O(lg(n))$ y puesto que modifican al árbol puede llegar a violarse alguna de las propiedades *red-black tree*.

En una rotación se cambia la estructura de los apuntadores. Existen dos tipos de rotaciones: hacia la derecha y hacia la izquierda. Cuando se hace una rotación hacia la izquierda alrededor de un nodo $x$ se asume que su hijo derecho $y$ es diferente a $T.nil$, puesto que la rotación a la izquierda "pivotea" alrededor del enlace de $x$ con $y$, convierte a $y$ en la raíz del subárbol, con $x$ como el hijo izquierdo y el hijo izquierdo de $y$ ahora como el hijo derecho de $x$.

El pseudocódigo `left-rotate` asume que $x.right \not= nil$ y que el padre de la raíz es $T.nil$:

```
left-rotate(T, x)
    y = x.right
    x.right = y.left
    if y.left != T.nil
        y.left.p = x
    
    y.p = x.p
    if x.p == T.nil
        T.root = y
    else if x == x.p.left
        x.p.left = y
    else
        x.p.right = y
    
    y.left = x
    x.p = y
```

El procedimiento `right-rotate` es simétrico a `left-rotate` y ambos se ejecutan en $O(1)$.

## Insertion
Se puede insertar un nuevo nodo en un árbol de $n$-nodos en $O(lg(n))$. Para lograrlo se inserta el nodo $z$ en el árbol $T$ como si de un *binary search tree* se tratara, pero ahora se pinta al nodo de rojo y para asegurar que las propiedades *red-black* se cumplen se utiliza al procedimiento `rb-insert-fixup` para recolorear nodos y hacer las rotaciones pertinentes.

```
rb-insert(T, z)
    y = T.nil
    x = T.root
    while x != T.nil
        y = x
        if z.key < x.key
            x = x.left
        else
            x = x.right
    
    z.p = y
    if y == T.nil
        T.root = z
    else if z.key < y.key
        y.left = z
    else
        y.right = z
    
    z.left = T.nil
    z.right = T.nil
    z.color = RED

    rb-insert-fixup(T, z)
```

Existen cuatro diferencias entre el `insert` "normal" y el `insert` para un *red-black* tree:
1. Toda instancia de $NIL$ es cambiada por $T.nil$.
2. Se asigna $T.nil$ a los hijos del nodo $z$.
3. Se colorea a $z$ de rojo.
4. La acción anterior puede violar alguna de las propiedades *red-black* y por ello se llama al procedimiento `rb-insert-fixup`.

```
rb-insert-fixup(T, z)
    while z.p.color == RED
        if z.p == z.p.p.left
            y = z.p.p.right

            if y.color == RED
                z.p.color = BLACK
                y.color = BLACK
                z.p.p.color = RED
                z = z.p.p
            else 
                if z == z.p.right
                    z = z.p
                    left-rotate(T, z)

                z.p.color = BLACK
                z.p.p.color = RED
                right-rotate(T, z)
        else 
            (same as then clause with "right" and "left" exchanged)
    
    T.root.color = BLACK
```

Este procedimiento se puede dividir en tres secciones:
1. **Determinar qué violaciones se generaron al insertar el nodo $z$ y pintarlo de rojo.**
Las únicas propiedades que son violadas son la propiedad 2 (la raíz debe ser negra) y la propiedad 4 (no puede haber dos nodos rojos contiguos).

2. **Cuál es el propśito del *while*.**
En el ciclo *while* se utiliza una invariante de ciclo de tres partes:
    1. El nodo $z$ es rojo.
    2. Si $z.p$ es la raíz entonces $z.p$ es negro.
    3. Si el árbol viola alguna de las propiedades entonces viola a lo más una.

3. **Explorar cada caso de los tres casos posibles.**
Se consideran seis casos pero al ser simétricos se reducen a solo tres.
    **Caso 1. El tío de z es rojo.** Se sabe que el abuelo del nodo $z$ es negro, por ello se colorea al padre de $z$ y al tío de $z$ de color negro. Su abuelo se pinta de rojo. Una vez hecho esto hacemos que $z$ apunte a su abuelo, es decir, "avanzó dos niveles" en el árbol.
    **Caso 2. El tío de z es negro y z es hijo derecho** y 
    **Caso 3. El tío de z es negro y z es hijo izquierdo.** Cuando ocurren el caso 2 una rotación a la izquierda es el paso previo, de esta manera se transforma en el caso 3, para el cual se realizan recoloreos y una rotación a la derecha. Después de aplicar estas acciones, $z.p$ ahora es negro logrando la terminación del ciclo *while*.

El tiempo de ejecución de `rb-insert` depende de la altura del árbol, que es a lo más $lg(n)$ por lo que su tiempo de ejecución es $O(lg(n))$. En este procedimiento el ciclo *while* se repite si ocurre el caso 1, una vez en el caso 2 ó 3 el ciclo termina.
