# Amortized analysis

En este análisis se promedia el tiempo requerido por una  secuencia de operaciones en una estructura de datos. Se demuestra que el costo promedio de una operación es pequeño incluso si alguna operación llega a ser muy costosa. No confundir este análisis con el *average-case analysis*.

## Análisis agregado

Se demuestra que para todo $n$, una secuencia de $n$ operaciones toma en el peor de los casos un tiempo de ejecución $T(n)$ en total. El costo amortizado es por lo tanto $\frac{T(n)}{n}$, estamos dividiendo el tiempo total entre el número total de operaciones llevadas a cabo.

## Ejemplo: *stacks operations*

Conocemos a las operaciones `push` y `pop` propias de una pila, cada una de estas operaciones toma un tiempo $O(1)$, es por esto que una secuencia de $n$ operaciones `push` y `pop` tiene un costo total de $\Theta(n)$.

Si agregamos una nueva operación a la pila: `multipop(s, k)` que remueve $k$ elementos de una pila $S$.

```
multipop(s, k)
    while not stack-empty(S) and k > 0
        pop(s)
        k = k - 1
```

El costo total de esta función es $min(s, k)$ donde $s$ representa el número de elementos en la pila. Si analizamos ahora una secuencia de $n$ operaciones `push`, `pop` y `multipop` sobre una pila vacía el costo de estas operaciones será a lo más $O(n)$, por lo que el costo promedio de una operación será $\frac{O(n)}{n} \to O(1)$. Dejando el costo para cada una de estas tres operaciones en $O(1)$.

## Método contable

Se asignan diferentes costos a las operaciones, algunas teniendo más o menos costo de lo que realmente deberían. A este costo se le conoce como costo amortizado. Cuando el costo amortizado de una operación excede su costo real, asignamos esta diferencia a otras operaciones de la estrutura de datos como **crédito**. El crédito nos ayuda a *pagar* en operaciones posteriores cuyo costo amortizado es menor que su costo real. Difiere del análisis agregado porque en este último todas las operaciones comparten un mismo costo amortizado.

Debemos elegir los costos amortizados de manera cuidadosa. Al igual que en el análisis agregado se trabaja con secuencias de operaciones. Denotamos el costo real de una operación $i$-ésima como $c_i$ y el costo amortizado de dicha operación como $\hat c_i$, requerimos que: $\sum_{i=1}^{n} \hat c_i \geq \sum_{i=1}^{n} c_i$.

El crédito total que tendríamos es la diferencia entre costo amortizado total y el costo real total. El crédito nunca es un número negativo.

### Ejemplo: *stacks operations*

Los costos de las operaciones en una pila son:

|operación|costo    |  
|:-------:|:-------:|
|push     |1        |
|pop      |1        |
|multipop |min(s, k)|

Asignamos los costos amortizados:

|operación|costo    |  
|:-------:|:-------:|
|push     |2        |
|pop      |0        |
|multipop |0        |

Suponiendo que para cada operación usamos dólares para representar el costo. Empezamos con una pila vacía, cuando insertamos pagamos dos dólares, pero como el costo real es de $1$ entonces tenemos un dólar de crédito. Cuando eliminamos no pagamos nada, pero realmente el costo es de un dólar, por ello está el crédito. Con el crédito pagamos el costo real. Lo mismo sucede con el multipop.

El costo amortizado para $n$ operaciones de `push`, `pop` y `multipop` es de $\Theta(n)$ y así lo es también para el costo real.

## Método de potencial

Representa el trabajo prepagado como ***potencial*** que puede ser liberado para pagar operaciones futuras. Si llevamos a cabo $n$ operaciones comenzando con una estructura de datos $D_0$ para cada $i = 1, 2, ..., n$; $c_i$ será el costo real de la operación $i$-ésima y $D_i$ la estructura de datos que resulta de aplicar la $i$-ésima operación a la estructura de datos $D_{i-1}$. Una función de potencial $\Phi$ mapea cada estructura de datos $D_i$ a un número real $\Phi(D_i)$, el cual es el potencial asociado con dicha estructura de datos $D_i$. El costo amortizado $\hat c_i$ de la $i$-ésima operación se define como: $\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i-1})$.

*Es el costo real más el cambio de potencial durante la operación*.

El costo amortizado total de $n$ operaciones es: $\sum_{i=1}^{n} \hat c_i = \sum_{i=1}^{n} c_i + \Phi(D_n) - \Phi(D_0)$.

