#lang racket
;; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;; ------------------------------------------------
;; Definição das listas
(define listaA '(1 2 3 4))
(define listaB '(5 6 7 8 9))
;; ------------------------------------------------
;; Operação com as listas
;;( 4  7  2  9 8 7  1  6  2  3  4)
(define nova-lista
  (append (list (list-ref listaA 3) (list-ref listaB 2) (list-ref listaB 4)) (rest (reverse listaB)) (rest listaA)))
;; ------------------------------------------------
(display "Nova lista: ")
(display nova-lista)
(newline)