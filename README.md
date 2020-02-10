# zlisp
Extremely basic Lisp interpreter for fun over lunch breaks

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
