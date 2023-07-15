//Program is done in cpp so pls use g++ to compile. It might take some time to give the output.

#include<bits/stdc++.h>
using namespace std;

// Function to calculate waiting time
void findWaitingTime(int n, int burst_time[], int waiting_time[], int arival_time[])
{
	int service_time[n];
	service_time[0] = 0;
	waiting_time[0] = 0;

	for (int i = 1; i < n ; i++)
	{
		
		service_time[i] = service_time[i-1] + burst_time[i-1];

		waiting_time[i] = service_time[i] - arival_time[i];

		if (waiting_time[i] < 0)
			waiting_time[i] = 0;
	}
}

// Function to calculate turn around time
void findTurnAroundTime( int n, int burst_time[], int waiting_time[], int turn_around_time[])
{
	
	for (int i = 0; i < n ; i++)
		turn_around_time[i] = burst_time[i] + waiting_time[i];
}

void FindAvgTime(int n, int arival_time[], int burst_time[])
{
    int Waiting_time[n], turn_around_time[n];

    findWaitingTime(n,burst_time,Waiting_time,arival_time);

    findTurnAroundTime(n,burst_time,Waiting_time,turn_around_time);
    
    cout << "Processes " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time "<< " Completion Time \n";
	
    int total_waiting_time = 0, total_tat = 0;
	
    for (int i = 0 ; i < n ; i++)
	{
		total_waiting_time = total_waiting_time + Waiting_time[i];
		total_tat = total_tat + turn_around_time[i];
		int compl_time = turn_around_time[i] + arival_time[i];
		cout << " " << i+1 << "\t\t" << burst_time[i] << "\t\t"<< arival_time[i] << "\t\t" << Waiting_time[i] << "\t\t "<< turn_around_time[i] << "\t\t " << compl_time << endl;
	}

	cout << "Average waiting time = "<< (float)total_waiting_time / (float)n;
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

int main()
{
    int n=5;
    int arival_time[] = {0,1,2,3,4};
	int burst_time[] = {2,3,5,4,6};
    FindAvgTime(n,arival_time,burst_time);
    return 0;
}