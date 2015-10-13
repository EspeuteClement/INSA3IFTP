function [vp] = ValeurPropre(A,prec)
   vp = zeros(size(A,1),1);
   
   i = 1;
   
   for i=1:size(A,1)
     vp(i) = PuissanceIteree(A,prec);
     
   end
   
   

end

function [y] = PuissanceIteree(A, prec)
    %%x = zeros(size(A,1),1);
    A = A';
    y = ones(size(A,1),1);
    
    while 1
        x = y / norm(y);
        y = A * x;
        
        % Quitter si l'angle entre les 2 vecteurs est inférieur a prec
        if acos(dot(y,x)/(norm(x) * norm(y)))<prec
            break;
        end
    end
end

