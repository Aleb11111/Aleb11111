
%   P(x<0)

n = input("Give mu>")
sigma = input("Give sigma> ")

%pdf = f(x) in lectures and cdf = F(x)
% P(X = x) -> pdf
% P(X <= x)) -> cdf
printf("P(X ≤ 0) is :")
normcdf(0,n,sigma)

%   P(X>=0)
%  P(X>=0) = 1 - P(X < 0) = 1 - P(X <= 0) because of the continuity

b = 1 - normcdf(0,n,sigma);
printf("P(X >= 0) = %d\n",b)

%P(a < X <= b) = F(b) - F(a)
%  = P(a<= X <= b)  = P(a < X < b)

%P(-1 <= X <=1)
c = normcdf(1,n,sigma)-normcdf(-1,n,sigma);
printf("P(-1 ≤ X ≤ 1) = %d\n",c)

%P(X ≤ −1 or X ≥ 1)
%   = 1 - P(-1 < X <1)
d = 1 - c;
printf("P(X ≤ −1 or X ≥ 1) = %d\n",d)

alfa = input("give alfa> ")
beta = input("give beta>")

% F(x) = P(X ≤ x) = a
%     how do we find F(x) if we know a?  => x = F^-1(a)
% the function for finding a quantile -> Inv
% norminv (alfa, MU, SIGMA)

quantileAlfa = norminv(alfa,n,sigma);
printf("P(X < xα) = P(X ≤ xα) = α = %d\n",quantileAlfa)

%P(X > xβ) = P(X ≥ xβ)

quantileBeta = norminv(1-beta,n,sigma);
printf("P(X > xβ) = P(X ≥ xβ) = %d\n",quantileBeta)

%                           TO RESOLVE THE OTHER FUNCTIONS
%       Stundetn = tcdf / tpdf / tinv
%       Fisher = fcdf / fpdf / finv
% see for the other one






