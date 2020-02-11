(def do-n-times
  (fn (^num n ^func thingtodo)
    (if (= n 0) 
       nil
       (do
         (thingtodo)
         (do-n-times 
           (add n -1)
           thingtodo)))))

(do-n-times 3 (fn (^any) (println "HI!")))

(do-n-times "hello" "bye")