all:test

test:main.cpp cir.h
	mpic++ -DUSE_MPI main.cpp
	mpirun -n 1 ./a.out > a
	mpic++ main.cpp
	mpirun -n 1 ./a.out > b
	cat a>c
	echo '#################################################'>>c
	cat b>>c
	vim a
serial:main.cpp
	g++ main.cpp
	./a.out|tee log.txt


parallel:main.cpp
#	rm log.txt
	mpic++ -DUSE_MPI main.cpp
	./b.sh 3|tee log.txt

parallel1:main.cpp
	mpic++ -DUSE_MPI main.cpp
	mpirun -f machinefile -n 4 ./a.out

parallel2:main.cpp
	mpic++ -DUSE_MPI main.cpp
	mpirun -n 1 ./a.out

clean:
#	rm -f ./*.txt
	rm -f ./*.figdata
	rm -f *.out

rmdata:
	rm -f ./Data*.txt
	rm -f ./Run-conf*.txt
	rm -f *.out
	rm -f ID.txt

doid:idtest.cpp
	g++ -o idtest idtest.cpp
	./idtest
	
	
