# Greedy algorithms

Toman la opción que se ve mejor en el momento, es decir, eligen un óptimo local con la esperanza de que éste los lleve a un óptimo global. No siempre producen soluciones óptimas.

## Un problema de *activity-selection*

Este problema consiste en organizar diversas actividades que requieren de un recurso en común. Tiene el objetivo de seleccionar el conjunto de mayor tamaño de actividades mutuamente compatibles.

Tenemos un conjunto $S=\{ a_1, a_2, ..., a_n \}$ de $n$ actividades propuestas que desean ocupar un recurso, el cual solo puede ser utilizado por una actividad a la vez. Cada actividad tiene un tiempo de inicio $s_i$ y un tiempo de finalización $f_i$, donde: $0 \leq s_i \leq f_i < \infty$. Si una actividad es seleccionada toma lugar en el tiempo dado por el intervalo $[s_i, f_i)$. Se dice que las actividades $a_i$ y $a_j$ son compatibles si los intervalos $[s_i, f_i)$ y $[s_j, f_j)$ no se suporponen, es decir, $s_i \geq f_j$ o $s_j \geq f_i$. Asumimos que las actividades están ordenadas de acuerdo a su tiempo de término de manera ascendente: $f_1 \leq f_2 \leq ... f_{n-1} \leq f_{n}$.

Por ejemplo:
|  i|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10| 11|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| si|  1|  3|  0|  5|  3|  5|  6|  8|  8|  2| 12|
| fi|  4|  5|  6|  7|  9|  9| 10| 11| 12| 14| 16|

Note como los subconjuntos: $\{ a_3, a_9, a_{11} \}$ y  $\{ a_1, a_4, a_8, a_{11} \}$ consisten de actividades compatibles. Y que el segundo subconjunto es más grande que el primero.

Debemos crear una solución ***greedy***.

### La subestructura óptima del problema *activity-selector*

Podemos verificar que este problema muestra una subestructura óptima. Si denotamos a $S_{ij}$ como el conjunto de actividades que empiezan después de que la actividad $a_i$ termine y que finalizan antes de que la actividad $a_j$ comience. Deseamos hallar el conjunto máximo de actividades compatibles en $S_{ij}$, suponiendo que dicho conjunto es $A_{ij}$ y que dicho conjunto incluye a una actividad $a_k$. Que la actividad $a_k$ esté presente nos deja con dos subproblemas:
1. Hallar las actividades compatibles en $S_{ik}$, es decir, aquellas actividades que comienzan después de que la actividad $a_i$ finalice y que terminen antes de que la actividad $a_k$ comience.
2. Hallar las actividades compatibles en $S_{kj}$, es decir, aquellas actividades que comienzan después de que la actividad $a_k$ finalice y que terminen antes de que la actividad $a_j$ comience.

Si denotamos el tamaño de una solución óptima para el conjunto $S_{ij}$ con $c[i, j]$, obtenemos una recurrencia: $c[i, j] = c[i, k] + c[k, j] + 1$. 

Si no sabemos si una solución óptima del conjunto $S_{ij}$ necesariamente incluye a la actividad $a_k$ entonces tendríamos que revisar todas las atividades para decidir cuál incluir, entonces reescribimos la recurrencia: $c[i, j] = \begin{cases} 0 & \text{si } S_{ij} = \empty \\ max_{a_k \in S_{ij}} c[i, k] + c[k, j] + 1 & \text{si } S_{ij} \not= \empty \end{cases} \\$

*Lo que se hace es considerar todas las posibles combinaciones de actividades*.

Se puede desarrollar un algoritmo y aplicar *memoization* (memorización). Pero hay otra característica que se puede usar a nuestro favor.

### Tomando la *greedy choice*

Lo que esto quiere decir es elegir la actividad que nos deje el recurso disponible para la mayor cantidad de actividades posible. Por ello elegimos la actividad en $S$ que cuente con el tiempo de finalización más temprano. Debido a que las actividades están ordenadas por tiempo de finalización la opción ***greedy*** es elegir a $a_1$.

Si tomamos la opción ***greedy*** solo nos queda un problema a resolver: hallar las actividades que empiecen después de que $a_1$ termine. Podríamos resolver este problema con *dynamic programming* pero no la necesitamos, en su lugar elegimos la actividad que termine primero, mantener las actividades compatibles y repetir hasta que no haya actividades disponibles. Esta solución funciona de forma *top-down*; se elige una actividad y se agrega a la solución óptima, después se resuelve el subproblema de elegir todas aquellas actividades que son compatibles.

### Un algoritmo *greedy* recursivo

En el procedimiento `recursive-activity-selector` se toman los tiempos de inicio y final de las actividades en dos arrays: $s$ y $f$, el índice $k$ que define al subproblema $S_k$ que tenemos que resolver y $n$ que indica el tamaño original del problema. Las $n$ actividades ya están ordenadas de acuerdo a su tiempo de terminación de forma ascendente. Además, se agrega la actividad $a_0$ con $f_0 = 0$ para que el subproblema $S_0$ sea el conjunto total de actividades $S$. La llamada inicial tiene a $k=0$.

```
recursive-activity-selector(s, f, k, n)
    m = k + 1

    while m <= n and s[m] <= f[k]
        m = m + 1
    
    if m <= n
        return { am } UNION recursive-activity-selector(s, f, m, n)
    else
        return empty set
```

El ciclo *while* busca la primera actividad en terminar, se examinan las actividades hasta hallar una compatible con $a_k$. El proceso puede retornar la unión de $\{ a_m \}$ y el conjunto de tamaño máximo en ser retornado por la llamada recursiva, o bien, el conjunto vacío porque no hay actividades compatibles.

### Un algoritmo *greedy* iterativo

```
greedy-activity-selector(s, f)
    n = s.length
    A = { a1 }
    k = 1
    
    for m = 2 to n
        if s[m] >= f[k]
            A = A UNION { am }
            k = m
    
    return A
```

La variable $k$ es el índice de la más reciente adición a $A$, esto corresponde a $a_k$ en la versión recursiva. El ciclo *for* se encarga de hallar la actividad que termine primero, la agrega a $A$ y se actualiza la variable $k$.

Al igual que la versión recursiva, esta versión tiene un tiempo de ejecución de $\Theta(n)$.
