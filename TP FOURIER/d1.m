function [ret] = d1(t,C,f0,beta,tho,deltaT)
    f1 = 250;
    ret = c(t) * cos(2 * pi() * f1 * t);
end