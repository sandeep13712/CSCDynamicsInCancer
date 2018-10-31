function createCSC ( file , imageName)
 
  A = load(strcat("./Txt/",file));
  disp(file); 
  
  [textRows textColumns] = size(A);   
    
  i=1;
  j=1;

  k=1;
  e=1;
  
  img = double( zeros(textRows,textColumns,3) );
              
    for j =1:textRows
    
      for k = 1:textColumns
      
        img(j,k,1) = 255;
        img(j,k,2) = 255;
        img(j,k,3) = 255;
        
        #assign color to CSC
        if ( A(j,k) == 1 )
          
          #CSC
          img(j,k,1) = 255;
          img(j,k,2) = 0;
          img(j,k,3) = 0;
          
        endif    
      
      endfor
    
    endfor

    img = img / 255;
    imwrite(img,strcat("./Images/","CSCIn",imageName,".png"));
    disp(strcat("CSCIn",imageName,".png"," image saved"));

  
  #save I.mat I
  
  #disp("Matrix Saved");  
 
endfunction
