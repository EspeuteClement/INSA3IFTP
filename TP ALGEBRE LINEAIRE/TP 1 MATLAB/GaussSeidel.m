function [returnValue] = GaussSeidel(A,B,prec)
  CoefStart = diag(A);
  M = zeros(size(A,1),1);
  k = 0;
  while true
  Temp = M;
    for i=1:size(A,1);
      
      sigma = 0;
      for j=1:size(A,1)
        if(j>i)
          sigma = sigma + A(i,j)*M(j);
        end % if
      end % j loop
      
      omega = 0;
      for j=1:size(A,1)
        if j<i
          omega = omega + A(i,j)*Temp(j);
        end
      end
      Temp(i) = (B(i) - sigma - omega)/A(i,i); % Calcul de M.X s = N.X s + B 
                                      %(A(i,i) représente la diagonnale)
    end
    
    
    Error = abs(A*Temp - B);
    maxError = max(Error);
    
    if maxError < prec; break
    end % Break si la précision est atteinte
    
    M = Temp;
    k = k+1;
  end
  disp(k);
  returnValue = M;
end