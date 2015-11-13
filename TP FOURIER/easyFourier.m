function easyFourier(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT,isReal)
    SampledData = sampleFunction(theFunction, samples, lowerBound, higherBound,C,f0,beta,tho,deltaT);
    
    FourierData = tfour(SampledData(2,:));
    
    PlotableFourierData = prepareFourierData(FourierData, samples, lowerBound, higherBound,isReal);
   
    figure(1);
    easyPlot(SampledData);
    figure(2);
    easyPlot(PlotableFourierData);
end