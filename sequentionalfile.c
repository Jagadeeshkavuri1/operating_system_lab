#include <stdio.h>  
#include <string.h>

struct fileTable { 
    char name[20]; 
    int sb, nob; 
} ft[30]; 

void main() { 
    int i, n; 
    char s[20]; 
    
    printf("Enter no of files: "); 
    scanf("%d", &n); 
    
    for(i = 0; i < n; i++) { 
        printf("\nEnter file name %d: ", i + 1); 
        scanf("%s", ft[i].name); 
        
        printf("Enter starting block of file %d: ", i + 1); 
        scanf("%d", &ft[i].sb); 
        
        printf("Enter no of blocks in file %d: ", i + 1); 
        scanf("%d", &ft[i].nob); 
    } 
    
    printf("\nEnter the file name to be searched: "); 
    scanf("%s", s); 
    
    for(i = 0; i < n; i++) {
        if(strcmp(s, ft[i].name) == 0) 
            break; 
    }
    
    if(i == n) 
        printf("\nFile Not Found\n"); 
    else { 
        printf("\nFile Name: %s\n", ft[i].name); 
        printf("Starting Block: %d\n", ft[i].sb); 
        printf("Number of Blocks: %d\n", ft[i].nob); 
        printf("Blocks Occupied: ");
        for(int j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].sb + j);
        }
        printf("\n");
    }
}
