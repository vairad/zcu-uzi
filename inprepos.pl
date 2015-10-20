%vim set syntax=prolog

operator(+).
operator(-).
operator(*).
operator(/).

cislo(1).
cislo(2).
cislo(3).

prefix_mark(prefixOp).

operand(X) :- cislo(X).

prefix_operand(X) :- operand(X).
prefix_operand(X) :- prefix_mark(X).

%prefix(Y,X,Z) :- operator(Y), prefix_operand(X), prefix_operand(Z).

%postfix(X,Z,Y) :- operator(Y), postfix_operand(X), postfix_operand(Z).



spoj(Neco, N, Seznam) :- append(Neco, N, M), append(M,Seznam).
spoj(Neco, N, Seznam) :- M = [Neco,N], append(M, Seznam).

spoj4(Neco, N, Seznam) :- Seznam = [Neco,N].
%Zkoumání infixové notace s binárními operátory
infix_mark(infixOp).

infix_operand(X) :- operand(X). 
infix_operand(X) :- infix_mark(X).

infix([X,Y,Z|T]) :- infix_operand(X), operator(Y), infix_operand(Z), infix2([infixOp|T]).
infix([H|T]) :- T = [], infix_operand(H).
%konec infixové notace

%Zkoumání prefixové notace s binárními operátory
prefix([R,Y,X,Z|T], []) :- operator(R), operator(Y),prefix([Y,X,Z|T], R).
prefix([R,Y,X,Z|T], Res) :- operator(R), operator(Y),spoj(Res,[R], M), prefix([Y,X,Z|T], M).
prefix([Y,X,Z|T], Res) :- operator(Y), prefix_operand(X), prefix_operand(Z), spoj(Res, [prefixOp], M), spoj(M,T,Seznam),prefix(Seznam,[]).
prefix([Y,X,Z|T],[]) :- operator(Y), prefix_operand(X), prefix_operand(Z),T = [].
 
%konex prefixové notace

%prefix_1([H|T], [Res]) :- write("prefix 1 "), write(H), operator(H), write(" operator true"), write(T), prefix_2(T, [Res]).
%prefix_2([H|T], [Res]) :- write("prefix 2 "), write(H), operand(H), write(" operand true"), write(T), prefix_3(T, [Res]).
%prefix_3([H|T], [Res]) :- write("prefix 3 "), write(H), operand(H), write(" operand true"), write([prefixOp|T]), prefix([prefixOp|T], [Res]).


%prefix(zkoumana posloupnost, predchozi nevyresene)
%prefix([H|T],[]) :- prefix_mark(H).
%prefix([H|T],[Res]) :- prefix_1([H|T], [Res]).
%prefix([H|T],[]) :- prefix(T,[Res|H]).

