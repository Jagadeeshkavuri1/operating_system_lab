#include<stdio.h>
int main(){
        int pid[15],bt[15],n,c,at[15],ct[15],tat[15],wt[15],s=0;
        float avg;
        printf("Enter Number of Process :: ");
        scanf("%d",&n);
        printf("Enter %d Process Ids :: \n",n);
        for (int i = 0; i < n; i++)
        {
        scanf("%d",&pid[i]);
        }
        for(int i=0; i < n;i++){
                printf("Enter process %d Burst Time :: ",pid[i]);
                scanf("%d",&bt[i]);
        }
        printf("If there is Arrival Times press 1 otherwise 0 :: ");
        scanf("%d",&c);
        if(c==1){
                for(int i=0;i<n;i++){
                        printf("Enter process %d Arrival Time :: ",pid[i]);
                        scanf("%d",&at[i]);
                }
        printf("|        Process Id       |       Burst Time       |       Arrival Time      |\n");
        printf("|----------------------------------------------------------------------------|\n");
        for(int i=0;i<n;i++){
                printf("|%25d|%24d|%25d|\n",pid[i],bt[i],at[i]);
        }
        }
        else{
         ct[0]=0;
                for(int i=0;i<n;i++){
                        ct[i+1]=ct[i]+bt[i];
                        wt[i]=ct[i+1]-bt[i];
                        s=s+wt[i];
                }
        printf("|        Process Id       |       Burst Time       |       Complete Time      |       Waiting Time      |\n");
        printf("|-------------------------|------------------------|--------------------------|-------------------------|\n");
        for(int i=0;i<n;i++){
                printf("|%25d|%24d|%26d|%25d|\n",pid[i],bt[i],ct[i+1],wt[i]);
        }
        avg=(float)s/n;
        printf("Average Waiting Time using First Come First Serve Technique :: %.2f",avg);
        }
        printf("\n"); 
        return 0;
}