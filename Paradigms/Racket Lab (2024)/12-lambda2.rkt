#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro)")
(newline)
(display "  Sou o aluno(a):  Mateus Magalhães Costa Ferreira ")
(newline)
;; ---------------------------------------------------
;;  Função Atraso de Parcela
;;  Prest = valor + (valor*(taxa/100)*tempo)
 (define atrasoDeParcela
  (lambda (valor taxa tempo)
    (+ valor (* (*(/ taxa 100)tempo)valor))
 )
 )
;;----------------------------------------------------
;;  Exemplos
(newline)
(display "Exemplo 1")
(newline)
(display "Prestação em atraso será de R$:")
(atrasoDeParcela 500 10 3)
(newline)

(display "Exemplo 2")
(newline)
(display "Prestação em atraso será de R$:")
(atrasoDeParcela 200 30 50)
(newline)

(display "Exemplo 3")
(newline)
(display "Prestação em atraso será de R$:")
(atrasoDeParcela 20000 12 6)
(newline)

(display "Exemplo 4")
(newline)
(display "Prestação em atraso será de R$:")
(atrasoDeParcela 42 25 80)
(newline)

