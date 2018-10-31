function createTDC ( file , imageName)
 
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
        
        #assign color to TDC
        if ( ( A(j,k) > 100 ) && ( A(j,k) < 1000 ) )

          #TDC
          img(j,k,1) = 0;
          img(j,k,2) = 0;
          img(j,k,3) = 255;

        endif        
      
      endfor
    
    endfor

    img = img / 255;
    imwrite(img,strcat("./Images/","TDCIn",imageName,".png"));
    disp(strcat("TDCIn",imageName,".png"," image saved"));

  
  #save I.mat I
  
  #disp("Matrix Saved");  
 
endfunction
