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
mulher(ivelise).
mulher(claudia).
mulher(leticia).

homem(joao).
homem(ronaldo).
homem(brunno).
homem(marcello).

%PATERNA
mulher(hermogenea).
mulher(nora).
mulher(sandra).
mulher(sueli).
mulher(paula).

homem(domingos).
homem(francisco).
homem(mateus).
homem(andre).

%1º GERAÇÃO MATERNA
mae(celia, telma).
mae(celia, ivelise).
mae(celia, ronaldo).

pai(joao, telma).
pai(joao, ivelise).
pai(joao, ronaldo).

%2º GERAÇÃO MATERNA
mae(telma, mateus).
mae(ivelise, claudia).
mae(ivelise, brunno).
mae(ivelise, marcello).
pai(ronaldo, leticia).


%1º GERAÇÃO PATERNA
mae(hermogenea, francisco).
mae(hermogenea, nora).
mae(hermogenea, sandra).

pai(domingos, francisco).
pai(domingos, nora).
pai(domingos, sandra).

%2º GERAÇÃO PATERNA
pai(francisco,mateus).
pai(francisco,andre).
mae(nora, sueli).
mae(sandra, paula).
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