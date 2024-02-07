

#include <stdio.h>
#include <stdlib.h>

void print_matrix(int source[][5],int size){
   
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<5;j++){
            printf("%d ",source[i][j]);
        }
        printf("\n");
    }
}

void print_array(int destination[],int size){
  
    int i;
    for(i=0; i<size;i++) printf("%d ",destination[i]);
    printf("\n");
}


int find_path(int source[][5],int destination[],int size){
    
    int i,j,count=0,sum=0;
    destination[count]=source[0][0];
    count++;
    
    for(i=0,j=0;i<14||j<5;i++,j++){
       
        if(j==4&&i!=13){
            destination[count]=source[i+1][j]; j--; count++;
            
        }else if(i==13&&j!=4){
            destination[count]=source[i][j+1]; i--; count++;
            
        }else if(j==4&&i==13) break;
        
        else if(j!=4&&i!=13){
            if(source[i][j+1]>source[i+1][j]){
                destination[count]=source[i][j+1];
                count++;
                i--;
                
            }else if(source[i][j+1]<source[i+1][j]){
                destination[count]=source[i+1][j];
                count++;
                j--;
            }
        }
    }
    for(i=0;i<count;i++){
        sum+=destination[i];
    }
    return sum;
}

int main() {
    
    int sum,i,j;
    int source[14][5]={0};
    int destination[18]={0};

    for (i=0;i<14;i++){
        for (j=0;j<5;j++){
            source[i][j]=rand()%100;
        }
    }
    
    print_matrix (source, 14);
    sum = find_path(source, destination, 14);
    printf("\n\n");
    print_array (destination,18);
    printf("Sum of the numbers in the path is %d\n",sum);
 
    return 0;
}
