function [ret] = x3(t,C,f0,beta,tho,deltaT)
    ret = exp(-beta*t)*heaviside(t);
end

function [ret] = heaviside(t)
    if (t < 0)
        ret = 0;
    elseif (t == 0)
        ret = 0.5;
    elseif (t > 0)
        ret = 1;
    end
end