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
(display "  Aluno:  Mateus Magalhães C. Ferreira")
(newline)
;;
;;
;; Variáveis e Expressoes LET
;; ---------------------------------------------------
(define y 5)		             ; para y=5
(define m 7)
(define z (+ m 6))	             ; para z = m+ 6
(define Pi 3.141516)
(define k (+ z (- m y)))

(define (quadrado x)            ; (define   (nomeFuncao   parametro)  definicao  )
    (* x x)  )


(define (entre7e18? n)
  (and (< 7 n) (< n 18) )               ;; AND logico
 )
;; ---------------------------------------------------

(newline)
  (display "O numero 8 esta' entre 7 e 18? ")
  (entre7e18? 8)

(newline)
  (display "O numero 37 esta' entre 7 e 18? ")
  (entre7e18? 37)

(newline)
(display "O valor de m é: ")
  (display m)
  (newline)

(display "O valor de z é: ")
  (display z)
  (newline)

(display "O valor de k é: ")
(display k)
(newline)

;; ---------------------------------------------------
; Expressao let:    (let ((var1 valor) ...) expr1  expr2 .....)
(newline)
(let ((x 24))
  (+ x 6))


(let ( (a 5) (b 8))
  (+ 3 (* a b)))


(let ( (op1 +) 
       (op2 *) 
       (x 5)
     )
  (op1 3 (op2 4 x))
)

(let ((a 5))
(* a a)
)


(let (( x 2) (y 10))
(+ (/ y 5) (* 48 x) )
)

(display "O quadrado de 16 : ")(quadrado 16)

