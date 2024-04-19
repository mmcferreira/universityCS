#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "    UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "    Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "    Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;; Definição de expressões
;; ---------------------------------------------------
(newline)
(display "Expressão 1:")
(newline)
(define P (- (- 4(/(- 42 73)8)) (+ 11 (- 5 (- 34 1)))))
(display P)
(newline)
(newline)
(display "Expressão 2:")
(define Q (/ (sqrt (+ (expt 5 2) (sin(- 12 8)) (cos (+ 20 25))) ) (*( - 5 3) (expt (+ 4 8) 2)) ))
(newline)
(display Q)