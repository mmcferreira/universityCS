#lang racket
;; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
(newline)
;; ------------------------------------------------
;; Definição das listas
(define lista1 '(30 31 32 33 34))
(define lista2 '(35 36))
(define nova-lista (append lista1 lista2))
;; ------------------------------------------------
;; Operações com as listas
(define primeiro-elemento1 (car lista1))
(define ultimo-elemento1 (last lista1))

(define primeiro-elemento2 (car lista2))
(define ultimo-elemento2 (last lista2))

(define comprimento1 (length lista1))
(define comprimento2 (length lista2))
(define comprimento3 (length nova-lista))
;; ------------------------------------------------
(display "Primeira Lista: ")
(display lista1)
(newline)

(display "Segunda Lista: ")
(display lista2)
(newline)
(newline)

(display "Primeiro elemento da primeira lista: ")
(display primeiro-elemento1)
(newline)

(display "Último elemento da primeira lista: ")
(display ultimo-elemento1)
(newline)
(newline)

(display "Primeiro elemento da segunda lista: ")
(display primeiro-elemento2)
(newline)

(display "Último elemento da segunda lista: ")
(display ultimo-elemento2)
(newline)
(newline)

(display "Comprimento da primeira lista: ")
(display comprimento1)
(newline)

(display "Comprimento da segunda lista: ")
(display comprimento2)
(newline)
(newline)

(display "Nova lista, concatenada das listas 1 e 2: ")
(display nova-lista)
(newline)
(display "Comprimento da nova lista: ")
(display comprimento3)
(newline)
