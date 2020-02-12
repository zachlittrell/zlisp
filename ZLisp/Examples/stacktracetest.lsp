
(println
  ( (fn (x) x)
    (reduce add 0 (list 1 2 3 "4"))))