Requerimos que $\Phi(D_i) \geq \Phi(D_0)$ para todo $i$, esto para garantizar que ***pagamos por adelantado***. Si la diferencia de potencial $\Phi(D_i) - \Phi(D_{i-1})$ para la operación $i$-ésima es:
* **Positiva**. El costo amortizado $\hat c_i$ representa un *overcharge* a la $i$-ésima operación y el potencial incrementa.
* **Negativa**. El costo amortizado $\hat c_i$ representa un *undercharge* a la $i$-ésima operación y el potencial decrementa para poder pagar el costo real de la operación.

### Ejemplo: *stacks operations*

Volvemos a las operaciones `push`, `pop` y `multipop`. Definimos una función de potencial $\Phi$ en una pila, para una pila vacía $D_0$, tenemos que $\Phi(D_0) = 0$ y como la pila no tiene un tamaño negativo tenemos que $\Phi(D_i) \geq 0$.

Si tenemos $s$ elementos en la $i$-ésima operación, la diferencia de potencial es: $\Phi(D_i)-\Phi(D_{i-1}) = (s + 1) - s = 1$, el costo amortizado es: $\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i-1}) = 1 + 1 = 2$.

Si la operación `multipop` causa que $k' = min(k, s)$ objetos salgan de la pila, la diferencia de potencial es: $\Phi(D_i) - \Phi(D_{i-1}) = -k'$ y el costo amortizado es: $\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i-1}) = k' - k' = 0$. Lo mismo sucede para el método `pop`.

El costo de las tres operaciones es $O(1)$, haciendo el costo de una secuencia de $n$ operaciones $O(n)$.

## Tablas dinámicas

No siempre sabremos cuanto almacenamiento requerirá cierta aplicación. Podemos asignar cierto espacio para una tabla y darnos cuenta después que no ha sido suficiente, por ello reasignamos memoria para una tabla de mayor tamaño y copiamos los elementos de la tabla original a esta nueva tabla. De forma similar si muchos objetos son eliminados es prudente reasignar espacio para una tabla de menor tamaño.

Asumimos que esta tabla dinámica permite las operaciones `table-insert` y `table-delete`. Utilizamos también el concepto de *load factor* $\alpha(T)$ de una tabla no vacía $T$ ser el número de elementos almacenados dividida por su tamaño (el número de slots disponibles). Si la tabla está vacía tiene tamaño $0$ y se define su *load factor* como $1$. El espacio sin usar nunca será mayor que una fracción constante del total del espacio disponible.

### *Table expansion*

Asumiendo que la tabla es un array de slots. La tabla se llena cuando todos los slots son utilizados, de manera equivalente, su *load factor* es $1$. Cuando intentemos insertar en una tabla llena la tabla debe expandirse. Se asigna memoria para una nueva tabla con más slots, ahora tenemos un array más grande y los elementos de la tabla original se copian a la nueva.

Una heurística nos dice que cuando asignamos memoria para una nueva tabla ésta debe ser del doble de tamaño que la original. Si solo manejamos inserciones el *load factor* de esta tabla es por lo menos $\frac{1}{2}$, nunca se desperdicia más de la mitad del espacio.

$T$ representa la tabla, el atributo $T.table$ es el apuntador al bloque de memoria para el almacenamiento (los slots), $T.num$ contiene el número de items en la tabla y $T.size$ es el número total de slots. Inicialmente $T.num = T.size = 0$.

```
table-insert(T, x)
    if T.size == 0
        allocate T.table with 1 slot
        T.size = 1
    
    if T.num == T.size
        allocate new-table with 2*T.size slots
        insert all items in T.table into new-table
        free T.table
        T.table = new-table
        T.size = 2*T.size
    
    insert x into T.table
    T.num = T.num + 1
```

Si analizamos una secuencia de $n$ operaciones `table-insert` en una inicialmente tabla vacía podemos deducir que cuando la tabla tiene espacio para el nuevo item el costo es $c_i=1$, si está llena sin embargo, el costo es $c_i = i$, debemos copiar $i-1$ elementos a la nueva tabla más el costo de insertar el nuevo elemento. Llevando a cabo las $n$ operaciones con el peor de los casos de esta operación siendo $O(n)$, terminamos con un costo de $O(n^2)$. Sin embargo, raramente expandiremos las $n$ veces que llevemos a cabo esta operación, siendo más específicos la operación $i$-ésima causa una expansión solo cuando $i-1$ es una potencia de $2$. Utilizando análisis agregado se determina que el costo de una operación es $O(1)$. $c_i = \begin{cases}  i & \text{si } i-1 \text{ es potencia de } 2 \\ 1 & \text{en otro caso} \end{cases}$. 
El costo total es: $\sum_{i=1}^{n} c_i \leq n + \sum_{j=0}^{lg(n)} 2^j \lt n + 2n = 3n$, el costo amortizado es de $3$
 
