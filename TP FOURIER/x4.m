function [ret] = x4(t,C,f0,beta,tho,deltaT)
    ret = dirac(t - deltaT);
end

function [ret] = dirac(t)
    if (abs(t) < 0.0001)
        ret = 1;
    else
        ret = 0;
    end
end