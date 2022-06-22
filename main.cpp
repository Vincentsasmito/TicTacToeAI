#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int debug = 0;

class Board {
  public:
    int index[3][3];

  Board() {   //con
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            index[i][x] = -1;
        }
    }
  }
};


class Computer{
    public:
    int x, y;

 int priority1n2(class Board board1, int target)
 {
  int kosong  = 0;
  int counter = 0;
  int col     = 0;
  int row     = 0;
  //Check horizontal win
  for(int i = 0; i < 3; i++)
  {
   counter = 0;
   kosong = 0;
   col = 0;
   row = 0;
   for(int j = 0; j < 3; j++)
   {
      if(board1.index[i][j] == target)
      {
       counter++;
      }
      else if(board1.index[i][j] == -1)
      {
       kosong++;
       row = i;
       col = j;
      }
   }
   if(counter == 2 && kosong == 1)
   {
    board1.index[row][col] = 0;
    y = row;
    x = col;
    return 1;
   }
  }
  //Check vertical win
  for(int j = 0; j < 3; j++)
  {
   counter = 0;
   kosong = 0;
   col = 0;
   row = 0;
   for(int i = 0; i < 3; i++)
   {
      if(board1.index[i][j] == target)
      {
       counter++;
      }
      else if(board1.index[i][j] == -1)
      {
       kosong++;
       row = i;
       col = j;
      }
      if(counter == 2 && kosong == 1)
       {
        y = row;
        x = col;
        return 1;
       }
   }
  }

  //Check diagonal kiri atas ke kanan bawah
  counter = 0;
  kosong = 0;
  col = 0;
  row = 0;
  int j = 0;
  for(int i = 0; i < 3 && j < 3; i++, j++)
  {
   if(board1.index[i][j] == target)
   {
    counter++;
   }
   else if(board1.index[i][j] == -1)
   {
    kosong++;
    row = i;
    col = j;
   }
  }
  if(counter == 2 && kosong == 1)
  {
    y = row;
    x = col;
    return 1;
  }

  //Check diagonal kiri bawah ke kanan atas
  j = 0;
  kosong = 0;
  col = 0;
  row = 0;
  counter = 0;
  for(int i = 2; i >= 0 && j < 3; i--, j++)
  {
   if(board1.index[i][j] == target)
   {
    counter++;
   }
   else if(board1.index[i][j] == -1)
   {
    kosong++;
    row = i;
    col = j;
   }
  }
  if(counter == 2 && kosong == 1)
  {
    y = row;
    x = col;
   return 1;
  }
    //prevent guarenteed loss
    if(debug == 2 && board1.index[1][1] == -1)
    {
        if(board1.index[0][0] == target || board1.index[0][2] == target || board1.index[2][0] == target || board1.index[2][2] == target)
        {
            x = 1;
            y = 1;
            return 1;
        }
    }
    else if((debug == 4) && ((board1.index[0][0] == target && board1.index[2][2] == target) || (board1.index[0][2] == target && board1.index[2][0] == target)))
    {
        if(board1.index[0][1] == -1)
        {
            x = 1;
            y = 0;
            return 1;
        }
        else if(board1.index[1][2] == -1)
        {
            x = 2;
            y = 1;
            return 1;
        }
        else if(board1.index[2][1] == -1)
        {
            x = 1;
            y = 2;
            return 1;
        }
        else if(board1.index[1][0] == -1)
        {
            x = 0;
            y = 1;
            return 1;
        }
    }
  return 0;
 }

