#include<iostream>
using namespace std;
void waiting_time(int p[], int n, int bt[],int wt[], int at[])
{
        int st[n];
        st[0] = 0;
        wt[0] = 0;
        for (int i = 1; i < n ; i++)
        {
                st[i] = st[i-1] + bt[i-1];
                wt[i] = st[i] - at[i];
                if (wt[i] < 0)
                        wt[i] = 0;
        }
}
void turn_around_time(int p[], int n, int bt[],int wt[], int tat[])
{
        for (int i = 0; i < n ; i++)
          tat[i] = bt[i] + wt[i];
}

void avg_time(int p[], int n, int bt[], int at[])
{
        int wt[n], tat[n];
        waiting_time(p, n, bt, wt, at);
        turn_around_time(p, n, bt, wt, tat);
        cout << "Processes " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time "<< " Completion Time \n";
        int total_wt = 0, total_tat = 0;
        for (int i = 0 ; i < n ; i++)
        {
                total_wt = total_wt + wt[i];
                total_tat = total_tat + tat[i];
                int compl_time = tat[i] + at[i];
                cout << i+1 << "\t\t" << bt[i] << "\t\t"<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << "\t\t " <<compl_time<<"\n";
        }

        cout << "Average waiting time = "<<total_wt<< "\n";
        cout << "\nAverage turn around time = "<<total_tat<<"\n";
}
int main()
{
        int p[10],n,i,bt[10],at[10];
        cout<<"it's same for preemptive and non preemptive \n";
        cout<<"enter no. of process";
        cin>>n;
        for(i=0;i<n;i++)
        {
        p[i]=i+1;
        }
        cout<<"enter no. burst time of each process";
        for(i=0;i<n;i++)
        {
        cin>>bt[i];
        }
        cout<<"enter the arrival time of each process";
        for(i=0;i<n;i++)
        {
        cin>>at[i];
        }
        avg_time(p, n, bt, at);
        return 0;
}
