#include <windows.h>
#include <gl\gl.h>
#include <GL\glut.h>
#include<math.h>
#include <stdlib.h>
#include <C:\Dev-Cpp\include\GL\glut.h>


float windowesAngle = 0.0f;
float doorAngle = 0.0f;
float bikeAngle = 0.0f;
float xDir = -2.0f;
float cameraAngle1 = 0.0f;
float cameraAngle2 = 0.0f;
float cameraAngle3 = 0.0f;
const float bi =  3.1415926f;

GLfloat vertices[][3]={{-2.0,-3.0,-30.0},
                       {2.0,-3.0,-30.0},
                       {2.0,3.0,-30.0},
                       {-2.0,3.0,-30.0},
                       {-2.0,-3.0,-10.0},
                       {2.0,-3.0,-10.0},
                       {2.0,3.0,-10.0},
                       {-2.0,3.0,-10.0}};

                       

void myinit(void)
{
  glClearColor(0.7, 0.7, 0.7, 0.0); /* gray background */
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  //glPointSize(1.0);
  //gluOrtho2D( -B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
void drawCircle(float Xc, float Yc,float Zc, float r, int iter){
     glColor3f (0.0 , 0.0,  0.0);
     
     glBegin(GL_LINE_LOOP);
     for(int i = 0;i < iter;i++){
        float theta = 2.0f * bi * float(i) / float(iter);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + Xc, y + Yc,Zc);
        }
     glEnd();    
}
void shape(int a, int b, int c, int d){
	glBegin(GL_QUADS);
        glColor3fv(vertices[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(vertices[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(vertices[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(vertices[d]);
		glVertex3fv(vertices[d]);
	glEnd();
}
void drawHome(){
    shape(0,3,2,1);
	shape(2,3,7,6);
	shape(0,4,7,3);
	shape(1,2,6,5);
	shape(4,5,6,7);
	shape(0,1,5,4);
}
void drawRoof(){
    glColor3f(.4,.2,.5);
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f, 3.0f,-9.99f);
    glVertex3f(2.0f, 3.0f, -9.99f);
    glVertex3f(0.0f, 4.0f, -9.99f);
    glEnd();
    glPopMatrix();
}
void drawAlternateWindows(){
    glColor3f(1,.4,.3);
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);  
    glBegin(GL_QUADS);
    glVertex3f(.5f, 1.5f,-9.99f);
    glVertex3f(.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 1.5f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, 1.5f,-9.99f);
    glVertex3f(-.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 1.5f,-9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(0.0 ,0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, .4f,-9.99f);
    glVertex3f(-.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(.5f, .4f,-9.99f);
    glVertex3f(.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
}
void drawWindows(){
    glColor3f(.4,.2,.5);
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);  
    glBegin(GL_QUADS);
    glVertex3f(.5f, 1.5f,-9.99f);
    glVertex3f(.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 1.5f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, 1.5f,-9.99f);
    glVertex3f(-.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 1.5f,-9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle ,0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, .4f,-9.99f);
    glVertex3f(-.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(.5f, .4f,-9.99f);
    glVertex3f(.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
}
void drawDoor(){ 
 glPushMatrix();
 glTranslatef(.75f, 0.0f,-9.99f);
   glRotatef(doorAngle, 0.0f, 1.0f, 0.0f);
   glTranslatef(-.75f, 0.0f,9.99f);
     glBegin(GL_QUADS); 
    glColor3f(.6,.6,.6);
    glVertex3f(.75f, -1.2f,-9.99f);
    glVertex3f(.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -1.2f, -9.99f);  
    glEnd();
    glPopMatrix();
}
void drawAltrnateDoor(){ 
 glPushMatrix();
 glTranslatef(.75f, 0.0f,-9.99f);
   glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
   glTranslatef(-.75f, 0.0f,9.99f);
     glBegin(GL_QUADS); 
    glColor3f(0,0,1);
    glVertex3f(.75f, -1.2f,-9.99f);
    glVertex3f(.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -1.2f, -9.99f);  
    glEnd();
    glPopMatrix();
}
void drawbike(){
  glColor3f(1,1,1);
  glPushMatrix();
  //glTranslatef(3.0,-2.0f,-9.0f);
  //glRotatef(bikeAngle ,0.0f, 0.0f, 1.0f); 
  //glTranslatef(3.0 ,2.0f,9.0f);
  
  drawCircle(-3.0,-2.0,-9.0,.4,50);
  drawCircle(-3.0,-2.0,-9.0,.3,50);
  
  glBegin(GL_LINES);
    glVertex3f(-3.0,-1.7,-9.0);
    glVertex3f(-3.0,-2.3,-9.0);
    glVertex3f(-3.3,-2,-9.0);
    glVertex3f(-2.7,-2,-9.0);
    glEnd();
  glPopMatrix();
  
  glPushMatrix();
  //glTranslatef(2.0,-2.0f,-9.0f);
  //glRotatef(bikeAngle, 0.0f, 0.0f, 1.0f); 
  //glTranslatef(-2.0 ,2.0f,9.0f);
  
  drawCircle(-2.0,-2.0,-9.0,.4,50);
  drawCircle(-2.0,-2.0,-9.0,.3,50);
  
  glBegin(GL_LINES);
 
    glVertex3f(-2.3,-2,-9.0);
    glVertex3f(-1.7,-2,-9.0);
    glVertex3f(-2.0,-1.7,-9.0);
    glVertex3f(-2.0,-2.3,-9.0);
    glEnd();
  glPopMatrix();
  
   glLineWidth(4);
   //glTranslatef(1.5, -2.0f , -9.0f);
   //glRotatef(bikeAngle, 0.0f, 0.0f, 1.0f); 
   //glTranslatef(-1.5, -2.0f, -9.0f); 
    
    glBegin(GL_LINES);
    glVertex3f(-3.0,-1.6,-9.0);
    glVertex3f(-2.0,-1.6,-9.0);
    glVertex3f(-2.5,-1.6,-9.0);
    glVertex3f(-2.5,-1.4,-9.0);
    glVertex3f(-2.4,-1.4,-9.0);
    glVertex3f(-2.6,-1.4,-9.0);
    glVertex3f(-2.1,-1.6,-9.0);
    glVertex3f(-2.1,-1.0,-9.0);
    glVertex3f(-2.1,-1.0,-9.4);
    glVertex3f(-2.1,-1.0,-8.6);
    glEnd();   
}

void theShow(){
     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix();
     glMatrixMode(GL_MODELVIEW); 
     glClearColor(0.2,0.6,0.3,8.0);      
     glLoadIdentity(); 
 glTranslatef(0.0, 0.0f,-20.0f);	
 glRotatef(cameraAngle1, 0.0f, 1.0f, 0.0f);
 glRotatef(cameraAngle2, 1.0f, 0.0f, 0.0f);
 glTranslatef(0.0, 0.0f,20.0f);
     drawHome();
     drawAlternateWindows();
     drawWindows();
     drawAltrnateDoor();
     drawDoor();
     drawRoof();
     glPushMatrix();
  glTranslatef(xDir , 0.0f,0.0f); 
  glTranslatef(0.0, 0.0f,-20.0f);	
  glRotatef(cameraAngle3, 0.0f, 1.0f, 0.0f);
  glTranslatef(0.0, 0.0f,20.0f);
     drawbike();
     glPopMatrix();
     glFlush();
     glutSwapBuffers();
}

void keyboard(unsigned char Button,int x,int y){
     if(Button == 'f'){
          xDir += .01;   
          bikeAngle += .4;     
     }
     else if(Button == 'o'){
          if(doorAngle < 180)
                 doorAngle += 5;
         
     }
     else if(Button == 'c'){
           if(doorAngle > 0)
                 doorAngle -= 5;          
     }
      else if(Button == 'O'){
           if(windowesAngle < 180)
                 windowesAngle += 5;
     }
      else if(Button == 'C'){
           if(windowesAngle > 0)
                 windowesAngle -= 5;    
     }
     else if(Button == 'd'){
          cameraAngle1 += 4;
     }
     else if(Button == 'a'){
          cameraAngle1 -= 4;
     }
     else if(Button == 'w'){
          cameraAngle2 += 4;
     }
     else if(Button == 's'){
          cameraAngle2 -= 4;
     }    
     theShow();
}
void update(int value){
	 cameraAngle3 += 2.0f;
	if (cameraAngle3 > 360) {
		cameraAngle3 -= 360;
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 1);
}
void mouse(int btn, int state, int x, int y){
 if(btn==GLUT_RIGHT_BUTTON  ){ 
   update(2) ;
 }
 if(btn ==GLUT_LEFT_BUTTON  ) {
        update(1);
 }
	theShow();
 }


int main(int argc, char** argv){
    
    	
 glutInit(&argc,argv);
  glutInitWindowSize( 600, 600 );       /* A x A pixel screen window  */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("My Rectangle"); /* window title                   */
  
  glutDisplayFunc(theShow);         /* tell OpenGL main loop what     */     
  glutKeyboardFunc(keyboard);
 	glutMouseFunc(mouse);
  glutReshapeFunc(handleResize);
  myinit();                         /* set attributes                 */
  glutMainLoop(); 
	return 0;
}
