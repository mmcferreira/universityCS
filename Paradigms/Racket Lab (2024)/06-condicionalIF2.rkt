;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui

;;;;;;;;;;;;;;;;   Escolha a linguagem R5RS
;;
;; Ajuda:  http://docs.racket-lang.org/guide/syntax-overview.html#(part._.Conditionals_with_if__and__or__and_cond)
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães C. Ferreira ")
(newline)
;; ---------------------------------------------------
(define (minMax x y)
  (if (< x y)
      (display "x é menor que y\n")
      (display "x não é menor que y\n"))
  
  (if (= x 10)
      (display "x é igual a 10\n")
      (display "x não é igual a 10\n")))

;; Chamada da função minMax com diferentes valores
(newline)
(minMax 5 8)
(newline)
(minMax 12 5)
(newline)
(minMax 10 15)