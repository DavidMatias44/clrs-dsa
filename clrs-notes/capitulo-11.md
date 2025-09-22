# Hash tables

## Hash table
Es una estructura de datos muy efectiva para implementar diccionarios. A tal punto que acceder a un elemento mediante búsqueda, consume tiempo constante $O(1)$.

## Direct addressing
El acceso directo (*direct addressing*) es una técnica simple que funciona muy bien cuando el universo $U$ de claves es razonablemente pequeño. Para representar un conjunto dinámico se puede usar un array o una *direct-access table* denotada por $T[0...m-1]$ donde cada posición o slot corresponde a una clave en el universo $U$ y $m$ es un número no demasiado grande.

Las operaciones en un diccionario son triviales en su implementación:

```
direct-address-seach(T, k)
    return T[k]
```

```
direct-address-insert(T, x)
    T[x.key] = x
```

```
direct-address-delete(T, x)
    T[x.key] = NIL
```

Todas estas operaciones toman $O(1)$.

La desventaja del *direct-addressing* es que si $U$ tiene muchos elementos, tener una tabla $T$ con un tamaño $|U|$ es impráctico, incluso imposible. Entonces una ***hash table*** es la solución, toma un conjunto $K$ de claves mucho menor al conjunto $U$, requiriendo mucho menos espacio, pero conservando el tiempo de búsqueda de un elemento en particular en $O(1)$.

Con *direct-addressing* cada clave iba al lugar que el correspodía, pero usando ***hashing*** el elemento se almacena en $h(k)$, es decir, se ocupa una **función *hash*** $h$ para calcular el lugar que le corresponde a la clave $k$: $h: U \to \{0, 1, ..., m-1\}$

*$h$ mapea del universo $U$ de claves a los slots de una **hash table** $T[0...m-1]$*.

Se dice entonces que $h(k)$ es el **valor hash** de la key $k$.

## Colisiones
Existe una complicación, dos claves pueden tener el mismo *slot*. Esto se conoce como colisión. La solución ideal sería evitar cualquier colisión, esto eligiendo a la función hash $h$ correctamente, sin embargo, al ser $|U| > m$ (el número de elementos en el universo de claves es mayor al número de *slots* disponibles en la tabla) esto es imposible, habrá al menos una colisión.

### Resolver colisiones mediante encadenamiento (chaining)
Usando este método colocamos todos los elementos que ocupan el mismo *slot* en la misma lista enlazada. Entonces, el *slot* $j$ tiene un apuntador a la cabeza (*head*) de la lista con todos los elementos que, después de aplicar la **función hash** ocupan el *slot* $j$. Si dicho *slot* está vacío, el apuntador entonces apunta a $NIL$.

```
chained-hash-insert(T, x)
    insert x at the head of the list T[h(x.key)]
```

```
chained-hash-search(T, k)
    search for an element with key k in list T[h(k)]
```

```
chainded-hash-delete(T, x)
    delete x from the list T[h(x.key)]
```

El peor caso para la inserción es O(1), para la búsqueda el *running time* es proporcional a la longitud de la lista. Para la eliminación, siempre que se ocupe una lista doblemente ligada tendrá O(1), caso contrario, el tiempo se aproxima al de la búsqueda.

### Análisis del hashing con encadenamiento.
Dada una *hash table* $T$ con $m$ *slots* que almacena $n$ elementos, se define un ***load factor*** $\alpha$ de $T$ como $\frac{n}{m}$, que es, el número de elementos en promedio almacenados en la "cadena". $\alpha$ está dado en términos de si es: menor, igual o mayor que 1.

En el peor de los casos, todos los elementos van al mismo *slot* dejándonos con una lista de $n$ elementos.

## Funciones hash
Una buena función hash satisface la ***simple uniform hashing***: cada clave puede ser "hasheada" a cualquier slot de forma equitativa al resto, independientemente de que ya haya sido mapeada una clave anteriormente. Esto tipicamente no lo sabemos, desconocemos la distribución que tomarán las claves.

A menudo se utilizan técnias heurísticas para crear una función hash que tenga buen desempeño.

## Método por división (division method)
Se mapea la clave $k$ a uno de los slots $m$ tomando el resto de dividir $k$ por $m$: $h(k) = k \mod m$.

Al requerir solo una operación el método es muy rápido.

