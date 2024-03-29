//   Write a C program to implement  Prority Scheduling Algorithm.

#include<stdio.h>
#define max 30
void Bubblesort(int proc[],int pri[],int bt[],int n)
{
        int i,j,temp_proc,temp_pri,temp_bt;
        for(i=0;i<n-1;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(pri[i]>pri[j])
                        {
                                temp_pri=pri[i];
                                pri[i]=pri[j];
                                pri[j]=temp_pri;

                                temp_proc=proc[i];
                                proc[i]=proc[j];
                                proc[j]=temp_proc;

                                temp_bt=bt[i];
                                bt[i]=bt[j];
                                bt[j]=temp_bt;
                        }
                }
        }
}
int main()
{
        int n,i,j,ct[max],bt[max],wt[max],pri[max],proc[max],sum_wt=0,sum_ct=0;
        float avg_wt,avg_ct;
        printf("Enter n : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter processor number :");
                scanf("%d",&proc[i]);
                printf("Enter burst time :");
                scanf("%d",&bt[i]);
                printf("Enter priority : ");
                scanf("%d",&pri[i]);
        }
        Bubblesort(proc,pri,bt,n);
        for(i=0;i<n;i++)
        {
                wt[i]=bt[i-1]+wt[i-1];
                sum_wt += wt[i];
        }
        avg_wt=(float)sum_wt/n;
        for(i=0;i<n;i++)
        {
                ct[i]=bt[i]+wt[i];
                sum_ct+=ct[i];
        }
        avg_ct=(float)sum_ct/n;
         printf("Proc\t\tPRIORITY\tBT\t\tCT\t\tWT \n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i],pri[i],bt[i],ct[i],wt[i]);
        }
        printf("AVG WAITING TIME IS %f and AVG COMPLETION TIME IS %f \n",avg_wt,avg_ct);
}

