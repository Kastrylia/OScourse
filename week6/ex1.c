#include <stdio.h>

int main(void) 
{
  printf("Enter the number of processors:");
  int n;
  scanf("%d",&n);
  int p[20];
  int at[20];
  int bt[20];
  int wt[n];
  int st[n];
  int tat[n];
  st[0] = 0;
  wt[0] = 0;
  
  for (int i = 0; i < n; i++)
  {
    p[i] = i+1;
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
  }
    
    for (int i = 1; i < n ; i++) 
    {
        st[i] = st[i-1] + bt[i-1];
        wt[i] = st[i] - at[i];
    
    if (wt[i] < 0) 
    {
        wt[i] = 0;
    }
    }
  
  for (int i = 0; i < n ; i++)
  {
    tat[i] = bt[i] + wt[i];
  }
  
  
  printf("Process ID\tWT\tTAT\tCT\n");
  int tWT = 0;
  int tTAT = 0;
  for (int i = 0 ; i < n ; i++)
  {
    tWT = tWT + wt[i];
    tTAT = tTAT + tat[i];
    int ct = tat[i] + at[i];
    printf("\t%d",p[i]);
    printf("\t%d",wt[i]);
    printf("\t%d",tat[i]);
    printf("\t%d\n",ct);
  }
  
  printf("Average waiting time %lf\n",(double)tWT/(double)n);
  printf("Average turnaround time: %lf",(double)tTAT/(double)n);
  return 0;
}