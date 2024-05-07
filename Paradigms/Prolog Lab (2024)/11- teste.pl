% programa  10-genealogia.pl
%
% Prof. Ausberto S. Castro Vera
% Disciplina : Paradigmas de Ling. de Programacao
% UENF-CCT-LCMAT-CC
% Date: 2024
% Aluno: Mateus Magalhães Costa Ferreira
%-------------------------------------------------
% FATOS

%MATERNA
mulher(celia).
mulher(telma).
homem(joao).
homem(ronaldo).

%1º GERAÇÃO MATERNA
mae(celia, telma).
mae(celia, ivelise).
mae(celia, ronaldo).

pai(joao, telma).
pai(joao, ivelise).
pai(joao, ronaldo).
%-------------------------------------------------
% REGRAS
filho(F, P) :- homem(F), pai(P, F).
filho(F, M) :- homem(F), mae(M, F).

filha(F, P) :- mulher(F), pai(P, F).
filha(F, M) :- mulher(F), mae(M, F).

irmao(X, Y) :- homem(X), ((mae(M, X), mae(M, Y));(pai(P, X), pai(P, Y))), X \= Y.
irma(X, Y) :- mulher(X), ((mae(M, X), mae(M, Y));(pai(P, X), pai(P, Y))), X \= Y.

% Tio e tia
tio(T, X) :- homem(T), ((pai(P, X), irmao(T, P)); (mae(M, X), irmao(T, M))).
tia(X,Y) :- mulher(X), (mae(M,Y),irma(X,M);pai(P,Y),irma(X,P)).

% Primo e prima
primo(P, X) :- homem(P), irmao(I, M), (pai(I, P); mae(I, P)), (pai(M, X); mae(M, X)), P \= X.
prima(P, X) :- mulher(P), irma(I, M), (pai(I, P); mae(I, P)), (pai(M, X); mae(M, X)), P \= X.