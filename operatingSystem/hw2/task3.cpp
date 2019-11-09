#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc ,char* argv[]){
	int pidx=0,pidy=0,pidz=0;
	int stat;
	printf("create main process %d\n",getpid());
	printf("process %d create process %d\n",getpid(),pidx=fork());
	printf("process %d create process %d\n",getpid(),pidy=fork());
	if(pidy==0){pidx=0;}
	printf("process %d create process %d\n",getpid(),pidz=fork());
	if(pidz==0){pidx=0;pidy=0;}
	/*
	your code
	*/
	if(pidx!=0){waitpid(pidx,&stat,0);}
	if(pidy!=0){waitpid(pidy,&stat,0);}
	if(pidz!=0){waitpid(pidz,&stat,0);}
	printf("process %d exit its child process %d %d %d\n",getpid(),pidx,pidy,pidz);
	
}
