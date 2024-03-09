|   |   |   |
|---|---|---|
|[►](javascript:void(0); "Expand/Collapse")||[The Racket Guide](index.html)|

|   |   |
|---|---|
|1|[Welcome to Racket](intro.html)|
|2|[Racket Essentials](to-scheme.html)|
|3|[Built-In Datatypes](datatypes.html)|
|4|[Expressions and Definitions](scheme-forms.html)|
|5|[Programmer-Defined Datatypes](define-struct.html)|
|6|[Modules](modules.html)|
|7|[Contracts](contracts.html)|
|8|[Input and Output](i_o.html)|
|9|[Regular Expressions](regexp.html)|
|10|[Exceptions and Control](control.html)|
|11|[Iterations and Comprehensions](for.html)|
|12|[Pattern Matching](match.html)|
|13|[Classes and Objects](classes.html)|
|14|[Units](units.html)|
|15|[Reflection and Dynamic Evaluation](reflection.html)|
|16|[Macros](macros.html)|
|17|[Creating Languages](languages.html)|
|18|[Concurrency and Synchronization](concurrency.html)|
|19|[Performance](performance.html)|
|20|[Parallelism](parallelism.html)|
|21|[Running and Creating Executables](running.html)|
|22|[More Libraries](More_Libraries.html)|
|23|[Dialects of Racket and Scheme](dialects.html)|
|24|[Command-Line Tools and Your Editor of Choice](other-editors.html)|
||[Bibliography](doc-bibliography.html)|
||[Index](doc-index.html)|

|   |   |   |
|---|---|---|
|[▼](javascript:void(0); "Expand/Collapse")|3|[Built-In Datatypes](datatypes.html)|

|   |   |
|---|---|
|3.1|[Booleans](booleans.html)|
|3.2|[Numbers](numbers.html)|
|3.3|[Characters](characters.html)|
|3.4|[Strings (Unicode)](strings.html)|
|3.5|[Bytes and Byte Strings](bytestrings.html)|
|3.6|[Symbols](symbols.html)|
|3.7|[Keywords](keywords.html)|
|3.8|[Pairs and Lists](pairs.html)|
|3.9|[Vectors](vectors.html)|
|3.10|Hash Tables|
|3.11|[Boxes](boxes.html)|
|3.12|[Void and Undefined](void_undefined.html)|

  [top](../index.html "up to the documentation top")  [contents](javascript:void(0); "show/hide table of contents")  [← prev](vectors.html "backward to "3.9 Vectors"")  [up](datatypes.html "up to "3 Built-In Datatypes"")  [next →](boxes.html "forward to "3.11 Boxes"") 

#### 3.10 Hash Tables

A hash table implements a mapping from keys to values, where both keys and values can be arbitrary Racket values, and access and update to the table are normally constant-time operations. Keys are compared using [equal?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._equal%7E3f%2529%2529&version=8.10), [eqv?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._eqv%7E3f%2529%2529&version=8.10), or [eq?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._eq%7E3f%2529%2529&version=8.10), depending on whether the hash table is created with [make-hash](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-hash%2529%2529&version=8.10), [make-hasheqv](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-hasheqv%2529%2529&version=8.10), or [make-hasheq](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-hasheq%2529%2529&version=8.10).

Examples:

> |   |
> |---|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht ([make-hash](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-hash%2529%2529&version=8.10)))|
> |> ([hash-set!](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2521%2529%2529&version=8.10) ht "apple" '(red round))|
> |> ([hash-set!](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2521%2529%2529&version=8.10) ht "banana" '(yellow long))|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "apple")|
> |'(red round)|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "coconut")|
> |hash-ref: no value found for key|
> |key: "coconut"|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "coconut" "not there")|
> |"not there"|

The [hash](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash%2529%2529&version=8.10), [hasheqv](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hasheqv%2529%2529&version=8.10), and [hasheq](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hasheq%2529%2529&version=8.10) functions create immutable hash tables from an initial set of keys and values, in which each value is provided as an argument after its key. Immutable hash tables can be extended with [hash-set](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2529%2529&version=8.10), which produces a new immutable hash table in constant time.

Examples:

> |   |
> |---|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht ([hash](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash%2529%2529&version=8.10) "apple" 'red "banana" 'yellow))|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "apple")|
> |'red|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht2 ([hash-set](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2529%2529&version=8.10) ht "coconut" 'brown))|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "coconut")|
> |hash-ref: no value found for key|
> |key: "coconut"|
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht2 "coconut")|
> |'brown|

A literal immutable hash table can be written as an expression by using #hash (for an [equal?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._equal%7E3f%2529%2529&version=8.10)-based table), #hasheqv (for an [eqv?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._eqv%7E3f%2529%2529&version=8.10)-based table), or #hasheq (for an [eq?](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=Equality.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._eq%7E3f%2529%2529&version=8.10)-based table). A parenthesized sequence must immediately follow #hash, #hasheq, or #hasheqv, where each element is a dotted key–value pair. The #hash, etc. forms implicitly [quote](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=quote.html%23%2528form._%2528%2528quote._%7E23%7E25kernel%2529._quote%2529%2529&version=8.10) their key and value sub-forms.

