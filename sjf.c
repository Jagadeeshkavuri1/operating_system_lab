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
      
        } 
        else{   
          for (int i = 0; i < n - 1; i++) {
          for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }  
     ct[0]=0;
                for(int i=0;i<n;i++){
                        ct[i+1]=ct[i]+bt[i];
                        wt[i]=ct[i+1]-bt[i];
                        s=s+wt[i];
                } 
                avg=(float)s/n;
        printf("Average Waiting Time using First Come First Serve Technique :: %.2f ms",avg);

}

        } 
