#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int Match_Num_Diag(int a[10][10], int b[10][10]);
int Match_Num_anti_Diag(int a[10][10], int b[10][10]);
int Match_Num_Col(int a[10][10], int b[10][10]);
int Match_Num_Row(int a[10][10], int b[10][10]);

int main()
{
    int array[100];
    int a[10][10];
    int x;
    //int p;
    int count;
    int i=0, j=0;
    int b[10][10];
    int count_row=0, count_col=0, count_d1=0, count_d2=0;
    a[0][0]=0;
    int bingo = 0;

    srand(time(NULL));

    for(count=0;count<100;count++){
        array[count]=rand()%100+1;
    }

    while(i<100){
        int r=rand()%100+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }

 count=0;

//запълване на матрицата с рандом числа
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){
            a[i][j] = array[count];
            //printf(" * ");
            printf(" %02d", a[i][j]);
            count++;
        }
        printf("\n");
    }

    printf("\n Enter your numbers: \n");


// запълване на матрицата с числа от клавиатурата
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){
            printf("B[%d][%d]=", i,j);
            scanf("%d", &b[i][j]);
        }
        printf("\n");
    }


// проверка за съвпадащи числа
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){
           if(a[i][j]==b[i][j]){
                printf("%d ", a[i][j]);
            }else{
                printf(" * ");
            }
        }
        printf("\n");
    }


    count_d1=Match_Num_Diag(a,b);
    count_d2=Match_Num_anti_Diag(a,b);
    count_col=Match_Num_Col(a, b);
    count_row=Match_Num_Row(a, b);
    bingo = count_col + count_d1 + count_d2 + count_row;
    if(bingo==0){
        printf("\n YOU LOST\n");
    }else{
            printf("\n BINGO YOU WIN \n");
        }



    return 0;
}
int Match_Num_Diag(int a[10][10], int b[10][10]){
    int count_d1=0;
    int bingo_d1=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
           if(a[i][j]==b[i][j] && i==j){
                count_d1++;
            }
        }
    }if(count_d1==10){
        bingo_d1++;
    }
    return bingo_d1;
}

int Match_Num_anti_Diag(int a[10][10], int b[10][10]){
    int count_d2=0;
    int bingo_d2=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
           if(a[i][j]==b[i][j] && i+j==2){
                count_d2++;
            }
        }
    } if(count_d2==10){
        bingo_d2++;
    }
    return bingo_d2;
}

int Match_Num_Col(int a[10][10], int b[10][10]){
    int count_col;
    int bingo_col=0;
    for(int j=0; j<10; j++){
        for(int i=0; i<10;i++){
           if(a[i][j]==b[i][j]){
                count_col++;
            }
        } if(count_col==10){
            bingo_col++;
        }else{
            count_col=0;
        }
    }
   return bingo_col;
}

int Match_Num_Row(int a[10][10], int b[10][10]){
    int count_row;
    int bingo_row=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
           if(a[i][j]==b[i][j]){
                count_row++;
            }
        } if(count_row==10){
            bingo_row++;
        }else{
            count_row=0;
        }

    }
   return bingo_row;
}
