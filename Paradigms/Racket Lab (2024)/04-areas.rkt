;; Introdução à Linguagem Scheme-Racket
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui

;;;;;;;;;;;;;;;;   Escolha a linguagem "Determine language from source"
;;
#lang racket      ;; define a linguagem default
; ------------------------------------------------

(display "  UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "  Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "  Aluno:  Mateus Magalhães C. Ferreira ")
(newline)
(newline)
;;
;;
;; (define   (nomeFuncao   parametros)  definicao  )
;;
;; AREAS
;; ---------------------------------------------------
(define (area-circulo r) 
  (* 3.14 (* r r))         )

(define (areatriangulo b h)
  (/ (* b h) 2))

(define (areadisco interno externo) 
  (- (area-circulo externo)
     (area-circulo interno)
  )
)

(define (area-quadrado l)
  (* l l)
)

(define (area-trapezio B b h)
  (/(*(+ B b )h)2)
)

(define (area-poligono l n)
  (define pi 3.14)
  (define numerador (* l (sqr n)))
  (define denominador (* 4 (tan (/ pi l))))
  (/ numerador denominador))
;
;--------------------------------------------------------------

(display "Circulo de raio 21   AREA = ")
(area-circulo 21)

(display "Triangulo base=10, altura=15    AREA = ")
(areatriangulo 10 15)

(display "Disco raio menor=12, raio maior=20   AREA = ")
(areadisco 12 20)

(display "Quadrado de lado=20   AREA = ")
(area-quadrado 20)

(display "Quadrado de base maior = 20, base menor = 10 e altura = 5   AREA = ")
(area-trapezio 20 10 5)

(display "Polígono regular de lados = 6 e tamanho dos lados = 10  AREA = ")
(area-poligono 6 10)