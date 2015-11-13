function [ret] = x4(t,C,f0,beta,tho,deltaT)
    ret = dirac(t - deltaT);
end