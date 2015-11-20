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

a=3;
b=3;
for i=1:a
    for j=1:b
        rectangle(r_s/2+i-floor(a/2),r_s/2+j-floor(b/2)) = 255/(a*b);
    end
    
end


RECTANGLE = fftshift(fft2(rectangle));
RECTANGLE_IMG = fourToImg(RECTANGLE);
figure(4)
image(RECTANGLE_IMG);
colormap(map);

I_RECTANGLE = 1./RECTANGLE;
dIM = IM .* I_RECTANGLE;

figure(3)
image(fourToImg(dIM));
colormap(map);

trueImg = ifft2(ifftshift(dIM));

figure(5)
image(trueImg);
colormap(map)
end