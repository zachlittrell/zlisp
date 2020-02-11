
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