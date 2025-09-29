# Augmenting data structures

## Estadísticas de orden dinámicas
Un *red-black tree* se puede modificar para determinar cualquier estadística de orden dinámica en un tiempo $O(lg(n))$.

Un *order-statistics tree* (árbol de estadísticas de orden) $T$ es un *red-black tree* con información adicional almacenada en cada nodo. Ahora cuenta con el atributo $size$, este atributo contiene el tamaño del subárbol y está dado por: $x.size = x.left.size + x.right.size + 1$.

Si dos elementos son iguales su ordenamiento está dado por la posición que toman en un recorrido *inorder*.

## Obteniendo un elemento dado un "rank"
El procedimiento `os-select(x, i)` retorna un apuntador al nodo que tiene la clave $i$-ésima más pequeña en el subárbol $x$.

```
os-select(x, i)
    r = x.left.size + 1
    if i == r
        return x
    else if i < r
        return os-select(x.left, i)
    else
        return os-select(x.right, i - r)
```

Lo primero que se hace es obtener el "rank" del nodo en el subárbol $x$, $x.left.size$ es el número de nodos que "vienen antes" en un recorrido *inorder*, por ello $x.left.size + 1$ es el "rank" del nodo $x$. Si $i$ es igual a $r$ entonces el nodo $x$ es el $i$-ésimo más pequeño y se retorna $x$. Si $i$ es más pequeño que $r$ el resultado está en el subárbol izquierdo de $x$. Caso contrario la respuesta está en el subárbol derecho. Como se mencionó antes $r$ elementos aparecen antes que $x$, por lo que el $i$-ésimo elemento mas pequeño en $x.right$ es el $(i - r)$-ésimo en el subárbol derecho.

*Suponiendo un árbol de tamaño 26, con 12 elementos a la izquierda y 13 a la derecha. Si buscamos el elemento 17 más pequeño ese sería el cuarto elemento más pequeño en el subárbol derecho porque:* $(i - r) \to (17 - 13)$.

## Determinando el "rank" de un elemento
Dado un apuntador a un nodo $x$ en un árbol de orden estadístico $T$, el procedimiento `os-rank` retorna la posición de $x$ en el orden lineal determinado por un recorrido *inorder*.

```
os-rank(T, x)
    r = x.left.size + 1
    y = x 
    while y != T.nil
        if y == y.p.right
            r = r + y.p.left + 1
        y = y.p
    return r
```

Reiterando, se puede ver al "rank" como el número de nodos que preceden a $x$ más uno. Este prodecimiento cuenta con invariantes de ciclo:
1. Antes de iterar, $r$ es el "rank" de $x$.
2. Al finalizar cada iteración $y$ ahora es $y.p$, es decir, con cada iteración se considera ahora la raíz del subárbol a $y.p$. Si el nodo $y$ es el hijo derecho de su padre debemos considerar nodos que preceden (del subárbol izquierdo), de ser hijo izquierdo no existen nodos que preceden.
3. El ciclo termina con $y = T.nil$, entonces $y$ es "todo el árbol", por ello el valor de $r$ es el "rank" del nodo en todo el árbol.

Cada iteración toma $O(1)$ y éstas se repiten de acuerdo a la altura del árbol, que está dada por $O(lg(n))$, por lo que el procedimiento toma $O(lg(n))$.

## Manteniendo al atributo size
Con los procedimientos ateriores se puede obtener información del orden estadístico pero debemos también poder mantener este atributo después de insertar o eliminar un nodo en el árbol y lograr esto sin afectar el tiempo de ejecución de dichos procedimientos.

Sabemos que la inserción se hace en dos partes:
1. Descender por el árbol para insertar el nodo en el lugar correcto. El nuevo nodo debe tener su atributo $size = 1$. Al insertar se recorren $O(lg(n))$ nodos.
2. Se hacen cambios estructurales mediante rotaciones, que a lo más son dos. Una rotación es una operación local, solo dos nodos tendrán su atributo $size$ invalidado. Se deben actualizar y esto toma O(1).

