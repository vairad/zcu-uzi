%vim set syntax=prolog
% Procedura muz  
muz(adam).
muz(karel).
muz(emil).  
muz(zibrid).
muz(jan).
muz(josef).  
muz(hugo).

% Procedura zena  
zena(lucie).
zena(eva).
zena(helena).
zena(klara). 
zena(kunhuta).
zena(katka). 
zena(ruzena).
zena(milena).

% Procedura manz  
manz(adam,eva).     
manz(karel,helena). 
manz(zibrid,kunhuta).  
manz(jan,lucie).    
manz(josef,katka).
manz(hugo,milena).  

% Procedura rodic  
rodic(adam,hugo).
rodic(adam,josef).      
rodic(eva,josef). 
rodic(eva,hugo).    
rodic(karel,zuzana). 
rodic(helena,zuzana). 
rodic(helena,alfred). 
rodic(karel,alfred).  
rodic(klara,emil). 
rodic(karel,emil).  
rodic(kunhuta,eva).   
rodic(kunhuta,katka).  
rodic(zibrid,eva).  
rodic(zibrid,katka).  
rodic(ruzena,jan). 
rodic(jan,adam).
rodic(lucie,adam). 

% Procedura otec  
otec(Otec,Dite):- rodic(Otec,Dite),muz(Otec).  

% Procedura matka  
matka(Matka,Dite):- rodic(Matka,Dite), zena(Matka).

% Procedura manzdite  
manzdite(X):- otec(Ot,X),matka(Mat,X),manz(Ot,Mat).

% Procedura deda  
deda(D,V):- rodic(R,V),otec(D,R).  

% Procedura vmanzelstvi  
vmanzelstvi(X,Y):- manz(X,Y). 
vmanzelstvi(X,Y):- manz(Y,X). 

% 1) otázka odpoví kdo je dědečkem
% deda(D, josef).

% 2) otázka odpoví kteří rodiče jsou v manželství
% rodic(X,_), rodic(Y,_), vmanzelstvi(X,Y)

%3) otázka odpoví které děti jsou manželské
% manzdite(D).

%4) kolik vnuku mel zibrid ... Za každého hashmark
% deda(zibrid,_), write('# '), false.

%5) babička, teta, sestra
babicka(B,V):- rodic(R,V),matka(B,R).

sestra(S,X):-rodic(R,S), rodic(R,X), S \= X, zena(S).
bratr(B,X):-rodic(R,B), rodic(R,X), X \= B, muz(B).

teta(T, X):- rodic(R,X), bratr(B,R), vmanzelstvi(B,T), zena(T).
teta(T, X):- rodic(R,X), sestra(T,R).



 
