function [A,B] = Generate(n)
    A = 10*rand(n) + n*10*eye(n);
    B= 10*rand(n,1);
end