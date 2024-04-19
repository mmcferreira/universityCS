;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname 20-estruturas) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
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
(display "  Aluno(a):  Mateus Magalhães C. Ferreira ")
(newline)
;;Definindo as Estruturas
;----------------------------------------------------------------------------
(define-struct moto (modelo cor ano))
(define-struct cidade (nome estado populacao))
(define-struct carro (marca modelo ano))
;----------------------------------------------------------------------------
;;Definindo interior
(define minha-moto (make-moto 'Honda 'Vermelho 2024))
(define minha-cidade (make-cidade 'RioDeJaneiro 'RJ 6747815))
(define meu-carro (make-carro 'Toyota 'Corolla 2024))
;----------------------------------------------------------------------------
;;Usando suas especificações
(newline)
(display "A marca do meu carro é: ")
(carro-marca meu-carro)

(newline)
(display "O ano da minha moto é:")
(moto-ano minha-moto)

(newline)
(display "O estado da minha cidade é:")
(cidade-estado minha-cidade)
