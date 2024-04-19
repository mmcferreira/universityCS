#lang racket      ;; define a linguagem default
; ------------------------------------------------
(newline)
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno(a):  Mateus Magalhães Costa Ferreira ")
(newline)
; ------------------------------------------------
(define (mapeamento x)
  (+ (* x x) (* 3 x) (- 9)))

(define Lista (list 9 49 81 37 83))
(display "Lista: ") (display Lista)
(newline)

(define resultados (map mapeamento Lista))
(display "Resultado do mapeamento: ") (display resultados)
(newline)