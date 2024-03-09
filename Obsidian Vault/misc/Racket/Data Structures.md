<html>
	<h2 style="font-family:courier;color:#FF0064">
		Data Structures
	</h2>
</html>

   



# Data structures



Racket’s data struc­tures have distinct char­ac­ter­is­tics that often recom­mend one over another for a partic­ular job:  + Chart adapted from [Jens Axel Søgaard](http://stackoverflow.com/a/27589146/1486915).



|Struc­ture|Access|Values|Index|Mutable?|
|---|---|---|---|---|
|pair|random|two|nothing|no|
|list|sequential|variable|nothing|no|
|hash table|random|variable|keys|optional|
|association list|sequential|variable|[car](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._car)))|no|
|vector|random|fixed|integers|optional|
|structure type|random|fixed|identifiers|optional|



[Hash tables](#hash-tables), [vectors](#vectors), and [struc­ture types](#structure-types) are avail­able in [mutable](/appendix/glossary.html#mutable) (meaning, internal values can be changed) and [immutable](/appendix/glossary.html#immutable) vari­ants. As a rule, unless you need a mutable struc­ture, choose an immutable one, because Racket can better opti­mize immutable struc­tures for speed.



### [Pairs](#pairs)



A _pair_ holds two values. A pair is made with [cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))), and the values can be retrieved with [car](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._car))) and [cdr](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cdr))). If you’ve got exactly two values, great. If you’ve got more, look else­where.

- 
    
    [Pairs](/explainer/pairs.html) explainer
    



### [Lists](#lists)



A _list_ holds any number of values. Because lists are made from a sequence of linked pairs, they’re opti­mized for sequen­tial access, and thus are the char­ac­ter­istic data struc­tures used in iter­a­tion and recur­sion. Random access (with [list-ref](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._list-ref)))) is feasible with short lists. For long lists, random access can be slow, so a [vector](#vector) is the better option.

- 
    
    [Lists](/explainer/lists.html) explainer
    



### [Vectors](#vectors)



A _vector_ is an array of values, indexed by loca­tion and opti­mized for random access. Though vectors come in immutable and mutable vari­ants, the length of a vector is always fixed.  + But see [grow­able vectors](http://docs.racket-lang.org/data/gvector.html), which can be resized.



A basic mutable vector can be made with [vector](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector))). Values are retrieved with [vector-ref](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-ref))), and changed with [vector-set!](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-set!))):



