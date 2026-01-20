#include<iostream>
#include<string>
using namespace std;
const int MAX =100;

int findbyroll(int roll[],int count,int targetroll){
    for(int i =0;i<count;i++){
        if(roll[i]==targetroll){
         return i;
        }
    }
    return -1;
}

void addstudent(int roll[],string name[], int m1[],int m2[],int m3[],int &count){
    if(count>=MAX){
        cout<<"DATABASE FULL\n";
        return;
    }
    int r;
    cout<<"ENTER ROLL NUMBER: ";
    cin>>r;
    if(findbyroll(roll,count,r)!=-1){
        cout<<"This roll number alreasy exist.\n";
        return;
    }
    roll[count]=r;
    cout<<"Enter name (no spaces): ";
    cin>>name[count];

    cout<<"Enter marks in 3 subjects: ";
    cin>>m1[count]>>m2[count]>>m3[count];
    count++;
    cout<<"Student added successfully ! \n";
}

void showall(const int roll[],const int m1[],const int m2[],const int m3[],const string name[],int count){
    if(count == 0){
        cout<<"No student to Show !\n";
        return;
    }
    cout<<"\nRoll\tName\tM1\tM2\tM3\tToatal\tAvg\n";
    cout<<"-------------------------------------------\n";
    for(int i=0;i<count;i++){
        int total=m1[i]+m2[i]+m3[i];
        double avg=total/3.0;
        cout<<roll[i]<<"\t";
        cout<<name[i]<<"\t";
        cout<<m1[i]<<"\t";
        cout<<m2[i]<<"\t";
        cout<<m3[i]<<"\t";
        cout<<total<<"\t";
        cout<<avg<<"\n";

    }
}
void searchstudent(int roll[],const string name[],const int m1[],const int m2[],const int m3[],int count){
    int r;
    cout<<"Enter the Roll Number: ";
    cin>>r;
    int a = findbyroll(roll,count,r);
        if(a == -1){
            cout<<"Student Not Found !!";
            return;
        }
    
    int total = m1[a]+m2[a]+m3[a];
    double avg = total/3.0;
    cout<<"Found: "<<name[a];
    cout<<"TOTAL: "<<total;
    cout<<"AVG: "<<avg<<"\n";  
}
void updatemarks(int roll[],int m1[],int m2[],int m3[],int count){
    int r;
    cout<<"Enter Roll Number: ";
    cin>>r;
    int a = findbyroll(roll,count,r);
        if(a == -1){
            cout<<"Student Not Found !!!\n";
            return;
        }
        cout<<"Enter updated Marks: ";
        cin>>m1[a]>>m2[a]>>m3[a];
        cout<<"Marks Updated !\n";
}
void deletestudent(int roll[],string name[],int m1[],int m2[], int m3[],int &count){
    int r;
    cout<<"Enter Roll Number: ";
    cin>>r;
    int a = findbyroll(roll,count,r);
    if(a == -1){
        cout<<"Student Not Found !!\n";
        return;
    }
    for(int i = a ; i < count-1;i++){
        roll[i]=roll[i+1];
        name[i]=name[i+1];
        m1[i]=m1[i+1];
        m2[i]=m2[i+1];
        m3[i]=m3[i+1];
    }
    count--;
    cout<<"Student Deleted !!\n";
}
int main(){
    int roll[MAX];
    string name[MAX];
    int m1[MAX],m2[MAX],m3[MAX];
    int count = 0;
    int choice;
    while(true){
        cout<<"\n**************** Student Management System *****************\n";
        cout<<"1. Add Student\n";
        cout<<"2. Show All Students\n";
        cout<<"3. Search by Roll number\n";
        cout<<"4. Update Marks\n";
        cout<<"5. Delete Student\n";
        cout<<"6. Exit\n";
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Please enter a number (1-6).\n";
            continue;
        }
        cout<<"Option selected: "<<choice<<"\n";
        if(choice==6){
            cout<<"Exiting...\n";
            return 0;
        }else if(choice == 1){
            addstudent(roll,name,m1,m2,m3,count);
        }else if(choice==2){
            showall(roll,m1,m2,m3,name,count);
        }else if(choice == 3){
            searchstudent(roll,name,m1,m2,m3,count);
        }else if (choice == 4){
            updatemarks(roll,m1,m2,m3,count);
        }else if(choice == 5){
            deletestudent(roll,name,m1,m2,m3,count);
        }else{
            cout<<"Invalid choice !!!\n";
        }
        
    }
}
