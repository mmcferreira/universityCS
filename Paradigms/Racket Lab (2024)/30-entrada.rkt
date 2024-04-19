;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024 
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  seu nome aqui e abaixo
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------
(newline)
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno(a): Mateus Magalhães Costa Ferreira ")
(newline)
;;
(newline)
(newline)

(display "Escreva QUATRO notas (numeros menores que 10, separados por espaços a  b  c d) : ")
(newline)
(define a (read))
(define b (read))
(define c (read))
(define d (read))

(define media
  (lambda (x y z w)
  (/ (+ (+ (+ x y) z) w) 4)
    ))

(display "A media = ")
(media a b c d)

(if (> (media a b c d) 5)
    (display "Aprovado")
    (display "Reprovado"))
;;--------------------------------------------
;; Defina aqui una media com notas com pesos diferentes
;
; (define MediaPesos ...............

