#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int s=1;
int empty=6;
int full=0;
int t=0;

struct Row
{
    bool producer;
    int AT;
    int BT;
    int serial;
    bool completed;
};

bool comp(const Row &a,const Row &b)
{
    if(a.producer==false&&b.producer==true&&a.AT==b.AT)
    {
        return b.AT<a.AT;

    }

    return a.AT<b.AT;
}

int signal(int s)
{
    s++;
    return s;
}

int wait(int s)
{
    while(s<=0);

    s--;
    return s;
}

void producer(int bt,int serial)
{
    s=wait(s);
    full=signal(full);
    empty=wait(empty);
    t+=bt;//Incrementing t to t+bt
    cout<<"Producer "<<serial<<" Producing Finished at  time t="<<t<<endl;

    s=signal(s);
}
void consumer(int bt,int serial)//Argument:Burst Time of Porcess
{
    s=wait(s);
    full=wait(full);
    empty=signal(empty);
    t+=bt;
    cout<<"Consumer "<<serial<<" Consuming Finished at t="<<t<<endl;
    s=signal(s);
}

int main()
{
    int prod=0,consum=0;
    cout<<"Enter Number of Producers"<<endl;
    cin>>prod;
    cout<<"Enter Number of Consumers"<<endl;
    cin>>consum;
    vector<Row>Arr(prod+consum);\
    queue<Row>producerqueue;
    queue<Row>consumerqueue;
    for(int i=0;i<prod;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Producer "<<i+1<<endl;
        Arr[i].producer=true;
        Arr[i].serial=i+1;
        Arr[i].completed=false;
        cin>>Arr[i].AT>>Arr[i].BT;
    }

    for(int i=0;i<consum;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Consumer "<<i+1<<endl;
        Arr[prod+i].producer=false;
        Arr[prod+i].serial=i+1;
        Arr[prod+i].completed=false;
        cin>>Arr[prod+i].AT>>Arr[prod+i].BT;
    }
    sort(Arr.begin(),Arr.end(),comp);
    int n=prod+consum;
    int leftover=n;
    for(int i=0;i<n;i++)
    {
        if(Arr[i].producer==true)
        {
            if(s==1&&empty!=0)
            {
                producerqueue.push(Arr[i]);
                Row f=producerqueue.front();
                t=max(t,f.AT);
                cout<<"Producer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(Arr[j].AT==f.AT)
                    {
                        if(Arr[j].producer==true)
                        {
                            cout<<" Producer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }

                producer(f.BT,f.serial);
                producerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Full.Producer "<<Arr[i].serial<<" Needs to wait"<<endl;
                producerqueue.push(Arr[i]);
            }

        }
        else
        {
            if(s==1&&full!=0)
            {
                consumerqueue.push(Arr[i]);
                Row f=consumerqueue.front();
                 t=max(t,f.AT);
                cout<<"Consumer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(Arr[j].AT==f.AT)
                    {
                        if(Arr[j].producer==true)
                        {
                            cout<<" Producer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }
                consumer(f.BT,f.serial);
                consumerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Empty.Consumer "<<Arr[i].serial<<" Needs to wait"<<endl;
                consumerqueue.push(Arr[i]);
            }

        }
    }
    vector<Row>left;
    while(producerqueue.size()!=0)
    {
        cout<<producerqueue.front().serial<<endl;
        left.push_back(producerqueue.front());
        producerqueue.pop();
    }
    while(consumerqueue.size()!=0)
    {
        left.push_back(consumerqueue.front());
        consumerqueue.pop();
    }
    sort(left.begin(),left.end(),comp);
    n=left.size();

    for(int i=0;i<n;i++)
    {
        if(left[i].producer==true)
        {
            if(s==1&&empty!=0)
            {
                producerqueue.push(left[i]);
                Row f=producerqueue.front();
                 t=max(t,f.AT);
                cout<<"Producer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(left[j].AT==f.AT)
                    {
                        if(left[j].producer==true)
                        {
                            cout<<" Producer "<<left[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<left[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }
                producer(f.BT,f.serial);
                producerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Full.Producer "<<left[i].serial<<" Needs to wait for Consumer"<<endl;
                producerqueue.push(left[i]);
            }

        }
        else
        {
            if(s==1&&full!=0)
            {
                consumerqueue.push(left[i]);
                Row f=consumerqueue.front();
                 t=max(t,f.AT);
                cout<<"Consumer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(left[j].AT==f.AT)
                    {
                        if(left[j].producer==true)
                        {
                            cout<<" Producer "<<left[j].serial<<" is waiting"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<left[j].serial<<" is waiting"<<endl;
                        }
                    }

                }
                consumer(f.BT,f.serial);
                consumerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Empty.Consumer "<<left[i].serial<<" Needs to wait for Producer"<<endl;
                consumerqueue.push(left[i]);
            }

        }
    }

}