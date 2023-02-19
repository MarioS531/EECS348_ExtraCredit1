#include <iostream>
#include <cstring>

using namespace std;

const int numProgrammers = 5;
const int numDepartments = 5;

int programmers[numProgrammers][5] = {
    {3,1,2,5,4},
    {4,3,1,5,2},
    {2,5,4,1,3},
    {4,5,2,1,3},
    {3,2,1,5,4}
};

int departments[numDepartments][5] = {
    {1,5,3,2,4},
    {1,3,4,2,5},
    {3,4,2,5,1},
    {3,1,2,4,5},
    {4,3,1,2,5}
};

int programmerAssigned[numProgrammers];
bool departmentAssigned[numDepartments];

void algorithm(){
    memset(programmerAssigned, -1, sizeof(programmerAssigned));
    memset(departmentAssigned, false, sizeof(departmentAssigned));
    
    while(true){
        int freeProgrammer = -1;
        for(int i=0;i<numProgrammers;i++){
            if(programmerAssigned[i] == -1){
                freeProgrammer = i;
                break;
            }
        }
        if(freeProgrammer == -1){
            break;
        }
        
        for(int i=0;i<5;i++){
            int preferredDepartment = programmers[freeProgrammer][i];
            if(!departmentAssigned[preferredDepartment]){
                programmerAssigned[freeProgrammer] = preferredDepartment;
                departmentAssigned[preferredDepartment] = true;
                break;
            }
            else{
                int currentProgrammer = -1;
                for(int j=0;j<numProgrammers;j++){
                    if(programmerAssigned[j] == preferredDepartment){
                        currentProgrammer = j;
                        break;
                    }
                }
                int rankOfCurrent = -1;
                int rankOfFree = -1;
                for(int j=0;j<5;j++){
                    if(departments[preferredDepartment][j] == freeProgrammer){
                        rankOfFree = j;
                    }
                    if(departments[preferredDepartment][j] == currentProgrammer){
                        rankOfCurrent = j;
                    }
                }
                if(rankOfFree < rankOfCurrent){
                    programmerAssigned[freeProgrammer] = preferredDepartment;
                    programmerAssigned[currentProgrammer] = -1;
                    break;
                }
            }
        }
    }
}

int main(){
    algorithm();
    for(int i=0;i<numDepartments;i++){
        cout<<"Department #"<<i+1<<" will get Programmer #";
        for(int j=0;j<numProgrammers;j++){
            if(programmerAssigned[j] == i){
                cout<<j+1<<endl;
            }
        }
    }
    return 0;
}
