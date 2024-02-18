#Ex 2 lab 2

n = input("Give me an n >")
p = input("Give me an p >")
x = 0:1:n; #number of successes in n trials

px = binopdf(x,n,p);

plot(x,px,'*r')
hold on
xx = 0:0.01:n;
cx = binocdf(xx,n,p);
plot(xx,cx,'g')
