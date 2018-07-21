#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>
#include<ostream>
#include<string.h>


int c = 0,startFlag = 0;
int flag=1;
float ctr = 0.1;
int nflag = 0;
float nc = 0;
int gameStart = 0;
long int lel = 0;

float baseSpeed = 0.7;
float speedMultiplier = 0.03;
//int lives=3;
char str[20] = {0};
int gameState = 0;
long int score = 0;
long int hse = 00;
void displayMenu();

class Background{
public:
  GLfloat x1,y1,x2,y2,x3,y3,x4,y4;
  GLfloat x1m,y1m,x2m,y2m,x3m,y3m,x4m,y4m;
  float ctr,speed;

  Background(float xn1,float xn2,float yn1, float yn2,float speed){
    x1 = x1m = xn1;
    y1 = y1m = yn1;
    x2 = x2m = xn2;
    y2 = y2m = yn1;
    x3 = x3m = xn2;
    y3 = y3m = yn2;
    x4 = x4m = xn1;
    y4 = y4m = yn2;


    ctr = 0;
    this->speed = speed;
  }

  void setSpeed(float speed){
    this->speed = speed;
  }

  void resetObstacle(float xn1,float xn2, float yn1, float yn2){
    x1 = x1m = xn1;
    y1 = y1m = yn1;
    x2 = x2m = xn2;
    y2 = y2m = yn1;
    x3 = x3m = xn2;
    y3 = y3m = yn2;
    x4 = x4m = xn1;
    y4 = y4m = yn2;
    ctr = 0;
  }


  void updateCord(){

    if(ctr>=500)
      ctr = 0;
    ctr +=speed;

    x1m  = x1 - ctr;
    x2m  = x2 - ctr;
    x3m  = x3 - ctr;
    x4m  = x4 - ctr;
  }

  void draw(){

      //glClearColor(0,0,0,0.1);

      glBegin(GL_POLYGON);
        glColor4f(1,1,1,0.5);
        glVertex2i(x1m,y1m);
        glColor4f(1,1,1,0.5);
        glVertex2i(x2m,y2m);
        glColor4f(0.52,0.80,0.98,0.5);
        glVertex2i(x3m,y3m);
        glColor4f(0.52,0.80,0.98,0.5);
        glVertex2i(x4m,y3m);
      glEnd();
  }

};

