function Partie2()
[im, map]=imread('PhotoTexte.png');

figure(1);
image(im);
colormap(map);

IM = fftshift(fft2(im));



figure(1);
image(im);
colormap(map);

affIM = abs(IM)+1;
maxi = max(max(affIM));
mini = min(min(affIM));
affIM = (log(affIM)-log(mini)) /(log(maxi)-log(mini))*255;

figure(2)
image(affIM);
colormap(map);

r_s = size(im,1);
rectangle = zeros(r_s);

% a=5;
% b=7;
% for i=1:a
%     for j=1:b
%         rectangle(r_s/2+i-floor(a/2),r_s/2+j-floor(b/2)) = 1/(a*b);
%     end
%     
% end

for i=257-2:257+2
    for j=257-3:257+3
       rectangle(i,j) = 1/(7*5); 
    end
end


RECTANGLE = fftshift(fft2(rectangle));
RECTANGLE_IMG = fourToImg(RECTANGLE);
figure(4)
image(rectangle);
colormap(map);

I_RECTANGLE = 1./RECTANGLE;


[imr, map]=imread('PhotoRef.png');

IMr = fftshift(fft2(imr));
Dr = IMr .* RECTANGLE;

Pi = abs(IMr);
Pb = abs(floor(Dr) - Dr);

W = I_RECTANGLE .* (abs(RECTANGLE).*abs(RECTANGLE)) ./(abs(RECTANGLE).*abs(RECTANGLE) + Pb./Pi);

dIM = IM .* W;

figure(3)
image(fourToImg(dIM));
colormap(map);

trueImg = abs(fftshift(((ifft2(ifftshift(dIM))))));

figure(5)
image(trueImg);
colormap(map);
end