Se deben evitar ciertos valores para $m$, $m$ no debe ser potencia de 2, esto ya es a nivel de bits, muchas veces números comparten características a este nivel, resultado en muchas colisiones. Un número primo no cercano a un número potencia de 2 es una buena opción.

## Método por multiplicación (multiplication method)
Opera en dos pasos:
1. Multiplicar la key $k$ por una constante $A$ en el rango $0 < A < 1$ y se extrae la parte fraccionaria.
2. Se multiplica este valor por $m$:
$h(k)=m(kA \mod 1)$

Donde: $KA \mod 1$ es la parte fraccionaria de $KA$.

Con este método el valor de $m$ no importa mucho, comunmente se elige una potencia de 2.

## Hashing universal
Hasta ahora las funciones hash son vulnerables a un peor caso $\Theta(n)$ donde las claves elegidas/dadas generan el mismo valor de $slot$, la única manera de arreglar esto es elegir una función hash aleatoria, de tal manera que sea independiente de las claves que van a ser almacenadas.

Al inicio de la ejecución se elige una función hash de manera aleatoria, garantizando un buen desempeño en promedio. Elegir una función hash con poco o nulo buen desempeño es poco probable.

## Open addressing
Con este método todos los elementos ocupan la tabla hash, es decir, cada entrada de la tabla o bien tiene un elemento del conjunto dinámico o el valor $NIL$. Al buscar un elemento se examina la tabla sistemáticamente hasta hallar al elemento o determinar que no está presente. No hay listas ligadas y no hay elementos "fuera" de la tabla. Entonces se dice que la tabla se va "rellenando" de modo que llega un punto donde ya no se pueden hacer más inserciones. Por esta razón el ***load factor*** nunca excede a 1.

Al no requerir apuntadores y listas ligadas, la memoria no ocupada por estos elementos se destina a tener más lugares en la hash table. Para llevar a cabo una inserción se examina dónde hay un lugar disponible y para determinar esto la función hash se convierte en: $h: U \times \{0, 1, ..., m-1\} \to \{0, 1, ..., m-1\}$. Se prueba para cada clave $k$: $<h(k, 0), h(k, 1), ..., h(k, m-1)>$, es decir, cada slot de la hash table es considerado.

## Linear probing
Se utiliza una función hash auxiliar: $h'=U \to \{0, 1, ..., m-1 \}$, esta función auxiliar es usada por la función hash: $h(k, i) = (h'(k) + i) \mod m$, donde: $i = 0, 1, ..., m-1$. Si el slot está ocupado, es donde el índice $i$ entra en funcionamiento, ya que nos irá haciendo "avanzar" linealmente (de ahí el nombre del método) por los slots de la tabla hasta el slot $m-1$ y "regresará" al principio, es decir, slot 0.

Es muy sencillo de implementar, pero sufre de ***primary clustering*** que son secuencias de slots contiguas que se ocupan, provocando un incremento en el tiempo de búsqueda y de inserción.

## Quadratic probing
Usa una función hash de la forma:
$h(k, i)=(h'(k) + c_1i + c_2i^2) \mod m$, donde: $h'$ es una función hash auxiliar, $c_1$ y $c_2$ son constantes positivas e $i=0, 1, ..., m-1$.

Funciona mucho mejor que ***linear probing***. Las posiciones probadas son "offsets" dados por $i$. Pero si dos claves tienen el mismo valor hash: $h(k_1, i) = h(k_2, i)$ genera una versión más "suave" de *clustering* conocida como ***secondary clustering***. No se forman bloques como en *primary clustering* pero las claves "compiten" por los mismos slots.

## Double hasing
Esta es una de las mejores opciones, usa una función de la forma: $h(k, i) = (h_1(k) + ih_2(k)) \mod m$, donde: $h_1$ y $h_2$ son funciones hash, e $i=0, 1, ... m-1$. Se garantiza que el "offset" depende de dos maneras diferentes de la clave $k$.

## Perfect hashing
Se puede tener muy buen rendimiento si el conjunto de claves es estático (no cambia), una vez ya almancenas en la tabla. Se le conoce como ***perfect hashing*** si $O(1)$ accesos a memoria son necesarios para buscar un elemento en el peor de los casos.

Para lograr esto se usan dos niveles de hashing con *universal hashing* en cada nivel. En el primer nivel se encuentra algo prácticamente igual al *chaining* pero en lugar de usar una lista ligada se utiliza una hash table secundaria.
