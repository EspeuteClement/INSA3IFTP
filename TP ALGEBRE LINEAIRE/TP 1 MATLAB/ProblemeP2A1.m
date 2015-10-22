function [exitV,exitVec,M] = ProblemeP2A1()
    M = zeros(1,150);
    exitV = zeros(20,1);
    exitVec = zeros(20,150);
    for i=1:150
        if (not(... % si c'est pas un bord :
            i<10 || i > 140 ...     % gestion des bords gauche et droits
            || mod(i-1,10) == 0 ... % gestion des bords bas
            || mod(i,10) == 0 ...   % gestion du bors haut
            || (i>61 && i<66) ...   % gestion du trou
            || (i>71 && i<76) ...   % gestion du trou
            || (i>81 && i<86)) )    % gestion du trou
            % Initialiser les coéficients
            M(i,i) = -4;
            M(i,i-10) = 1;
            M(i,i+10) = 1;
            M(i,i+1) = 1;
            M(i,i-1) = 1;
        else % Si c'est un bords
            M(i,i) = 1;
        end
    end
    % Calcul des valeurs propres pour l'inverse de la matrice (les plus
    % grandes valeurs propre
    [v,vecteurs] = ValeurPropre(inv(-M),0.0001);
    
    %Récuperer les premiers vecteurs non =-1
    i = 1;
    pos = 1;
    while i <= 10
       if v(pos) > 0
            exitV(i,1) = -1/(v(pos)); % On applique la formule du cours
            exitVec(i,:) = vecteurs(:,i)';
            i = i + 1;
        end
        pos = pos + 1; 
    end
    
    % On calcule les plus petites valeurs propres
    [v,vecteurs] = ValeurPropre(M,0.0001);
    
    for i=1:10
        if v(i+10) < 0
            exitV(i+10,1) = v(i);
            exitVec(i+10,:) = vecteurs(:,i)';
        end
        pos = pos + 1;
    end
    
    % On les affiches !
    for i=1:20
        surf(reshape(exitVec(i,:),10,15));
        pause();
    end
    %%%%%%%%%%%%%%%%%%%%surf(reshape(vecteurs(:,2),10,15));
    %surf(reshape(vecteurs(20,:),15,10));
    % TODO FAIRE METHODE ITERATIOSN INVERSE POUR AVOIR UNE REPRESENTATION
    % CORRECTE DE LA REPARTITION DES ONDES
    % v = v';
end