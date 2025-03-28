#include<stdio.h> 
int main(){ 
    int pid[15],bt[15],ct[15],wt[15],rt[15]; 
    int n,i,g,k=0,j=0,p=0,s=0;  
    float avg;
    printf("enter number of processors "); 
    scanf("%d",&n); 
    printf("enter processors_ids");  
    for(i=0;i<n;i++){ 
       scanf("%d",&pid[i]); 
    } 
    for(int i=0; i < n;i++){
        printf("Enter process %d Burst Time :: ",pid[i]);
        scanf("%d",&bt[i]); 
        k=k+bt[i];  
        rt[i]=bt[i]; 
} 
printf("enter the time quantum :"); 
scanf("%d",&g); 
ct[0]=0;
while(j<k){ 
    for(i=0;i<n;i++){ 
        if(rt[i]!=0){ 
            if(rt[i]<g){  
                ct[i]=ct[p]+rt[i];  
                j=j+rt[i];
                p=i; 
                rt[i]=0;
            } 
            else{  
                ct[i]=ct[p]+g; 
                rt[i]=rt[i]-g; 
                p=i;
                j=j+g;

            }
        }
    }
} 
for(int i=0;i<n;i++){
    wt[i]=ct[i]-bt[i];
    s=s+wt[i]; 
}

printf("|        Process Id       |       Burst Time       |       Complete Time      |       Waiting Time      |\n");
printf("|-------------------------|------------------------|--------------------------|-------------------------|\n");
for(int i=0;i<n;i++){
printf("|%25d|%24d|%26d|%25d|\n",pid[i],bt[i],ct[i],wt[i]);
} 

 avg=(float)s/n;
        printf("Average Waiting Time using First Come First Serve Technique :: %.2f",avg);
        printf("\n"); 
    return 0;
}
