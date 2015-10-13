function [v] = ProblemeP2A1()
    M = zeros(150,150);
    for i=10:140
        if (not(mod(i-1,10) == 0 || mod(i,10) == 0 || (i>61 && i<66) || (i>61 && i<66) || (i>71 && i<76) || (i>81 && i<86)) )
            M(i,i) = -4;
            M(i,i-10) = 1;
            M(i,i+10) = 1;
            M(i,i+1) = 1;
            M(i,i-1) = 1;
        end
    end
    eig(M);
    v = ValeurPropre(M,0.0001);
    v = v';
end