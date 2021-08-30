#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<fstream>
using namespace std;
COORD coord={0,0};
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void file_writing(int score)
    {
        system("cls");

        char arr[100];
        gotoxy(50,5);
        cout<<"Enter your name ";
        cin.getline(arr,100);

        ofstream score_file("score_card.txt",ios::app);
        score_file<<arr<<" : "<<score<<endl;
        (score_file).close();
        system("cls");
}
void file_reading()
{
    char arr1[100];
    ifstream scorefile("score_card.txt");
    if(!scorefile)
    {
        gotoxy(55,3);
        cout<<"No Data";
        return;
    }
    gotoxy(51,2);
    cout<<"SCORES";
    gotoxy(50,3);
    cout<<"________";
    int x=5;
    while(!(scorefile).eof())
        {
        scorefile.getline(arr1,100);
        gotoxy(50,x++);
        cout<<arr1<<endl;
        }
    scorefile.close();
}
void print_credit(int x,int y,string line)
{
    if(y<27 && y>0)
   {
        gotoxy(x,y);
        cout<<line;
   }
}
struct Snake_coord
{
    int x_coord;
    int y_coord;
};
void box(int x,int y,int sz)
{
		int i;
		gotoxy(x-3,y-1);
		cout<<"+";
		for(i=0;i<sz+4;i++)
			cout<<"-";
		cout<<"+";
		gotoxy(x-3,y);
		cout<<"|";
		gotoxy(x+sz+2,y);
		cout<<"|";
		gotoxy(x-3,y+1);
		cout<<"+";
		for(i=0;i<sz+4;i++)
			cout<<"-";
		cout<<"+";
}
void unbox(int x,int y,int sz)
{
		int i;
		gotoxy(x-3,y-1);
		cout<<" ";
		for(i=0;i<sz+4;i++)
			cout<<" ";
		cout<<" ";
		gotoxy(x-3,y);
		cout<<" ";
		gotoxy(x+sz+2,y);
		cout<<" ";
		gotoxy(x-3,y+1);
		cout<<" ";
		for(i=0;i<sz+4;i++)
			cout<<" ";
		cout<<" ";
}
void tran()
{
	 for(int t=0;t<118;t+=2)
		{
            delay(5);
            gotoxy(t,0);
            cout<<char (250);
            gotoxy(118-t,26);
            cout<<char (250);
        }
        gotoxy(0,26);
        cout<<char (250);
    for(int t=0;t<26;t++)
        {
            delay(5);
            gotoxy(0,26-t);
            cout<<char (250);
            gotoxy(118,t);
            cout<<char (250);
		}
		delay(200);
}
void tran1()
{
	 for(int t=0;t<=94;t+=2)
		{
            gotoxy(t,0);
            cout<<char (250);
            gotoxy(94-t,20);
            cout<<char (250);
        }
        gotoxy(0,26);
        cout<<char (250);
    for(int t=0;t<=20;t++)
        {
            gotoxy(0,20-t);
            cout<<char (250);
            gotoxy(94,t);
            cout<<char (250);
		}
}
void removeSnake(Snake_coord *array1,int size1)
{
    for(int i=0;i<size1;i++)
    {
        gotoxy(array1[i].x_coord,array1[i].y_coord);
        cout<<" ";
    }
}
void DisplaySnake(Snake_coord *array1,int size1)
{
    for(int i=1;i<size1;i++)
    {
        gotoxy(array1[i].x_coord,array1[i].y_coord);
        cout<<"o";
    }
    gotoxy(array1[0].x_coord,array1[0].y_coord);
    cout<<char (153);
}
void DisplayFood(Snake_coord food)
{
    gotoxy(food.x_coord,food.y_coord);
    cout<<char (233);
}
void GetNewfood(Snake_coord *Newfood)
{
    gotoxy(Newfood->x_coord,Newfood->y_coord);
    cout<<" ";

    srand(time(0));
    Newfood->x_coord=rand()%94;
    if(Newfood->x_coord%2==0 || Newfood->x_coord==0)
        Newfood->x_coord++;
    Newfood->y_coord=rand()%20;
    if(Newfood->y_coord==0)
        Newfood->y_coord++;
}
void move_forward(Snake_coord *array1, int size1,int x, int y)
{
    int i;
    for(i=size1-1;i>0;i--)
    {
        array1[i].x_coord=array1[i-1].x_coord;
        array1[i].y_coord=array1[i-1].y_coord;
    }
    array1[0].x_coord=x;
    array1[0].y_coord=y;
}
void credits()
{
    system("cls");
    int i,x=40;
    for(i=26;i>-25;i--)
    {
        print_credit(x,i,"ANANCONDA - The Snake Game");
        print_credit(x,i+1,"--------------------------");
        print_credit(x,i+5,"Thank you for playing");
        print_credit(x,i+10,"A game by");
        print_credit(x,i+14,"Jitendra Yadav ( Chief Executing Officer)");
        print_credit(x,i+16,"Jainam Jain (Manager)");
        print_credit(x,i+19,"(Students of IIT GOA)");
        print_credit(x,i+25,"Game Completion date- __/07/2019");
        delay(500);

        print_credit(x,i,"                          ");
        print_credit(x,i+1,"                          ");
        print_credit(x,i+5,"                       ");
        print_credit(x,i+10,"                          ");
        print_credit(x,i+14,"                                          ");
        print_credit(x,i+16,"                     ");
        print_credit(x,i+19,"                     ");
        print_credit(x,i+25,"                                 ");

    }
}
int game_play()
{
    int  v=4,x=13, y=10,i,score=0,n=0,play,snake_speed=150;
    bool food_changed=true,game_end=false,ver=false;
    Snake_coord Snake[900], food;

    system("CLS");
    tran1();

    gotoxy(105,3);
    cout<<"SCORE";
    gotoxy(5,25);
    cout<<"Press 'Spacebar' to pause/ 'p' to play";
    for(i=0; i<3;i++)
    {
        Snake[i].x_coord=x-i*2;
        Snake[i].y_coord=y;
    }
    food.x_coord= rand()%94;
    food.y_coord= rand()%20;
    GetNewfood(&food);


    while(!game_end)
    {
        DisplaySnake(Snake,3+n);
        if(food_changed)
        {
            DisplayFood(food);
            food_changed=false;
        }

        delay(snake_speed);
        if(GetAsyncKeyState(VK_SPACE))
        {
           play=_getch();

           while(play!='p')
           {
                play=_getch();
           }
        }
        removeSnake(Snake,3+n);
        if(v==4)
            x=x+2;
        else if (v==3)
            x=x-2;
        else if(v==2)
            y=y+1;
        else
            y=y-1;

        if(x==-1 && ver==false)
            x=93;
        else if (x==95 && ver==false)
            x=1;
        if (y==0 && ver==true)
            y=19;
        else  if(y==20 && ver==true)
            y=1;

        move_forward(Snake,3+n,x,y);
        if (GetAsyncKeyState(VK_UP) && v!=2)
           v=1,ver=true;
        else if (GetAsyncKeyState(VK_DOWN) && v!=1)
           v=2,ver=true;
        else if (GetAsyncKeyState(VK_LEFT) && v!=4)
           v=3,ver=false;
        else if (GetAsyncKeyState(VK_RIGHT) && v!=3)
           v=4,ver=false;



        if(Snake[0].x_coord==food.x_coord && Snake[0].y_coord==food.y_coord)
        {
            score+=5;
            gotoxy(107,5);
            cout<<score;
            n=n+1;
            if(snake_speed>50)
                snake_speed-=2;
            GETNEW:
            GetNewfood(&food);
            food_changed=true;
            for(int i=0;i<n+3;i++)
            {
                if(food.x_coord==Snake[i].x_coord && food.y_coord==Snake[i].y_coord)
                    goto GETNEW;
            }
        }
        for(int i=3;i<n+3;i++)
            {
            if(Snake[0].x_coord==Snake[i].x_coord && Snake[0].y_coord==Snake[i].y_coord)
            {
                game_end=true;
                system("CLS");
            }
            }
    }
    return score;

}
void game_menu()
{
    GAME_MENU:
    int z;
    system("cls");
    int selected=6,nav1,last_selected;
    box(58,6,11);
    gotoxy(59,6);
    cout<<"NEW GAME";
    gotoxy(59,10);
    cout<<"SCORES";
    gotoxy(59,14);
    cout<<"CREDITS";
    do{
        nav1=_getch();
        last_selected=selected;
        if(nav1==80)
        {
             selected+=4;
             if(selected==18)
                selected=6;
        }

        else if(nav1==72)
        {
            selected-=4;
            if(selected==2)
                selected=14;
        }
        unbox(58,last_selected,11);
        box(58,selected,11);
    }
    while(nav1!=13);

    if(selected==6)
    {
        z=game_play();
        file_writing(z);

        goto GAME_MENU;

    }
    else if(selected==10)
    {
        int c;
        system("cls");
        file_reading();
        gotoxy(80,25);
        cout<<"PRESS ANY KEY TO GO TO MAIN MENU";
        if(c=_getch())
        system("cls");
        goto GAME_MENU;
    }
    else if(selected==14)
        credits();
        goto GAME_MENU;

}
void opening_transition()
{
    gotoxy(50,12);
    cout<<"SNAKE GAME";
    tran();
}
int main()
{


    setcursor(0,0);
    opening_transition();
    game_menu();
    gotoxy(0,26);
}
