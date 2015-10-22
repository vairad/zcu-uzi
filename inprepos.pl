%vim set syntax=prolog

operator('+').
operator('-').
operator('*').
operator('/').
operator('%').
operator(mod).	


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

cislo(V) :- cifra(X), cifra(Y), V is 10*X+Y.
cislo(V) :- cislo(X), X\=0, cifra(Y), V is 10*X+Y.

promenna('x').
promenna('y').
promenna('z').

operand(X) :- cislo(X).
operand(X) :- promenna(X).


%##########################################################################################################################################
%Pomocné pracující predikáty

spoj(Zacatek, Navazuje, Seznam) :- append(Zacatek, Navazuje, M), append(M,Seznam).
spoj(Zacatek, Navazuje, Seznam) :- M = [Zacatek, Navazuje], append(M, Seznam).

obrat(L,R):-  obrat_in(L,[],R). 
obrat_in([H|T],A,R) :-  obrat_in(T,[H|A],R).
obrat_in([],A,A). 

%##########################################################################################################################################
%Zkoumání infixové notace s binárními operátory
infix_mark(infixOp).

infix_operand(X) :- operand(X). 
infix_operand(X) :- infix_mark(X).

infix([X,Y,Z|T]) :- infix_operand(X), operator(Y), infix_operand(Z), infix([infixOp|T]).
infix([H|T]) :- T = [], infix_operand(H).
%konec infixové notace

%##########################################################################################################################################
%Zkoumání prefixové notace s binárními operátory


	%značka symbolizující nalezený prefixový výraz na nižší úrovni
prefix_mark(prefixOp).
	
	%operandy, ktere mohou vystupovat v prefixové notaci

prefix_operand(X) :- operand(X).
prefix_operand(X) :- prefix_mark(X).

	%predikát "spuštění" kontroly prefixové notace
prefix(R) :- prefix(R, []).
	%zabere true na nejjednodužší výraz typu "+ 2 2"	
prefix([Y,X,Z|T], []) :- operator(Y), prefix_operand(X), prefix_operand(Z), T = [].
	% skok ve výrazu který obsahuje syntax typu "+ 2 + 2 2"	
prefix([R,Y,X|T], Res) :- operator(R), prefix_operand(Y), operator(X), spoj([R],[Y],M), spoj(Res, M, Seznam), prefix([X|T], Seznam).
	% posun výrazem, který začíná pouze operátory
prefix([R,Y|T], Res) :- operator(R), operator(Y), spoj(Res,[R], Seznam), prefix([Y|T], Seznam).
	% namísto prefixového zápisu vloži žolík prefixOp a spustí analýzu prefix znovu se zjednodušeným výrazem.
prefix([Y,X,Z|T], Res) :- operator(Y), prefix_operand(X), prefix_operand(Z), spoj(Res, [prefixOp], M), spoj(M,T,Seznam), prefix(Seznam,[]). 


%konec prefixové notace
%##########################################################################################################################################

%Zkoumání postfixové notace ... Jde pouze o opačně zapsanou prefixovou notaci
postfix(A) :- obrat(A,R), prefix(R).

%##########################################################################################################################################
% predikáty obsluhující uživatelské rozhraní

help :- nl, nl, write("Inprepos"), nl,
	write("Tento program rozpoznává formu zápisu aritmetických výrazů"), nl,
	write("Napšte konec. pro ukončení programu."), nl,
	write("Napiste help. nebo ??. pro zobrazení nápovědy."), nl,
	write("Vaše výrazy zapisjte jako seznam."), nl,
	write("Například [+, 1, 1,]."), nl.
	

testuj(X) :- infix(X), write("Tento výraz je zapsán infixovou formou"), nl, test.
testuj(X) :- prefix(X), write("Tento výraz je zapsán prefixovou formou"), nl, test.
testuj(X) :- postfix(X), write("Tento výraz je zapsán postfixovou formou"), nl, test.
testuj(X) :- X = konec, write("Končím program").
testuj(X) :- X = end, write("Končím program").
testuj(X) :- X = exit, write("Končím program").
testuj(X) :- X = halt, write("Končím program").
testuj(X) :- X = help, help, test.
testuj(X) :- X = ??, help, test.
testuj(X) :- write("Tento výraz neodpovídá pre-, in- ani postfixové formě."), nl, test. 

test :-  nl, nl, write("Zadejte Váš aritmetický vyraz ve formátu seznamu: [+, 1, 9, +]"), nl,
	 read(X), nl,
	 write("Zadal jste vyraz: "), write(X), nl,
	 testuj(X).


% program spustíte pomocí predikátu start
start :- help, test.

