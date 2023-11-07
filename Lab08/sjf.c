#include <stdio.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a  = *b;
   * b = temp;
}

int main(){
    int bt[20],pos[20],t,n,i,j,tat,totalTime;
    float avgTAT=0, avgWT=0;

    printf("Enter the no fo Process :");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter the Burst Time P[%d] : ", i);
        scanf("%d",&bt[i]);
        pos[i] = i+1;
    }
    
    // Sort burst times 
    for(i=0; i<n; i++){
        int p = i;
        for(j=i+1; j<n; j++){
            if(bt[j] < bt[p])
                p = j;
        }
        swap(&bt[i],&bt[p]);
        swap(&pos[i],&pos[p]);
    }
    

    
    tat = 0;
    printf("\nProcess  Burst Time  Waiting Time  Turnaround Time");
    for(i=0; i<n; i++){
        tat = tat + bt[i];
        avgTAT += tat;
        avgWT +=tat-bt[i];
        printf("\nP[%d]        %d            %d             %d", pos[i], bt[i], tat-bt[i], tat);
    }
    
    avgWT = avgWT/n;
    avgTAT = avgTAT/n;

    printf("\n\nAverage Waiting Time: %f", avgWT);
    printf("\nAverage Turnaround Time: %f\n", avgTAT);
    
    return 0;
}