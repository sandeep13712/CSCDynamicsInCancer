#!/usr/bin/octave -qf

# Copy as Matrix  from text file with data saved in  rows

# function createImagesOfTDC (  )
  
  fileName = "SimulationStep";
  # 0 1 10 20 30 . . 1600
  
  file = strcat(fileName,"0.txt");
  
  createTDC ( file , strcat(fileName,"0") );
  
  
  file = strcat(fileName,"1.txt");
  
  createTDC ( file , strcat(fileName,"1"));
  
  i=10;
  while i<=1400
      file = strcat(fileName,num2str(i),".txt");
      createTDC ( file , strcat(fileName,num2str(i)));
      i = i + 10;
  endwhile
  
  
# endfunction
