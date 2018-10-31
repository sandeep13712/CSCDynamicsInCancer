dist = zeros(1:10,1);
for setCount = 1:10
    clear Cordinates
    folderName = strcat('Set',num2str(setCount));
    cd(folderName);
    cd('Txt');
    for i = 0:10:990
        fileName = strcat('SimulationStep',num2str(i),'.txt');
        a = dlmread(fileName);
        [m n] = find(a == 1);
        Cordinates(1+i/10,1) = m;
        Cordinates(1+i/10,2) = n;
    end
    
    d = 0;
    for t = 2:100
        d = d + sqrt(((Cordinates(t,1) - Cordinates(t-1,1))^2 + (Cordinates(t,2) - Cordinates(t-1,2))^2));
    end
    dist(setCount) = d;
    
    cd ../../
end


