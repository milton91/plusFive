#include <stdio.h>
#include <stdio.h>
char map[10][10];

int initialx;
int initialy;
int flag = 0;

int wall = -1;

void flood(int x, int y, int row, int col, char map[100][100], int *flag)
{
    //printf("checkRecursion");
    if (x < 0 || y < 0 || y == col){     
        return;
    }
    if(map[x][y] == '#')    
        return;    

    if (map[x][y] == 'X' && x == row-1){      
        //printf("checkFinishCondition");
        *flag = 1;
        return;
    }

    if(map[x][y] == 'X'){
        //printf("checkCondition");
        map[x][y] = '#';
    }
   
   flood(x + 1, y, row, col, map, flag);
   flood(x - 1, y, row, col, map, flag);
   flood(x, y + 1, row, col, map, flag); 
   flood(x, y - 1, row, col, map, flag);
   

   return;

}

int main()
{
    int start_x, start_y, flag=0, row, col;
    char map[100][100];

    system("cls");
    printf("Asumsi path mulai dari atas dan berakhir di bawah\n#:tembok X:path\n\n");
    printf("Row: "); scanf("%d", &row);getchar();
    printf("Column: "); scanf("%d", &col);getchar();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    for(int j=0; j<col; j++){
        if(map[0][j] == 'X'){
            start_x = 0;
            start_y = j;
            flood(start_x, start_y, row, col, map, &flag);}
    }
        
    if(flag == 0){
        printf("Path Not found\n");
    }
    else if(flag == 1){
        printf("Path Found!\n");
    }

    return 0;
}