Examples:

> |   |
> |---|
> |\|   \|<br>\|---\|<br>\|> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht #hash(("apple" . red)\|<br>\|("banana" . yellow)))\||
> |> ([hash-ref](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-ref%2529%2529&version=8.10) ht "apple")|
> |'red|

> > > ![+](magnify.png)[Reading Hash Tables](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=reader.html%23%2528part._parse-hashtable%2529&version=8.10) in [The Racket Reference](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=index.html&version=8.10) documents the fine points of the syntax of hash table literals.

Both mutable and immutable hash tables print like immutable hash tables, using a quoted #hash, #hasheqv, or #hasheq form if all keys and values can be expressed with [quote](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=quote.html%23%2528form._%2528%2528quote._%7E23%7E25kernel%2529._quote%2529%2529&version=8.10) or using hash, hasheq, or hasheqv otherwise:

Examples:

> |   |
> |---|
> |\|   \|<br>\|---\|<br>\|> #hash(("apple" . red)\|<br>\|("banana" . yellow))\||
> |'#hash(("apple" . red) ("banana" . yellow))|
> |> ([hash](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash%2529%2529&version=8.10) 1 ([srcloc](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=exns.html%23%2528def._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._srcloc%2529%2529&version=8.10) "file.rkt" 1 0 1 ([+](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=generic-numbers.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._%252B%2529%2529&version=8.10) 4 4)))|
> |(hash 1 (srcloc "file.rkt" 1 0 1 8))|

A mutable hash table can optionally retain its keys weakly, so each mapping is retained only so long as the key is retained elsewhere.

Examples:

> |   |
> |---|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht ([make-weak-hasheq](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-weak-hasheq%2529%2529&version=8.10)))|
> |> ([hash-set!](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2521%2529%2529&version=8.10) ht ([gensym](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=symbols.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._gensym%2529%2529&version=8.10)) "can you see me?")|
> |> ([collect-garbage](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=garbagecollection.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._collect-garbage%2529%2529&version=8.10))|
> |> ([hash-count](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-count%2529%2529&version=8.10) ht)|
> |0|

Beware that even a weak hash table retains its values strongly, as long as the corresponding key is accessible. This creates a catch-22 dependency when a value refers back to its key, so that the mapping is retained permanently. To break the cycle, map the key to an ephemeron that pairs the value with its key (in addition to the implicit pairing of the hash table).

> > > ![+](magnify.png)[Ephemerons](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=ephemerons.html&version=8.10) in [The Racket Reference](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=index.html&version=8.10) documents the fine points of using ephemerons.

Examples:

> |   |
> |---|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht ([make-weak-hasheq](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-weak-hasheq%2529%2529&version=8.10)))|
> |\|   \|<br>\|---\|<br>\|> ([let](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=let.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fletstx-scheme..rkt%2529._let%2529%2529&version=8.10) ([g ([gensym](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=symbols.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._gensym%2529%2529&version=8.10))])\|<br>\|([hash-set!](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2521%2529%2529&version=8.10) ht g ([list](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=pairs.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._list%2529%2529&version=8.10) g)))\||
> |> ([collect-garbage](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=garbagecollection.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._collect-garbage%2529%2529&version=8.10))|
> |> ([hash-count](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-count%2529%2529&version=8.10) ht)|
> |1|

> |   |
> |---|
> |> ([define](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=define.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fbase..rkt%2529._define%2529%2529&version=8.10) ht ([make-weak-hasheq](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-weak-hasheq%2529%2529&version=8.10)))|
> |\|   \|<br>\|---\|<br>\|> ([let](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=let.html%23%2528form._%2528%2528lib._racket%252Fprivate%252Fletstx-scheme..rkt%2529._let%2529%2529&version=8.10) ([g ([gensym](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=symbols.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._gensym%2529%2529&version=8.10))])\|<br>\|([hash-set!](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-set%2521%2529%2529&version=8.10) ht g ([make-ephemeron](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=ephemerons.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._make-ephemeron%2529%2529&version=8.10) g ([list](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=pairs.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._list%2529%2529&version=8.10) g))))\||
> |> ([collect-garbage](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=garbagecollection.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._collect-garbage%2529%2529&version=8.10))|
> |> ([hash-count](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html%23%2528def._%2528%2528quote._%7E23%7E25kernel%2529._hash-count%2529%2529&version=8.10) ht)|
> |0|

> > > ![+](magnify.png)[Hash Tables](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=hashtables.html&version=8.10) in [The Racket Reference](https://download.racket-lang.org/releases/8.10/doc/local-redirect/index.html?doc=reference&rel=index.html&version=8.10) provides more on hash tables and hash-table procedures.

  [top](../index.html "up to the documentation top")  [contents](javascript:void(0); "show/hide table of contents")  [← prev](vectors.html "backward to "3.9 Vectors"")  [up](datatypes.html "up to "3 Built-In Datatypes"")  [next →](boxes.html "forward to "3.11 Boxes"")