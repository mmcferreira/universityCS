;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui

;;;;;;;;;;;;;;;;   Escolha a linguagem R5RS
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães C. Ferreira ")
(newline)
;;--------------------------------------
(define dobro
  (lambda (x)
    (* x 2)))
;;---------------------------------------------
(define par-ou-impar
  (lambda (x)
    (if (even? x)
        "Par"
        "Ímpar")))

;;---------------------------------------------
;;---------------------------------------------

;;----------- Executando funcoes --------------
(newline)
(display "O dobro do número 25 é: ")
(dobro 25)
(display "O número 40 é par ou ímpar? É:")
(par-ou-impar 40)