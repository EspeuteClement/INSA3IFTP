function [ret] = prepareFourierData(data,samples,lowerBound,higherBound,spectre)
    
    ret = zeros(2,samples);
    % Bake the ret
    
    if strcmp(spectre,'real')
       ret(2,:) = real(data);
    elseif strcmp(spectre,'imag')
       ret(2,:) = imag(data);
    elseif strcmp(spectre,'mod')
       ret(2,:) = abs(data);
    elseif strcmp(spectre,'arg')
       ret(2,:) = angle(data);
    end
    
    % Add the frequencies :
    fe = samples/(higherBound-lowerBound);
    feStep = 1/(higherBound-lowerBound);
    
    for samplePosition = 1:samples
       ret(1,samplePosition) = -fe/2 + (samplePosition-1) * feStep;
    end
        
end