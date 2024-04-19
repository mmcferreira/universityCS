;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; Abril 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;;---------------------------------------------

(define (faixa idade) 
     (cond 
              ((<= idade 0)  "Invalido")
              ((<= idade 10)  "Infancia")
              ((<= idade 14)  "Pre-Adolescencia")
              ((<= idade 19)  "Adolescencia")
              ((<= idade 65)  "Fase Adulta")
              ((<= idade 100)  "Velhice")
              (else "Invalido")  
              )
  ) 

;;---------------------------------------------
(newline)
(display "Pergunte a fase da vida entre 0 e 100 anos.")
(newline)
(display "Fase da Vida para -2 anos: ")
(faixa -2)

(newline)
(display "Fase da Vida para 8 anos: ")
(faixa 8)

(newline)
(display "Fase da Vida para 14 anos: ")
(faixa 14)

(newline)
(display "Fase da Vida para 20 anos: ")
(faixa 20)

(newline)
(display "Fase da Vida para 89 anos: ")
(faixa 89)

(newline)
(display "Fase da Vida para 204 anos: ")
(faixa 204)