#lang racket      ;; define a linguagem default
; ------------------------------------------------
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro), 2024")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;;
;;
;; PARES CONSTANTES
;; ---------------------------------------------------
(define x (cons 13 8))
(define y (cons 21 9))
;; ---------------------------------------------------

(display "O par x é: ")
(display x)
(newline)

(display "O par y é: ")
(display y)
(newline)
(newline)

(display "O primeiro valor de x é: ")
(car x)
(display "O primeiro valor de y é: ")
(car y)
(newline)

(display "O segundo valor de x é: ")
(cdr x)
(display "O segundo valor de y é: ")
(cdr y)

