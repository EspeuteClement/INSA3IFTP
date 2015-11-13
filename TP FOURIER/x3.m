function [ret] = x3(t,C,f0,beta,tho,deltaT)
    ret = exp(-beta*t)*heaviside(t);
end