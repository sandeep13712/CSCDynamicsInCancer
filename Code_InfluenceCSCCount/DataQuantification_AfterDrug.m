TotalSimulationSets = 10;
tumor_size = zeros(700,18);

% data = zeros(32,9*TotalSimulationSets+27);
f = {'AlphaPoint25Beta1', 'AlphaPoint25Beta5', 'AlphaPoint25Beta10','AlphaPoint5Beta1','AlphaPoint5Beta5','AlphaPoint5Beta10','AlphaPoint75Beta1','AlphaPoint75Beta5','AlphaPoint75Beta10'};
for i = 1 : 9
    f(i)
    f1 = f(i);
    f2 = f1{1,1};
    cd(f2);
    for simSetNo = 1:TotalSimulationSets
        folderName = strcat('Set',num2str(simSetNo));
        cd(folderName)
        filename = dir('*.csv');
        p = csvread(filename.name, 1, 1);
        for itrNo = 1:700
            tumor_size(itrNo,(i-1)*10+simSetNo) = sum(p(itrNo,1:15));
        end 
        cd ..
    end
    cd ..
end

finalData = zeros(700,18);

for i = 1:9
   for itr = 1:700
     finalData(itr,i*2-1) = mean(tumor_size(itr,(i-1)*10+1:i*10));
     finalData(itr,i*2) = std(tumor_size(itr,(i-1)*10+1:i*10))/sqrt(10);
   end
end




for i = 1:2:6
plot(finalData(:,i));
hold on
end