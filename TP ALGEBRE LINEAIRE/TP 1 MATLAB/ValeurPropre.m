function [ret] = ValeurPropre(A,prec)
   v = zeros(size(A,1),size(A,1));
   u = zeros(size(A,1),size(A,1));
   for i=1:size(A,1)
     [x,y,l] = PuissanceIteree(A,prec);
     v(:,i) = x;
     u(i,:) = y;
     A = Wielandt(A,v(:,i),u(i,:),l);
     ret(i) = l;
   end

end

function [u,v,lambda] = PuissanceIteree(A, prec)
    %%x = zeros(size(A,1),1);
    A = A;
    u = ones(size(A,1),1);
    
    while 1
        x = u / norm(u);
        u = A * x;
        
        lambda = x' * u / (norm(x)*norm(x));
        v = (A'* x)';
        % Quitter si l'angle entre les 2 vecteurs est inférieur a prec
        angle = acos(dot(u,x)/(norm(x) * norm(u)))
        if angle > pi()/2
           angle = angle - pi();
        end
        if abs(angle)<prec
            break;
        end
    end
end

function [M] = Wielandt(A,v,u,l)
    M = A - l * (v*u)/(u*v)
end

