#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno(a): Mateus Magalhães Costa Ferreira ")
(newline)
; ------------------------------------------------
(newline)
(display "Informações Pessoais")
(newline)
(display "Digite o nome, a altura e o estado natal")
(newline)
(newline)
; ------------------------------------------------
(display "Indivíduo 1:" )
(define nome (read))
(define altura (read))
(define estado (read))
(newline)
; ------------------------------------------------
(display "Indivíduo 2:" )
(define nome2 (read))
(define altura2 (read))
(define estado2 (read))
(newline)
(newline)
; ------------------------------------------------
(display "Informações Pessoais Comparadas")
(newline)
(display "Nomes")
(newline)
(display nome) (display " x ") (display nome2)
(newline)


(display "Alturas")
(newline)
(display altura) (display " x ") (display altura2)
(newline)

(display "Estados natais")
(newline)
(display estado) (display " x ") (display estado2)
(newline)