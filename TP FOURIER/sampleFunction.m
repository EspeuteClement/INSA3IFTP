% Compute the samples for a given function
% Params :
% theFunction : A function handle (use @nameOfYourFunction). The function
% should look like f(x,C,f0,beta,tho,deltaT)
% C,f0,beta,tho,deltaT corresponds to differents parameters for the
% function.
function [sampleList] = sampleFunction(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT)
    % Initialize the array
    sampleList = zeros(2,samples);
    
    % Compute the length of one sample
    samplePeriod = (higherBound - lowerBound)/samples;
    for samplePosition = 1:samples
        % Our position in the sample :
        time = lowerBound + samplePeriod*samplePosition;
        
        % Put the time in the first array ...
        sampleList(1,samplePosition) = lowerBound + samplePeriod*samplePosition;
        
        % Put the sample in the second array ...
        sampleList(2,samplePosition) = theFunction(lowerBound + samplePeriod*samplePosition,C,f0,beta,tho,deltaT);
    end
end