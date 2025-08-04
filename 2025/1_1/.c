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

    }




int check_win()
    {
    // 检查行
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            if(board[i][0] == O) return 1;  // 用户胜利
            if(board[i][0] == X) return 2;  // AI胜利
        }
    }
    
    // 检查列
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) 
        {
            if(board[0][j] == O) return 1;
            if(board[0][j] == X) return 2;
        }
    }
    
    // 检查对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == O) return 1;
        if(board[0][0] == X) return 2;
    }
    
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
    {
        if(board[0][2] == O) return 1;
        if(board[0][2] == X) return 2;
    }
    
    // 检查平局
    int empty = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // 如果还有数字位置，表示有空位
            if(board[i][j] >= '1' && board[i][j] <= '9') 
            {
                empty = 1;
            }
        }
    }
    if(!empty) return 3;  // 平局
    
    return 0;  // 继续游戏
    }




int main()
{
    int gameState = 0; // 游戏状态
    while(1)
    {
        // 打印棋盘
        printf("\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n", board[0][0], board[0][1], board[0][2],board[1][0], board[1][1], board[1][2],board[2][0], board[2][1], board[2][2]);
        printf("\nIt's turn for you.(1-9,0 to return)\n");
        scanf("%d",&a);//用户输入

        if(a > 0 && a <= 9)//判断是否合法
        {
            //玩家回合
            board[(a-1)/3][(a-1)%3] = O;
            gameState = check_win();// 检查游戏状态
            if(gameState > 0) 
            {
                break; // 跳出游戏循环
            }

            //ai回合
            ai;
            gameState = check_win();// 再次检查游戏状态
            if(gameState > 0) {
                break; // 跳出游戏循环
            }
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

    // 游戏结束
    printf("\nFinal board:\n");
    printf("\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n", board[0][0], board[0][1], board[0][2],board[1][0], board[1][1], board[1][2],board[2][0], board[2][1], board[2][2]);
    
    switch(gameState) 
    {
        case 1:
            printf("\nCongratulations! You win!\n");
            break;
        case 2:
            printf("\nAI wins!\n");
            break;
        case 3:
            printf("\nIt's a draw!\n");
            break;
    }
}