(define vec (vector 'sym "str" 42))  
vec ; '#(sym "str" 42)  
(vector-ref vec 0) ; 'sym  
(vector-ref vec 1) ; "str"  
(vector-ref vec 2) ; 42  
(vector-set! vec 0 'foo)  
(vector-set! vec 1 "bar")  
vec ; '#(foo "bar" 42)  
(vector-set! vec 1 25)  
vec ; '#(foo 25 42)

|   |   |
|---|---|
|1<br> 2<br> 3<br> 4<br> 5<br> 6<br> 7<br> 8<br> 9<br>10|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) vec ([vector](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector))) 'sym "str" 42))<br>vec ; '#(sym "str" 42)<br>([vector-ref](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-ref))) vec 0) ; 'sym<br>([vector-ref](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-ref))) vec 1) ; "str"<br>([vector-ref](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-ref))) vec 2) ; 42<br>([vector-set!](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-set!))) vec 0 'foo)<br>([vector-set!](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-set!))) vec 1 "bar")<br>vec ; '#(foo "bar" 42)<br>([vector-set!](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-set!))) vec 1 25)<br>vec ; '#(foo 25 42)|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



Vectors and lists can be mutu­ally converted with [vector->list](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._vector-~3elist))) and [list->vector](http://docs.racket-lang.org/reference/vectors.html#(def._((quote._~23~25kernel)._list-~3evector))).

- 
    
    [Vectors](http://docs.racket-lang.org/guide/vectors.html) in the Racket Guide
    
- 
    
    [Vectors](http://docs.racket-lang.org/reference/vectors.html) in the Racket Refer­ence
    



### [Hash tables](#hash-tables)



A _hash table_ is a mapping of keys to values, which can them­selves be any data type. Hash values can be retrieved with [hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))):



(define ht (hash  
            'foo "bar"  
            '(1 2 3) expt  
            42 #'(start-zombie-apocalypse)))  
  
(hash-ref ht '(1 2 3)) ; #<procedure:expt>  
(hash-ref ht 42) ; #<syntax:5:17 (start-zombie-apocalypse)>  
(hash-ref ht 'foo) ; "bar"

|   |   |
|---|---|
|1<br>2<br>3<br>4<br>5<br>6<br>7<br>8|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) ht ([hash](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash)))<br>            'foo "bar"<br>            '(1 2 3) [expt](http://docs.racket-lang.org/reference/generic-numbers.html#(def._((quote._~23~25kernel)._expt)))<br>            42 #'(start-zombie-apocalypse)))<br><br>([hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))) ht '(1 2 3)) ; #<procedure:expt><br>([hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))) ht 42) ; #<syntax:5:17 (start-zombie-apocalypse)><br>([hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))) ht 'foo) ; "bar"|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



A hash table can be [mutable](/appendix/glossary.html#mutable)—meaning, values can be added, deleted, or updated—or [immutable](/appendix/glossary.html#immutable). An immutable hash table is created with [hash](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash))) (as demon­strated above). A mutable hash table is created with [make-hash](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._make-hash))), and then can be changed with [hash-set!](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-set!))):



(define mht (make-hash))  
(hash-set! mht 'foo "bar")  
(hash-ref mht 'foo) ; "bar"  
(hash-set! mht 'foo 42)  
(hash-ref mht 'foo) ; 42

|   |   |
|---|---|
|1<br>2<br>3<br>4<br>5|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) mht ([make-hash](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._make-hash)))))<br>([hash-set!](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-set!))) mht 'foo "bar")<br>([hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))) mht 'foo) ; "bar"<br>([hash-set!](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-set!))) mht 'foo 42)<br>([hash-ref](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hash-ref))) mht 'foo) ; 42|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



By default, a hash table uses [equal?](http://docs.racket-lang.org/reference/Equality.html#(def._((quote._~23~25kernel)._equal~3f))) to compare keys. Hash tables that use the faster [equality](/explainer/equality.html) func­tions ([eq?](http://docs.racket-lang.org/reference/Equality.html#(def._((quote._~23~25kernel)._eq~3f))) and [eqv?](http://docs.racket-lang.org/reference/Equality.html#(def._((quote._~23~25kernel)._eqv~3f)))) are also avail­able. If your keys are only symbols, you can use [hasheq](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hasheq))) or [make-hasheq](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._make-hasheq))); if your keys are only symbols or numbers, you can use [hasheqv](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._hasheqv))) or [make-hasheqv](http://docs.racket-lang.org/reference/hashtables.html#(def._((quote._~23~25kernel)._make-hasheqv))).



A vector is faster than a hash table, so if you can use sequen­tial inte­gers for keys, a vector is the better choice.

- 
    
    [Equality](/explainer/equality.html) explainer
    
- 
    
    [Hash tables](http://docs.racket-lang.org/guide/hash-tables.html) in the Racket Guide
    
- 
    
    [Hash tables](http://docs.racket-lang.org/reference/hashtables.html) in the Racket Refer­ence
    



### [Asso­ci­a­tion lists](#association-lists)



The humble _asso­ci­a­tion list_ is often over­looked for small jobs. It’s not a distinct data struc­ture, but rather a list where every element is a pair that holds a key and value (aka an [asso­ci­a­tion](/appendix/glossary.html#association)):



(define assns (list (cons 'k1 "v1") (cons 'k2 "v2")))  
assns ; '((k1 . "v1") (k2 . "v2"))

|   |   |
|---|---|
|1<br>2|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) assns ([list](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._list))) ([cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))) 'k1 "v1") ([cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))) 'k2 "v2")))<br>assns ; '((k1 . "v1") (k2 . "v2"))|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



Asso­ci­a­tion lists are easy to make and break, with the help of [map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))):



(define assns (map cons (range 5) '(a b c d e)))  
assns ; '((0 . a) (1 . b) (2 . c) (3 . d) (4 . e))  
(define keys (map car assns))  
keys ; '(0 1 2 3 4)  
(define vals (map cdr assns))  
vals ; '(a b c d e)

|   |   |
|---|---|
|1<br>2<br>3<br>4<br>5<br>6|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) assns ([map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))) [cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))) ([range](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/list..rkt)._range))) 5) '(a b c d e)))<br>assns ; '((0 . a) (1 . b) (2 . c) (3 . d) (4 . e))<br>([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) keys ([map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))) [car](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._car))) assns))<br>keys ; '(0 1 2 3 4)<br>([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) vals ([map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))) [cdr](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cdr))) assns))<br>vals ; '(a b c d e)|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



