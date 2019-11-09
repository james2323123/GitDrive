#include <stdio.h>
#include <iostream>
#include <sys/types.h> 
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

using namespace std;

int main(){
	int id;
	cout << "PID=" << getpid() << endl;
	id = fork();
	if(id == 0){
		for(int i=0;i<10000;i++){
			for(int j=0;j<10000;j++){
				;	
			}
		}	
		cout << "hello form process " << getpid() << " ppid= " << getppid() << endl;
	}
	else{
		exit(0);
	}
}
