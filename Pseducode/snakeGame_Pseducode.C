START

//DECLARE HEADER FILES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

//Define MACROS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//Define functions and variables

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

Typedef struct coordinate
{
    int x
    int y
    int direction
}coordinate;

coordinate head,  bend [500], food, body[200]

main ()//function
    char key
    print()
    system("cls")
    system("colour 17")
    load()
    length <- 3
    head.x <- 25
    head.y <- 20
    head.direction <- RIGHT
    boarder ()
    food()
    life <- 5
    bend [0] <- head
    move()
    return <- 0

move()//function
    int a, i

    do
    food ()
    fflush(stdin)
    len <- 0
    i <- 0
  
    while i <- 200 do
    body [i].x <- 0 
    body [i].y <- 0
    if (i == length) then 
    break
    endif
    i += 1
    end while 

    delay (length)
    boarder ()

    if (head.direction == RIGHT) then
    right ()

    if (head.direction == LEFT) then
    LEFT ()

    if (head.direction == DOWN) then
    DOWN ()

    if (head.direction == UP) then
    UP ()

    EXITGAME()

    END IF 
    
    WHILE  KBHIT()! = 0
    END DO WHILE 

    a <- getch ()
    if (a == 27) then 
    system ("cls")
    exit (0)
    end if 

    key <- getch ()

    if((key==RIGHT && head.direction!=LEFT && head.direction!=RIGHT)
    ||(key==LEFT && head.direction!=RIGHT && head.direction!=LEFT)
    ||(key==UP && head.direction!=DOWN && head.direction!=UP)
    ||(key==DOWN && head.direction!=UP && head.direction!=DOWN))then

    bend_no += 1
    bend[bend_no] <- head
    head.direction <- key
    if (key == UP) then 
    head.y--
    end if 
        
    if (key == DOWN) then
    head.y++
    end if
    
    if (key == RIGHT) then
    head.x++
    end if
        
    if (key == LEFT) then
    head.x--
    end if

    move ()
        
    end if
    
    else if (key == 27) then
    system("cls")
    exit(0)
    end else if
    
    else
    print ("\a")
    move()
    end else 
    
    
COORD coord <- {0,0}// sets coordinates to (0,0) as global variables
gotoxy (x,y)//function
    coord.x <-x
    coord.y <- y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)

GotoXY (x,y)//function
    HANDLE a
    COORD b
    fflush (stdout)
    b.x <- x
    b.y <- y
    a <- GetstdHandle(STD_OUTPUT_HANDLE)
    SetConsoleCursorPosition(a,b)

load()//function
    int row , col r,c,q
    gotoxy (36,15)
    r <- 1
    while (r <- 20) do
    q <- 0
    while (q<-1000000) do
    print ("%c",177)
    q <- q+1
    end while 
    r <- r+1
    end while
    getch()
    
down()//function
    int i
    i <- 0
    while (i <= (head.y - bend[bend_no].y) && len < length) do 
    Gotoxy (head.x, head.y - i)
    if (len == 0) then
    print ("v")
    end if
    else
    print("*")
    end else

    body[len].x <- head.x
    body[len].y <- head.y - i
    len++
    
    i <- i+1
    end while

    bend ()
    if(!kbhit()) then
    head.y <- head.y+1
    end if

    delay (long double k)//function
    score()
    long double i
    i <- 0
    while (i <= (0)) do
    i ++
    end while

exitgame()//function
    int i, check <- 0
    i <- 4
    while i < length do
    if (body[0].x==body[i].x&&body[0].y==body[i].y) then
    check <- check+1
    end if

    if (i == length || check != 0) then
    break
    end if

    i <- i + 1
    end while

    if (head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0) then   
    life <- life -1
    if (life >= 0) then
    head.x <- 25
    head.y <- 20
    bend_no <- 0
    head.direction <- Right
    move()
    end if 
    else
    system("cls")
    printf("All Lives Completed\nBetter Luck Next Time!!\nPress Any Key To Quit The Game\n")
    record()
    exit(0)
    end else  
    end if

food ()//function
    if (head.x == food.x && head.y == food.y) then
    length <- length +1
    time_t a
    a <- time(0)
    srand(a)
        
    food.x <- rand()%70
    if (food.x <= 10) then
    food.x+=11
    end if
        
    food.y <- rand()%30
    if (food.y <= 10) then
    food.y+=11
    end if
    end if 

    else if (food.x==0) then

    food.x <- rand()%70
    if (food.x <= 10) then
    food.x+=11
    end if
        
    food.y <- rand()%30
    if (food.y <= 10) then
    food.y+=11
    end if

    end else if

left()//function 
    int i
    i <- 0
    while (i <= (bend[bend_no].x - head.x) && len<length) do
    Gotoxy ((head.x+i), head.y)
    if (len == 0) then
    print ("<")
    end if
    else
    print("*")
    end else

    body[len].x <- head.x+i
    body[len].y <- head.y
    len <- len + 1
    
    i <- i+1
    end while

    bend ()
    if(!kbhit()) then
    head.x <- head.x-1
    end if

right()//function
    int i
    i<-0
    while (i<=(head.x-bend[bend_no].x)&&len<length) do
    body[len].x <- head.x-i
    body[len].y <- head.y
    GotoXY(body[len].x,body[len].y)
    if (len == 0) then
    print(">")
    else
    print("*")
    end if
    len <-len+1
    i<-i+1
    end while
    bend()
    if (!kbhit()) then
    head.x <- head.x+1
    end if

