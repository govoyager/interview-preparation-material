//Program is done in cpp so pls use g++ to compile. It might take some time to give the output.


#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {

    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;



    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    n=5;
    p[0].arrival_time =0;
    p[1].arrival_time =1;
    p[2].arrival_time =2;
    p[3].arrival_time =3;
    p[4].arrival_time = 4;
    p[0].burst_time = 2;
    p[1].burst_time = 3;
    p[2].burst_time = 5;
    p[3].burst_time = 4;
    p[4].burst_time = 6;    
    
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i+1;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int id = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(p[i].burst_time < mn) {
                    mn = p[i].burst_time;
                    id = i;
                }
                if(p[i].burst_time == mn) {
                    if(p[i].arrival_time < p[id].arrival_time) {
                        mn = p[i].burst_time;
                        id = i;
                    }
                }
            }
        }
        if(id != -1) {
            p[id].start_time = current_time;
            p[id].completion_time = p[id].start_time + p[id].burst_time;
            p[id].turnaround_time = p[id].completion_time - p[id].arrival_time;
            p[id].waiting_time = p[id].turnaround_time - p[id].burst_time;
            
            
            total_turnaround_time += p[id].turnaround_time;
            total_waiting_time += p[id].waiting_time;
            

            is_completed[id] = 1;
            completed++;
            current_time = p[id].completion_time;
            prev = current_time;
        }
        else {
            current_time++;
        }
        
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,p[i].arrival_time);
        max_completion_time = max(max_completion_time,p[i].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
   
    cout<<endl<<endl;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
}