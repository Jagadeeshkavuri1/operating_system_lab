#include<stdio.h>
int mutex=1,fill=0,empty=10;
void producer(){
        while(mutex==0);
        mutex--;
        if(empty==0){
        printf("Buffer is Full");
        mutex++;
        }
        else{
        fill++;
        empty--;
        printf("Producer Produces 1 good.Therefore Producer contains %d goods",fill);
        mutex++;    
        }
}
void consumer(){
        while(mutex==0);
        mutex--;
        if(fill==0){
        printf("Buffer is Empty");
        mutex++;
        }
        else{
        fill--;
        empty++;
        printf("Consumer consumes 1 good.Therefore Producer contains %d goods",fill);
        mutex++;    
        }
}
int main(){
        int ch;
        printf("Enter 1 for producer produces good\nEnter 2 for Consumer to consume good\nEnter 3 to Exit\n");
        do{
                printf("\nEnter your Choice ::");
                scanf("%d",&ch);
                switch (ch)
                {
                case 1:
                        producer();
                        break;
                case 2:
                        consumer();
                        break;
                default: 
                printf("%d",mutex);
                        printf("Program Terminated\n");
                        break;
                }
        }while(ch!=3);
        return 0;
}
