;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname 02-numeros) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;; Introdução à Linguagem Racket (Scheme)
;; Prof. Ausberto S. Castro Vera       (ascv@uenf.br)
;; UENF-CCT-LCMAT - Curso de Ciencia da Computacao
;; 2024
;; Aluno: Mateus Magalhães Costa Ferreira      <===========  escreva seu nome aqui
;;
;;;;;;;;;;;;;;;;   Escolha a linguagem "Determine language from source"
;;

; ------------------------------------------------
(display "    UENF-CCT-LCMAT-CC, 2024")
(newline)
(display "    Paradigmas de Linguagens de Programacao (Prof. Ausberto Castro)")
(newline)
(display "    Aluno: Mateus Magalhães C. Ferreira  ")
(newline)
;;
;;
;; Numeros e aritmetica
;; ---------------------------------------------------

(display "Soma 13 + 18 = ")
(+ 13 18)

(display "Produto 57*92 = ")
(* 57 92)

(display "Mistura 7 + (3*9) = ")
(+ 7 (* 3 9))

(display "Combinando (2 + (3*4))/2 - 4 = ")
(- (/ (+ 2 (* 3 4)) 2) 4)

(display "Raiz quadrada de 6  = ")
(sqrt 6)

(display "Raiz quadrada de 14= ")
(sqrt 14)

(display "Complexos - raiz quadrada de -1= ")
(sqrt -1)

;; #i significa "inexato"
(newline)
(display "Valor de Pi+7 ")
(+ pi 7)

(display "Seno 60 graus: ")
(sin (/ pi 3))

(display "Coseno 60 graus: ")
(cos (/ pi 3))

(display "Coseno 45 graus: ")
(cos (/ pi 4))

(display "Logaritmo Natural de 17: ")
(log 17)

(display "exponente 6^3 = ")
(expt 6 3)   

(display "exponente 4^(1/2) = ")
(expt 4 1/2) 

(display "Maximo de  3 32 42 27 3 = ")
(max 3 32 42 27 3)

(display "minimo de  31 3 42 25 9 = ")
(min 31 3 42 25 9)

(display "valor absoluto de 18 = ")
(abs  18)

(display "valor absoluto de -7 = ")
(abs -7) 

;; Expressoes "quote": listas de objetos tratados como dados
;;
(newline)
'"quotes obriga as listas serem tratadas como DADOS"
(quote ( 8 1 9))
(quote (/ 4 (* 3 7)))
'(1 a 9 b)    ;; comentario
'((a b)(9 5))
'(+ 7 (* 5 4) )