bend()//function
    int i, j, diff
    i <- bend_no
    while (i>=0 && len<length) do
    if (bend[i].x==bend[i-1].x) then
    diff <- bend[i].y-bend[i-1].y
    if (diff < 0) then
    j <- 1
    while (j<=(-diff)) do
    body[len].x=bend[i].x
    body[len].y=bend[i].y+j
    GotoXY(body[len].x,body[len].y)
    print("*")
    len <- len + 1
    if(len==length) then
    break
    end if
    j <- j + 1
    end while 
    end if
    else if (diff > 0) then
    j <- 1
    while (j <= diff) do
    body[len].x=bend[i].x
    body[len].y=bend[i].y-j
    GotoXY(body[len].x,body[len].y)
    print("*")
    len <- len + 1
    if(len==length) then
    break
    end if
    j <- j + 1
    end while
    end else if 
    end if
    else if(bend[i].y==bend[i-1].y) then
    diff=bend[i].x-bend[i-1].x
    if(diff<0) then
    j <- 1
    while(j<=(-diff)&&len<length) do
    body[len].x=bend[i].x+j
    body[len].y=bend[i].y
    GotoXY(body[len].x,body[len].y)
    print("*")
    len <- len + 1
    if(len==length) then
    break
    end if
    j <- j + 1
    end while
    end if
    else if(diff>0) then
    j <- 1
    while (j<=diff&&len<length) do
    body[len].x=bend[i].x-j
    body[len].y=bend[i].y
    GotoXY(body[len].x,body[len].y)
    print("*")
    len <- len + 1
    if(len==length) then
    break
    end if
    j <- j + 1
    end while
    end else if
    end else if 
    end while 

boarder()//function
    system("cls")
    int i;
    GotoXY(food.x,food.y)
    print("O");
    i <- 10
    while (i<71) do
    GotoXY(i,10)
    print(":")
    GotoXY(i,30)
    print(":")
    i <- i + 1
    end while
    i <- 10
    while (i<31) do
    GotoXY(10,i)
    print(":")
    GotoXY(70,i)
    print(":")
    i <- i + 1
    end while

Print()//function
    printf("Welcome To The Snake Game.\n\n (Press Any Key To Continue...)\n")
    getch()
    system("cls")
    print("Game Instructions:\n")
    print("\n-> Use Arrow Keys To Move The Snake.
    \n\n-> You Will Be Provided Foods (O) at The random Coordinates Of The Screen Which You Have To Eat, To Make Score.\n")
	print("Everytime You Eat A Food The Length Of The Snake Will Be Increased By 1 Element indicating the score.")
	print("\n\n-> Here You Are Provided With Five Lives. Your Life Will Decrease As You Hit The Wall Or Snake's Body.")
	print("\n\n-> You Can Pause The Game While Playing By Pressing Any Key, To Continue The Paused Game Press Any Key Once Again.")
	print("\n\n-> If You Want To Exit Press ESC.\n")
    print("\n\n\nPress Any Key To Play The Game...")
    if(getch()==27) then
    exit(0)
    end if

record()//function
    char plname[20],nplname[20],cha,c
    int i,j,px
    FILE *info
    info <- fopen("record.txt","a+")
    getch()
    system("cls")
    print("Enter Your Name: ")
    read(plname)

    j <- 0
    while (plname[j]!='\0') do
    nplname[0] <- toupper(plname[0])
    if(plname[j-1]==' ') then
    nplname[j] <- toupper(plname[j])
    nplname[j-1] <- plname[j-1]
    end if
    else 
    nplname[j]=plname[j]
    end else
    j <- j + 1
    end while
    nplname[j] <- '\0'

    fprint(info,"\n\nPlayer Name: %s\n",nplname)

    time_t mytime
    mytime <- time(NULL)
    fprint(info,"\nPlayed Date:%s",ctime(&mytime))

    fprint(info,"Score: %d\n",px <- Scoreonly())
    i <- 0
    while (i<=50) do
    fprintf(info,"%c",'_')
    i <- i + 1
    end while
    fprint(info,"\n")
    fclose(info)
    print("Press 'y' if you want to see past records (y/n): ")
    cha <- getch()
    system("cls")
    if(cha=='y') then
    info <- fopen("record.txt","r");
    do
    putchar(c=getc(info));
    while(c!=EOF)
    end DO WHILE
    end if
    fclose(info)

score()//function
    int score
    GotoXY(20,8)
    score <- length-3   
    print("SCORE : %d",(length-3))
    score <- length-3
    GotoXY(50,8)
    print("Life : %d",life)
    return score

Scoreonly()//function
    int score <- Score()
    system("cls")
    return score

up()//function
    int i
    i <- 0
    while (i<=(bend[bend_no].y-head.y)&&len<length) do
    GotoXY(head.x,head.y+i)
    if(len==0) then
    print("^")
    end if            
    else
    print("*")
    end else    
    body[len].x <- head.x
    body[len].y <- head.y + i
    len <- len + 1
    i <- i + 1
    end while
    Bend()
    if(!kbhit()) then
    head.y <- head.y - 1
    end if

STOP