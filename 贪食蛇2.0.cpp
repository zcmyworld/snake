 #include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>
#define begin 3
struct Snake
{
	int x[3000];//Snake����󳤶�Ϊ3000
	int y[3000];
	int length;
	int direction;
	int food;
	int life;
}s;

int main()
{
	initgraph(700,400);
	void gameover(int length);/*��Ϸ����*/
	void boring(int m,int n);/*ʹ�ð�ť��˸*/
	void boring2();/*��ʾ̰ʳ��*/
	void windows();/*��ʾ��ʼ����*/
	void color(int m,int n);/*ʹ�ô��ڱ�ɻ�ɫ*/
	int windowsbutton1(int speed);/*��ҳ��Ϸ�ȼ���ť���ܵĺ��������صȼ�ֵ*/
	void windowsbutton3();/*��ҳ��Ϸ˵����ť�Ĺ��ܣ�����˵�����޷���ֵ*/
	int i;
	int x,y,m,n,o,p;/*�⼸����������ʳ����������*/
	int score;/*����*/
	char c;
	char str[1024];
	MOUSEMSG mouse,m1;
	
	int stop=1;//��ͣ
	int speed=50;//�ٶ�
	int color2=1;//��ͣ��ִ�а�ť�����ƣ�1Ϊִ��
	srand(time(NULL));
	s.x[0]=0,s.y[0]=0;
	s.length=begin;
	s.direction=1;
	s.food=1;
	s.life=1;
	score=0;
	boring2();
	while(1)/*���˵���ѭ��*/
	{
		mouse=GetMouseMsg();
		windows();
		if(mouse.uMsg==WM_LBUTTONDOWN&&mouse.x>=50&&mouse.x<=210&&mouse.y>=300&&mouse.y<=350)
		{	
			cleardevice();
			speed=windowsbutton1(speed);	
			cleardevice();
			windows();
		}
		if(mouse.uMsg==WM_LBUTTONDOWN&&mouse.x>=490&&mouse.x<=650&&mouse.y>=300&&mouse.y<=350)
		{
			windowsbutton3();
		}
		if(mouse.uMsg==WM_LBUTTONDOWN&&mouse.x>=270&&mouse.x<=430&&mouse.y>=300&&mouse.y<=350)
		{	
			boring(270,300);
			cleardevice();			
			/*-----����Ϸ-----*/
			while(1)/*������Ϸ��ѭ��*/
			{	
				//if(stop==1)
				while(!kbhit())
				{	
					line(602,0,602,400);
					/*-----ʳ��-----*/
					while(s.food==1)
					{
						setcolor(YELLOW);
						x=rand()%601;
						y=rand()%401;
						m=x%5;
						n=y%5;
						o=x%10;
						p=y%10;
						if(m==0&&n==0&&o!=0&&p!=0)
						{	
							circle(x,y,4);
							s.food=2;
						}
					}	
					setcolor(GREEN);
					/*-----ʳ��-----*/
					
					if(stop==1)
					/*β�ƶ�*/
					for(i=s.length;i>0;i--)
					{
						s.x[i]=s.x[i-1];
						s.y[i]=s.y[i-1];
						setcolor(BLACK);
						rectangle(s.x[i],s.y[i],s.x[i]+10,s.y[i]+10);
					}
					
					/*Snake����ƶ�*/
					for(i=0;i<s.length;i++)
					{	
						setcolor(GREEN);
						rectangle(s.x[i],s.y[i],s.x[i]+10,s.y[i]+10);
					}
					
					
					/*����Ŀ���*/
					if(stop==1)
					switch(s.direction)
					{
						case 1:s.x[0]=s.x[0]+10;break;
						case 2:s.y[0]=s.y[0]+10;break;
						case 3:s.x[0]=s.x[0]-10;break;
						case 4:s.y[0]=s.y[0]-10;break;
					}
					if(c=='d'&&s.direction!=3)/*ʹSnake����������*///right
						s.direction=1;
					if(c=='s'&&s.direction!=4)//down
						s.direction=2;
					if(c=='a'&&s.direction!=1)//left
						s.direction=3;
					if(c=='w'&&s.direction!=2)//up
						s.direction=4;
					
					
					/*�ٶ�*/
					Sleep(speed);
					/*ˢ��Snake�����һ��*/
					//setcolor(BLACK);
					//rectangle(s.x[i],s.y[i],s.x[i]+10,s.y[i]+10);
					/*�Ե�ʳ��*/
					
					if(x-5==s.x[0]&&y-5==s.y[0])
					{
						setcolor(BLACK);
						circle(x,y,4);
						s.food=1;
						s.length++;
					}
					if(s.x[0]==600)
					{	gameover(s.length);
						break;
					}
					if(s.x[0]==-10)
					{	gameover(s.length);
						break;
					}
					if(s.y[0]==-10)
					{	gameover(s.length);
						break;
					}
					if(s.y[0]==400)
					{	gameover(s.length);
						break;
					}
					for(i=3;i<s.length;i++)
					{
						if(s.x[i]==s.x[0]&&s.y[i]==s.y[0])
						{
							s.life=2; 
							break;
						}
					}
					if(s.life==2)
					{
						gameover(s.length);
						break;
					}
					/*�����ұ߿�*/
					score=(s.length-3)*10;
					sprintf(str,"%d",score);
					setcolor(YELLOW);
					outtextxy(605,20,"������");
					outtextxy(605,40,str);
					rectangle(605,60,690,90);
					outtextxy(630,70,"����");
					rectangle(605,100,690,130);
					outtextxy(630,110,"��ͣ");
					if(color2==1)
					{
						setcolor(RED);
						rectangle(605,60,690,90);
						outtextxy(630,70,"����");
						setcolor(YELLOW);
					}
					if(color2==2)
					{	
						setcolor(RED);
						rectangle(605,100,690,130);
						outtextxy(630,110,"��ͣ");
						setcolor(YELLOW);
					}
					rectangle(605,340,690,370);
					outtextxy(608,349,"�������˵�");
					
				}	
				c=getch();
				if(c=='h')
				{
					cleardevice();
					s.x[0]=30,s.y[0]=0;
					s.length=begin;
					s.direction=1;
					s.food=1;
					s.life=1;
					score=0;
				}
				if(c=='e')/*����*/
				{
					stop=1;
					color2=1;
				}
				if(c=='q')/*��ͣ*/
				{
					stop=2;
					color2=2;
				}
				if(c=='r')
				{
					cleardevice();
					s.x[0]=30,s.y[0]=0;
					s.length=begin;
					s.direction=1;
					s.food=1;
					s.life=1;
					score=0;
					break;	
				}
			}
		}
	}
	getch();
	return 0;
}
int windowsbutton1(int speed)
{	void color(int m,int n);
	while(1)
	{	
		MOUSEMSG mouse1;
		mouse1=GetMouseMsg();
		setcolor(YELLOW);
		outtextxy(320,20,"��Ϸ�ȼ�");
		setcolor(GREEN);
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>=100&&mouse1.x<=200&&mouse1.y>=50&&mouse1.y<=100)
			speed=150;
		rectangle(100,50,200,100);
		outtextxy(145,70,"1");
		if(speed==150)
			color(100,50);			
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>=500&&mouse1.x<=600&&mouse1.y>=50&&mouse1.y<=100)
			speed=100;
		rectangle(500,50,600,100);
		outtextxy(545,70,"2");
		if(speed==100)
			color(500,50);
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>=100&&mouse1.x<=200&&mouse1.y>=120&&mouse1.y<=170)
			speed=50;
		rectangle(100,120,200,170);
		outtextxy(145,140,"3");
		if(speed==50)
			color(100,120);
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>500&&mouse1.x<=600&&mouse1.y>=120&&mouse1.y<=170)
			speed=40;
		rectangle(500,120,600,170);
		outtextxy(545,140,"4");
		if(speed==40)
			color(500,120);
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>100&&mouse1.x<=200&&mouse1.y>=190&&mouse1.y<=240)
			speed=30;
		rectangle(100,190,200,240);
		outtextxy(145,210,"5");
		if(speed==30)
			color(100,190);
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>500&&mouse1.x<=600&&mouse1.y>=190&&mouse1.y<=240)
			speed=10;
		rectangle(500,190,600,240);
		outtextxy(545,210,"6");
		if(speed==10)
			color(500,190);
		rectangle(500,260,600,310);
		outtextxy(520,275,"ȷ�Ϸ���");
		if(mouse1.uMsg==WM_LBUTTONDOWN&&mouse1.x>500&&mouse1.x<=600&&mouse1.y>=260&&mouse1.y<=310)
			break;
	}
	return speed;
}
void windowsbutton3()
{	void windows();
	MOUSEMSG m;
	cleardevice();
	outtextxy(20,20,"��ã���ӭ����̰ʳ����Ϸ");
	outtextxy(20,40,"����Ϊ��Ϸʹ��˵��");
	outtextxy(20,60,"1.������½ǵķ��ؿ��Է��ص����˵�");
	outtextxy(20,80,"2.���˵��еġ���Ϸ�ȼ�������ѡ����Ϸ�Ѷȣ�1~6�Ѷȵ��������ѡ�񼴿�");
	outtextxy(20,100,"3.�ڵ����ʼ��Ϸ֮ǰ���뱣֤������뷨ΪӢ������");
	outtextxy(20,120,"4.��Ϸʱʹ��w���Ʒ����ϣ�s���Ʒ����£�a���Ʒ�����d���Ʒ�����");
	outtextxy(20,140,"5.������Ϸ�󣬰�q������ͣ��Ϸ����e���Լ�����Ϸ����h�������¿�ʼ��Ϸ����r���Է������˵�");
	outtextxy(20,160,"6.��Ϸʱ�ұ�Ϊ����̨������ɽ�����ز���");
	outtextxy(20,180,"ף��Ϸ���~");
	outtextxy(530,315,"�������˵�");
	rectangle(490,300,650,350);
	rectangle(490,240,650,290);
	outtextxy(530,255,"��ϵ����");
	
	while(1)
	{	
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN&&m.x>=490&&m.x<=650&&m.y>=300&&m.y<=350)
			break;
		if(m.uMsg==WM_LBUTTONDOWN&&m.x>=490&&m.x<=650&&m.y>=240&&m.y<=290)
		{
			cleardevice();
			outtextxy(20,20,"���!");
			outtextxy(20,40,"����Ϸ���кܶ�BUG,ϣ����һ����BUG�����¼�¼");
			outtextxy(20,60,"1.��������Ϸ֮���޷�ʹ��m.uMsg���������Ϣ");
			outtextxy(20,80,"2.��ͣ��Ϸʱ����β�����һ��������Ϸ֮����ʧ");
			outtextxy(20,100,"3.����ʾgameover֮����Ȼ���Խ���wasd�ķ������");
			outtextxy(20,120,"4.��������������˽Ȿ���������һ���о���̣���ӭ��ϵ");
			outtextxy(20,140,"QQ634872896");
			outtextxy(20,160,"�ϣ�л~");
			outtextxy(600,350,"by־��");
			rectangle(550,300,650,340);
			outtextxy(580,315,"����");
		}
	}
	cleardevice();
	windows();
}
void gameover(int length)
{	int score;
	char str[1024];
	cleardevice();
	setcolor(YELLOW);
	outtextxy(300,200,"GAMEOVER");
	score=(s.length-3)*10;
	sprintf(str,"%d",score);
	setcolor(BLUE);
	outtextxy(300,100,"������");
	outtextxy(300,150,str);
	//rectangle(250,250,450,300);
	//outtextxy(300,270,"���������Ϸ");
}
void color(int m,int n)
{
	setcolor(YELLOW);
	rectangle(m,n,m+100,n+50);
	setcolor(GREEN);
}
void windows()
{
	void boring2();
	boring2();
	setcolor(GREEN);
	rectangle(270,300,430,350);
	outtextxy(320,315,"��ʼ��Ϸ");
	rectangle(50,300,210,350);
	outtextxy(100,315,"��Ϸ�ȼ�");
	rectangle(490,300,650,350);
	outtextxy(540,315,"��Ϸ˵��");

}
/*����˼�壬����boring�������������͵�*/
void boring(int m,int n)
{
	int i;
	for(i=0;i<5;i++)
	{
		setcolor(YELLOW);
		rectangle(m,n,m+160,n+50);
		Sleep(100);		
		setcolor(GREEN);
		rectangle(m,n,m+160,n+50);
		Sleep(100);
	}
	setcolor(WHITE);
}
void boring2()
{
	setcolor(WHITE);
	/*̰*/
	line(135,30,30,130);
	line(130,35,230,130);
	line(130,100,135,130);
	line(95,130,165,130);
	line(165,130,130,160);
	line(80,160,180,160);
	line(80,160,80,200);
	line(180,160,180,200);
	line(135,175,80,230);
	line(130,180,180,230);
	/*ʳ*/
	line(355,30,250,130);
	line(350,35,450,130);
	line(350,100,355,130);
	line(315,130,385,130);
	line(315,130,315,230);
	line(315,155,385,155);
	line(315,180,385,180);
	line(385,130,385,180);
	line(315,180,385,230);
	line(350,205,365,190);
	/*��*/
	line(540,100,470,100);
	line(540,150,470,150);
	line(540,100,540,150);
	line(470,100,470,150);
	line(505,50,505,200);
	line(470,220,540,180);
	line(530,170,550,190);
	line(610,50,620,100);
	line(560,100,670,100);
	line(560,100,560,150);
	line(670,100,670,150);
	line(590,130,590,200);
	line(590,200,600,220);
	line(600,220,680,220);
	line(680,220,680,200);
	line(590,175,640,150);
}