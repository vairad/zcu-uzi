%vim set syntax=prolog

cifra(0).
cifra(1).
cifra(2).
cifra(3).
cifra(4).
cifra(5).
cifra(6).
cifra(7).
cifra(8).
cifra(9).

cislo(X):- cifra(X).
cislo(X):- cislo(Y), Y\=0, cifra(Z), X is 10*Y+Z.

nsb(X,Y,V) :- cislo(X), cislo(Y), V is X*Y, !.
