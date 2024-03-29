% 13. The list a1, ..., an is given and it consists of distinct integers.
% Write a predicate to determine all subsets with aspect of "mountain"
% (a set has a "mountain" aspect if the elements increase to a certain point and then decrease).


% munte(l1...ln, f) =
%	true, n <= 1 and f = 1
%	munte(l2...ln, 0), l1 < l2 and f = 0
%	munte(l2...ln, 1), l1 >= l2 and f = 0
%	munte(l2...ln, 1, l1 > l2 and f = 1
%	false, otherwise

munte([], 1).
munte([_], 1).
munte([H1, H2|T], 0) :- H1 < H2,
    munte([H2|T], 0).
munte([H1, H2|T], 0) :- H1 >= H2,
    munte([H2|T], 1).
munte([H1, H2|T], 1) :- H1 > H2,
    munte([H2|T], 1).

% isMountain(l1...ln) =
%	munte(l1...ln, 0), l1 < l2

% isMountain(L:list)
% isMountain(i)

isMountain([H1, H2, H3|T]) :- H1 < H2, munte([H1, H2, H3|T] ,0).

% subsets(l1...ln) =
%	[], n = 0
%	l1 + subsets(l2...ln), n > 0
%	subsets(l2...l% 13. The list a1, ..., an is given and it consists of distinct integers. Write a predicate to determine all
%     subsets with aspect of "mountain" (a set has a "mountain" aspect if the elements increase to a certain
%     point and then decrease).



% subsets(l1l2...ln) =
% = [], if n = 0
% = {l1} U subsets(l2...ln), if n >= 1
% = subsets(l2...ln), if n >= 1

% subsets(L:list, R:list)
%(i,o)

subsets([],[]).
subsets([H|T],[H|R]):-
    subsets(T,R).
subsets([_|T],R):-
    subsets(T,R).



% flag = 0 for an increasing sequence
% flag = 1 for a decreasing sequence
% mountain(l1l2...ln, flag) =
% = true, if n = 1 and flag = 1
% = mountain(l2...ln, 0), if l1 < l2 and flag = 0
% = mountain(l2...ln, 1), otherwise

% mountain(L:list, F:number)
% (i,i)

mountain([_],1):-!.
mountain([H1,H2|T],0):-
    H1 < H2,
    mountain([H2|T],0).
mountain([H1,H2|T],_):-
    H1 > H2,
    mountain([H2|T],1).


% checkMountain(L:list)
% (i)

checkMountain([H1,H2|T]):-
    H1 < H2,
    mountain([H1,H2|T],0).


% oneSol(L:list, R:list)
% (i,o)

oneSol(L,R):-
    subsets(L,R),
    checkMountain(R).

allSols(L,R):-
    findall(RPartial, oneSol(L,RPartial),R).
