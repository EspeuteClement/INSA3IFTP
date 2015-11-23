function [ret] = c(t,C,f0,beta,tho,deltaT)
    f1 = 250;
    f2 = 300;
    ret = s1(t) * cos(2 * pi() * f1 * t) + s2(t) * cos(2 * pi() * f2 * t);
end