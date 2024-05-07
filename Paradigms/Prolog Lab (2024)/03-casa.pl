% Programa casa.pl
%
% Prof. Ausberto S. Castro Vera
% Disciplina : Paradigmas de Ling. de Programacao
% UENF-CCT-LCMAT-CC
% Ano: 2024
% Aluno: Mateus Magalhães Costa Ferreira
%-------------------------------------------------
%    Ver mapa da casa
%
%------------- FATOS  -----------------------
lugar(sala).
lugar(cozinha).
lugar(escritorio).
lugar(corredor).
lugar('sala de jantar').
lugar(celeiro).
lugar(jardim).

lugar(quarto).
lugar(closet).
lugar(banheiro).

porta(escritorio, corredor).
porta(cozinha, escritorio).
porta(corredor, 'sala de jantar').
porta(cozinha, celeiro).
porta('sala de jantar', cozinha).
porta(quarto, corredor).
porta(banheiro, quarto).
porta(closet, quarto).


localizacao(escrivaninha, escritorio).
localizacao(laranja, cozinha).
localizacao(lanterna, escrivaninha).
localizacao('maq de lavar', celeiro).
localizacao(sabao, 'maq de lavar').
localizacao(verdura, cozinha).
localizacao(faca, cozinha).
localizacao(panela, cozinha).
localizacao(arroz, cozinha).
localizacao(uva, cozinha).
localizacao(biscoitos, cozinha).
localizacao(computador, escritorio).
localizacao(mesa,'sala de jantar').

localizacao(celular, quarto).
localizacao(notebook, quarto).
localizacao(ventilador, quarto).
localizacao(isqueiro, quarto).
localizacao(espelho, banheiro).
localizacao(chuveiro, banheiro).
localizacao(vaso, banheiro).
localizacao('escova de dente', banheiro).
localizacao(casacos, closet).
localizacao('corta vento', closet).
localizacao(camisetas, closet).
localizacao(bermuda, closet).


comestivel(laranja).
comestivel(biscoitos).
comestivel(arroz).
comestivel(uva).

gosto_amargo(verdura).

estamos_em(quarto).

%%---------------  REGRAS --------------------
conectar(X,Y) :- porta(X,Y).
conectar(X,Y) :- porta(Y,X).

lista_coisas(Lugar) :-
           localizacao(X, Lugar),
           tab(2),
           write(X),
           nl,
           fail.
           lista_coisas(Nestelugar).
           
lista_portas(Lugar) :-
           conectar(Lugar, X),
           tab(2),
           write(X),
           nl,
           fail.
           lista_portas(_).
           
observar :- estamos_em(Lugar),
            write('Voce esta na '), write(Lugar), nl,
            write('Voce pode ver:'), nl,
            lista_coisas(Lugar),
            write('Voce pode ir para:'), nl,
            lista_portas(Lugar).

estou(Lugar) :-
    write('Estou no(a): '), write(Lugar), nl,nl,
    write('Posso ver:'), nl,
    lista_coisas(Lugar),
    write('Posso ir para:'), nl,
    lista_portas(Lugar).


lista_comestiveis(Comestivel) :-
    write('Os alimentos comestiveis são: '), nl,
    comestivel(X),
    tab(2),
    write(X),
    nl,
    fail.
    lista_coisas(Coisascomestiveis).

encontrar(T, R) :-
    localizacao(T, R),
    write('O objeto '), write(T), write(' está no(a) '), write(R), nl.

mover(Lugar):- retract(estamos_em(X)), asserta(estamos_em(Lugar)).

posso_ir(Lugar):- estamos_em(X), conectar(X, Lugar).
posso_ir(Lugar):- write('Voce nao pode ir de aqui para '), write(Lugar), nl, fail.

goto(Lugar):- posso_ir(Lugar), mover(Lugar), observar.