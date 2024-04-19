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
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;; ---------------------------------------------------
(define (calcular-media notas)
  (define numero-notas (length notas)) 
  (define media (/ (apply + notas) numero-notas))
  
  (display "Notas fornecidas: ")
  (display notas)
  (newline)
  (display "Média das notas: ")
  (display media)
  (newline)
  
  (if (>= media 6.0)
      (display "Aprovado")
      (display "Reprovado")))

(define notas-exemplo '(5.0 7.5 8.0))
(display "Notas do Aluno A: ")
(display notas-exemplo)
(newline)
(calcular-media notas-exemplo)
(newline)
(newline)

(define outras-notas '(2.1 7.3 3.2))
(display "Notas do Aluno B: ")
(display outras-notas)
(newline)
(calcular-media outras-notas)
(newline)