function easyFourier(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT,spectre)
    SampledData = sampleFunction(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT);
    
    FourierData = tfour(SampledData(2,:));
    
    
   
    fig1 = figure(1);
    set(fig1,'name','Fonction')
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
        
        fig2 = figure(2);
        set(fig2,'name','Partie Réelle')
        easyPlot(FourierReal);
        
        fig3 = figure(3);
        set(fig3,'name','Partie Imaginaire')
        easyPlot(FourierImag);
        
        fig4 = figure(4);
        set(fig4,'name','Amplitude')
        easyPlot(FourierMod);
        
        fig5 = figure(5);
        set(fig5,'name','Phase')
        easyPlot(FourierArg);
        
        
        
    end
end