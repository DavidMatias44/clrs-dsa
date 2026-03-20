# Elementary graphs algorithms

## Representaciones de grafos

Los grafos $G=(V, E)$ se pueden representar de dos maneras:
1. **Listas de adyacencia**. A menudo utilizada para representar grafos escasos, para los cuales $|E|$ es mucho menor que $|V|^2$. Esta representación consiste en un array nombrado $Adj$ de $|V|$ listas, una lista para cada vértice. Para cada $u \in V$ el elemento $Adj[u]$ contiene todos los vértices V de tal manera que hay una arista $(u, v) \in E$, es decir, $Adj[u]$ consiste de todos los vértices adyacentes a $u$ en el grafo. Si trabajamos con un grafo dirigido la suma de tamaño de las listas de adyacencia es igual a $|E|$, en cambio si es no dirigido la suma es igual a $2|E|$ puesto que en la lista de adyacencia de $u$ aparece $v$ y viceversa. Estas listas se pueden adaptar para poder representar grafos ponderados, grafos donde cada arista tiene un peso asociado, inicialmente el peso es dado por una función peso $w : E \to \R$. Entonces simplemente almacenaríamos el peso $w(u, v)$ de la arista $(u, v) \in E$ en la lista de adyacencia de $u$. La gran desventaja que tiene esta representación es que no hay una manera más rápida de determinar si una arista $(u, v)$ está en el grafo que no sea buscar a $v$ en $Adj[u]$. La cantidad de memoria requerida es de $\Theta(V + E)$.

2. **Matriz de adyacencia**. Usada para representar grafos densos, en los que $|E|$ es cercano a $|V|^2$ o cuando se quiere saber si una arista conecta dos vértices dados. En esta representación se asume que los vértices están numerados del $1, 2, \dots, |V|$ de alguna manera arbitraria. Entonces la representación consiste en una matriz de tamaño $|V| \times |V|$ y con $A = (a_{ij})$, tal que: $a_{ij} = \begin{cases} 1 & \text{si } (i, j) \in E \\ 0 & \text{caso contrario} \end{cases}$. Se requiere $\Theta(V^2)$ de memoria, y ésta es independiente del número de aristas en el grafo. Debido a que en un grafo no dirigido $(u, v)$ y $(v, u)$ representan la misma arista la matriz de adyacencia es igual a su traspuesta, $A = A^T$. Un grafo ponderado puede ser representado con una matriz de adyacencia, por ejemplo, para un grafo $G = (V, E)$ con una función de peso $w$, almacenamos el peso $w(u, v)$ de la arista $(u, v) \in E$ como la entrada en la columna $v$ y renglón $u$. Si una arista no existe se puede almacenar $NIL$, $0$ ó $\infty$. Aunque utilicen más memoria son más simples y deben ser la elección cuando los grafos son razonablemente pequeños.

## Breadth First Search (BFS)

Es uno de los algoritmos más simples para búsqueda en un grafo. Dado un grafo $G = (V, E)$ y un vértice *source* (origen) $s$, BFS explora sistemáticamente las aristas de $G$ para descubrir cada vértice que es alcanzable desde $s$. Se calcula la distancia (número más pequeño de artistas) desde $s$ hasta el vértice alcanzable. También produce el ***breadth first tree*** (BFT) con $s$ siendo la raíz. Para cada vértice $v$ alcanzable desde $s$ el camino simple en el BFS desde $s$ hasta $v$ es el camino más corto (shortest path). Este algoritmo funciona para grafos dirigidos y no dirigidos.

Se le conoce como ***breadth first search*** (búsqueda primero por amplitud) porque expande la frontera entre los nodos no descubiertos y los descubiertos de manera uniforme. Esto significa que el algoritmo descubre todos los vértices a una distancia $k$ desde $s$ antes de descubrir los vértices que están a una distancia $k + 1$.

