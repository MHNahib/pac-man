#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

float tempX=150, packEyeX=160,tempY=150, packEyeY=170;
int initial= 45, red= 315;
int score=0, level=0;
string playerName;
int L1x[]= {111,388,94,499,309};
int L1y[]= {111,435,370,279,275};


float angle=30.0f;

float packPosX0= tempX, packPosX1= tempX, packPosY0= tempY, packPosY1= tempY;


float enemyX, enemyY, enemyPoint=0;

void init()
{
    glClearColor(0.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f);
    glOrtho(0,800,0,600,-15,5);
}


// random number generator
int random(int min, int max)
{

    return min + rand() % (( max + 1 ) - min);
}


void body(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,198,0);
    glVertex2f(cx,cy);

    for(int i=initial; i<=red; i++)
    {
        float angle =  3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);


        glVertex2f((x+cx),(y+cy));



    }
    glEnd();

}

void eye(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(212, 241, 249);
    glVertex2f(cx,cy);

    //for(int i=45;i<=315;i++)
    for(int i=0; i<=360; i++)

    {
        float angle =  3.1416f * i/180;
        // cout<<angle<<endl;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);



        glVertex2f((x+cx),(y+cy));

    }



    glEnd();



}

void level2(){
    // left wall
        glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex3f(0,0,0.0);
        glVertex3f(10,0,0.0);
        glVertex3f(10,600,0.0);
        glVertex3f(0,600,0.0);
        glEnd();

        // right wall

        glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex3f(800,0,0.0);
        glVertex3f(790,0,0.0);
        glVertex3f(790,600,0.0);
        glVertex3f(800,600,0.0);
        glEnd();

        // top wall

        glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex3f(0,600,0.0);
        glVertex3f(0,590,0.0);
        glVertex3f(790,590,0.0);
        glVertex3f(800,600,0.0);
        glEnd();

        // top wall

        glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex3f(0,0,0.0);
        glVertex3f(800,0,0.0);
        glVertex3f(800,10,0.0);
        glVertex3f(0,10,0.0);
        glEnd();
}

void level3(){

    // box 1

    glBegin(GL_QUADS);
    //glColor3ub(255,99,9);
    glColor3ub(255,0,0);
    glVertex3f(10,10,0.0);
    glVertex3f(160,10,0.0);
    glVertex3f(160,160,0.0);
    glVertex3f(10,160,0.0);
    glEnd();

    // box 1

    glBegin(GL_QUADS);
    //glColor3ub(255,99,9);
    glColor3ub(255,0,0);
    glVertex3f(10,10,0.0);
    glVertex3f(180,10,0.0);
    glVertex3f(180,200,0.0);
    glVertex3f(10,200,0.0);
    glEnd();

    // box 2

    glBegin(GL_QUADS);
    //glColor3ub(255,99,9);
    glColor3ub(255,0,0);
    glVertex3f(790,10,0.0);
    glVertex3f(620,10,0.0);
    glVertex3f(620,200,0.0);
    glVertex3f(790,200,0.0);
    glEnd();

    // box 3

    glBegin(GL_QUADS);
    //glColor3ub(255,99,9);
    glColor3ub(255,0,0);
    glVertex3f(790,590,0.0);
    glVertex3f(620,590,0.0);
    glVertex3f(620,460,0.0);
    glVertex3f(790,460,0.0);
    glEnd();

    // box 4

    glBegin(GL_QUADS);
    //glColor3ub(255,99,9);
    glColor3ub(255,0,0);
    glVertex3f(10,590,0.0);
    glVertex3f(160,590,0.0);
    glVertex3f(160,460,0.0);
    glVertex3f(10,460,0.0);
    glEnd();





    // fan 01
    glPushMatrix();
    glTranslatef(650,350 , 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-650,-350 , 0.0f);



    glBegin(GL_TRIANGLES);
    glColor3ub(255,181,0);
    glVertex2f(650,350);
    glColor3ub(253,222,7);
    glVertex2f(650,250);
    glColor3ub(253,222,7);
    glVertex2f(690,250);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255,181,0);
    glVertex2f(650,350);
    glColor3ub(253,222,7);
    glVertex2f(650,450);
    glColor3ub(253,222,7);
    glVertex2f(610,450);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255,181,0);
    glVertex2f(650,350);
    glColor3ub(253,222,7);
    glVertex2f(750,350);
    glColor3ub(253,222,7);
    glVertex2f(750,390);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255,181,0);
    glVertex2f(650,350);
    glColor3ub(253,222,7);
    glVertex2f(550,350);
    glColor3ub(253,222,7);
    glVertex2f(550,310);
    glEnd();


    glPopMatrix();
}

// enemy circle

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{

    glBegin(GL_TRIANGLE_FAN);
    // glColor3ub(41, 255, 9);
    glColor3ub(random(10, 255), random(10, 255), random(10, 255));
    glVertex2f(cx,cy);
    glColor3ub(random(10, 255), random(10, 255), random(10, 255));
    for(int i=0; i<=360; i++)

    {
        float angle =  3.1416f * i/180;
        // cout<<angle<<endl;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);



        glVertex2f((x+cx),(y+cy));




    }
    glEnd();



}


void enemyGenerator()
{

    if(enemyPoint==0)
    {
        enemyX= L1x[0];
        enemyY= L1y[0];
    }
    if(enemyPoint==1)
    {
        enemyX= L1x[1];
        enemyY= L1y[1];
    }
    if(enemyPoint==2)
    {
        enemyX= L1x[2];
        enemyY= L1y[2];
    }
    if(enemyPoint==3)
    {
        enemyX= L1x[3];
        enemyY= L1y[3];
    }
    if(enemyPoint==4)
    {
        enemyX= L1x[4];
        enemyY= L1y[4];
    }

    circle(5,5, enemyX, enemyY);
}



