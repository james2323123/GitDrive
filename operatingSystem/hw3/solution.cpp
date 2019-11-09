#include <string>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;



int main(){
	int opponent_choice;
	int shmid = 0;
	int *shm;
	int key;
	int ti = 100;
	string signal;
	string temp;
	string choice;
	cin >> key;
	shmid = shmget(key, sizeof(int), IPC_CREAT|0666);
	shm = (int*)shmat(shmid, NULL, 0);
	while(ti--){
		
		cin >> signal;
		if(signal == "OK"){
			opponent_choice = *shm;
			if(opponent_choice == 0){// paper
				choice = "Scissor";
			}
			else if(opponent_choice == 1){// sissor
				choice = "Stone";
			}
			else if(opponent_choice == 2){// stone
				choice = "Paper";
			}
			else{
				choice = "Error!";
			}
		}
		else{
			cerr << "unexpected signal: " << signal << endl;
			choice = "Error!";
		}
		cout << choice << endl;
		cin >> temp;
	}
	
	

}