Background b1(450,500,400,410,0.5),b2(450,500,330,340,0.56),b3(450,500,450,460,0.52);
class Dinosaur{
public:
float x1,y1,x2,y2,x3,y3,x4,y4;
float x1m,y1m,x2m,y2m,x3m,y3m,x4m,y4m;
float ctr;
float hp[8][2],tp[3][2],lrp[4][2],llp[4][2],bp[4][2],ap[4][2];
float hpm[8][2],tpm[3][2],lrpm[4][2],llpm[4][2],bpm[4][2],apm[4][2];
int flag;

Dinosaur(){
  x1= x1m = 100;
  y1 = y1m = 150;
  x2 = x2m = 150;
  y2 = y2m = 150;
  x3 = x3m = 150;
  y3 = y3m = 200;
  x4 = x4m = 100;
  y4 = y4m = 200;

  hp[0][0] = {150};
  hp[0][1] = {180};
  hp[1][0] = {125};
  hp[1][1] = {180};
  hp[2][0] = {125};
  hp[2][1] = {200};
  hp[3][0] = {150};
  hp[3][1] = {200};
  hp[4][0] = {150};
  hp[4][1] = {190};
  hp[5][0] = {130};
  hp[5][1] = {190};
  hp[6][0] = {130};
  hp[6][1] = {185};
  hp[7][0] = {150};
  hp[7][1] = {185};

  tp[0][0] = {115};
  tp[0][1] = {160};
  tp[1][0] = {100};
  tp[1][1] = {175};
  tp[2][0] = {115};
  tp[2][1] = {170};

  lrp[0][0] = {130};
  lrp[0][1] = {150};
  lrp[1][0] = {135};
  lrp[1][1] = {150};
  lrp[2][0] = {135};
  lrp[2][1] = {160};
  lrp[3][0] = {130};
  lrp[3][1] = {160};

  llp[0][0] = {120};
  llp[0][1] = {150};
  llp[1][0] = {125};
  llp[1][1] = {150};
  llp[2][0] = {125};
  llp[2][1] = {160};
  llp[3][0] = {120};
  llp[3][1] = {160};

  bp[0][0] = {140};
  bp[0][1] = {160};
  bp[1][0] = {140};
  bp[1][1] = {180};
  bp[2][0] = {115};
  bp[2][1] = {180};
  bp[3][0] = {115};
  bp[3][1] = {160};

  ap[0][0] = {140};
  ap[0][1] = {170};
  ap[1][0] = {150};
  ap[1][1] = {170};
  ap[2][0] = {150};
  ap[2][1] = {165};
  ap[3][0] = {140};
  ap[3][1] = {165};

  hpm[0][0] = {150};
  hpm[0][1] = {180};
  hpm[1][0] = {125};
  hpm[1][1] = {180};
  hpm[2][0] = {125};
  hpm[2][1] = {200};
  hpm[3][0] = {150};
  hpm[3][1] = {200};
  hpm[4][0] = {150};
  hpm[4][1] = {190};
  hpm[5][0] = {130};
  hpm[5][1] = {190};
  hpm[6][0] = {130};
  hpm[6][1] = {185};
  hpm[7][0] = {150};
  hpm[7][1] = {185};

  tpm[0][0] = {115};
  tpm[0][1] = {160};
  tpm[1][0] = {100};
  tpm[1][1] = {175};
  tpm[2][0] = {115};
  tpm[2][1] = {170};

  lrpm[0][0] = {130};
  lrpm[0][1] = {150};
  lrpm[1][0] = {135};
  lrpm[1][1] = {150};
  lrpm[2][0] = {135};
  lrpm[2][1] = {160};
  lrpm[3][0] = {130};
  lrpm[3][1] = {160};

  llpm[0][0] = {120};
  llpm[0][1] = {150};
  llpm[1][0] = {125};
  llpm[1][1] = {150};
  llpm[2][0] = {125};
  llpm[2][1] = {160};
  llpm[3][0] = {120};
  llpm[3][1] = {160};

  bpm[0][0] = {140};
  bpm[0][1] = {160};
  bpm[1][0] = {140};
  bpm[1][1] = {180};
  bpm[2][0] = {115};
  bpm[2][1] = {180};
  bpm[3][0] = {115};
  bpm[3][1] = {160};

  apm[0][0] = {140};
  apm[0][1] = {170};
  apm[1][0] = {150};
  apm[1][1] = {170};
  apm[2][0] = {150};
  apm[2][1] = {165};
  apm[3][0] = {140};
  apm[3][1] = {165};

  ctr = 0.1;
  flag = 0;
  }

  void updateCord(){


    if(c>0){
  		if(ctr<=0){
  			c = 0;
  			flag = 1;
  		}

  		if(ctr>=c)
  			flag = 0;

  		if(flag==1)
  			ctr+=1.0;
  		else
  			ctr-=1.0;

  	}

    y1m  = y1+ctr;
    y2m = y2 +ctr;
    y3m = y3 + ctr;
    y4m = y4 + ctr;

    int i=0;
    for(i=0;i<8;++i)
      hpm[i][1] = hp[i][1] +ctr;

    for(i=0;i<4;++i){
      lrpm[i][1] = lrp[i][1]+ctr;
      llpm[i][1]=llp[i][1]+ctr;
      apm[i][1]=ap[i][1]+ctr;
      bpm[i][1]=bp[i][1]+ctr;
    }

    for(i=0;i<3;++i)
      tpm[i][1] =tp[i][1] +ctr;
  }

