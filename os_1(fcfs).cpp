// Write a C program to implement FCFS (First Come First Serve ) Scheduling Algorithm.

#include<stdio.h>
int main()	
{
        int n,IT[100],i,CT[100],WT[100],sum_wt=0,sum_ct=0;
        float avg_wt=0.0,avg_ct=0.0;
        printf("Enter n :");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%d",&IT[i]);
        }
        for(i=0;i<n;i++)
        {
                WT[i]=IT[i-1]+WT[i-1];
                sum_wt += WT[i];
        }
        avg_wt=(float)sum_wt/n;
        for(i=0;i<n;i++)
        {
                CT[i]=IT[i]+WT[i];
                sum_ct+=CT[i];
        }
        avg_ct=(float)sum_ct/n;
        printf("AVG WAITING TIME IS %f and AVG COMPLETION TIME IS %f \n",avg_wt,avg_ct);
        return 0;
}

