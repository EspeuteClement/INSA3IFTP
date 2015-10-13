function [v,vecteurs] = ProblemeP2A1()
    M = zeros(150,150);
    for i=1:150
        if (not(i<10 || i > 140 || mod(i-1,10) == 0 || mod(i,10) == 0 || (i>61 && i<66) || (i>61 && i<66) || (i>71 && i<76) || (i>81 && i<86)) )
            M(i,i) = -4;
            M(i,i-10) = 1;
            M(i,i+10) = 1;
            M(i,i+1) = 1;
            M(i,i-1) = 1;
        else
            M(i,i) = 1;
        end
    end
    [v,vecteurs] = ValeurPropre(M,0.0001);
    surf(reshape(vecteurs(:,1),10,15))
    
    % TODO FAIRE METHODE ITERATIOSN INVERSE POUR AVOIR UNE REPRESENTATION
    % CORRECTE DE LA REPARTITION DES ONDES
    v = v';
end