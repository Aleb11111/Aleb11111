%11
%
% a. Replace all occurrences of an element from a list with another
% element.
%
% replace(L: list, E1: number, E2:number, R: list)
% flow model: replace(i,i,i,o)

replace([],_,_,[]).
replace([H|T],E1,E2,[E2|R]):- H =:= E1, !,
    replace(T,E1,E2,R).
replace([H|T],E1,E2,[H|R]):- replace(T,E1,E2,R).


% b. For a heterogeneous list, formed from integer numbers and list of
% numbers, define a predicate to determine
% the maximum number of the list, and then to replace this value in
% sublists with the maximum value of sublist.

%Maximum number

% maxim_number(A:number, B:number, R:number)
% maxim_number(i, i, o)

max_number(A,B,A):- A>=B.
max_number(A,B,B):- A<B.


%Maximum number in a list

% maxim_list(L:list, R:number)
% maxim_list(i, o)
%
maxim_list([], -999999).
maxim_list([H], H):- number(H).
maxim_list([H|T], R) :- number(H),
    maxim_list(T, RM),!,
    max_number(H, RM, R).
maxim_list([_|T], R) :-
    maxim_list(T, R).



% heterList(L:list, R:list)
% flow model: heterList(i, o)

heterList([], _, []).
heterList([H|T], M, [HR|R]) :- is_list(H),
    maxim_list(H, RM),!,
    replace(H, M, RM, HR),
    heterList(T, M, R).
heterList([H|T], M, [H|R]) :-
    heterList(T, M, R).

% mainHeter(L:list, R:list)
% flow model: heterList(i, o)

mainHeter(L, R) :-
    maxim_list(L, RM),
    heterList(L, RM, R).

