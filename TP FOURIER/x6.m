function [ret] = x6(t,C,f0,beta,tho,deltaT)
    ret = rectangularPulse(-tho/2, tho/2, t);
end

function [ret] = rectangularPulse(a, b, t)
    if (t < a || t > b)
        ret = 0;
    elseif (t == a || t == b)
        ret = 0.5;
    elseif (t > a && t < b)
        ret = 1;
    end
end