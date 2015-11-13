function [ret] = x6(t,C,f0,beta,tho,deltaT)
    ret = rectangularPulse(-tho/2, tho/2, t);
end