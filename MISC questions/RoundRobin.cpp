//Program is done in cpp so pls use g++ to compile. It might take some time to give the output.


#include<iostream>
#include<iomanip>
using namespace std;
 
void CalcWaitingTime(int wt_time[], int n, int burst_time[], int quantum, int completion_time[], int arrival_time[])
{
  int remaining_time[n];
 
  for(int i = 0; i < n; i++)
    remaining_time[i] = burst_time[i];
 
  int time = 0;
  int arrival = 0;
 
  
  while(true)
  {
    bool done = true;
    for(int i = 0; i < n; i++)
    {
      if(remaining_time[i] > 0)
      {
        done = false;
        if(remaining_time[i] > quantum && 
           arrival_time[i] <= arrival)
        {
          time += quantum;
          remaining_time[i] -= quantum;
          arrival++;
        }
        else
        {
          if(arrival_time[i] <= arrival)
          {
            arrival++;
            time += remaining_time[i];
            remaining_time[i] = 0;
            completion_time[i] = time; 
          }
        }
      }
    }
 
    if(done==true) 
      break;
  } 
}
 
void CalcTurnAroundTime(int wait_time[], int n, int burst_time[], int turn_around_time[], int completion_time[], int arrival_time[])
{
  for(int i = 0; i < n; i++)
  {
    turn_around_time[i] = completion_time[i] - 
                  arrival_time[i];
    wait_time[i] = turn_around_time[i] - 
                 burst_time[i];
  }
}
 
void CalcAvgTime(int n, int burst_time[], int quantum, int arrival_time[])
{
  int wait_time[n];
  int turn_around_time[n];
  int completion_time[n];
  int total_wait_time = 0, total_tat = 0;
  CalcWaitingTime(wait_time, 
                  n, burst_time, 
                  quantum, 
                  completion_time, 
                  arrival_time); 
  CalcTurnAroundTime(wait_time, 
                     n, burst_time, 
                     turn_around_time, 
                     completion_time, 
                     arrival_time);
  cout << "\t" << "PROCESS" << 
          "\t\t" << "ARRIVAL TIME" << 
          "\t" << "BURST TIME" << 
          "\t" << "COMPLETION TIME" <<
          "\t" << "TURN AROUND TIME" <<
          "\t" << "WAITING TIME\n";
 
  for (int i = 0; i < n; i++) 
  { 
    total_wait_time = total_wait_time + wait_time[i]; 
    total_tat = total_tat + turn_around_time[i]; 
    cout << "\t\t" << i + 1 << 
            "\t\t" << arrival_time[i] << 
            "\t\t" << burst_time[i] << 
            "\t\t" << completion_time[i] <<
            "\t\t" << turn_around_time[i] <<
            "\t\t" << wait_time[i] << endl; 
  } 
 
  cout << "\nAVERAGE WAITING TIME : " <<
          (float)total_wait_time / (float)n; 
  cout << "\nAVERAGE TURN AROUND TIME : " <<
          (float)total_tat / (float)n; 
}
 

int main()
{
  int n=5;
  int arival_time[] = {0,1,2,3,4};
	int burst_time[] = {2,3,5,4,6};
  int quantum =2;
  CalcAvgTime( n, burst_time, quantum, arival_time);
  return 0;
}