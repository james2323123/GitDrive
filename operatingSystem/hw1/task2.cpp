#include <stdio.h>
#include <iostream>
#include <sys/types.h> 
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

using namespace std;

int forkWrap(){

	int id = -1;
	id = fork();
	if(id == 0){
		cout << "process with PID " << getpid() << " and PPID " 
		<< getppid() << " created" << endl;
	}
	return id;
}

void exitWrap(){
	
	cout << "process with PID " << getpid() << " terminated" << endl;
	exit(0);
}

void makeChild(int count){
	
	int id = -1;
	//cout << "count = " << count << endl;
	id = forkWrap();
	if(id == 0 && count > 1){// fork again
		makeChild(--count);
	}
	else{// wait
		wait(NULL);
		exitWrap();
	}
	
}
 
int main() {
	makeChild(10);
}



                       
