;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui

;;;;;;;;;;;;;;;;   Escolha a linguagem "Determine language from source"
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------

(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães C. Ferreira ")
(newline)
(newline)
;; AREA DO GALÃO
;; ---------------------------------------------------
(define (volume-galao r a)
  (define pi 3.141)
  (define area-base (* pi (* r r)))
  (define volume (* area-base a))
  volume)
;;--------------------------------------------------------------
(display "Galão de raio = 5 e altura = 10 VOLUME = ")
(volume-galao  5 10)