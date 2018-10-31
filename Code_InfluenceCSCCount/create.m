function create( file , imageName)
 
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
        
        #assign color to type of cells
        if ( (A(j,k) == 0) || ( A(j,k) > 1000) )
        
          #ES with fibers
          img(j,k,1) = 255;
          img(j,k,2) = 255;
          img(j,k,3) = 255;
          
        elseif ( A(j,k) == 1 )
          
          #CSC
          img(j,k,1) = 255;
          img(j,k,2) = 0;
          img(j,k,3) = 0;
          
        elseif ( (A(j,k) > 10) && (A(j,k) < 100) )

          #TAC
          img(j,k,1) = 0;
          img(j,k,2) = 128 + ( A(j,k) - 11 ) *12  ;
          img(j,k,3) = 0;
        
        elseif ( ( A(j,k) > 100 ) && ( A(j,k) < 1000 ) )

          #TDC
          img(j,k,1) = 0;
          img(j,k,2) = 0;
          img(j,k,3) = 255;
        
        endif
        
        
%        if ( ( (j == 1 || j == 200) && (k>=1) && (k<= 200) ) || ( (k == 1 || k == 200) && (j>=1) && (j<= 200) ))
%        
%          img(j,k,1) = 0;
%          img(j,k,2) = 0;
%          img(j,k,3) = 0;
%          
%        elseif ( ( (j == 10 || j == 189) && (k>=10) && (k<= 189) ) || ( (k == 10 || k == 189) && (j>=10) && (j<= 189) ) )
%        
%          img(j,k,1) = 0;
%          img(j,k,2) = 0;
%          img(j,k,3) = 0;
%
%        elseif ( ( (j == 22 || j == 177) && (k>=22) && (k<= 177) ) || ( (k == 22 || k == 177) && (j>=22) && (j<= 177) )  )
%        
%          img(j,k,1) = 0;
%          img(j,k,2) = 0;
%          img(j,k,3) = 0;
%
%        elseif ( ( (j == 37 || j == 163) && (k>=37) && (k<= 163) ) || ( (k == 37 || k == 163) && (j>=37) && (j<= 163) ) )
%        
%          img(j,k,1) = 0;
%          img(j,k,2) = 0;
%          img(j,k,3) = 0;
%          
%        elseif ( ( (j == 55 || j == 144) && (k>=55) && (k<= 144) ) || ( (k == 55 || k == 144) && (j>=55) && (j<= 144) ) )
%        
%          img(j,k,1) = 0;
%          img(j,k,2) = 0;
%          img(j,k,3) = 0;
%          
%        endif                
      
      endfor
    
    endfor

    img = img / 255;
    imwrite(img,strcat("./Images/",imageName,".png"));
    disp(strcat(imageName,".png"," image saved"));

  
  #save I.mat I
  
  #disp("Matrix Saved");  
 
endfunction
