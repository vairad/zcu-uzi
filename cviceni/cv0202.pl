%vim set syntax=prolog
muz(vojtech).
muz(karel).
muz(ondrej).

zena(anezka).
zena(hana).
zena(jitka).
zena(lucka).
zena(eliska).

rodic(vojtech,hana).
rodic(anezka,hana).
rodic(karel,ondrej).
rodic(karel,jitka).
rodic(hana,ondrej).
rodic(hana,jitka).
rodic(ondrej,eliska).
rodic(lucka,eliska).

matka(X,Y) :- rodic(X,Y), zena(X).
otec(X,Y) :- rodic(X,Y), muz(X).

manzele(X,Y) :- otec(X,Z), matka(Y, Z).
sourozenci(X,Y) :- matka(Z,X), matka(Z, Y), X \= Y.
potomek(X) :- matka(_,X).

slechtic(anezka).
slechtic(X) :- otec(Y,X), slechtic(Y).
slechtic(X) :- matka(Y,X), slechtic(Y).

pohlavi :- write("Zadej jméno:"), nl, read(X), nl, zena(X), write(X),  write(" je zena").
pohlavi :- write("Zadej jméno:"), nl, read(X), nl, muz(X), write(X), write(" je muz").
