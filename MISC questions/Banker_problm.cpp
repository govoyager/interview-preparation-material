#include<bits/stdc++.h>
using namespace std;

int resource[32767];
int process_all[1000][1000];
int process_max[1000][1000];
int process_rem[1000][1000];
int res_avail[32767];
int n,nr;
int res_sum[32767]={0};
int fin_index[32767];
int nf=0;
bool deadlock=false;


void solve()
{
    queue<int> q;
    int i,j,flag=0,x,nq=-1,rep[32767];
    for(i=0;i<n;i++)
    {
        for(j=0;j<nr;j++)
        {
            process_rem[i][j]=process_max[i][j]-process_all[i][j];
            if(process_rem[i][j]<0)
            process_rem[i][j]=0;
        }
    }
    for(i=0;i<nr;i++)
    res_avail[i]=resource[i]-res_sum[i];

    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=0;j<nr;j++)
        {
            if(process_rem[i][j]>res_avail[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        q.push(i);
        else 
        {
            fin_index[nf++]=i;
            for(j=0;j<nr;j++)
            res_avail[j]+=process_all[i][j];
        }
    }
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        if(nq!=-1)
        {
            if(nq==x)
            {
                flag=1;
                for(j=0;j<nr;j++)
                {
                    if(rep[j]!=res_avail[j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    deadlock=true;
                    break;
                }
            }            
        }
        flag=1;
        for(j=0;j<nr;j++)
        {
            if(process_rem[x][j]>res_avail[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            q.push(x);
            if(nq==-1)
            {
                nq=x;
                for(j=0;j<nr;j++)
                rep[j]=res_avail[j];
            }
        }
        else 
        {
            fin_index[nf++]=x;
            for(j=0;j<nr;j++)
            res_avail[j]+=process_all[x][j];
        }
    }

}

int main()
{
    int i,j,f=0;
    cout<<"Enter the number of resources: \n";
    cin>>nr;
    for(i=0;i<nr;i++)
    {
        cout<<"\nEnter the max available instances of Resource "<<i+1<<" : ";
        cin>>resource[i];
    }

    cout<<"\nEnter the number of processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nDetails of Process "<<i+1<<endl;
        for(j=0;j<nr;j++)
        {
            cout<<"\n\tEnter Alloted for Resource "<<j+1<<": ";
            cin>>process_all[i][j];
        }
        for(j=0;j<nr;j++)
        {
again:      cout<<"\n\tEnter MAX needed for Resource "<<j+1<<": ";
            cin>>process_max[i][j];
            if(process_max[i][j]>resource[j])
            {
                cout<<"Invalid input.Enter lesser value.\n";
                goto again;
            }
        }
    }
    for(i=0;i<nr;i++)
    {
        res_sum[i]=0;
        for(j=0;j<n;j++)
        res_sum[i]+=process_all[j][i];        
    }
    cout<<"Checking input...\n";
    f=1;
    for(i=0;i<nr;i++)
    {
        if(resource[i]<res_sum[i])
        {
            f=0;
            break;
        }
    }
    if(f==0)
    {
        cout<<"Input given was invalid as it exceeded the total available resources.\n";
        exit(0);
    }
    cout<<"Input validation successful.\n";
    solve();
    if(deadlock)
    cout<<"\nDeadlock has occured!!.So its unsafe condition.\n";
    else 
    {
        cout<<"It's safe condition.\n";
        cout<<"Order of execution of processes:\n";
        for(i=0;i<nf;i++)
        cout<<"Process"<<fin_index[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}