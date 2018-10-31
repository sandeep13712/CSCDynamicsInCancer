for num in {1..10}; do
cd 1
	cd Set$num
	nohup ./Executable_CSC1Zone &
    	cd ..
cd ..

cd 2
	cd Set$num
	nohup ./Executable_CSC2Zones &
    	cd ..
cd ..

cd 3
	cd Set$num
	nohup ./Executable_CSC3Zones &
    	cd ..
cd ..

cd 4
	cd Set$num
	nohup ./Executable_CSC4Zones &
    	cd ..
cd ..

cd 5
	cd Set$num
	nohup ./Executable_CSC5Zones &
    	cd ..
cd ..

sleep 5

done


