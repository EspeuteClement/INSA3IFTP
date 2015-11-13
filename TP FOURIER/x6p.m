function [ret] = x6p(t,C,f0,beta,tho,deltaT)
    ret = rectangularPulse(tho,f0, t);
end

function [ret] = rectangularPulse(tho,f0, t)
    value = 1/2*sin(2 * pi() * f0 * t)+0.5;
    if value >= 0.5
        ret = 1;
    else
        ret = 0;
    end
end