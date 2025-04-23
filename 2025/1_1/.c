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
        //如果横竖斜有两个相同的X，把这一条线所有都变成X
        if ((board[0][0] == board[1][1] || board[0][0] == board[2][2] || board[1][1] == board[2][2]) && (board[0][0] == 'X' || board[1][1] == 'X' || board[2][2] == 'X') && board[0][0] != 'O' && board[1][1] != 'O' && board[2][2] != 'O')
        {
            board[0][0] = 'X';
            board[1][1] = 'X';
            board[2][2] = 'X';
        }
        if ((board[0][2] == board[1][1] || board[0][2] == board[2][0] || board[1][1] == board[2][0]) && (board[0][2] == 'X' || board[1][1] == 'X' || board[2][0] == 'X') && board[0][2] != 'O' && board[1][1] != 'O' && board[2][0] != 'O')
        {
            board[0][2] = 'X';
            board[1][1] = 'X';
            board[2][0] = 'X';
        }
        
        for (int i = 0; i < 3; i++)
        {
            if ((board[i][0] == board[i][1] || board[i][0] == board[i][2] || board[i][1] == board[i][2]) && (board[i][0] == 'X' || board[i][1] == 'X' || board[i][2] == 'X') && board[i][0] != 'O' && board[i][1] != 'O' && board[i][2] != 'O')
            {
                board[i][0] = 'X';
                board[i][1] = 'X';
                board[i][2] = 'X';
            }
            if ((board[0][i] == board[1][i] || board[0][i] == board[2][i] || board[1][i] == board[2][i]) && (board[0][i] == 'X' || board[1][i] == 'X' || board[2][i] == 'X') && board[0][i] != 'O' && board[1][i] != 'O' && board[2][i] != 'O')
            {
                board[0][i] = 'X';
                board[1][i] = 'X';
                board[2][i] = 'X';
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
