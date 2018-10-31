TotalSimulationSets = 10
% data = zeros(32,9*TotalSimulationSets+27);
f = {'AlphaPoint25Beta1', 'AlphaPoint25Beta5', 'AlphaPoint25Beta10','AlphaPoint5Beta1','AlphaPoint5Beta5','AlphaPoint5Beta10','AlphaPoint75Beta1','AlphaPoint75Beta5','AlphaPoint75Beta10'};
for i = 1 : 9
f(i)
f1 = f(i)
f2 = f1{1,1}
cd(f2);
for simSetNo = 1:TotalSimulationSets
folderName = strcat('Set',num2str(simSetNo));
cd(folderName)
filename = dir('*.csv');
filename.name
p = csvread(filename.name, 701, 1, [701 1 701 26]);
data(1:15,simSetNo + 10*(i-1)) = p(1:15)';
data(16,simSetNo + 10*(i-1)) = sum(data(1:5,simSetNo + 10*(i-1)));
data(17,simSetNo + 10*(i-1)) = sum(data(6:10,simSetNo + 10*(i-1)));
data(18,simSetNo + 10*(i-1)) = sum(data(11:15,simSetNo + 10*(i-1)));
data(19,simSetNo + 10*(i-1)) = sum(data(16:18,simSetNo + 10*(i-1)));
data(20,simSetNo + 10*(i-1)) = 100*data(16,simSetNo + 10*(i-1))/data(19,simSetNo + 10*(i-1)); %CSCFraction
data(21,simSetNo + 10*(i-1)) = 100*data(17,simSetNo + 10*(i-1))/data(19,simSetNo + 10*(i-1)); %TACFraction
data(22,simSetNo + 10*(i-1)) = 100*data(18,simSetNo + 10*(i-1))/data(19,simSetNo + 10*(i-1)); %TDCFraction
data(23,simSetNo + 10*(i-1)) = sum(data([1,6,11],simSetNo + 10*(i-1))); %Zone1Total
data(24,simSetNo + 10*(i-1)) = sum(data([2,7,12],simSetNo + 10*(i-1))); %Zone1Total
data(25,simSetNo + 10*(i-1)) = sum(data([3,8,13],simSetNo + 10*(i-1))); %Zone1Total
data(26,simSetNo + 10*(i-1)) = sum(data([4,9,14],simSetNo + 10*(i-1))); %Zone1Total
data(27,simSetNo + 10*(i-1)) = sum(data([5,10,15],simSetNo + 10*(i-1))); %Zone1Total
clear p
cd ..
end
cd ..
end
for simulationCondition = 1:9
for rowNo = 1:27
data(rowNo,10*9+(simulationCondition-1)*2+1) = mean(data(rowNo,(10*simulationCondition-9:10*simulationCondition)));
data(rowNo,10*9+(simulationCondition-1)*2+2) = std(data(rowNo,(10*simulationCondition-9:10*simulationCondition)));
end
end
dataToPlot = zeros(9,15);
for simulationCondition = 1:9
dataToPlot(simulationCondition,1) = data(19,10*9+(simulationCondition-1)*2+1);
dataToPlot(simulationCondition,2) = data(19,10*9+(simulationCondition-1)*2+2);
dataToPlot(simulationCondition,3) = data(20,10*9+(simulationCondition-1)*2+1); %CSC Fraction
dataToPlot(simulationCondition,4) = data(20,10*9+(simulationCondition-1)*2+2); %CSC Fraction
dataToPlot(simulationCondition,5) = data(21,10*9+(simulationCondition-1)*2+1); %TAC Fraction
dataToPlot(simulationCondition,6) = data(21,10*9+(simulationCondition-1)*2+2); %CSC Fraction
dataToPlot(simulationCondition,7) = data(22,10*9+(simulationCondition-1)*2+1); %TDC Fraction
dataToPlot(simulationCondition,8) = data(22,10*9+(simulationCondition-1)*2+2); %CSC Fraction
dataToPlot(simulationCondition,9) = data(23,10*9+(simulationCondition-1)*2+1); %TotalCells in Zone1
dataToPlot(simulationCondition,10) = data(23,10*9+(simulationCondition-1)*2+2); %TotalCells in Zone1
dataToPlot(simulationCondition,11) = data(24,10*9+(simulationCondition-1)*2+1); %TotalCells in Zone2
dataToPlot(simulationCondition,12) = data(24,10*9+(simulationCondition-1)*2+2); %TotalCells in Zone2
dataToPlot(simulationCondition,13) = data(25,10*9+(simulationCondition-1)*2+1); %TotalCells in Zone3
dataToPlot(simulationCondition,14) = data(25,10*9+(simulationCondition-1)*2+2); %TotalCells in Zone3
dataToPlot(simulationCondition,15) = data(26,10*9+(simulationCondition-1)*2+1); %TotalCells in Zone4
dataToPlot(simulationCondition,16) = data(26,10*9+(simulationCondition-1)*2+2); %TotalCells in Zone3
dataToPlot(simulationCondition,17) = data(27,10*9+(simulationCondition-1)*2+1); %TotalCells in Zone5
dataToPlot(simulationCondition,18) = data(27,10*9+(simulationCondition-1)*2+2); %TotalCells in Zone5
end
% Testing %%%%%%%%%%%%
% 1. Make sure that it is fetching the right data.
% A25B5Set1, A5B1Set4, A5B10Set6, A75B5Set10
% 2. Make sure that totals etc are calculated correctly.
% A25B1Set1, A5B10Set2, A75B1Set3
% 3. Test that the average and STDs are getting calculated correctly.
% A25B5 A5B5 A75B1
