#include<stdio.h> 
int main(){ 
    int pid[20],bt[20],ct[20],wt[20],tat[20],pt[20],n,s=0,temp; 
    float avg; 
    printf("enter the processes count"); 
    scanf("%d",&n); 
    printf("enter the process ids and brust time "); 
    for (int i=0;i<n;i++){ 
        scanf("%d",&pid[i]);  
        scanf("%d",&bt[i]);
    }   
    for(int i=0;i<n;i++){ 
    
        scanf("%d",&pt[i]);
    }
    for(int i=0;i<n-1;i++){ 
         for(int j=i+1;j<n;j++){  
             if(pt[i]>pt[j]){  
                   temp=pt[i]; 
             pt[i]=pt[j]; 
             pt[j]=temp;
             temp=bt[i]; 
             bt[i]=bt[j]; 
             bt[j]=temp; 
             temp = pid[i]; 
             pid[i]=pid[j]; 
             pid[j]=temp;
             }
         }
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
        
    
    
