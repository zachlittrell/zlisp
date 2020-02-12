(def sum (fn (^pair  lst) (reduce add 0 lst)))
(println "Print sum of first 10 integers")
(println (sum (list 1 2 3 4 5 6 7 8 9 10)))

(println "Print first 20 powers of 2")
(map println (iterate (fn (^num x) (mult 2 x)) 1 20))

(println "Concatenate two lists")
(map println (concat (list "Hello" "and") (list "Goodbye")))

(println "Size of filtered list")
(def filtered (filter nil? (list nil nil nil 3 nil "hi")))
(println "Filtered")
(println (length filtered))
