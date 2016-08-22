#include "mpi.h"

#include<iostream>
#include<fstream>


#include <math.h>
#include <stdio.h>
#include "cir.h"
using namespace std;


void save(const char *file,double *x,int s){
	ofstream out(file);
	if(!out.is_open()){cerr<<"Error:file("<<file<<") can't be opened."<<endl;}
	for(int i=0;i<s;i++){
		char *tmp=(char *)&x[i];
		out.write(tmp,sizeof(x[i]));
	}
	out.close();
}
void read(const char *file,double *x,int s){
	ifstream in(file);
	if(!in.is_open()){cerr<<"Error:file("<<file<<") can't be opened."<<endl;}
	for(int i=0;i<s;i++){
		char *tmp=(char*)&x[i];
		in.read(tmp,sizeof(double));
	}
	in.close();
}

void printV(double *d,int s){
	for(int i=0;i<s;i++){
		if(i!=0)cout<<",";
		printf("%g",d[i]);
	}
}
int *g_argc;
char ***g_argv;
void doInit(){
	MPI_Init(g_argc,g_argv);
}
int main(int argc, char *argv[]){
	g_argc=&argc;
	g_argv=&argv;
	//
	double x[7],fx;
	read("x.txt",x,7);
#ifdef USE_MPI
	MPI_Init(g_argc,g_argv);
	fx=myfun(x);
#else
	fx=myfun(x);
	MPI_Init(g_argc,g_argv);
#endif
	cout<<"fx:"<<fx<<endl;
	//MPI_Finalize();
	return 0;
}




//cout<<"X:[";printV(x,7); ;cout<<endl;
