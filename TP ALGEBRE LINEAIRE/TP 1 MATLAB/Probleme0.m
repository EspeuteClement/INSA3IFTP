% A is the matrix representing the coefficents of the equations system.
% B is the matrix of the initial values.
function Probleme0()
  A = zeros(450);
  B = zeros(450, 1);
  
  for i=1:450
    % Left Side
    if(i >= 2 && i <= 14)
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i+165) = 1;
      A(i, i+15) = 1;
      A(i, i) = -4;
   
    % Right Side
    elseif(i >= 437 && i <= 449)
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-270) = 1;
      A(i, i-15) = 1;
      A(i, i) = -4;
   
    % Bold Line
    elseif(i >= 167 && i <= 179)
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i-165) = 1;
      A(i, i+270) = 1;
      A(i, i) = -6;
   
    % Red Points
    elseif(i == 233 || i == 263-15 || i == 278-15)
      A(i, i) = 1;
      B(i) = 100;
   
    % Green Points
    elseif((i >= 319-15 && i <= 327-15) || (i >= 334-15 && i <= 342-15))
      A(i, i) = 1;
      B(i) = 10;
   
    % Blue Points (top and bottom sides)
    elseif(mod(i-1, 15) == 0 || mod(i-15, 15) == 0)
      A(i, i) = 1;
      B(i) = 50;
   
    % General case
    else
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i) = -4;
    end
  end
 
  % Solving
  X = GaussSeidel(A,B, 0.001)
  Y = reshape(X, 15, 30);
  surf(Y);
end