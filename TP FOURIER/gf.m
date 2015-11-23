function [ret] = gf(t,C,f0,beta,tho,deltaT)
    deltaF = 40;
    ret =  sin(2*pi()*f0*t) + 2*sin(2*pi()*(f0 + deltaF)*t) + 3*sin(2*pi()*(f0 + 2*deltaF)*t);
end