void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    enemyGenerator();

    glBegin(GL_QUADS);
//glColor3ub(255,99,9);
    glColor3ub(0,0,0);
    glVertex3f(tempX-30,tempY-30,0.0);
    glVertex3f(tempX+30,tempY-30,0.0);
    glVertex3f(tempX+30,tempY+30,0.0);
    glVertex3f(tempX-30,tempY+30,0.0);
    glEnd();

    body(30,30, tempX, tempY);
    eye(5,5, packEyeX, packEyeY);


    if(level==1)
    {

        level2();

    }

    // level 2

    if(level==2){

        level3();



    }





    glFlush();
}

void update(int value)
{

    ////Tell GLUT that the scene has changed
    angle+=10;
    initial-=0.9;
    red+=1.9;
    if(initial<11 || red> 360)
    {
        initial= 45;
        red= 315;
    }

    //  cout<<Y<<endl;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void checker()
{
    /*
    int num= 1+ (rand() % 500);

    if(num<100){
        num+=100;
    }
    */
    if(level==0)
    {
        if((tempX>750 || tempX<50) || (tempY<50 || tempY>550))
        {
            /*
            tempX=num, packEyeX=num+10;
            tempY=num, packEyeY=num+20;
            */

            tempX=150, packEyeX=160,tempY=150, packEyeY=170;

        }
    }

    if(level==1)
    {
        if((tempX>770 || tempX<30) || (tempY<30 || tempY>580))
        {
            /*
            tempX=num, packEyeX=num+10;
            tempY=num, packEyeY=num+20;
            */

            cout<<"SORRY, "<<playerName<<"! YOUR SCORE IS "<<score<<endl;
            cout<<"PRESS Q/q KEY TO EXIT: ";
            char inp;
            cin>>inp;
            if(inp=='q' ||inp=='Q')
            {
                exit(0);
            }

        }
    }

        if(level==2)
    {
        if((tempX>550 || tempX<30) || (tempY<30 || tempY>580))
        {
            /*
            tempX=num, packEyeX=num+10;
            tempY=num, packEyeY=num+20;
            */

            cout<<"SORRY, "<<playerName<<"! YOUR SCORE IS "<<score<<endl;
            cout<<"PRESS Q/q KEY TO EXIT: ";
            char inp;
            cin>>inp;
            if(inp=='q' ||inp=='Q')
            {
                exit(0);
            }

        }
    }

    if(level==3)
    {
        cout<<"YES, "<<playerName<<"! YOU HAVE COMPLEATED ALL THE LEVELS."<<endl<<" YOUR SCORE IS "<<score<<endl;
            cout<<"PRESS Q/q KEY TO EXIT: ";
            char inp;
            cin>>inp;
            if(inp=='q' ||inp=='Q')
            {
                exit(0);
            }
    }






    /*
    if((packPosX0>= enemyX && packPosX1<= enemyY) && (packPosY0>= enemyY && packPosY1<= enemyY))
    {
        cout<<"+10"<<endl;
        enemyPoint+=1;

    }


    if((enemyX >= tempX || enemyX <= tempX) && (enemyY >= tempY || enemyY <= tempY))
    {

    }


    cout<<"tempX: "<<tempX;
    cout<<" tempY: "<<tempY<<endl;
    cout<<"("<<tempX-30<<","<<tempY-30<<")-("<<tempX+30<<","<<tempY+30<<")"<<endl;
    cout<<"enemy positon: "<<enemyX<<","<<enemyY<<endl;
    */
    if(enemyPoint>4)
    {

        level+=1;
        enemyPoint=0;
        cout<<"LEVEL UP!"<<endl;
        cout<<"YOUR SCORE IS "<<score<<endl;
    }

    if(enemyX >= tempX-5 && enemyX<= tempX+5)
    {
        //cout<<"pass1"<<endl;
        if(tempY-5>= enemyY && enemyY<= tempY+5)
        {
            //cout<<"pass2"<<endl;
            cout<<"+10"<<endl;
            enemyPoint+=1;
            score+=10;
        }
    }

    if(enemyY>= tempY-5 && enemyY<= tempY+5)
    {
        //cout<<"pass3"<<endl;
        if(tempX-5>= enemyX && enemyX<= tempX+5)
        {
            //cout<<"pass4"<<endl;
            cout<<"+10"<<endl;
            enemyPoint+=1;
        }
    }



}


static void key(unsigned char key, int x, int y)
{


    checker();
    switch (key)
    {

    case 'w':
        tempY+=5.0;
        packEyeY+=5.0;


        break;

    case 's':

        tempY-=5.0;
        packEyeY-=5.0;


        break;

    case 'a':

        tempX-=5.0;
        packEyeX-=5.0;


        break;

    case 'd':

        tempX+=5.0;
        packEyeX+=5.0;



        break;


    }

    //cout<<"tempX: "<<tempX<<", tempY"<<tempY<<endl;

    glutPostRedisplay();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 70);
    glutCreateWindow("Pack Man Project");
    init();
    glutDisplayFunc(myDisplay);

    glutTimerFunc(25, update, 0);
    // update(0);

    cout<<"Player Name: ";
    cin>>playerName;
    cout<<"Level: 0\tScore: 0"<<endl;

    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
