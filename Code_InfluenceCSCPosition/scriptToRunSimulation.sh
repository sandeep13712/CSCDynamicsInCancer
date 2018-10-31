for num in {1..10}; do

cd AlphaPoint25Beta1
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint25Beta5
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint25Beta10
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint5Beta1
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint5Beta5
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint5Beta10
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint75Beta1
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint75Beta5
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

cd AlphaPoint75Beta10
	cd Set$num
	nohup ./Executable_AfterDrug &
    	cd ..
cd ..

sleep 3

done


