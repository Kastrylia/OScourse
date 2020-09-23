#include <stdio.h>

void swap (int* a, int i, int j){
    a[i]+=a[j];
    a[j]=a[i]-a[j];
    a[i]=a[i]-a[j];
}

void sorting (int* bt, int* at, int* pr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if ((at[j] > at[j + 1]) || (at[j] == at[j + 1] && bt[j] > bt[j + 1]))
            {
                swap(bt, j, j + 1);
                swap(at, j, j + 1);
                swap(pr, j, j + 1);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of processes ");
    scanf("%d",&n);
    int p[n], at[n], bt[n], wt[n], tat[n], ct[n];
    int  awt = 0, atat = 0;
 
    for(int i=0; i<n; i++) 
    {
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        p[i] = i + 1;
    }
    
    sorting(bt, at, p, n);
 
    ct[0]=0;
    wt[0]=0;
    tat[0]=bt[0];
    
    for(int i=1; i<n; i++) {
        wt[i]=0;
        ct[i]=0;
        for(int j=0; j<i; j++) wt[i]+=bt[j];
        wt[i] -= at[i];
        ct[i] += wt[i] + at[i];
        tat[i]=bt[i]+wt[i];
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("Process ID\tWT\tTAT\tCT\n");
    for(int i=0; i<n; i++)
    {
     printf("\t%d",p[i]);
     printf("\t%d",wt[i]);
     printf("\t%d",tat[i]);
     printf("\t%d\n",ct[i]);
    }
    printf("\n\nAverage Waiting Time: %f", (double)awt/n);
    printf("\nAverage Turnaround Time: %f", (double)atat/n);
 
    return 0;
}