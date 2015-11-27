function Partie2()
% Charger l'image
[im, map]=imread('PhotoTexte.png');

% Afficher l'image
figure(1);
image(im);
colormap(map);

% Transform�e de fourier de l'image
IM = fftshift(fft2(im));

% On affiche la transform�e de fourier de l'image
affIM =fourToImg(IM);
figure(2)
image(affIM);
colormap(map);

% G�n�ration de la fonction de flou
r_s = size(im,1);
rectangle = zeros(r_s);

% a=5;
% b=7;
% for i=1:a
%     for j=1:b
%         rectangle(r_s/2+i-floor(a/2),r_s/2+j-floor(b/2)) = 1/(a*b);
%     end   
% end

for i=257-2:257+2
    for j=257-3:257+3
       rectangle(i,j) = 1/(7*5); 
    end
end
% On effectue la transform�e de fourier du rectangle
RECTANGLE = fftshift(fft2(rectangle));

% On affiche le rectangle
RECTANGLE_IMG = fourToImg(RECTANGLE);
figure(4)
image(rectangle);
colormap(map);

% Utilisation de lafonction de Wiener
I_RECTANGLE = 1./RECTANGLE;

% On charge l'image de r�f�rence pour calculer Pb et Pi
[imr, map]=imread('PhotoRef.png');

% Transform�e de fourier de l'image de r�f�rence
IMr = fftshift(fft2(imr));

% On floute la transform�e de fourier de l'image de r�f�rence
Dr = IMr .* RECTANGLE;


Pi = abs(IMr).^2;


dr = fftshift(((ifft2(ifftshift(Dr)))));
b = round(dr)-dr;
B = fftshift(fft2(b));
Pb = abs(B).^2;
W = I_RECTANGLE .* (abs(RECTANGLE).^2) ./(abs(RECTANGLE).^2 + (Pb./Pi));

% Calcul de l'image d�cod�e
dIM = IM .* W;

% On affiche la transform�e de fouier de l'image d�cod�e
figure(3)
image(fourToImg(dIM));
colormap(map);

% On d�transforme l'image
trueImg = abs(fftshift(((ifft2(ifftshift(dIM))))));

%On affiche l'image d�cod�e
figure(5)
image(trueImg);
colormap(map);
end