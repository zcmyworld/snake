#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define N 500
int head,tail;
int flag=1,dian0,dian1;
int sui()
{
 int a;
 int t=1,d=20;
 srand(time(NULL));  /*初始化随机数种子*/
 a=rand()%(d-t)+t;  /*生成一个[t,d)区间内的整数*/
 return(a);
}

main()
{ int change(char qipan[22][22],int zuobiao[2][20] ,char deriction);
 long start;
 int gamespeed=N;
 int timeover;
 char qipan[22][22];
 int zuobiao[2][20];
 int i,j,count;
 int direction=77;
 int count1;
 /*********初始化蛇的坐标*************/
 for(i=0;i<=3;i++)
 {
  zuobiao[0][i]=1;
  zuobiao[1][i]=i+1;
 }
 head=3;tail=0;
 /**********初始化棋盘**************/
 for(i=1;i<21;i++)
  for(j=1;j<21;j++)
   qipan[i][j]=' ';
 for(i=0;i<22;i++)
 {
  qipan[0][i]='-';
  qipan[21][i]='-';
 }
 for(i=1;i<21;i++)
 {
  qipan[i][0]='|';
  qipan[i][21]='|';
 }
 /**************初始化蛇在棋盘的位置**********/
 for(i=1;i<=3;i++)
  qipan[1][i]='*';
 qipan[1][4]='#';
 /*************游戏开始***************/
 while(direction!='Q')
 {
  system("cls");
  if(flag==1)
  {
   do
   {
    dian0=sui();
    dian1=sui();
    for(count1=count=tail;count<=head;count++)
    {
     if((zuobiao[0][count]==dian0)&&(zuobiao[1][count]==dian1))
      break;

    }
   }
   while((count-1)!=head);
   qipan[dian0][dian1]='@';
  }
  
  
  for(i=0;i<22;i++)
  {
   for(j=0;j<22;j++)
    printf("%c",qipan[i][j]);
   printf("\n");
  }
  /**********获取控制方向***************/
  timeover=1;
  start=clock();
  while(!kbhit()&&(timeover=clock()-start<=gamespeed));
  if(timeover)
  {
   getch();
   direction=getch();
  }
  else
   direction=direction;
  if(!(direction==72||direction==80||direction==75||direction==77))
   return 0;
  if(!change(qipan,zuobiao,direction))
   return 0;
 }
 return 0;


}
int change(char qipan[22][22],int zuobiao[2][20],char direction)
{
 int x,y;
 if(direction==72)
 { x=zuobiao[0][head]-1;
  y=zuobiao[1][head];
 }
 if(direction==80)
 { x=zuobiao[0][head]+1;
  y=zuobiao[1][head];
 }
 if(direction==75)
 { x=zuobiao[0][head];
  y=zuobiao[1][head]-1;
 }
 if(direction==77)
 { x=zuobiao[0][head];
  y=zuobiao[1][head]+1;
 }
 if(x==0||x==21||y==0||y==21)
  return 0;
 if(qipan[x][y]!=' ')
  return 0;
 /********处理蛇头*********/
 qipan[zuobiao[0][head]][zuobiao[1][head]]='*';
 head=(head+1)%20;
 zuobiao[0][head]=x;
 zuobiao[1][head]=y;
 qipan[zuobiao[0][head]][zuobiao[1][head]]='#';
 /********处理蛇尾*********/
 if(x==dian0&&y==dian1)
  flag=1;          //蛇吃到点//
 else
 { flag=0;
  qipan[zuobiao[0][tail]][zuobiao[1][tail]]=' ';
  tail=(tail+1)%20;           //蛇未吃到//
 }
 return 1;                   ///tail和head是全局变量，不用返回
}

