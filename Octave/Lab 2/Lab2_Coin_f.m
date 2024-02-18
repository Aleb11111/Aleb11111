#   Write a code that simulates 3 coin tosses and compute the value of variable X

N = input("Enter the number of simulations >")
U = rand(3,N);
Y = (U < 0.5) # if U<0.5 -> Y = 1 (heads)  and   if U>=0.5  -> Y = 0 (tails)
X = sum(Y);
#plot the probability
hist(X)