  void drawDino(){

    glBegin(GL_POLYGON);
        glVertex2fv(hpm[0]);
        glVertex2fv(hpm[1]);
        glVertex2fv(hpm[2]);
        glVertex2fv(hpm[3]);
        glVertex2fv(hpm[4]);
        glVertex2fv(hpm[5]);
        glVertex2fv(hpm[6]);
        glVertex2fv(hpm[7]);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2fv(lrpm[0]);
      glVertex2fv(lrpm[1]);
      glVertex2fv(lrpm[2]);
      glVertex2fv(lrpm[3]);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2fv(llpm[0]);
      glVertex2fv(llpm[1]);
      glVertex2fv(llpm[2]);
      glVertex2fv(llpm[3]);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2fv(bpm[0]);
      glVertex2fv(bpm[1]);
      glVertex2fv(bpm[2]);
      glVertex2fv(bpm[3]);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2fv(apm[0]);
      glVertex2fv(apm[1]);
      glVertex2fv(apm[2]);
      glVertex2fv(apm[3]);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2fv(tpm[0]);
      glVertex2fv(tpm[1]);
      glVertex2fv(tpm[2]);
    glEnd();
  }
};
Dinosaur dino;

class Obstacle{
public:
  GLfloat x1,y1,x2,y2,x3,y3,x4,y4;
  GLfloat x1m,y1m,x2m,y2m,x3m,y3m,x4m,y4m;
  GLfloat p1[2],p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2],p9[2],p10[2],p11[2],p12[2],p13[2],p14[2],p15[2],p16[2];
  GLfloat p1m[2],p2m[2],p3m[2],p4m[2],p5m[2],p6m[2],p7m[2],p8m[2],p9m[2],p10m[2],p11m[2],p12m[2],p13m[2],p14m[2],p15m[2],p16m[2];
  float ctr,speed;

  Obstacle(float xn1,float xn2,float yn1, float yn2,float speed){
    x1 = x1m = xn1;
    y1 = y1m = yn1;
    x2 = x2m = xn2;
    y2 = y2m = yn1;
    x3 = x3m = xn2;
    y3 = y3m = yn2;
    x4 = x4m = xn1;
    y4 = y4m = yn2;

    p1[0] = p1m[0] = 470;
    p1[1] = p1m[1] = 150;
    p2[0] = p2m[0] = 470;
    p2[1] = p2m[1] = 170;
    p3[0] = p3m[0] = 450;
    p3[1] = p3m[1] = 170;
    p4[0] = p4m[0] = 450;
    p4[1] = p4m[1] = 200;
    p5[0] = p5m[0] = 460;
    p5[1] = p5m[1] = 200;
    p6[0] = p6m[0] = 450;
    p6[1] = p6m[1] = 180;
    p7[0] = p7m[0] = 470;
    p7[1] = p7m[1] = 180;
    p8[0] = p8m[0] = 470;
    p8[1] = p8m[1] = 200;
    p9[0] = p9m[0] = 480;
    p9[1] = p9m[1] = 200;
    p10[0] = p10m[0] = 480;
    p10[1] = p10m[1] = 170;
    p11[0] = p11m[0] = 490;
    p11[1] = p11m[1] = 170;
    p12[0] = p12m[0] = 490;
    p12[1] = p12m[1] = 200;
    p13[0] = p13m[0] = 500;
    p13[1] = p13m[1] = 200;
    p14[0] = p14m[0] = 500;
    p14[1] = p14m[1] = 160;
    p15[0] = p15m[0] = 480;
    p15[1] = p15m[1] = 160;
    p16[0] = p16m[0] = 480;
    p16[1] = p16m[1] = 150;
    ctr = 0;
    this->speed = speed;
  }

  void setSpeed(float speed){
    this->speed = speed;
  }

  void resetObstacle(float xn1,float xn2, float yn1, float yn2){
    x1 = x1m = xn1;
    y1 = y1m = yn1;
    x2 = x2m = xn2;
    y2 = y2m = yn1;
    x3 = x3m = xn2;
    y3 = y3m = yn2;
    x4 = x4m = xn1;
    y4 = y4m = yn2;
    ctr = 0;
  }

  void testCollide(){
    float d1x = dino.x1m - this->x3m;
  	float d1y = dino.y1m - this->y3m;
  	float d2x = this->x1m - dino.x3m;
  	float d2y = this->y1m - dino.y3m;


  	if(d1x>0.0 || d1y>0.0 || d2x>0.0 || d2y>0.0 ){
      //glutDisplayFunc(displayMenu);
      return;
    }


    if(score>hse)
        hse = score;
    score = 0;
    glutDisplayFunc(displayMenu);

  }

  void updateCord(){

    ctr +=speed;

    x1m  = x1 - ctr;
    x2m  = x2 - ctr;
    x3m  = x3 - ctr;
    x4m  = x4 - ctr;

    p1m[0] = p1[0] - ctr;
    p2m[0] = p2[0] - ctr;
    p3m[0] = p3[0] - ctr;
    p4m[0] = p4[0] - ctr;
    p5m[0] = p5[0] - ctr;
    p6m[0] = p6[0] - ctr;
    p7m[0] = p7[0] - ctr;
    p8m[0] = p8[0] - ctr;
    p9m[0] = p9[0] - ctr;
    p10m[0] = p10[0] - ctr;
    p11m[0] = p11[0] - ctr;
    p12m[0] = p12[0] - ctr;
    p13m[0] = p13[0] - ctr;
    p14m[0] = p14[0] - ctr;
    p15m[0] = p15[0] - ctr;
    p16m[0] = p16[0] - ctr;
  }

  void draw(){
    glBegin(GL_POLYGON);
      glVertex2fv(p1m);
      glVertex2fv(p8m);
      glVertex2fv(p9m);
      glVertex2fv(p16m);
    glEnd();
    glBegin(GL_POLYGON);
      glVertex2fv(p2m);
      glVertex2fv(p3m);
      glVertex2fv(p4m);
      glVertex2fv(p5m);
      glVertex2fv(p6m);
      glVertex2fv(p7m);
    glEnd();
    glBegin(GL_POLYGON);
      glVertex2fv(p10m);
      glVertex2fv(p11m);
      glVertex2fv(p12m);
      glVertex2fv(p13m);
      glVertex2fv(p14m);
      glVertex2fv(p15m);
    glEnd();
  }
};