 int priority3n4(class Board board1, int target)
 {
    if(board1.index[1][0] == target && board1.index[0][1] == target && board1.index[0][0] == -1)
    {
        y = 0;
        x = 0;
        return 1;
    }
    else if(board1.index[0][1] == target && board1.index[1][2] == target && board1.index[0][2] == -1)
    {
        y = 0;
        x = 2;
        return 1;
    }
    else if(board1.index[1][2] == target && board1.index[2][1] == target && board1.index[2][2] == -1)
    {
        y = 2;
        x = 2;
        return 1;
    }
    else if(board1.index[2][1] == target && board1.index[1][0] == target && board1.index[2][0] == -1)
    {
        y = 2;
        x = 0;
        return 1;
    }
    else if(board1.index[0][0] == target && board1.index[2][2] == target && board1.index[2][0] == -1)
    {
        x = 0;
        y = 2;
        return 1;
    }
    else if(board1.index[0][0] == target && board1.index[2][2] == target && board1.index[0][2] == -1)
    {
        x = 2;
        y = 0;
        return 1;
    }
    else if(board1.index[0][2] == target && board1.index[2][0] == target && board1.index[0][0] == -1)
    {
        x = 0;
        y = 0;
        return 1;
    }
    else if(board1.index[0][0] == target && board1.index[2][2] == target && board1.index[2][2] == -1)
    {
        x = 2;
        y = 2;
        return 1;
    }
    else if(board1.index[0][0] == 1 && board1.index[2][2] == -1)
    {
        x = 2;
        y = 2;
        return 1;
    }
    else if(board1.index[0][2] == 1 && board1.index[2][0] == -1)
    {
        x = 0;
        y = 2;
        return 1;
    }
    else if(board1.index[2][2] == 1 && board1.index[0][0] == -1)
    {
        x = 0;
        y = 0;
        return 1;
    }
    else if(board1.index[2][0] == 1 && board1.index[0][2] == -1)
    {
        x = 2;
        y = 0;
        return 1;
    }
    return 0;
 }

 int priority5(class Board board1)
 {
  //salib
  if(board1.index[1][0] == 0)
  {
   if(board1.index[0][1] == -1)
   {
    y = 0;
    x = 1;
    return 1;
   }
   else if(board1.index[2][1]){
    y = 2;
    x = 1;
    return 1;
   }
  }
  else if(board1.index[0][1] == 0)
  {
   if(board1.index[1][0] == -1)
   {
    y = 1;
    x = 0;
    return 1;
   }
   else if(board1.index[1][2] == -1)
   {
    y = 1;
    x = 2;
    return 1;
   }
  }
  else if(board1.index[1][2] == 0)
  {
   if(board1.index[0][1] == -1)
   {
    y = 0;
    x = 1;
    return 1;
   }
   else if(board1.index[2][1] == -1)
   {
    y = 2;
    x = 1;
    return 1;
   }
  }
  else if(board1.index[2][1] == 0)
  {
   if(board1.index[1][2] == -1)
   {
    y = 1;
    x = 2;
    return 1;
   }
   else if(board1.index[1][0] == -1)
   {
    y = 1;
    x = 0;
    return 1;
   }
  }
  //x
  else if(board1.index[1][0] == 0)
  {
   if(board1.index[0][0] == -1)
   {
    y = 0;
    x = 0;
    return 1;
   }
   else if(board1.index[2][0] == -1)
   {
    y = 2;
    x = 0;
    return 1;
   }
  }
  else if(board1.index[0][1] == 0)
  {
   if(board1.index[0][0] == -1)
   {
    y = 0;
    x = 0;
    return 1;
   }
   else if(board1.index[0][2] == -1)
   {
    y = 0;
    x = 2;
    return 1;
   }
  }
  else if(board1.index[1][2] == 0)
  {
   if(board1.index[0][2] == -1)
   {
    y  = 0;
    x = 2;
    return 1;
   }
   else if(board1.index[2][2] == -1)
   {
    y = 2;
    x = 2;
    return 1;
   }
  }
  else if(board1.index[2][1] == 0)
  {
   if(board1.index[2][2] == -1)
   {
    y = 2;
    x = 2;
    return 1;
   }
   else if(board1.index[2][0] == -1)
   {
    y = 2;
    x = 0;
    return 1;
   }
  }

  //x tanpa teman
  if(board1.index[0][0] == -1)
  {
      x = 0;
      y = 0;
      return 1;
  }
  else if(board1.index[0][2] == -1)
  {
      x = 2;
      y = 0;
      return 1;
  }
  else if(board1.index[2][2] == -1)
  {
      x = 2;
      y = 2;
      return 1;
  }
  else if(board1.index[2][0] == -1)
  {
      x = 0; y = 2;
      return 1;
  }
  //salib tanpa teman
  if(board1.index[0][1] == -1)
  {
      x = 1;
      y = 0;
      return 1;
  }
  else if(board1.index[1][2] == -1)
  {
      x = 2;
      y = 1;
      return 1;
  }
  else if(board1.index[2][1] == -1)
  {
      x = 1;
      y = 2;
      return 1;
  }
  else if(board1.index[1][0] == -1)
  {
      x = 0;
      y = 1;
      return 1;
  }

  return 0;
 }


};

