function [X] = Relaxation(A,B,prec)
  M = tril(A);
  L = tril(A,1);
  U = triu(A,1);
  N = -A+M;
  D = diag(diag(A));
  P = inv(M) * N;
  C = inv(M) * B;
  X = zeros(length(A));
  
  O = zeros(length(A),1);
  omega = 1;
  minRho = 1;
  
  % Calcul du parametre
  for j=0.01:0.1:1.99;

    pi = inv(D + j * L) * ((1-j) * D - j * U);
    rho = max(abs(eig(pi)));
    if (rho < minRho);
      omega = j;
      minRho = rho;
    end

  end
  minRho
  RN = M;

  %for i=0:init;
  %X = P*X + C;
  %RN_1 = (1-omega)*RN + omega * X;
  %end
  while true
    TEMP = O;
    for i=1:size(A,1);
      sigma = 0;
      for j=1:size(A,1);
        if (j ~= i);
          sigma = sigma + A(i,j)*O(j);
        end %if
      end % j loop
      TEMP(i)= (1 - minRho) * O(i) + minRho/A(i,i) * (B(i) - sigma);
     end %i loop
     
     error = abs(A*TEMP - B);
     maxError = max(error);
     if maxError<prec;
      break
     end
     O = TEMP;
  end % while
  
  X = O;
end