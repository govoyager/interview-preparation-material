#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
int readcount=0;
int writecount=0;
int t=0;
int mutex=1;
int rw_mutex=1;
using namespace std;
struct Row
{
    int AT;
    int BT;
    bool reader;
    int serial;
    int endtime;
};
bool comp(const Row &a,const Row &b)
{
    if(a.reader==true&&b.reader==false&&a.AT==b.AT)
    {
        return 2<1;
    }

    return a.AT<b.AT;
}
int main()
{
    int read=0,write=0;
    cout<<"Enter Number of Readers"<<endl;
    cin>>read;
    cout<<"Enter Number of Writers"<<endl;
    cin>>write;
    vector<Row>Arr(read+write);
    for(int i=0;i<read;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Reader "<<i+1<<endl;
        Arr[i].reader=true;
        Arr[i].serial=i+1;

        cin>>Arr[i].AT>>Arr[i].BT;
        Arr[i].endtime=Arr[i].BT+Arr[i].AT;
    }

    for(int i=0;i<write;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Writer "<<i+1<<endl;
        Arr[read+i].reader=false;
        Arr[read+i].serial=i+1;
        cin>>Arr[read+i].AT>>Arr[read+i].BT;
        Arr[read+i].endtime=Arr[read+i].BT+Arr[read+i].AT;
    }
    queue<Row>readers;
    queue<Row>writers;
    sort(Arr.begin(),Arr.end(),comp);
    int n=read+write;
    for(int i=0;i<n;i++)
    {
        if(Arr[i].reader==true)
        {
            readers.push(Arr[i]);
        }
        else
        {
            writers.push(Arr[i]);
        }
    }
    queue<Row>ongoing;
    while(readers.size()!=0||writers.size()!=0)
    {
        Row f;
        while(ongoing.size()!=0&&ongoing.front().endtime==t)
        {
            f=ongoing.front();
            if(f.reader==true)
            {
                cout<<"Reader "<<f.serial<<" Finished reading at t= "<<t<<endl;
                readcount--;
            }
            else
            {
                cout<<"Writer "<<f.serial<<" Finished writing at t= "<<t<<endl;
                writecount--;
            }
            ongoing.pop();
        }
        Row turn;
        if(readcount==0&&writecount==0)
        {

            if(writers.size()!=0&&writers.front().AT<=t)
            {
                turn=writers.front();
                writecount++;
                turn.endtime=t+turn.BT;
                cout<<"Writer "<<turn.serial<<" Started Writing at t= "<<t<<endl;
                ongoing.push(turn);
                writers.pop();

            }
            else if(readers.size()!=0&&readers.front().AT<=t)
            {
                turn=readers.front();
                cout<<"Reader "<<turn.serial<<" Started Reading at t= "<<t<<endl;
                turn.endtime=t+turn.BT;
                readcount++;
                ongoing.push(turn);
                readers.pop();
            }

        }
        else if(writecount==0)
        {
            if(readers.size()!=0&&readers.front().AT<=t)
            {
                turn=readers.front();
                turn.endtime=t+turn.BT;
                cout<<"Reader "<<turn.serial<<" Started Reading at t= "<<t<<endl;
                readcount++;
                ongoing.push(turn);
                readers.pop();


            }


        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(Arr[i].AT==t)
                {
                    if(Arr[i].reader==true)
                    {
                        cout<<"Reader "<<Arr[i].serial<<" Starts waiting at t= "<<t<<endl;
                    }
                    else
                    {
                        cout<<"Writer "<<Arr[i].serial<<" Starts waiting at t= "<<t<<endl;

                    }
                }

            }
        }

        t++;
    }
    Row f;
    while(ongoing.size()!=0)
    {
            f=ongoing.front();
            if(f.reader==true)
            {
                cout<<"Reader "<<f.serial<<" Finished reading at t= "<<t<<endl;
                readcount--;
            }
            else
            {
                cout<<"Writer "<<f.serial<<" Finished writing at t= "<<t<<endl;
                writecount--;
            }
            ongoing.pop();
            t++;
    }
}