# zlisp
Basic toy Lisp interpreter for fun over lunch breaks

## Example code
```clojure
(def fibn 
  (fn (n) 
    (if (< n 2) 
        n 
       (add 
         (fibn 
           (add n -1))
         (fibn
           (add n -2))))))

(map println 
     (map fibn (list 0 1 2 3 4 5)))
```

## Current features
* Anonymous closures with (fn (..) ...)
* Lexical scoping
* Common functions such as map, get, def, do, cons, if
* Objects can be one of 4 types: numbers (doubles), strings, functions, or pairs. 


## TODO
* Implement better error messaging
* Add more numeric functions
* Move cpp and header files into better folder structures
* Change LispVal into an inheritance hierarchy instead of using std::variant
* Re-evaluate the usefulness of piggy-backing off pairs to implement lists
