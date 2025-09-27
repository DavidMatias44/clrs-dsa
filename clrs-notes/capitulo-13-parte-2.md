# Red-Black Trees

## Deletion
Al igual que otras operaciones, eliminar de un árbol con $n$-nodos toma $O(lg(n))$. Y el procedimiento es más complicado que el de insertar.

Se modifica el procedimiento `transplant`:

```
rb-transplant(T, u, v)
    if u.p == T.nil
        T.root = v
    else if u == u.p.left
        u.p.left = v
    else
        u.p.right = v
    v.p = u.p
```

Las diferencias son:
1. Se coloca el sentinela $T.nil$ en lugar de $NIL$.
2. La asignación de $v.p$ ocurre incondicionalmente.

El procedimiento `rb-delete` contiene algunas líneas adicionales que ayudan a dar un seguimiento al nodo $y$ que puede causar violaciones a las propiedades *red-black*. Después de eliminar se llama a `rb-delete-fixup` que lleva a cabo cambios de color y rotaciones para restaurar estas propiedades.

```
rb-delete(T, z)
    y = z
    y-original-color = y.color

    if z.left == T.nil
        z = z.right
        rb-transplant(T, z, z.right)
    else if z.left == T.nil
        z = z.left
        rb-transplant(T, z, z.left)
    else
        y = tree-minimum(z.right)
        y-original-color = y.color
        x = y.right

        if y.p == z
            x.p = y
        else
            rb-transplant(T, y, y.right)
            y.right = z.right
            y.right.p = y
        
        rb-transplant(T, z, y)
        y.left = z.left
        y.left.p = y
        y.color = z.color

    if y-original-color == BLACK
        rb-delete-fixup(T, x)
```

Existen diferencias entre `rb-delete` y `tree-delete`, se mantiene a $y$ como el nodo a ser removido o movido dentro del árbol según sea el caso si el nodo tiene dos hijos o menos de dos hijos. Debido a que el color de $y$ puede cambiar se almacena el color original antes de cualquier cambio que se pueda hacer. El apuntador $x$ avanza por el árbol apuntando a alguno de los hijos de $y$, o bien, al valor sentinela $T.nil$ (en el caso de que no cuente con hijos).

Se quiere eliminar al nodo $z$, si éste tiene menos de dos hijos, solo toca reemplzar a $y$ con $z$, si en cambio, cuenta con sus dos hijos $y$ debe ser sucesor de $z$. Es importante conocer el color de $y$ antes de moverlo en el árbol. Tenemos a $x$ que apunta a la posición original de $y$, $x$ puede causar violaciones a las propiedades *red-black*.

```
rb-delete-fixup(T, x)
    while x != T.root and x.color == BLACK
        if x == x.p.left
            w = x.p.right

            if w.color == RED
                w.color = BLACK
                x.p.color = RED
                left-rotate(T, x.p)
                w = x.p.right
            
            if w.left.color == BLACK and w.right.color == BLACK
                w.color = RED
                x = x.p
            else 
                if w.right.color == BLACK
                    w.left.color = BLACK
                    w.color = RED
                    right-rotate(T, w)
                
                w.color = x.p.color
                x.p.color = BLACK
                w.right.color = BLACK
                left-rotate(T, x.p)
                x = T.root
        else
            (same as then clause with "right" and "left" exchanged)
    
    x.color = BLACK
```

Si el color original de $y$ era rojo no hubo ninguna violación a las propiedades *red-black* porque:
1. La $black-height$ no se modificó.
2. Dos nodos rojos no se han hecho adyacentes.

En cambio si el nodo era negro, surgen tres problemas:
1. La raíz pudo hacerse roja (violación de la propiedad 2).
2. Tanto $x$ como $x.p$ son rojos (violación de la propiedad 4).
3. Mover a $y$ en el árbol causa que algún camino cuente con menos nodos negros afectando a los ancestros de $y$, se viola por lo tanto la propiedad 5 (el número de nodos negros es el mismo para cada camino desde un nodo hasta las hojas). Se dice que el nodo $x$ que ahora ocupa el lugar de $y$ colabora como dos nodos negros a la $black-height$. Esto se puede ver como un estado temporal que tiene el nodo $x$ previo a realizar los arreglos pertinentes: el nodo puede ser ***doubly black***, es decir, el nodo es negro y por lo tanto suma dos nodos negros a la $black-height$ o es un nodo ***red-and-black***, donde el nodo es rojo pero suma como si fuera nodo negro a la $black-height$.

El procedimiento `rb-delete-fixup` restaura las propiedaes 1, 2 y 4. Lo que se busca hacer es mover el **nodo negro extra** hacia arriba en el árbol hasta que:
1. $x$ apunte a un nodo **red-and-black** en ese caso el nodo $x$ se pinta de negro.
2. $x$ apunte a la raíz, en ese caso el nodo solo se remueve, o bien,
3. Se llevan a cabo rotaciones y recoloreos que provocan la salida del ciclo *while*.

Dentro del procedimiento `rb-delete-fixup` primero se quiere saber si $x$ es el hijo de la izquierda o derecha, el nodo $w$ será su hermano. Se manejan cuatro casos:
**Caso 1. $w$ es rojo.** Si esto ocurre entonces $w$ debe tener un hijo negro, lo que tenemos que hacer es intercambiar los colores de $w$ y de $x.p$ y rotamos hacia la izquierda con $x.p$ como pivote. Con esto convertimos el caso 1 en el caso 2, 3 ó 4.
**Caso 2. $w$ es negro y sus dos hijos también son negros.** Quitamos un nodo negro del nodo $x$ y uno del nodo $w$, dejando a $x$ con solo un nodo negro y a $w$ siendo ahora de color rojo. El ciclo se repite pero ahora $x$ apunta a $x.p$, es decir, "pasamos" el nodo negro extra al padre de $x$.
**Caso 3. $w$ es negro, su hijo izquierdo es rojo y su hijo derecho es negro.** Debemos cambiar los colores de $w$ y de su hijo izquierdo para entonces llevar a cabo una rotación hacia la derecha sobre el nodo $w$. El nuevo nodo $w$ cuenta ahora con un hijo derecho de color rojo. Transformamos el caso 3 en el caso 4.
**Caso 4. $w$ es negro y su hijo derecho es rojo.** Llevando a cabo cambios de color y haciendo una rotación hacia la izquierda sobre el nodo $x.p$ se remueve el negro extra de $x$. Ahora $x$ apunta a la raíz del árbol y se puede terminar el ciclo.

Este prodecimiento toma $O(lg(n))$ y como es llamado por `rb-delete` cuyas acciones fuera del método `rb-delete-fixup` dependen de la altura del árbol, es decir, se repiten a lo más $lg(n)$, la complejidad final sigue siendo $O(lg(n))$.
