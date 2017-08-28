#include <stdio.h>
#define EMPTY 0 
#define CROSS 1 
#define ROUND 2 


int validate(int (*board)[3]) 
{ 

  // this function validates board 
  int ret=0; 
  int sum=0; 
  int i, j;

  for(i=0;i<3;i++) 
  { 
    sum=0; 
    for(j=0;j<3;j++) 
    { 
      if(board[i][j]==CROSS) 
        sum++; 
      else if(board[i][j]==ROUND) 
        sum--; 
    } 
    if(sum==3) 
      return CROSS;
    else if(sum==-3) 
      return ROUND; 
  } 

  for(i=0;i<3;i++) 
  { 
    sum=0; 
    for(j=0;j<3;j++) 
    { 
      if(board[j][i]==CROSS) 
        sum++; 
      else if(board[j][i]==ROUND) 
        sum--; 
    } 
    if(sum==3) 
      return CROSS; 
    else if(sum==-3) 
      return ROUND; 
  } 

  sum=0; 
  for(i=0;i<3;i++) 
  { 
    if(board[i][i]==CROSS) 
      sum++; 
    else if(board[i][i]==ROUND) 
      sum--; 
  } 

  if(sum==3) 
    return CROSS;
  else if(sum==-3) 
    return ROUND; 

  // nothing or its a tie 
  return 0; 
}

int main () 
{ 

  int board[3][3]; 
  int i,j,type,result; 

  // board initialized 
  for(i=0;i<3;i++) 
  { 
    for(j=0;j<3;j++) 
      board[i][j]=EMPTY; 
  } 


  // now playing 

  int count=0; 

  while(count<8) 
  { 
    // enter your move (turn by turn) 
    scanf("%d%d%d",&i,&j,&type); 

    board[i][j]=type; 

    result = validate(board); 
    count++; 

    if(result==1 || result==2) 
      break;

  } 

} 
