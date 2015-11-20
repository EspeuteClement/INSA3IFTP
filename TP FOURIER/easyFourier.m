function easyFourier(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT,spectre)
    SampledData = sampleFunction(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT);
    
    FourierData = tfour(SampledData(2,:));
    
    
   
    subplot(3,2,1);
    easyPlot(real(SampledData));

    
    % if we don't want to display all the stats
    if ~strcmp(spectre,'full')
        PlotableFourierData = prepareFourierData(FourierData, samples, lowerBound, higherBound,spectre);
        fig2 = figure(2);
        set(fig2,'name','Transformée')
        easyPlot(PlotableFourierData);
    else
        FourierReal = prepareFourierData(FourierData, samples, lowerBound, higherBound,'real');
        FourierImag = prepareFourierData(FourierData, samples, lowerBound, higherBound,'imag');
        FourierMod = prepareFourierData(FourierData, samples, lowerBound, higherBound,'mod');
        FourierArg = prepareFourierData(FourierData, samples, lowerBound, higherBound,'arg');
        
        subplot(3,2,2);
        easyPlot(FourierReal);
        title('Partie réele')
        
        subplot(3,2,3);
        easyPlot(FourierImag);
        title('Partie imaginaire')
        
        subplot(3,2,4);
        easyPlot(FourierMod);
        title('Partie module')
        
        subplot(3,2,5);
        
        easyPlot(FourierArg);
        title('Partie argument')
        
        
        
    end
end