Utilizando el método contable resulta más intuitivo entender esto: cada elemento paga $3$ en una inserción, se está pagando por insertarse a sí mismo, moverse cuando la tabla se expanda y mover a otro elemento que ya ha sido movido previamente cuando la tabla se ha expandido previamente.

Suponiendo una tabla de tamaño $m$ que es el resultado de una expansión, la tabla tiene por lo tanto $\frac{m}{2}$ elementos y no tiene crédito. Al insertar cobramos tres dólares, la inserción de cada elemento cuesta un dólar, otro dólar es crédito para este elemento y un tercer dólar para alguno de los $\frac{m}{2}$ elementos que ya están en la tabla. La tabla no se llenará hasta que otros $\frac{m}{2} - 1$ elementos hayan sido insertados pero para entonces tendremos el crédito para mover cada uno de los elementos para la reinserción en la nueva tabla.

### *Table expansion and contraction*

La operación `table-delete` elimina un elemento de la tabla. Para limitar la cantidad de espacio desperdiciado se contrae la tabla cuando el *load factor* se vuelve muy pequeño, la contracción es análoga a la expansión. Se asigna memoria para una nueva tabla más pequeña y se copian los elementos a la nueva tabla, se puede liberar la memoria que estaba siendo utilizada por la vieja tabla.

Se podría pensar que dividir el tamaño de la tabla a la mitad cada vez que se contraiga, pero esta no es la mejor opción. Suponiendo que llevamos a cabo $n$ operaciones en una tabla $T$, donde las primeras $\frac{n}{2}$ son inserciones con un costo total de $\Theta(n)$. Al finalizar esta secuencia de operaciones tenemos que: $T.num = T.size = \frac{n}{2}$. Las $\frac{n}{2}$ operaciones restantes se lleva a cabo de la siguiente manera: `table-insert`, `table-delete`, `table-delete`, `table-insert`, `table-insert`, `table-delete`, `table-delete`, ...

La primera inserción provoca que la tabla se expanda a un tamaño $n$, las dos eliminaciones provocan que regrese a un tamaño $\frac{n}{2}$ y así sucesivamente. Para cada contracción y expansión el costo es $\Theta(n)$ y como hay $\Theta(n)$ de ellas el costo de estas $n$ operaciones es de $\Theta(n^2)$, con el costo amortizado de una operación siendo $\Theta(n)$.

Lo que podemos hacer es permitir que el *load factor* sea menor a $\frac{1}{2}$, siendo más específicos hacemos una contracción cuando tenga menos de $\frac{1}{4}$ de elementos, el *load factor* de la tabla está acotado inferiormente por la constante $\frac{1}{4}$.

Intuitivamente se considera a $\frac{1}{2}$ como el *load factor* ideal y el potencial de la tabla es de 0. Si la tabla se desvía del valor $\frac{1}{2}$ el potencial incrementa, para el momento en el que expandimos o contraemos la tabla ha ganado suficiente potencial para poder copiar todos los elementos en la nueva tabla. Necesitamos una función de potencial que crezca hasta ser igual a $T.num$ en el momento en el que el *load factor* es igual a $1$ o decreció hasta ser igual a $\frac{1}{4}$. Después de expandir el *load factor* regresa a ser $\frac{1}{2}$ y el potencial se reduce a $0$.

Contruimos por lo tanto una función de potencial $\Phi$ para una secuencia de $n$ operaciones `table-insert` y `table-delete` y denotamos el *load factor* de una tabla no vacía como $\alpha(T) = \frac{T.num}{T.size}$, tenemos que: $T.num = \alpha(T)*T.size$. La tabla esté o no vacía usamos como nuestra función de potencial a: $\Phi(T) = \begin{cases} 2 * T.num - T.size & \text{si } \alpha(T) \geq \frac{1}{2} \\ \frac{T.size}{2} - T.num & \text{si } \alpha(T) < \frac{1}{2} \end{cases}$

