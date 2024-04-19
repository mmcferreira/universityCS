;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname 17-raizes-poly) (read-case-sensitive #t) (teachpacks ((lib "gui.rkt" "teachpack" "htdp"))) (htdp-settings #(#t constructor repeating-decimal #t #t none #f ((lib "gui.rkt" "teachpack" "htdp")) #f)))
;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024 
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  seu nome aqui e abaixo
;;
  ;; define a linguagem default ===> Habilite Advanced Student
; ------------------------------------------------
(newline)
(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno(a):  Mateus Magalhães Costa Ferreira ")
(newline)
;;;
;;
;;  Aplicações:  raizes do polinomio Ax^2 + Bx + C = 0
;; ---------------------------------------------------

(define (poly2grau a b c)
  (cond 
    [(= a 0) "degenerada" ]
    [(< (* b b) 
        (* 4 a c)) 
     "Nenhuma Ou Complexa" ]
    [(= (* b b) 
        (* 4 a c)) 
     (/ (- b) (* 2 a))]
    [(> (* b b) 
        (* 4 a c)) 
     (list (/ (+ (- b) 
                 (sqrt (- (* b b) (* 4 a c)))) 
              (* 2 a)) 
           (/ (- (- b) 
                 (sqrt (- (* b b) (* 4 a c)))) 
              (* 2 a)))])) 

;;--------------------------------------
(newline)
(display "Exemplo 1")
(newline)
(display "X^2 + 4 = 0 , Raizes = ")
(poly2grau 1 0 4) 
(display "deveria ser complexa") 
(newline)

(newline)
(display "Exemplo 2")
(newline)
(display "X^2 - 5X + 6 = 0 , Raizes = ")
(poly2grau 1 -5 6) 
(display "deveria ser 3 e 2")
(newline)

(newline)
(display "Exemplo 3")
(newline)
(display "2X^2 - 3X + 1 = 0 , Raizes = ")
(poly2grau 2 -3 1) 
(display "deveria ser 1 e 0.5")
(newline)

(newline)
(display "Exemplo 4")
(newline)
(display "x^2 -4 = 0 , Raizes = ")
(poly2grau 1 0 -4) 
(display "deveria ser 2 e -2")
(newline)

(newline)
(display "Exemplo 5")
(newline)
(display "X^2 + 10X + 25 = 0 , Raizes = ")
(poly2grau 1 10 25) 
(display "deveria ser -5")
(newline)