Obstacle ob1(450,500,150,200,0.15),ob2(450,500,150,200,0.15);

int pos = 0,newrand = 0;
int flag2 = 0;

void idle(){

  if(gameState){
    ob1.testCollide();
    ob2.testCollide();
    dino.updateCord();

    b1.updateCord();
    b2.updateCord();
    b3.updateCord();
		lel +=1;

		if(lel%200==0){
				score+=1;
			}

    if(score%40==0){
      speedMultiplier = 0.03 *(score/40);
      ob1.setSpeed(baseSpeed+speedMultiplier);
      ob2.setSpeed(baseSpeed+speedMultiplier);
    }
    flag2 = 0;

    if(ob1.ctr>=pos){
      flag2 = 1;
    }

    if(ob1.ctr>=500){
      ob1 = ob2;
      ob2.resetObstacle(450,500,150,200);
      srand ( time(0) );
      int pos1 = rand()%150 + 350;
      srand ( time(0) );
      int pos2 = rand()%50;
      srand ( time(0) );
      int posDecide = rand()%2;

      switch(posDecide){
        case 0 : pos = pos1;
                 break;
        case 1 : pos = pos2;
                 break;
      }

    }

    if(score>7)
  		ob1.updateCord();

    if(flag2==1 && score>=15){
      ob2.updateCord();
    }
    glutPostRedisplay();
  }

}



