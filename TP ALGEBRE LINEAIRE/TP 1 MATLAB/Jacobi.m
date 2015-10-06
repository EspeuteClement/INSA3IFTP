function [returnValue] = Jacobi(A,B,prec)
  CoefStart = diag(A);
  M = zeros(size(A,1),1);
  k = 0;
  while true
  Temp = M;
    for i=1:size(A,1);
      
      sigma = 0;
      for j=1:size(A,1)
        if(j~=i)
          sigma = sigma + A(i,j)*M(j);
        end % if
      end % j loop
      Temp(i) = (B(i) - sigma)/CoefStart(i); % Calcul de M.X s = N.X s + B 
                                      %(A(i,i) représente la diagonnale)
    end
    if (abs(Temp(1) - M(1))<prec) or (k>10000);, break end % Break si la précision est atteinte
    M = Temp;
    k = k+1;
  end
  returnValue = M;
end