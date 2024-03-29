;Return the level of a node X in a tree of type (1). The level of the root element is 0.

; pargurg_st(l1l2...ln, nrNoduri, nrMuchii) = 
; = nil, if n = 0
; = nil, if nrNoduri = 1 + nrMuchii
; = {l1} U {l2} U parcurg_st(l3...ln, nrNoduri + 1, l2 + nrMuchii), otherwise

; Traverses theleft subtree 
; (= nrNoduri ( + 1 nrMuchii)) nil) -> end condition

(defun parcurg_st (l nrNoduri nrMuchii)
  (cond
    ((null l) nil)
    ((= nrNoduri ( + 1 nrMuchii)) nil)
    (t (cons (car l) (cons (cadr l) (parcurg_st (cddr l) (+ 1 nrNoduri) (+ (cadr l) nrMuchii)))))
  )
)


; parcurg_dr(l1l2...ln, nrNoduri, nrMuchii) =
; = nil, if n = 0
; = l1l2...ln, if nrNoduri = 1 + nrMuchii
; = parcurg_dr(l3...ln, nrNoduri + 1, nrMuchii + l2), otherwise


;same end condition as parcurg_st
;used for traversing the right subtree of a node

(defun parcurg_dr (l nrNoduri nrMuchii)
  (cond
    ((null l) nil)
    ((= nrNoduri (+ 1 nrMuchii)) l)
    (t (parcurg_dr (cddr l) (+ 1 nrNoduri) (+ (cadr l) nrMuchii)))
  )
)


;stang(l1l2...ln) = 
; = parcurg_st(l3...ln, 0,0)

(defun stang(l)
  (parcurg_st (cddr l) 0 0)
)


;drept(l1l2...ln) =
; = parcurg_dr(l3...ln, 0, 0)

(defun drept(l)
  (parcurg_dr (cddr l) 0 0)
)


; myAppend(l1l2...ln, p1p2...pm) = 
; = p1p2...pm, if n = 0
; = {l1} U myAppend(l2...ln, p1p2...pm), otherwise

(defun myAppend(l p)
  (cond
    ((null l) p)
    (t (cons (car l) (myAppend (cdr l) p)))
  )
)


; findLevel(l1l2...ln, elem, level) = 
; = 0, if n = 0
; = level, if l1 = elem
; = findLevel(stang(l), elem, level + 1) + findLevel(drept(l), elem, level + 1)

;recursively calls itself for the left subtree (stang l) and the right subtree (drept l), 
;each time incrementing the level by 1

(defun findLevel(l elem level)
  (cond
    ((null l) 0)
    ((equal (car l) elem) level)
    (t (+ (findLevel (stang l) elem (+ 1 level)) (findLevel (drept l) elem (+ 1 level))))
  )
)


; checkExistence(l1l2...ln, elem) = 
; = true, if l1 = elem
; = false, if n = 0
; = checkExistence(l2...ln, elem), otherwise

(defun checkExistence(l elem)
  (cond 
    ((null l) nil)
    ((equal (car l) elem) t)
    (t (checkExistence (cdr l) elem))
  )
)

(defun main(l elem)
  (cond
    ((checkExistence l elem) (findLevel l elem 0))
    (t -1) ; Return -1 if the element is not found
  )
)