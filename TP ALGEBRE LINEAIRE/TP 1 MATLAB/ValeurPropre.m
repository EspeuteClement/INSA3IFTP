function [ret,v] = ValeurPropre(A,prec)
   v = zeros(size(A,1),size(A,1));
   u = zeros(size(A,1),size(A,1));
   init = rand(size(A,1),1);% On initialise avec une matrice random pour
   %                            eviter de tomber sur un cas ou init est
   %                            vecteur propre (ce qui fout tout en l'air)
%    for i=1:size(A,1)
%       init(i) = 1/i;
%    end
    
   % Appliquer la methode de puissance itérée pour trouver les vecteurs
   % propres et la valeur propre, et Wieltandt pour extraire la plus grande
   % valeur propre.
   for i=1:size(A,1)
     [x,y,l] = PuissanceIteree(A,prec,init);
     v(:,i) = x;
     u(i,:) = y;
     A = Wielandt(A,v(:,i),u(i,:),l);
     ret(i) = l;
   end

end

function [y,v,lambda] = PuissanceIteree(A, prec, init)
    y = init;
    
    while 1
        x = y / norm(y);
        y = A * x;
        
        % Calcul de la norme qui prends en compte le signe
        [m,j] = max(x);
        lambda = A(j,:) * x  / m;
        if isnan(lambda)
           lambda = 0;
        end
        v = (A'* x)';
        
        % Quitter si l'angle entre les 2 vecteurs est inférieur a prec
        angle = acos(dot(y,x)/(norm(x) * norm(y)));
        if angle > pi()/2
           angle = angle - pi();
        end
        if abs(angle)<prec || isnan(angle)
            break;
        end
    end
end

function [M] = Wielandt(A,v,u,l)
    M = A - l * (v*u)/(u*v);
end

