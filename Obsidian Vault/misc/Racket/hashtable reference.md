<html>
	<h2 style="font-family:courier;color:#FF0064">
		Hash Tables
	</h2>
</html>

A hash table (or simply hash) maps each of its keys to a single value. For a given hash table, keys are equivalent via [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29), [equal-always?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal-always~3f%29%29), [eqv?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eqv~3f%29%29), or [eq?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eq~3f%29%29), and keys are retained either strongly, weakly (see [Weak Boxes](weakbox.html)), or like [ephemerons](ephemerons.html#%28tech._ephemeron%29). A hash table is also either mutable or immutable. Immutable hash tables support effectively constant-time access and update, just like mutable hash tables; the constant on immutable operations is usually larger, but the functional nature of immutable hash tables can pay off in certain algorithms. Use [immutable?](booleans.html#%28def._%28%28quote._~23~25kernel%29._immutable~3f%29%29) to check whether a hash table is immutable.

> > > Immutable hash tables actually provide O(log N) access and update. Since N is limited by the address space so that log N is limited to less than 30 or 62 (depending on the platform), log N can be treated reasonably as a constant.

For [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29)-based hashing, the built-in hash functions on [strings](strings.html#%28tech._string%29), [pairs](pairs.html#%28tech._pair%29), [lists](pairs.html#%28tech._list%29), [vectors](vectors.html#%28tech._vector%29), [prefab](structures.html#%28tech._prefab%29) or transparent [structures](structures.html#%28tech._structure%29), etc., take time proportional to the size of the value. The hash code for a compound data structure, such as a list or vector, depends on hashing each item of the container, but the depth of such recursive hashing is limited (to avoid potential problems with cyclic data). For a non-[list](pairs.html#%28tech._list%29) [pair](pairs.html#%28tech._pair%29), both [car](pairs.html#%28def._%28%28quote._~23~25kernel%29._car%29%29) and [cdr](pairs.html#%28def._%28%28quote._~23~25kernel%29._cdr%29%29) hashing is treated as a deeper hash, but the [cdr](pairs.html#%28def._%28%28quote._~23~25kernel%29._cdr%29%29) of a [list](pairs.html#%28tech._list%29) is treated as having the same hashing depth as the list.

A hash table can be used as a two-valued [sequence](sequences.html#%28tech._sequence%29) (see [Sequences](sequences.html)). The keys and values of the hash table serve as elements of the sequence (i.e., each element is a key and its associated value). If a mapping is added to or removed from the hash table during iteration, then an iteration step may fail with [exn:fail:contract](exns.html#%28def._%28%28lib._racket%2Fprivate%2Fbase..rkt%29._exn~3afail~3acontract%29%29), or the iteration may skip or duplicate keys and values. See also [in-hash](sequences.html#%28def._%28%28lib._racket%2Fprivate%2Fbase..rkt%29._in-hash%29%29), [in-hash-keys](sequences.html#%28def._%28%28lib._racket%2Fprivate%2Fbase..rkt%29._in-hash-keys%29%29), [in-hash-values](sequences.html#%28def._%28%28lib._racket%2Fprivate%2Fbase..rkt%29._in-hash-values%29%29), and [in-hash-pairs](sequences.html#%28def._%28%28lib._racket%2Fprivate%2Fbase..rkt%29._in-hash-pairs%29%29).

Two hash tables cannot be [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29) unless they have the same mutability, use the same key-comparison procedure ([equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29), [equal-always?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal-always~3f%29%29), [eqv?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eqv~3f%29%29), or [eq?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eq~3f%29%29)), both hold keys strongly, weakly, or like [ephemerons](ephemerons.html#%28tech._ephemeron%29). Empty immutable hash tables are [eq?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eq~3f%29%29) when they are [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29).

Changed in version 7.2.0.9 of package base: Made empty immutable hash tables [eq?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eq~3f%29%29) when they are [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29).

Caveats concerning concurrent modification: A mutable hash table can be manipulated with [hash-ref](#%28def._%28%28quote._~23~25kernel%29._hash-ref%29%29), [hash-set!](#%28def._%28%28quote._~23~25kernel%29._hash-set%21%29%29), and [hash-remove!](#%28def._%28%28quote._~23~25kernel%29._hash-remove%21%29%29) concurrently by multiple threads, and the operations are protected by a table-specific semaphore as needed. Several caveats apply, however:

- If a thread is terminated while applying [hash-ref](#%28def._%28%28quote._~23~25kernel%29._hash-ref%29%29), [hash-ref-key](#%28def._%28%28quote._~23~25kernel%29._hash-ref-key%29%29), [hash-set!](#%28def._%28%28quote._~23~25kernel%29._hash-set%21%29%29), [hash-remove!](#%28def._%28%28quote._~23~25kernel%29._hash-remove%21%29%29), [hash-ref!](#%28def._%28%28lib._racket%2Fprivate%2Fmore-scheme..rkt%29._hash-ref%21%29%29), [hash-update!](#%28def._%28%28lib._racket%2Fprivate%2Fmore-scheme..rkt%29._hash-update%21%29%29), or [hash-clear!](#%28def._%28%28quote._~23~25kernel%29._hash-clear%21%29%29) to a hash table that uses [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29), [equal-always?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal-always~3f%29%29), or [eqv?](Equality.html#%28def._%28%28quote._~23~25kernel%29._eqv~3f%29%29) key comparisons, all current and future operations on the hash table may block indefinitely.
    
- The [hash-map](#%28def._%28%28quote._~23~25kernel%29._hash-map%29%29), [hash-for-each](#%28def._%28%28quote._~23~25kernel%29._hash-for-each%29%29), and [hash-clear!](#%28def._%28%28quote._~23~25kernel%29._hash-clear%21%29%29) procedures do not use the table’s semaphore to guard the traversal as a whole (if a traversal is needed, in the case of [hash-clear!](#%28def._%28%28quote._~23~25kernel%29._hash-clear%21%29%29)). Changes by one thread to a hash table can affect the keys and values seen by another thread part-way through its traversal of the same hash table.
    
- The [hash-update!](#%28def._%28%28lib._racket%2Fprivate%2Fmore-scheme..rkt%29._hash-update%21%29%29) and [hash-ref!](#%28def._%28%28lib._racket%2Fprivate%2Fmore-scheme..rkt%29._hash-ref%21%29%29) functions use a table’s semaphore independently for the [hash-ref](#%28def._%28%28quote._~23~25kernel%29._hash-ref%29%29) and [hash-set!](#%28def._%28%28quote._~23~25kernel%29._hash-set%21%29%29) parts of their functionality, which means that the update as a whole is not “atomic.”
    
- Adding a mutable hash table as a key in itself is trouble on the grounds that the key is being mutated (see the caveat below), but it is also a kind of concurrent use of the hash table: computing a hash table’s hash code may require waiting on the table’s semaphore, but the semaphore is already held for modifying the hash table, so the hash-table addition can block indefinitely.
    

Caveat concerning mutable keys: If a key in an [equal?](Equality.html#%28def._%28%28quote._~23~25kernel%29._equal~3f%29%29)-based hash table is mutated (e.g., a key string is modified with [string-set!](strings.html#%28def._%28%28quote._~23~25kernel%29._string-set%21%29%29)), then the hash table’s behavior for insertion and lookup operations becomes unpredictable.

A literal or printed hash table starts with #hash, #hashalw, #hasheqv, or #hasheq. See [Reading Hash Tables](reader.html#%28part._parse-hashtable%29) for information on [read](Reading.html#%28def._%28%28quote._~23~25kernel%29._read%29%29)ing hash tables and [Printing Hash Tables](printing.html#%28part._print-hashtable%29) for information on [print](Writing.html#%28def._%28%28quote._~23~25kernel%29._print%29%29)ing hash tables.

```
(hash? v) → boolean?
	v : (any/c)
Returns #t if v is a hash table, #f otherwise.

(hash-equal? hash) → boolean?
	hash : hash?
Returns #t if hash compares keys with equal?, #f if it compares with eq?, eqv?, or equal-always?.

(hash-eq? hash) → boolean?
	hash : hash?
Returns #t if hash compares keys with eq?, #f if it compares with equal?, eqv?, or equal-always?.

(hash-eqv? hash) → boolean?
	hash : hash?
Returns #t if hash compares keys with eqv?, #f if it compares with equal?, eq?, or equal-always?.

(hash-equal-always? hash) → boolean?
	hash : hash?
Returns #t if hash compares keys with equal-always?, #f if it compares with equal?, eqv?, or eq?.



(hash-strong? hash) → boolean?
	hash : hash?
Returns #t if hash retains its keys strongly, #f if it retains keys weakly or like ephemerons.

(hash-weak? hash) → boolean?
	hash : hash?
Returns #t if hash retains its keys weakly, #f if it retains keys strongly or like ephemerons.

(hash-ephemeron? hash) → boolean?
	hash : hash?
Returns #t if hash retains its keys like ephemeron, #f if it retains keys weakly or strongly.

(hash key val ... ...) → (and/c hash? hash-equal? immutable? hash-strong?)
	key : any/c
	val : any/c



(hashalw key val ... ...) → (and/c hash? hash-equal-always? immutable? hash-strong?)
	key : any/c
	val : any/c

(hasheq key val ... ...) → (and/c hash? hash-eq? immutable? hash-strong?)
	key : any/c
	val : any/c

(hasheqv key val ... ...) → (and/c hash? hash-eqv? immutable? hash-strong?)
	key : any/c
	val : any/c

Creates an immutable hash table with each given key mapped to the following val; each key must have a val, so the total number of arguments to hash must be even.

The hash procedure creates a table where keys are compared with equal?, hashalw creates a table where keys are compared with equal-always?, hasheq procedure creates a table where keys are compared with eq?, hasheqv procedure creates a table where keys are compared with eqv?.



(make-hash [assocs]) → (and/c hash? hash-equal? (not/c immutable?) hash-strong?)
(make-hashalw [assocs]) → (and/c hash? hash-equal-always? (not/c immutable?) hash-strong?)
(make-hasheq [assocs]) → (and/c hash? hash-eq? (not/c immutable?) hash-strong?)
(make-hasheqv [assocs]) → (and/c hash? hash-eqv? (not/c immutable?) hash-strong?)

Creates a mutable hash table that holds keys strongly.


The make-hash procedure creates a table where keys are compared with equal?, make-hashalw creates a table where keys are compared with equal-always?, make-hasheq procedure creates a table where keys are compared with eq?, make-hasheqv procedure creates a table where keys are compared with eqv?.




(make-weak-hash [assocs]) → (and/c hash? hash-equal? (not/c immutable?) hash-weak?)
(make-weak-hashalw [assocs]) → (and/c hash? hash-equal-always? (not/c immutable?) hash-weak?)
(make-weak-hasheq [assocs]) → (and/c hash? hash-eq? (not/c immutable?) hash-weak?)
(make-weak-hasheqv [assocs]) → (and/c hash? hash-eqv? (not/c immutable?) hash-weak?)

Creates a mutable hash table that holds keys weakly.


Beware that values in a weak hash table are retained normally. If a value in the table refers back to its key, then the table will retain the value and therefore the key; the mapping will never be removed from the table even if the key becomes otherwise inaccessible. To avoid that problem, use an ephemeron hash table.




(make-ephemeron-hash [assocs]) → (and/c hash? hash-equal? (not/c immutable?) hash-ephemeron?)
(make-ephemeron-hashalw [assocs]) → (and/c hash? hash-equal-always? (not/c immutable?) hash-ephemeron?)
(make-ephemeron-hasheq [assocs]) → (and/c hash? hash-eq? (not/c immutable?) hash-ephemeron?)
(make-ephemeron-hasheqv [assocs]) → (and/c hash? hash-eqv? (not/c immutable?) hash-ephemeron?)

Like the make-hash ones, but creates a mutable hash table that holds key-value combinations in the same way as an ephemeron.
```


```

//mutable hash
(hash-set! hash key v) → void?
	hash : (and/c hash? (not/c immutable?))
	key : any/c
	v : any/c

Maps key to v in hash, overwriting any existing mapping for key.

(hash-set*! hash key v ... ...) → void?
	hash : (and/c hash? (not/c immutable?))
	key : any/c
	v : any/c

Maps each key to each v in hash, overwriting any existing mapping for each key. Mappings are added from the left, so later mappings overwrite earlier mappings.



//immutable hash
(hash-set hash key v) → (and/c hash? immutable?)
	hash : (and/c hash? immutable?)
	key : any/c
	v : any/c

Functionally extends hash by mapping key to v, overwriting any existing mapping for key, and returning the extended hash table.

(hash-set* hash key v ... ...) → (and/c hash? immutable?)
	hash : (and/c hash? immutable?)
	key : any/c
	v : any/c

Functionally extends hash by mapping each key to v, overwriting any existing mapping for each key, and returning the extended hash table. Mappings are added from the left, so later mappings overwrite earlier mappings.


(hash-ref hash key [failure-result]) → [any]
	hash : hash?
	key : any/c
	failure-result: failure-result/c = (lambda () (raise (make-exn:fail:contract ....)))

Returns the value for key in hash. If no value is found for key, then failure-result determines the result:

- If failure-result is a procedure, it is called (through a tail call) with no arguments to produce the result.

- Otherwise, failure-result is returned as the result.


(hash-ref-key hash key [failure-result]) → [any]
	hash : hash?
	key : any/c
	failure-result: failure-result/c = (lambda () (raise (make-exn:fail:contract ....)))

Returns the key held by hash that is equivalent to key according to hash’s key-comparison function. If no key is found, then failure-result is used as in hash-ref to determine the result.

If hash is not an impersonator, then the returned key, assuming it is found, will be eq?-equivalent to the one actually retained by hash:



If a mutable hash is updated multiple times using keys that are not eq?-equivalent but are equivalent according to the hash’s key-comparison procedure, the hash retains the first one.


Conversely, an immutable hash retains the key that was most-recently used to update it.


If hash is an impersonator, then the returned key will be determined as described in the documentation to impersonator-hash.

(hash-ref hash key to-set) → [any]
	hash : hash?
	key : any/c
	to-set: failure-result/c

Returns the value for key in hash. If no value is found for key, then to-set determines the result as in hash-ref (i.e., it is either a thunk that computes a value or a plain value), and this result is stored in hash for the key. (Note that if to-set is a thunk, it is not invoked in tail position.)


([hash-has-key? hash key) → [boolean?]
	hash : hash?
	key : any/c

Returns #t if hash contains a value for the given key, #f otherwise.

([hash-update! hash key updater [failure-result] → void?
	hash : (and/c hash? (not/c immutable?))
	key : any/c
	updater : (any/c . -> . any/c
	failure-result: failure-result/c = (lambda () (raise (make-exn:fail:contract ....)))

Updates the value mapped by key in hash by applying updater to the value. The value returned by updater becomes the new mapping for key, overwriting the original value in hash.

The optional failure-result argument is used when no mapping exists for key already, in the same manner as in hash-ref.


(hash-update hash key updater [failure-result] → (and/c hash? immutable?)
	hash : (and/c hash? immutable?)
	key : any/c
	updater : (any/c . -> . any/c)
	failure-result : failure-result/c = (lambda () (raise (make-exn:fail:contract ....)))

Functionally updates the value mapped by key in hash by applying updater to the value and returning a new hash table. The value returned by updater becomes the new mapping for key in the returned hash table.

The optional failure-result argument is used when no mapping exists for key already, in the same manner as in [hash-ref](#%28def._%28%28quote._~23~25kernel%29._hash-ref%29%29).


(hash-remove! hash key) → void?
	hash : (and/c hash? (not/c immutable?))
	key : any/c

Removes any existing mapping for key in hash.


(hash-remove hash key) → (and/c hash? immutable?)
	hash : (and/c hash? immutable?)
	key : any/c

Functionally removes any existing mapping for key in hash, returning hash (i.e., a result eq? to hash) if key is not present in hash.


(hash-clear! hash) → void?
	hash : (and/c hash? immutable?)

Removes all mappings from hash.

If hash is not an impersonator, then all mappings are removed in constant time. If hash is an impersonator, then each key is removed one-by-one using hash-remove!.


(hash-clear hash) → (and/c hash? immutable?)
	hash : (and/c hash? immutable?)

Functionally removes all mappings from hash.

If hash is not a chaperone, then clearing is equivalent to creating a new hash table, and the operation is performed in constant time. If hash is a chapreone, then each key is removed one-by-one using hash-remove.



(hash-copy-clear hash [#:kind kind]) → hash?
	hash : hash?
	kind : (or/c #f 'immutable 'mutable 'weak 'ephemeron) = #f

Produces an empty hash-table with the same key-comparison procedure as hash, with either the given kind or the same kind as the given hash.

If kind is not supplied or #f, produces a hash table of the same kind and mutability as the given hash. If kind is 'immutable, 'mutable, 'weak, or 'ephemeron, produces a table that’s immutable, mutable with strongly-held keys, mutable with weakly-held keys, or mutable with ephemeron-held keys respectively.



(hash-map hash proc [try-order?]) → (listof any/c)
	hash : hash?
	proc : (any/c any/c . -> . any/c)
	try-order? : any/c = #f

Applies the procedure proc to each element in hash in an unspecified order, accumulating the results into a list. The procedure proc is called each time with a key and its value, and the procedure’s individual results appear in order in the result list.

If a hash table is extended with new keys (either through proc or by another thread) while a hash-map or hash-for-each traversal is in process, arbitrary key–value pairs can be dropped or duplicated in the traversal. Key mappings can be deleted or remapped (by any thread) with no adverse affects; the change does not affect a traversal if the key has been seen already, otherwise the traversal skips a deleted key or uses the remapped key’s new value.



(hash-map/copy hash proc [#:kind kind]) → hash?
	hash : hash?
	proc : (any/c any/c . -> . (values any/c any/c))
	kind : (or/c #f 'immutable 'mutable 'weak 'ephemeron) = #f

Applies the procedure proc to each element in hash in an unspecified order, accumulating the results into a new hash with the same key-comparison procedure as hash, with either the given kind or the same kind as the given hash.

If kind is not supplied or #f, produces a hash table of the same kind and mutability as the given hash. If kind is 'immutable, 'mutable, 'weak, or 'ephemeron, produces a table that’s immutable, mutable with strongly-held keys, mutable with weakly-held keys, or mutable with ephemeron-held keys respectively.


(hash-keys hash [try-order?]) → (listof any/c)
	hash : hash?
	try-order? : any/c = #f

Returns a list of the keys of hash in an unspecified order.

If try-order? is true, then the order of keys is normalized under certain circumstances. See hash-map for further explanations on try-order? and on information about modifying hash during hash-keys.



(hash-values hash [try-order?]) → (listof any/c)
	hash : hash?
	try-order? : any/c = #f

Returns a list of the values of hash in an unspecified order.

If try-order? is true, then the order of values is normalized under certain circumstances, based on the ordering of the associated keys. See hash-map for further explanations on try-order? and on information about modifying hash during hash-keys.


(hash->list hash [try-order?]) → (listof any/c)
	hash : hash?
	try-order? : any/c = #f

Returns a list of the key–value pairs of hash in an unspecified order.

If try-order? is true, then the order of keys and values is normalized under certain circumstances. See hash-map for further explanations on try-order? and on information about modifying hash during hash-keys.


(hash-keys-subset? hash1 hash2) → boolean?
	hash1 : hash?
	hash2 : hash?

Returns #t if the keys of hash1 are a subset of or the same as the keys of hash2. The hash tables must both use the same key-comparison function (eq?, eqv?, equal?, equal-always?), otherwise the exn:fail:contract exception is raised.

Using hash-keys-subset? on immutable hash tables can be much faster than iterating through the keys of hash1 to make sure that each is in hash2.



(hash-for-each hash proc [try-order?]) → void?
	hash : hash?
	proc : (any/c any/c . -> . any/c)
	try-order? : any/c = #f

Applies proc to each element in hash (for the side-effects of proc) in an unspecified order. The procedure proc is called each time with a key and its value.



(hash-count hash) → exact-nonnegative-integer?
	hash : hash?

Returns the number of keys mapped by hash.


(hash-empty? hash) → boolean?
	hash : hash?

Equivalent to (zero? (hash-count hash)).

(hash-iterate-first hash) → (or/c #f exact-nonnegative-integer?)
	hash : hash?

Returns #f if hash contains no elements, otherwise it returns an integer that is an index to the first element in the hash table; “first” refers to an unspecified ordering of the table elements, and the index values are not necessarily consecutive integers.

For a mutable hash, this index is guaranteed to refer to the first item only as long as no items are added to or removed from hash. More generally, an index is guaranteed to be a valid hash index for a given hash table only as long it comes from hash-iterate-first or hash-iterate-next, and only as long as the hash table is not modified. In the case of a hash table with weakly held keys or keys held like ephemerons, the hash table can be implicitly modified by the garbage collector (see Garbage Collection) when it discovers that the key is not reachable.


(hash-iterate-next hash pos) → (or/c #f exact-nonnegative-integer?)
	hash : hash?
	pos : exact-nonnegative-integer?

Returns either an integer that is an index to the element in hash after the element indexed by pos (which is not necessarily one more than pos) or #f if pos refers to the last element in hash.

If pos is not a valid hash index of hash, then the result may be #f or it may be the next later index that remains valid. The latter result is guaranteed if a hash table has been modified only by the removal of keys.



(hash-iterate-key hash pos) → any/c
	hash : hash?
	pos : exact-nonnegative-integer?

(hash-iterate-key hash pos bad-index-v) → any/c
	hash : hash?
	pos : exact-nonnegative-integer?
	bad-index-v : any/c

Returns the key for the element in hash at index pos.

If pos is not a valid hash index of hash, then the result is bad-index-v if bad-index-v is provided, otherwise the exn:fail:contract exception is raised.





(hash-iterate-value hash pos) → any/c
	hash : hash?
	pos : exact-nonnegative-integer?

(hash-iterate-value hash pos bad-index-v) → any/c
	hash : hash?
	pos : exact-nonnegative-integer?
	bad-index-v : any/c

Returns the value for the element in hash at index pos.

If pos is not a valid hash index of hash, then the result is bad-index-v if bad-index-v is provided, otherwise the exn:fail:contract exception is raised.


(hash-iterate-pair hash pos) → (cons any/c any/c)
	hash : hash?
	pos : exact-nonnegative-integer?

(hash-iterate-pair hash pos bad-index-v) → (cons any/c any/c)
	hash : hash?
	pos : exact-nonnegative-integer?
	bad-index-v : any/c

Returns a pair containing the key and value for the element in hash at index pos.

If pos is not a valid hash index of hash, then the result is (cons any/c any/c) if bad-index-v is provided, otherwise the exn:fail:contract exception is raised.





(hash-iterate-key+value hash pos) → any/c any/c
	hash : hash?
	pos : exact-nonnegative-integer?

(hash-iterate-key+value hash pos bad-index-v) → any/c any/c
	hash : hash?
	pos : exact-nonnegative-integer?
	bad-index-v : any/c

Returns the key and value for the element in hash at index pos.

If pos is not a valid hash index of hash, then the result is (values bad-index-v bad-index-v) if bad-index-v is provided, otherwise the exn:fail:contract exception is raised.






(hash-clear hash) → (and/c hash? immutable?)
	hash : hash?

Returns a mutable hash table with the same mappings, same key-comparison mode, and same key-holding strength as hash.
```