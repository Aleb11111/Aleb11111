A = [1,0,-2;2,1,3;0,1,0];
B = [2,1,1;1,0,-1;1,1,0];
C = A - B;
D = A*B;
E = A.*B;

x = 0:0.001:3;
y = x.^5/10;
#plot(x,y)
z = x.*sin(x);
t = cos(x);
#plot(x,y,'-.r',x,z,'--g',x,t,'-y')
#title("The plot from lab 1")
#h = legend("x^5/10","xsin(x)","cox(x)")
#legend show
subplot(3,1,1)
plot(x,y,'r')
subplot(3,1,2)
plot(x,z,'b')
subplot(3,1,3)
plot(x,t,'g')
