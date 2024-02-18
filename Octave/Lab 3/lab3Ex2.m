p = input("Give the value for p, make sure that you enter a value between 0.05 and 0.95>")
for n = 1: 3 : 100

  x=0:1:n;
  y=binopdf(x,n,p);
  plot(x,y)
  pause(0.8)

  endfor
