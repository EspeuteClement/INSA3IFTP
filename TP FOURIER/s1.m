function [ret] = s1(t,C,f0,beta,tho,deltaT)
    syms n;
    ret = symsum(n * cos(2 * pi() * 20 * n * t), 1, 5);
end