Podemos observar en esta función que cuando el *load factor* es igual a $1$ tenemos que $T.size = T.num$ y esto implica que $\Phi(T) = T.num$ por lo que el potencial puede pagar por una expansión y cuando el *load factor* es igual a $\frac{1}{4}$ tenemos que $T.size = 4*T.num$ lo que implica que $\Phi(T) = T.num$, también se puede pagar por una contracción.

Sea $\alpha_i$ el *load factor* de la tabla después de la operación $i$-ésima y $\Phi_i$  el potencial después de la operación $i$-ésima. En el caso en el que la $i$-ésima operación es `table-insert`.
- Si: $\alpha_{i-1} \geq \frac{1}{2}$, ya sea si la tabla se expande o no el costo amortizado es a lo más 3 (como se vió anteriormente).
- Si: $\alpha_{i-1} \lt \frac{1}{2}$ (la tabla no se va a expandir a pesar de la inserción) y $\alpha_i \lt \frac{1}{2}$, entonces: $\hat c_i = c_i + \Phi_i - \Phi_{i-1} = 1 + (\frac{size_i}{2} - num_i) - (\frac{size_{i-1}}{2} - num_{i-1})$, sabemos que $num_{i-1} = num_i - 1$ y que $size_{i-1} = size_i$ porque no hubo expansión, entonces reemplazando: $1 + (\frac{size_i}{2} - num_i) - (\frac{size_i}{2} - (num_i - 1)) = 1 + \frac{size_i}{2} - num_i - \frac{size_i}{2} + num_i - 1 = 0$.
- Si: $\alpha_{i-1} < \frac{1}{2}$ pero $\alpha_i \geq \frac{1}{2}$, entonces tenemos que: $\hat c_i = 1 + (2num_i - size_i) - (\frac{size_{i-1}}{2} - num_{i-1})$ y sabemos que: $size_{i-1} = size_i - 1$ y que: $num_i = num_{i-1} + 1$ puesto que no se expandió la tabla. Reemplazando tenemos: $\hat c_i = 1 + (2(num_{i-1} + 1) - size_{i-1}) - (\frac{size_{i-1}}{2} - num_{i-1}) = 1 + 2num_{i-1} + 2 - size_{i-1} -\frac{size_{i-1}}{2} + num_{i-1} = 3num_{i-1} - \frac{3size_{i-1}}{2} + 3$. Tenemos que: $\alpha_{i-1} = \frac{num_{i-1}}{size_{i-1}} \to num_{i-1} = \alpha_{i-1}size_{i-1}$, por lo tanto: $3\alpha_{i-1}size_{i-1} - \frac{3size_{i-1}}{2} + 3 < \frac{3size_{i-1}}{2} - \frac{3size_{i-1}}{2} + 3 = 3$. `table-insert` tiene por consiguiente un coste amortizado de lo más $3$.

Para el procedimiento `table-delete`: $num_i = num_{i-1} - 1$.
- Si: $\alpha_{i-1} < \frac{1}{2}$ y no hubo contracción en la operación $i$-ésima, es decir, $size_i = size_{i-1}$ el costo amortizado es: $\hat c_i = c_i + \Phi_i - \Phi_{i-1} = 1 + (\frac{size_i}{2} - num_i) - (\frac{size_{i-1}}{2} - num_{i-1}) = 1 + (\frac{size_i}{2} - num_i) - (\frac{size_i}{2} - (num_i + 1)) = 1 + \frac{size_i}{2} - num_i - \frac{size_i}{2} + num_i + 1 = 2$
- Si: $\alpha_{i-1} < \frac{1}{2}$ y la operación $i$-ésima provoca una contracción, el costo real de la operación es $c_i = num_i + 1$, debido a que eliminamos un elemento y copiamos $num_i$ elementos. Por lo que tenemos: $\frac{size_i}{2} = \frac{size_{i-1}}{4} = num_{i-1} = num_i + 1$ y el costo amortizado es: $\hat c_i = c_i + \Phi_i - \Phi_{i-1} = num_i + 1 + (\frac{size_i}{2} - num_i) - (\frac{size_{i-1}}{2} - num_{i-1}) = num_i + 1 + ((num_i + 1) - num_i) - ((2num_i + 2) - num_i - 1) = num_i + 1 + 1 - 2num_i - 2 + num_i + 1 = 1$

Probando así que el costo amortizado de cada operación está acotada superiormente por una constante, el tiempo de ejecución en una tabla dinámica para $n$ operaciones es $O(n)$.
