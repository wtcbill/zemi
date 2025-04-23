#include <stdio.h>
#include <string.h>

int a;
char O = 'O'; 
char X = 'X'; 
char board[3][3] = 
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void ai()//简单ai
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j])
            {
                /* code */
            }
            
        }
        
    }

int main()
{
    
    while(1)
    {
        // 打印棋盘
        printf("\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n", board[0][0], board[0][1], board[0][2],board[1][0], board[1][1], board[1][2],board[2][0], board[2][1], board[2][2]);
        printf("\nIt's turn for you.(1-9,0 to return)\n");
        scanf("%d",&a);

        if(a > 0 && a <= 9)//判断是否合法
        {
            board[(a-1)/3][(a-1)%3] = O;
            ai;
            printf("\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n", board[0][0], board[0][1], board[0][2],board[1][0], board[1][1], board[1][2],board[2][0], board[2][1], board[2][2]);
               
        }
        else if(a == 0)//退出
            {
                return 0;
            }
        else 
        {
            printf("\nIt's wrong.\n");//重新输入
            while(getchar() != '\n');
        }
    }
}
