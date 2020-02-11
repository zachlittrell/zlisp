(def reverse
  (fn (^pair lst)
    (_reverse-help nil lst)))

(def _reverse-help
  (fn (^pair res ^pair lst)
    (if (nil? lst)
      res
      (_reverse-help (cons (head lst) res)
                     (tail lst)))))

(map println (reverse (list 1 2 3 4 5)))