As lists, asso­ci­a­tion lists work with the usual [list](/explainer/lists.html) func­tions. They can also be used with [assoc](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/list..rkt)._assoc))) (and its vari­ants [assv](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/list..rkt)._assv))), [assq](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/list..rkt)._assq))), and [assf](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/list..rkt)._assf)))) to find partic­ular element pairs:



(define assns (map cons (range 5) '(a b c d e)))  
(assoc 3 assns) ; '(3 . d)

|   |   |
|---|---|
|1<br>2|([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) assns ([map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))) [cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))) ([range](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/list..rkt)._range))) 5) '(a b c d e)))<br>([assoc](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/list..rkt)._assoc))) 3 assns) ; '(3 . d)|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



Asso­ci­a­tion lists also can be used in a hash-table-ish way with generic [dictio­nary](/appendix/glossary.html#dictionary) func­tions like [dict-ref](http://docs.racket-lang.org/reference/dicts.html#(def._((lib._racket/dict..rkt)._dict-ref))):



(require racket/dict)  
(define assns (map cons (range 5) '(a b c d e)))  
(dict-ref assns 3) ; 'd

|   |   |
|---|---|
|1<br>2<br>3|([require](http://docs.racket-lang.org/reference/require.html#(form._((lib._racket/private/base..rkt)._require))) racket/dict)<br>([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) assns ([map](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/private/map..rkt)._map))) [cons](http://docs.racket-lang.org/reference/pairs.html#(def._((quote._~23~25kernel)._cons))) ([range](http://docs.racket-lang.org/reference/pairs.html#(def._((lib._racket/list..rkt)._range))) 5) '(a b c d e)))<br>([dict-ref](http://docs.racket-lang.org/reference/dicts.html#(def._((lib._racket/dict..rkt)._dict-ref))) assns 3) ; 'd|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)

- 
    
    [Lists](/explainer/lists.html) explainer
    
- 
    
    [Dictio­naries](http://docs.racket-lang.org/reference/dicts.html) in the Racket Refer­ence
    



### [Struc­ture types](#structure-types)



A _struc­ture type_ is a user-defined data struc­ture with an arbi­trary number of fields. Like a hash table, a struc­ture type allows access to its fields by name. Like a vector, the number of fields is fixed by the struc­ture-type defi­n­i­tion.



The [struct](http://docs.racket-lang.org/reference/define-struct.html#(form._((lib._racket/private/base..rkt)._struct))) form defines the struc­ture type itself, and also manu­fac­tures a [pred­i­cate](/appendix/glossary.html#predicate), plus [getters](/appendix/glossary.html#getter) (and, for mutable struc­ture types, [setters](/appendix/glossary.html#setter)) for each field. The #:transparent option makes the struc­ture type print­able in the REPL:



(struct style (color size weight) #:transparent #:mutable)  
(define s (style "red" 42 'bold))  
s ; (style "red" 42 'bold)  
(style? s) ; #t  
(style-color s) ; "red"  
(set-style-color! s "blue")  
(style-color s) ; "blue"

|   |   |
|---|---|
|1<br>2<br>3<br>4<br>5<br>6<br>7|([struct](http://docs.racket-lang.org/reference/define-struct.html#(form._((lib._racket/private/base..rkt)._struct))) style (color size weight) #:transparent #:mutable)<br>([define](http://docs.racket-lang.org/reference/define.html#(form._((lib._racket/private/base..rkt)._define))) s (style "red" 42 'bold))<br>s ; (style "red" 42 'bold)<br>(style? s) ; #t<br>(style-color s) ; "red"<br>(set-style-color! s "blue")<br>(style-color s) ; "blue"|

![copy to clipboard](/fonts/feather-v1.1/svg/download.svg)



It’s not uncommon for a Rack­e­teer to throw some values into a list as a quick-and-dirty data struc­ture. But for anything that will be used more than once, a struc­ture type is better:

1. 
    
    The getters and setters have read­able names.
    
2. 
    
    The struc­ture type can have fields added to its defi­n­i­tion without changing existing refer­ences.
    
3. 
    
    An instance of a struc­ture type is repre­sented as a single object in memory, so it can be passed around a program “by refer­ence” (meaning, it’s not dupli­cated if passed from one func­tion to another).
    
4. 
    
    A struc­ture type has its own unique pred­i­cate, which can be effi­ciently tested (say, inside a [contract](/explainer/contracts.html)).
    



The disad­van­tage of a struc­ture type is that it’s a distinct data type from a hash table, vector, or list, so it can’t be directly used with library func­tions that consume those types. There’s a little more house­keeping to get values in & out.