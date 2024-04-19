#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
;; Função para calcular o fatorial de um número de forma iterativa
(define (fatorial-iter N)
  (define (fat-iter produto contador max-cont)
    (if (> contador max-cont)
        produto
        (fat-iter (* contador produto)
                   (+ contador 1)
                   max-cont)))
  (fat-iter 1 1 N))

;; Exemplo de uso
(display "Fatorial de 5 (iterativo) = ")
(display (fatorial-iter 5))
(newline)

(display "Fatorial de 10 (iterativo) = ")
(display (fatorial-iter 10))
(newline)
