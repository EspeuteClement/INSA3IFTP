function [ret] = gf(t,f,f0,beta,tho,deltaT)
    deltaF = 40;
    ret =  sin(2*pi()*f*t) + 2*sin(2*pi()*(f + deltaF)*t) + 3*sin(2*pi()*(f + 2*deltaF)*t);
end