void keyUp(unsigned char key, int x,int y){
  if(key=='z')
  {
    dino.y3m +=25;
    dino.y4m +=25;
  }
}

void init(){
	glClearColor(0.39,0.58,1.0,1.0);
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_PROJECTION);
}

void convertToChar(int x, char str2[20]){
	char str1[20];
	int temp,i=0;
	while(x>0){
		temp = x%10;
		str1[i++] = temp + '0';
		x = x/10;
	}

	int j;

  int k=0;
	for(j=i-1;j>=0;--j,++k)
		str2[k] = str1[j];

}

void drawBg(){
  glBegin(GL_POLYGON);
    glColor3f(0.52,0.80,0.98);
    glVertex2i(0,150);
    glColor3f(0.52,0.80,0.98);
    glVertex2i(500,150);
    glColor3f(0.098,0.098,0.439);
    glVertex2i(500,500);
    glColor3f(0.098,0.098,0.439);
    glVertex2i(0,500);
  glEnd();
}
void display(){
  glClearColor(0.39,0.58,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	int i;

  if(gameState){

    drawBg();
  	glColor3f(0.0,0.0,0.0);
    glColor3f(0.13,0.54,0.13);


    ob1.draw();

    if(flag2==1&&score>=15){
      ob2.draw();
    }

    b1.draw();
    b2.draw();
    b3.draw();
    glColor3f(0,0,0);
    dino.drawDino();

    glBegin(GL_QUADS);
      glColor3f(0.54,0.27,0.074);
      glVertex2i(0,0);
      glColor3f(0.54,0.27,0.074);
      glVertex2i(500,0);
      glColor3f(0.80,0.52,0.24);
      glVertex2i(500,150);
      glColor3f(0.80,0.52,0.24);
      glVertex2i(0,150);
    glEnd();

    convertToChar(score,str);
    glLineWidth(5);
  	//glRasterPos2i(450,450);
    glColor3f(0,0,0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(450,450,0);
    glScalef(0.1,0.1,1);
  	for(i=0;i<strlen(str);++i)
  		glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
    glPopMatrix();
  }
  glFlush();
	glutSwapBuffers();
}

void keyDown(unsigned char key, int x,int y){
  if(key==char(32)){
    if(gameState){
      c = 250;
    }
    else{
      score=0;
      gameState = 1;
      glutDisplayFunc(display);
    }
  }


  if(key == 'z'){

    dino.y3m -=25;
    dino.y4m -=25;
  }

}

void displayMenu(){
  lel = 0;
  score = 0;
  gameState = 0;
  ob1.resetObstacle(450,500,150,200);
  ob2.resetObstacle(450,500,150,200);
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);
  int i;


  char sc[5] = {0,0,0,0,0};

  glLineWidth(2);
  convertToChar(hse,sc);
  glColor3f(0,0,0);

  char hs[] = {'H','i','g','h',' ','S','c','o','r','e',' ',':','\0'};
  //glRasterPos2i(200,300);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(100,252,0);
  glScalef(0.3,0.3,1);
  for(i=0;i<strlen(hs);++i)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,hs[i]);
  glPopMatrix();


  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(375,252,0);
  glScalef(0.3,0.3,1);
  for(i=0;i<strlen(sc);++i)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,sc[i]);
  glPopMatrix();

  char str2[20] = {'D','I','N','O',' ','J','U','M','P'};


  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(150,360,0);
  glScalef(0.3,0.3,1);
  for(i=0;i<strlen(str2);++i)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,str2[i]);
  glPopMatrix();

  char str[20] = "Hit Space to start";

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(80,130,0);
  glScalef(0.3,0.3,1);
  for(i=0;i<strlen(str);++i)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
  glPopMatrix();
  glFlush();
}

int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("Dino Jump");
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable( GL_BLEND );
  init();
	glutDisplayFunc(displayMenu);
	glutIdleFunc(idle);
  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);
	glutMainLoop();
	return 0;
}
