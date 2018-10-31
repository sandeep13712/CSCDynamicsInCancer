for num in {2..10}; do

cd 10
	cd Set$num
	nohup ./Executable_CSC10 &
    	cd ..
cd ..

cd 20
	cd Set$num
	nohup ./Executable_CSC20 &
    	cd ..
cd ..

cd 50
	cd Set$num
	nohup ./Executable_CSC50 &
    	cd ..
cd ..

cd 100
	cd Set$num
	nohup ./Executable_CSC100 &
    	cd ..
cd ..

cd 200
	cd Set$num
	nohup ./Executable_CSC200 &
    	cd ..
cd ..

cd 300
	cd Set$num
	nohup ./Executable_CSC300 &
    	cd ..
cd ..

cd 400
	cd Set$num
	nohup ./Executable_CSC400 &
    	cd ..
cd ..

cd 500
	cd Set$num
	nohup ./Executable_CSC500 &
    	cd ..
cd ..

cd 1000
	cd Set$num
	nohup ./Executable_CSC1000 &
    	cd ..
cd ..

sleep 3

done


