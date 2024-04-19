#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Sou o aluno(a):  Mateus Magalhães Costa Ferreira ")
(newline)
; ------------------------------------------------
(display "Teste Lógicos:")
(newline)

(define x 35)
(define y 10)
  
(define teste1 (and (> x 20) (< x 49)))
(define teste2 (and (> y 6) (< y 8)))
(define teste3 (or teste1 teste2))
(define teste4 (not teste1))
(define teste5 (not (> (/ x y) 5)))

(display "Resultado 1 (x): 35 é maior que 20 E menor que 49?")
(newline)
(display teste1)
(newline)
(newline)

(display "Resultado 2 (y): 10 é maior que 6 E menor que 30?")
(newline)
(display teste2)
(newline)
(newline)

(display "Resultado 3: teste 1 OU 2 está certo?")
(newline)
(display teste3)
(newline)
(newline)

(display "Resultado 4: teste 1 NÃO está certo?")
(newline)
(display teste4)
(newline)
(newline)

(display "Resultado 5: x/y NÃO é maior que 5?")
(newline)
(display teste5)
(newline)
(newline)