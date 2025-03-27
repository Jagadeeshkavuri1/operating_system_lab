#include<stdio.h> 
int main(){ 
    int pid[20],bt[20],ct[20],wt[20],tat[20],n,s=0; 
    float avg; 
    printf("enter the processes count"); 
    scanf("%d",&n); 
    printf("enter the process ids and brust time "); 
    for (int i=0;i<n;i++){ 
        scanf("%d",&pid[i]);  
        scanf("%d",&bt[i]);
    }  
    ct[0]=0;  
    for(int i=0;i<n;i++){ 
        ct[i+1]=ct[i]+bt[i]; 
        tat[i]=ct[i+1];
        wt[i]=tat[i]-bt[i]; 
        s=s+wt[i]; 
    } 
    avg= (float)s/n; 
    printf("%f",avg); 
}
        
    
    
