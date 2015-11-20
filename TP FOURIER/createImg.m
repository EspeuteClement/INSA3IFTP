function [affIM] = createImg(IM)
affIM = abs(IM)+1;
maxi = max(max(affIM));
mini = min(min(affIM));
affIM = (log(affIM)-log(mini)) /(log(maxi)-log(mini))*255;

end