Con esto vemos que el tiempo de inserción se sigue manteniendo en $O(lg(n))$ como si de un *red-black tree* se tratara.

También sabemos que la eliminación ocurren en dos partes:
1. Se remueve el nodo $y$ del árbol o solo se mueve dentro del árbol.
2. Se realizan a lo más tres rotaciones, cada una en un tiempo constante O(1). Y para actualizar los atributos $size$ se decrementa dicho atributo desde el nodo $y$ hasta la raíz. El camino recorrido tiene longitud $O(lg(n))$.

Por lo que al igual que la inserción el tiempo de eliminación sigue siendo $O(lg(n))$.

## Cómo "aumentar" estructuras de datos
Se agregan funcionalidades adicionales a la estructura de datos base. Se puede ver como un proceso de cuatro pasos:
1. Elegir una estructura de datos subyacente.
2. Determinar la información adicional a agregar en la estrucutura de datos elegida.
3. Verificar que se le pueda dar mantenimiento a dicha información adicional.
4. Implementar nuevas operaciones.

## Árboles de intervalo (interval trees)
Un intervalo cerrado es un par ordenado de números reales $[t_1, t_2]$ con $t_1 \leq t_2$. Representa al conjunto: $\{ t \in \R : t_1 \leq t \leq t_2\}$. Los intervalos abiertos o semi-abiertos omiten uno o ambos extremos del conjunto. Los intervalos en esta implementación son cerrados. Podemos representar un intervalo $[t_1, t_2]$ como un objeto $i$, con atributos: $i.low = t_1$ (el extremo inferior del intervalo) y $i.high = t_2$ (el extremo superior del intervalo). Se dice que un intervalo $i$ se suporpone a un intervalo $i'$ si: $i \cap i' \not= \empty$, esto es, $i.low \leq i'.high$ y $i'low \leq i.high$.

Un *interval-tree* es un *red-black tree* que posee un conjunto dinámico de elementos, donde cada elemento contiene un intervalo $x.int$. Este tipo de árboles llevan a cabo las siguientes operaciones: `insert`, `delete`, `search`.

Si damos seguimiento a los pasos descritos anteriormente:
1. Elegimos a los *red-black trees* como nuestra estructura de datos base. Cada nodo contiene un intervalo $x.int$ y la clave que posee el nodo $x$ es el extremo inferior $x.int.low$. Entonces un recorrido *inorder* dejará a los intervalos ordenados por su extremo inferior.
2. Además de los intervalos cada nodo contiene un atributo $x.max$ que es el valor máximo de los extremos superiores del subárbol con raíz en el nodo $x$.
3. Debemos verificar que insertar y eliminar tome $O(lg(n))$ en un *interval-tree* de $n$-nodos. Y esto lo hace, puesto que actualizar el atributo $max$ después de una rotación toma $O(1)$. Podemos determinar $x.max$ dado un $x.int$ y los valores $max$ de los hijos del nodo $x$ con: $x.max = max(x.int.high, x.left.max, x.right.max)$.
4. Requerimos que la operación `interval-search(T, i)` que encuentra un nodo en el árbol $T$ cuyo intervalo se superpone a $i$. Si no existe tal intervalo se retorna el valor sentinela $T.nil$.

```
interval-search(T, i)
    x = T.root
    while x != T.nil and i does not overlap x.int
        if x.left != T.nil and x.left.max >= i.low
            x = x.left
        else
            x = x.right
    return x
```

La búsqueda para el intervalo que se superponga a $i$ inicia con $x$ en la raíz del árbol, después se desciende por el árbol. Termina cuando el intervalo se encuentra o $x$ es el valor sentinela $T.nil$.

Cada iteración toma $O(1)$ y éstas se repiten $O(lg(n))$ veces, puesto que depende de la altura del árbol. Este procedimiento toma $O(lg(n))$.
