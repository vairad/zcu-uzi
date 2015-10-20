%vim set syntax=prolog

operator(+).
operator(-).
operator(*).
operator(/).

cislo(1).
cislo(2).
cislo(3).

infix_mark(infixOp).
prefix_mark(prefixOp).

operand(X) :- cislo(X).

infix_operand(X) :- operand(X). 
infix_operand(X) :- infix_mark(X).

prefix_operand(X) :- operand(X).
prefix_operand(X) :- prefix_mark(X).

%postfix_operand(X) :- operand(X).


%infix(X,Y,Z) :- operator(Y), infix_operand(X), infix_operand(Z).

%prefix(Y,X,Z) :- operator(Y), prefix_operand(X), prefix_operand(Z).

%postfix(X,Z,Y) :- operator(Y), postfix_operand(X), postfix_operand(Z).


%infix([H|T]) :- write("infix 1 "), write(H), infix_operand(H), write(" operand true"), write(T), infix_1(T).
%infix([H|T]) :- infix_mark(H).

%infix_1([H|T]) :- write("infix 2 "), write(H), operator(H), write(" operator true"), write(T),  infix_2(T).
%infix_2([H|T]) :- write("infix 3 "), write(H), infix_operand(H), write("operand true"), infix([infixOp|T]).

%Zkoumání infixové notace s binárními operátory
infix([X,Y,Z|T]) :- infix_operand(X), operator(Y), infix_operand(Z), infix2([infixOp|T]).
infix([H|T]) :- T = [], infix_operand(H).


prefix([Y,X,Z|T],[]) :- write("novy prefix "), operator(Y), prefix_operand(X), prefix_operand(Z), T = []. 


%prefix_1([H|T], [Res]) :- write("prefix 1 "), write(H), operator(H), write(" operator true"), write(T), prefix_2(T, [Res]).
%prefix_2([H|T], [Res]) :- write("prefix 2 "), write(H), operand(H), write(" operand true"), write(T), prefix_3(T, [Res]).
%prefix_3([H|T], [Res]) :- write("prefix 3 "), write(H), operand(H), write(" operand true"), write([prefixOp|T]), prefix([prefixOp|T], [Res]).


%prefix(zkoumana posloupnost, predchozi nevyresene)
%prefix([H|T],[]) :- prefix_mark(H).
%prefix([H|T],[Res]) :- prefix_1([H|T], [Res]).
%prefix([H|T],[]) :- prefix(T,[Res|H]).

