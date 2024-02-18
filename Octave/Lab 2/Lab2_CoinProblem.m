
#   a)

# x ~ bino(3,0.5)       -> n = 3 and p = 0.5
# x = 0:1:3
# X = matrix -> on first line -> values that can be obtained     -> on second
#                                                             line the probability of obtaining that value
n = 3;
p = 0.5;
x = 0:1:3;

px = binopdf(x,n,p);


#   b)

xx = 0:0.01:3;

cx = binocdf(xx,n,p);
#plot(xx,cx,'-b');


#   c)

p1 = binopdf(0,n,p);
printf('p(X = 0) is %1.6f\n',p1)


p2 = 1 - binopdf(1,n,p);
printf('p(X <> 1) is %1.6f\n',p2)


#   d)

p3 = binocdf(2,n,p);
printf('p(X <= 2) is %1.6f\n',p3)

#p(X<3) = P(X<=1)
p4 = binocdf(1,n,p);
printf('p(X < 2) is %1.6f\n',p4)

#   e)

#    p(X >= 1) = 1 - p(X < 1)
p5 = 1 - binopdf(0,n,p);
printf('p(X >= 1) is %1.6f\n',p5)


#    p(X > 1) = 1 - p(X <= 1)
p6 = 1 - binocdf(1,n,p);
printf('p(X > 1) is %1.6f\n',p6)



