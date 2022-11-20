#include<stdio.h>
void main(){
    int s[10][10],i,j,m,n,count=0,k,b[10][10];
    printf("Enter rows and columns:");
    scanf("%d%d",&m,&n);
    printf("Enter elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&s[i][j]);
            if(s[i][j]!=0){
                count++;
            }
        }
    }
    
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=count;

    k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(s[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=s[i][j];
            }
            k++;
        }
    }

    printf("Sparse Matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}
