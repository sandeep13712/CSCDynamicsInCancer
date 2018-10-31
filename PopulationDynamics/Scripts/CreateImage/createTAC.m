function createTAC ( file , imageName)
 
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
        
        #assign color to TAC

	if ( (A(j,k) > 10) && (A(j,k) < 100) )

          #TAC
          img(j,k,1) = 0;
          img(j,k,2) = 128 + ( A(j,k) - 11 ) *12  ;
          img(j,k,3) = 0;

        endif    
      
      endfor
    
    endfor

    img = img / 255;
    imwrite(img,strcat("./Images/","TACIn",imageName,".png"));
    disp(strcat("TACIn",imageName,".png"," image saved"));
 
endfunction
