%vim set syntax=prolog

ma(dum,dvere).
ma(dum,okno).
ma(dum,komin).

rozbite(okno).
rozbite(komin).

oprav(X) :- write('spravuji '), write(X), nl.

opravit :- write('Musime opravit:'), nl, rozbite(X), write(X), nl, fail.

spravuji :- write('spravuji), spravuji.
