#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>//for the sleep() function

int i,j,height=20, width=20;
int gameover, score;
int x, y, fruitx, fruity, flag;
//function to generate the fruit within the boundary
void setup(){
    gameover=0;
    //stores height and width
    x=height/2;
    y=width/2;
label1:
    fruitx=rand()%20;
    if(fruitx==0)
        goto label1;
label2:
    fruity=rand()%20;
    if(fruity==0)
        goto label2;
    score=0;
    }

    //function to draw the boundaries
    void draw(){
        system("cls");
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                if(i==0||i==width-1||j==0||j==height-1){
                    printf("#");
                }
                else{
                    if(i==x&&j==y)
                        printf("0");
                    else if(i==fruitx&&j==fruity)
                        printf("*");
                    else
                        printf(" ");
                }
            }
            printf("\n");
        }
        //print the score after the game ends
        printf("score=%d",score);
        printf("\n");
        printf("press X to quit the game");
    }

    //function to take the input
    void input(){
    if (kbhit()){
        switch (getch()){
    case 'a':
        flag =1;
        break;
    case 's':
        flag =2;
        break;
    case 'd':
        flag =3;
        break;
    case 'w':
        flag=4;
        break;
    case 'x':
        gameover=1;
        break;
        }
    }
    }
    //function for the logic behind each movement
    void logic(){
        sleep(0.01);
        switch (flag){
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
        }

        //if the game is over
        if(x<0||x>height||y<0||y>width)
            gameover=1;

        //if the snake reaches the fruit the update the score
        if(x==fruitx&&y==fruity){
            label3:
                fruitx=rand()%20;
                if(fruitx==0)
                    goto label3;
        //after eating the above fruit generate a new fruit
        label4:
            fruity=rand()%20;
            if(fruity==0)
                goto label4;
            score +=10;
        }
    }

    //Driver code
    void main(){
    int m,n;
        //generate boundary
        setup();
        //until the game is over
        while(!gameover){
            //function call
            draw();
            input();
            logic();
        }
    }
