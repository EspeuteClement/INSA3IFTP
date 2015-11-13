function [ret] = prepareFourierData(data,samples,lowerBound,higherBound,isReal)
    
    ret = zeros(2,samples);
    % Bake the ret
    
    if isReal == 1
       ret(2,:) = real(data);
    else
       ret(2,:) = imag(data);
    end
    
    % Add the frequencies :
    fe = samples/(higherBound-lowerBound);
    feStep = 1/(higherBound-lowerBound);
    
    for samplePosition = 1:samples
       ret(1,samplePosition) = -fe/2 + (samplePosition-1) * feStep;
    end
        
end