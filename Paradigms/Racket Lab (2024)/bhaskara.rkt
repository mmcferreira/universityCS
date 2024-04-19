#lang racket      ;; define a linguagem default
; ------------------------------------------------
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programação (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães Costa Ferreira ")
(newline)
    ;; Função Bhaskara
; ------------------------------------------------
(define (bhaskara a b c)
  (define delta (- (* b b) (* 4 a c)))
  (cond
    ((< delta 0)
     (display "Não há raízes reais para esta equação."))
    ((= delta 0)
     (let ((raiz (- (/ b (* 2 a)))))
       (display "A raiz única é: ")
       (display raiz)))
    (else
     (let ((raiz1 (/ (+ (- b) (sqrt delta)) (* 2 a)))
           (raiz2 (/ (- (- b) (sqrt delta)) (* 2 a))))
       (display "As raízes são: ")
       (display raiz1)
       (display " e ")
       (display raiz2)))))

; ------------------------------------------------
(display "O Bhaskara de 25x^2 - 55x + 10 = 0, é: ")
(newline)
(bhaskara 25 -55 10)