Para poder dar seguimiento al progreso, BFS colorea cada nodo de blanco, gris o negro. Todos los nodos comienzan siendo blancos, después se colorean o bien de negro o gris. Se dice que un vértice es **descubierto** cuando nos topamos con él en la búsqueda y se vuelve *no blanco*. Por lo tanto los nodos grises y negros son nodos descubiertos. El algortimos hace distinción entre ellos (descubiertos y no descubiertos) para asegurar que el proceso de búsqueda sea de tipo **primero en amplitud**. Si $(u, v) \in E$ y el vértice $u$ es negro entonces $v$ es gris o negro, esto es, todos los vértices adyacentes a vértices negros han sido descubiertos, los vértices grises tiene vértices adyacentes blancos y representan la frontera entre los vértices descubiertos y no descubiertos.

La construcción del BFT empieza con la raíz $s$, cuando se descubre un vértice blanco $v$ en el proceso en el que se escanea la lista de adyacencia de un nodo ya descubierto, en este caso denotado por $u$ se agrega el vértice $v$ y la arista $(u, v)$ al árbol. Decimos entonces que $u$ es el predecesor o padre de $v$ y como el nodo es descubierto una vez, tiene un padre.

El procedimiento BFS asume que se utiliza una lista de adyacencia para representar el grafo y añade el atributo $color$ a cada vértice del grafo. También se añade el atributo $p$ para representar el predecesor y el atributo $d$ para representar la distancia desde $s$ hasta $u$, se utiliza una cola para manejar el conjunto de nodos grises.

```
BFS(G, s)
    for each vertex u in G.V - { s }
        u.color = WHITE
        u.d = infinity
        u.p = NIL
    
    s.color = GRAY
    s.d = 0
    s.p = NIL
    Q = empty set

    while q != empty set
        u = DEQUEUE(Q)
        
        for each v in G.Adj[u]
            if v.color == WHITE
                v.color = GRAY
                v.d = u.d + 1
                v.p = u
                ENQUEUE(Q, v)
        u.color = BLACK
```

Cada vértice excepto $s$ se pinta de blanco, se le asigna $\infty$ a su distancia a $s$ y a su padre se le asigna $NIL$. El vértice $s$ es pintado de gris cuando se *descubre*, su distancia se vuelve $0$ y su padre sigue siendo $NIL$. Después se inicializa la cola con solo el vértice $s$. El ciclo *while* itera por los vértices grises, los cuales no tienen sus listas de adyacencia completamente exploradas, la cabeza de la cola se asigna a $u$.

El ciclo *for* considera cada vértice $v$ de la lista de adyacencia del vértice $u$, si el vértice es blanco se pinta de gris, su atributo distancia $v.d$ ahora es $u.d + 1$, su padre $v.p$ se vuelve $u$ y se añade al final de la cola. Cuando se itera por cada uno de los vértices adyacentes de $u$ se pinta de negro.

Las operaciones de la cola son de tiempo constante $O(1)$ y se llevan a cabo $|V|$ veces, entonces el total es $O(V)$ y debido a que se escanean las listas de adyacencia solo cuando el vértices es sacado de la cola, la lista es escaneada a lo más una vez, esto toma un tiempo $O(E)$, la inicialización que se hace al comienzo del procedimiento toma $O(V)$, por lo que el tiempo total de ejecución es $O(V) + O(E) + O(V) \to O(V + E)$.

## Depth First Search (DFS)

Como el nombre lo sugiere la estrategia que sigue este algoritmo es buscar **más profundo** siempre que sea posible. Se exploran las aristas del vértice recién descubierto $v$ mientras aún tenga aristas sin explorar. Una vez que todas las aristas de $v$ han sido exploradas la búsquda ***backtracks*** (retrocede) y regresa al vértice padre (aquel vértice que lo descubrió) para verificar si hay aristas sin explorar, si las tiene siguen la búsqueda, en caso contrario sigue retrocediendo (hace *backtracking*). El proceso finaliza cuando todos los vértices que son alcanzables desde $s$ son descubiertos.

Al igual que BFS, cuando DFS descubre un vértice $v$ durante el escaneo de una lista de adyacencia de un vértice $u$ ya descubierto lo guarda colocando al predecesor de $v$, $v.p$ como $u$. BFS produce un sólo árbol mientras que el DFS genera múltiples árboles. En este proceso también se colorean los vértices para indicar su estado, esta técnica garantiza que cada vértice termina exactamente en un DFT, haciendo a estos árboles disjuntos (no tienen vértices en común).

