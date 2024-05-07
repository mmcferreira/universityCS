% programa  02-familia-B.pl
%
% Prof. Ausberto S. Castro Vera
% Disciplina : Paradigmas de Ling. de Programacao
% UENF-CCT-LCMAT-CC
% Date: 2024
% Aluno: Mateus Magalhães Costa Ferreira
%-------------------------------------------------
 % FATOS

    mulher(luisa).  % significa luisa � uma mulher
    mulher(eva).
    mulher(martha).
    mulher(suzana).

    homem(adam).
    homem(pedro).
    homem(paulo).

    pai(adam,pedro). % significa adam � pai de pedro
    pai(adam,paulo).
    pai(adam,luisa).
   
    mae(eva,luisa).
    mae(eva,pedro).
    mae(eva,maria).
    mae(martha,suzana).

    marido(adam,eva).
    esposa(eva,adam).

    filha(maria,eva).
    filha(luisa,adam).
    filha(suzana,martha).

    irma(eva,martha).

 % REGRAS

    filho(F,P):-homem(F),pai(P,F).
    filho(F,M):-homem(F),mae(M,F).
    
    filha(F,P):-mulher(F),pai(P,F).
    filha(F,M):-mulher(F),mae(M,F).

% Completar as regras:
    irma(X,Y) :- mulher(X),(pai(P,X),pai(P,Y);mae(M,X),mae(M,Y)), X\=Y.
    irmao(X,Y) :- homem(X),(pai(P,X),pai(P,Y);mae(M,X),mae(M,Y)), X\=Y.
    prima(X,Y) :- mulher(X), mulher(Y), pai(PX,X), mae(MX,X), (pai(PY,Y);mae(MY,Y)), (irmao(PX,PY);irma(MX,MY)), X\=Y.
    tia(X,Y) :- mulher(X), (mae(M,Y),irma(X,M);pai(P,Y),irma(X,P)).

