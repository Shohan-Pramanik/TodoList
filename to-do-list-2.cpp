#include<bits/stdc++.h>
using namespace std;
int ct=1,currentpostion=1;
class mytodo{
public:
    string description;
    string duedate;
    int priority;
};
class mytodo mytodolist[100];
bool addtodolist(string description,string duedate,int priority){
    if(ct<100){
        mytodolist[ct].description=description;
        mytodolist[ct].duedate=duedate;
        mytodolist[ct].priority=priority;
        ct++;
        return true;
    }
    else{
        return false;
    }
}
bool getnextitem(mytodo &nextitem){
    if(ct==1){
        return false;
    }
    else{
        nextitem=mytodolist[currentpostion++];
        return true;
    }
}
bool getbypriority(mytodo &matche,int priority){
    for(int i=1;i<ct;i++){
        if(mytodolist[i].priority==priority){
            matche=mytodolist[i];
            currentpostion++;
            return true;
        }
    }
    return false;
}
bool showtodolist(){
    for(int i=currentpostion;i<ct;i++){
        cout<<"## "<<mytodolist[i].description<<"  "<<mytodolist[i].duedate<<"  "<<mytodolist[i].priority<<endl;
    }
    return true;
}
int main(){
    int choice,priority;
    string description,duedate;
    mytodo matche,nextitem;
    while(1){
        cout<<"Enter -1 to terminate the program"<<endl;
        cout<<"Enter 1 to add a new item in the list"<<endl;
        cout<<"Enter 2 to see the next item in the list"<<endl;
        cout<<"Enter 3 to see the next item by given priority"<<endl;
        cout<<"Enter 4 to see the Remaining item in the list"<<endl;
        cin>>choice;
        if(choice==1){
            getchar();
            cin>>description;
            cin>>duedate;
            cin>>priority;
            addtodolist(description,duedate,priority);
        }
        else if(choice==2){
            getnextitem(nextitem);
            cout<<"## "<<nextitem.description<<"  "<<nextitem.duedate<<"  "<<nextitem.priority<<endl;
        }
        else if(choice==3){
            cout<<"Enter priority :"<<endl;
            cin>>priority;
            getbypriority(matche,priority);
            cout<<"## "<<matche.description<<"  "<<matche.duedate<<"  "<<matche.priority<<endl;
        }
        else if(choice==4){
            showtodolist();
        }
    }
    return 0;
}
