n = input("Give a n that is greater or equal to 30> ")
p = input("Give a p that is less or equal to 0.05> ")

landa = n*p;
%try to plot in the same graph the pdf of the binomial and the pdf of the poisson
x = 0:3:100;
y = poisspdf(x,landa);
plot(x,y);
