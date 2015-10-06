% A is the matrix representing the coefficents of the equations system.
% B is the matrix of the initial values.
function Probleme1(delta,t)
  A = zeros(450);
  B = zeros(450, 1);
 
  for i=1:450
    % Left Side
    if(i == 1)
        A(i, i+165) = 1;
        A(i, i+1) = 1;
        A(i, i+15) = 1;
        A(i, i) = -3;
    elseif(i == 15)
        A(i, i+165) = 1;
        A(i, i-1) = 1;
        A(i, i+15) = 1;
        A(i, i) = -3;
    elseif(i >= 2 && i <= 14)
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i) = -4;
      A(i, i+165) = 1;
      A(i, i+15) = 1;
     
   
    % Right Side
    elseif(i >= 437 && i <= 449)
 
      A(i, i-1) = 1;
      A(i, i) = -4;
      A(i, i+1) = 1;
      A(i, i-270) = 1;
      A(i, i-15) = 1;
   
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
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i) = -4;
       B(i) = 300;
   
    % Green Points
    elseif((i >= 320-15 && i <= 326-15))
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i) = -3;
   
    elseif((i >= 335-15 && i <= 341-15))
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i+15) = 1;
      A(i, i) = -3;
     
    % Blue Points (top and bottom sides)
    elseif(mod(i-1, 15) == 0 )
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i) = -3;
    elseif(mod(i-15, 15) == 0)
       A(i, i-1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i) = -3;
    % General case
    else
      A(i, i-1) = 1;
      A(i, i+1) = 1;
      A(i, i-15) = 1;
      A(i, i+15) = 1;
      A(i, i) = -4;
    end
  end
 
  %A = A(1:450,1:450);
 
  % Solving
  sh=surf(reshape(B,15,30));
  set(gca,'zlim',[-0.5 10])
  for (i=0:delta:t)
      B = expm(A*delta)*B;
      set(sh,'zdata',reshape(B,15,30))
      pause(0.05);
  end
end