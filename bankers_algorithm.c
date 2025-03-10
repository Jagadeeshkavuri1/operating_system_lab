#include<stdio.h> 
int main(){ 
int all[10][5],pros[15],need[10][5],avil[15][5],n,m,max[10][10]; 
printf("enter the number of processes ");  
scanf("%d",&n);  
printf("enter the number of resources "); 
scanf("%d",&m);
for(int i =0;i<n;i++){ 
    printf("enter the %dst  process id",i+1) ;
    scanf("%d",&pros[i]);  
} 
for(int i =0;i<m;i++){  
    printf("enter resource available %d resource ",i);
    scanf("%d",avil[0][i]);
}
for(int i=0;i<n;i++){  

    printf("enter the %d process  allocated resouces",pros[i]); 
    for(int j=0;j<m;j++){  
        printf("enter the %d allocated resource",j);
        scanf("%d",&all[i][j]);
    }  
    for(int j=0;j<m;j++){ 
        printf("enter the %dst resouce max need",j); 
        scanf("%d",&max[i][j]);
    }

}

    return 0;
}