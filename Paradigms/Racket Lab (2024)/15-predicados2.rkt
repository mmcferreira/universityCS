#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Sou o aluno(a):  Mateus Magalhães Costa Ferreira ")
(newline)
; ------------------------------------------------
(define (test-char? char)
  (char? char))

(define (test-char-m? char)
  (displayln (format "O caractere ~a é válido? ~a" char (if (test-char? char) "Sim" "Não"))))

(define (test-char-14? char)
  (displayln (format "O caractere ~a é válido? ~a" char (if (test-char? char) "Sim" "Não"))))

(define (test-char-b? char)
  (displayln (format "O caractere ~a é válido? ~a" char (if (test-char? char) "Sim" "Não"))))

(test-char-m? 'm)
(test-char-14? 14)
(test-char-b? #\b)
(test-char-m? #\m)