int checkWin(class Board board1, int target)
{
    //Check horizontal win
    for(int i = 0; i < 3; i++)
    {
        int counter = 0;
        for(int x = 0; x < 3; x++)
        {
           if(board1.index[i][x] == target)
           {
               counter++;
           }
        }
        if(counter == 3)
        {
            return 1;
        }
    }

    //Check vertical win
    for(int x = 0; x < 3; x++)
    {
        int counter = 0;
        for(int i = 0; i < 3; i++)
        {
            if(board1.index[i][x] == target)
            {
                counter++;
            }
        }
        if(counter == 3)
        {
            return 1;
        }
    }
    //Check diagonal kiri atas ke kanan bawah
    int x = 0;
    int counter = 0;
    for(int i = 0; i < 3 && x < 3; i++, x++)
    {
        if(board1.index[i][x] == target)
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return 1;
    }

    //Check diagonal kiri bawah ke kanan atas
    x = 0;
    counter = 0;
    for(int i = 2; i >= 0 && x < 3; i--, x++)
    {
        if(board1.index[i][x] == target)
        {
            counter++;
        }
    }
    if(counter == 3)
    {
        return 1;
    }

    //win not found return 0
    return 0;
}

void printBoard(class Board board1)
{
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            if(board1.index[i][x] != -1)
            {
                if(x == 2)
                {
                    printf(" %d\n", board1.index[i][x]);
                }
                else
                {
                    printf(" %d |", board1.index[i][x]);
                }

            }
            else{
                if(x == 2)
                {
                    printf(" - \n");
                }
                else{
                    printf(" - |");
                }
            }
        }
    }
}

void play(class Board board1)
{
    int turn = rand() % 2;
    bool win = false;
    Computer comp;
    while(!win)
    {
        if(turn == 0)//Computer
        {
            printf("Computer's turn.(0)\n");

            debug++;
            if(debug == 6)
            {
                printf("\n.\n");
            }
            //Check if first move, fill center
                int flag = comp.priority1n2(board1, 0);
                if(flag == 1)
                {
                    board1.index[comp.y][comp.x] = 0;
                }
                else{
                    flag = comp.priority1n2(board1, 1);
                    if(flag == 1)
                    {
                        board1.index[comp.y][comp.x] = 0;
                    }
                    else{
                        flag = comp.priority3n4(board1, 0);
                        if(flag == 1)
                        {
                            board1.index[comp.y][comp.x] = 0;
                        }
                        else{
                            flag = comp.priority3n4(board1, 1);
                            if(flag == 1)
                            {
                                board1.index[comp.y][comp.x] = 0;
                            }
                            else{
                                flag = comp.priority5(board1);
                                if(flag == 1)
                                {
                                    board1.index[comp.y][comp.x] = 0;
                                }
                                else{
                                    printf("\n?????\n");
                                }
                            }
                        }
                    }
                }
            win = checkWin(board1, 0);
            printBoard(board1);
            if(win == true)
            {
                printf("Computer Won.\n");
            }
            turn = 1;
            if(debug == 9)
            {
                printf("Draw!\n");
                turn = 999;
                break;
            }


        }
        else if(turn == 1)//Player
        {
            debug++;
            printf("Player's turn(1).\n");
            int x = -1;
            int y = -1;
            do
            {
                printf("Enter square coordinates([Row 0 - 2][Column 0 - 2]): ");
                scanf("%d %d", &x, &y);
            }while(x < 0 || x > 2 || y < 0 || y > 2 || board1.index[x][y] != -1);
            board1.index[x][y] = 1;
            int found = checkWin(board1, 1);
            printBoard(board1);
            if(found == 1)
            {
                printf("Player won.\n");
                win = true;
            }
            turn = 0;
            if(debug == 9)
            {
                printf("Draw!\n");
                turn = 999;
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    Board board1;
    play(board1);
}
