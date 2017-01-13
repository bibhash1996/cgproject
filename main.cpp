#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>


#include"1.c"
#include"2.c"
#include"3.c"
#include"4.c"
#include"5.c"
#include"6.c"
#include"7.c"
#include"8.c"
#include"9.c"
#include"10.c"
#include"11.cpp"

void Write1(char *string)                                                //to write the string passed as parameter
{
    while(*string)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void Write2(char *string)                                               //to write the string passed as parameter
{
    while(*string)
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}

void OnMouseClick(int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                //if left button of the mouse is pressed
  {

     if(x>25&&x<275&&y>15&&y<45)                                       //if position of mouse lies between the first button coordinates
     {
           //printf("bibhash");
            glBegin(GL_POLYGON);                                       //to draw the polygon using the following coordinates
        	glColor3f (0.9,0.9, 0.9);                                  //set the color
        	glVertex2f(-0.45,0.85);
        	glVertex2f(-0.95,0.85);
        	glVertex2f(-0.95,0.95);
        	glVertex2f(-0.45,0.95);
        	glEnd();                                                   //to end drawing the polygon
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);      //define the display mode
        	glutInitWindowSize(700,600);                               //choose the window size
        	glutInitWindowPosition(400,100);                           //establish the window position
        	glutCreateWindow("3D Gasket");                             //create the window
            glutDisplayFunc(display2);                                 //for display callback
        	init();
        	glEnable(GL_DEPTH_TEST);                                   //enables an openGL feature
        	glClearColor(1.0,1.0,1.0,1.0);                             //set the present RGBA clear color
        	glutMainLoop();

     }
     if(x>25&&x<275&&y>75&&y<105)                                      //if position of mouse lies between the second button coordinates
     {

        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);          //define the display mode
    	glutInitWindowSize(700,600);                                   //choose the window size
    	glutInitWindowPosition(400,100);                               //establish the window position
    	glutCreateWindow("Teapot");                                    //create the window
    	glutDisplayFunc(display3);                                     //for display callback
    	glEnable(GL_LIGHTING);                                         //enables an openGL feature
    	glEnable(GL_LIGHT0);
    	glShadeModel(GL_SMOOTH);                                       //selects shade mode
    	glEnable(GL_DEPTH_TEST);                                       //enables an openGL feature
    	glEnable(GL_NORMALIZE);
    	glClearColor(0.1f,0.1f,0.1f,0.0f);                             //sets the present RGBA clear color
    	glutMainLoop();

     }
     if(x>25&&x<275&&y>135&&y<165)                                       //if position of mouse lies between the third button coordinates
     {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);        //define the display mode
        glutInitWindowSize(700, 600);                                    //choose the window size
        glutInitWindowPosition(400,100);                                 //establish the window position
        glutCreateWindow("Color Cube");                                  //create the window
        glutReshapeFunc(myReshape);                                      //for myReshape callback
        glutDisplayFunc(display4);                                       //for display callback
        glutIdleFunc(spinCube);                                          //for spinCube callback
        glutMouseFunc(mouse);                                            //for mouse callback
        glEnable(GL_DEPTH_TEST);                                         //Enable hidden-surface removal
        glutMainLoop();

     }
     if(x>25&&x<275&&y>195&&y<225)                                        //if position of mouse lies between the fourth button coordinates
     {
        theta1=theta1*(3.14/180);                                         //specifies the angle of rotation
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
    	glutInitWindowSize(700,600);                                      //choose the window size
    	glutInitWindowPosition(400,100);                                  //establish the window position
    	glutCreateWindow("House");                                        //create the window
    	glutDisplayFunc(display1);                                        //for display callback
    	myinit();
    	glutMainLoop();
     }
     if(x>25&&x<275&&y>255&&y<285)                                        //if position of mouse lies between the fourth button coordinates
     {
        xz=50;yz=50;
    	xo=110;yo=110;
    	xmin=50;ymin=50;
    	xmax=100;ymax=100;
    	xvmin=200,yvmin=200;
       	xvmax=300;yvmax=300;
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
    	glutInitWindowSize(700,600);                                      //choose the window size
    	glutInitWindowPosition(400,100);                                  //establish the window position
    	glutCreateWindow("Cohen SutherLand");                             //create the window
    	glutDisplayFunc(display5);                                        //for display callback
    	myinit1();
    	glutMainLoop();

     }
     if(x>25&&x<275&&y>315&&y<345)                                        //if position of mouse lies between the fifth button coordinates
     {
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
    	glutInitWindowSize(700,600);                                      //choose the window size
    	glutInitWindowPosition(400,100);                                  //establish the window position
    	glutCreateWindow("Filling a Polygon using Scan-line Algorithm");  //create the window
    	glutDisplayFunc(display6);                                        //for display callback
    	myinit2();
    	glutMainLoop();

     }
     if(x>25&&x<275&&y>375&&y<405)                                        //if position of mouse lies between the sixth button coordinates
     {
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
    	glutInitWindowSize(700,600);                                      //choose the window size
    	glutInitWindowPosition(400,100);                                  //establish the window position
    	glutCreateWindow("Rectangular Mesh");                             //create the window
    	glutDisplayFunc(display7);                                        //for display callback
    	init2();
    	glutMainLoop();
     }
     if(x>25&&x<275&&y>435&&y<465)                                        //if position of mouse lies between the sixth button coordinates
     {
          printf("bibhash125");
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);             //define the display mode
	    glutInitWindowSize(700,600);                                      //choose the window size
	    glutInitWindowPosition(400,100);                                  //establish the window position
	    glutCreateWindow("Colorcube Viewer");                             //create the window
	    glutReshapeFunc(myReshape8);                                      //for myReshape callback
	    glutDisplayFunc(disp8);                                           //for display callback
	    glutMouseFunc(mouse8);                                            //for mouse callback
	    glutKeyboardFunc(keys8);                                          //for keyboard callback
	    glEnable(GL_DEPTH_TEST);                                          //enables an openGL feature
	    glutMainLoop();

     }
     //new button
    if(x>1001&&x<1200&&y>135&&y<165)                                        //if position of mouse lies between the sixth button coordinates
     {
        printf("bibhash");
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB | GLUT_DEPTH);                        //define the display mode
	    glutInitWindowPosition(400,100);                                  //establish the window position
	    glutInitWindowSize(700,600);                                      //choose the window size
	    glutCreateWindow("STACK AND QUEUE");                     //create the window
	    init11();
	    glutDisplayFunc(display11);
	    glutIdleFunc(idle11);
	    glutMouseFunc(mouse11);
	    glEnable(GL_DEPTH_TEST);                                      //for display callback
	    glutMainLoop();

     }


     if(x>25&&x<275&&y>495&&y<525)                                        //if position of mouse lies between the seventh button coordinates
     {
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
	    glutInitWindowPosition(400,100);                                  //establish the window position
	    glutInitWindowSize(700,600);                                      //choose the window size
	    glutCreateWindow("Cylinder & ParralelPiped");                     //create the window
	    init3();
	    glutDisplayFunc(display9);                                        //for display callback
	    glutMainLoop();
      }

     if(x>25&&x<275&&y>555&&y<585)                                        //if position of mouse lies between the eighth button coordinates
      {
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);                        //define the display mode
        glutInitWindowSize(700,600);                                      //choose the window size
        glutInitWindowPosition(400,100);                                  //establish the window position
        glutCreateWindow("Lian-Barsky");                                  //create the window
        glutDisplayFunc(disp2);                                           //for display callback
        init5();
        glutMainLoop();
      }

  }
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);                                         //clears the color buffer
	glColor3f (0.2,0.2,0.2);                                            //set the color
    glBegin(GL_POLYGON);                                                  //to draw the polygon using the following coordinates
	  glVertex2f(-0.4,-1.0);
	  glVertex2f(-1.0,-1.0);
	  glVertex2f(-1.0,1.0);
	  glVertex2f(-0.4,1.0);
	glEnd();                                                                //to end drawing the polygon

    glBegin(GL_POLYGON);                                                    //to draw the polygon using the following coordinates
      glColor3f (1.0,1.0,1.0);                                             //set the color
      glVertex2f(-0.4,1.0);
      glColor3f(0.95,0.89,1);                                               //set the color
	  glVertex2f(1.0,1.0);
	  glColor3f (1.0,1.0,1.0);                                             //set the color
	  glVertex2f(1.0,-1.0);
	  glColor3f(0.5,0.7,0.9);                                            //set the color
	  glVertex2f(-0.4,-1.0);
	glEnd();
   glColor3f (0.2,0.2,0.2);
    glBegin(GL_POLYGON);                                                  //to draw the polygon using the following coordinates
	  glVertex2f(0.7,-1.0);
	  glVertex2f(1.0,-1.0);
	  glVertex2f(1.0,1.0);
	  glVertex2f(0.7,1.0);
	glEnd();
  /*  glBegin(GL_LINE_LOOP);                                                  //to draw the border
      glVertex2f(-0.3,0.9);
	  glVertex2f(0.9,0.9);
	  glVertex2f(0.9,-0.9);
	  glVertex2f(-0.3,-0.9);
	glEnd();
	glBegin(GL_LINE_LOOP);                                                  //to draw the border
      glVertex2f(-0.28,0.87);
	  glVertex2f(0.88,0.87);
	  glVertex2f(0.88,-0.87);
	  glVertex2f(-0.28,-0.87);
	glEnd();*/

	glColor3f(0.3,0.1,0.4);                                                 //set the color
    glRasterPos2f(-0.255,0.67);                                             //to provide position for rasterization
    Write1("COMPUTER GRAPHICS PROJECT WITH OPENGL");
    glBegin(GL_LINES);                                                      //to underline
      glVertex2f(-0.255,0.663);
      glVertex2f(0.700,0.663);
    glEnd();
    glColor3f(0,0.2,0.4);                                                   //set the color
    glRasterPos2f(0.02,0.47);                                               //to provide position for rasterization
    Write1("A MENU BASED  PACKAGE");
    glBegin(GL_LINES);                                                      //to underline
      glVertex2f(0.02,0.463);
      glVertex2f(0.64,0.463);
    glEnd();
    glColor3f(0.6,0.2,0.7);                                                   //set the color
    glRasterPos2f(0.08,0.17);                                               //to provide position for rasterization
    Write2(" BY:");
    glColor3f(0.3,0.2,0.4);                                                 //set the color
    glRasterPos2f(0.08,-0.07);                                              //to provide position for rasterization
    Write1("NAME: BIBHASH SINGH ");
    glRasterPos2f(0.08,-0.17);
    Write1("REG NO:14GAEI6009");
    glRasterPos2f(0.08,-0.27);
    Write1("CLASS:V SEM ISE");
    glColor3f(0.8,0.1,0.2);                                                 //set the color
    glRasterPos2f(0.08,-0.53);                                              //to provide position for rasterization
    Write2(" GUIDE:");
    glRasterPos2f(0.08,-0.63);                                              //to provide position for rasterization
    Write1("Mrs.VIMALA H S");
    glRasterPos2f(-0.23,-0.73);                                             //to provide position for rasterization


    GLUquadricObj * quadricObj;	    	                                    //Creates a quadratic object
	quadricObj = gluNewQuadric();	                                     	//Sets a pointer to a new quadratic object
	gluQuadricDrawStyle(quadricObj, GLU_FILL);
	glPushMatrix();
    glColor3f (0.4,0.3,0.8);                                               //Sets ellipse color
    glTranslatef(-0.7,0.91,0.0);		                                   //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);                                            //Scales the ellipse
    //gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
	glRasterPos2f(-0.89,0.88);                                             //to provide position for rasterization
    Write1("TETRAHEDRON");

   	glColor3f (0.4,0.4,0.7);		                                      //Sets ellipse color
	glPushMatrix();
    glTranslatef(-0.7,0.7,0.0);	                                          //Translates the ellipse
	glScalef(0.35,0.089,0.0);	    	                                  //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                               //Sets ellipse color
    glRasterPos2f(-0.81,0.67);                                            //to provide position for rasterization
    Write1("TEAPOT");

    glColor3f (0.5,0.4,0.6);			                                  //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,0.5,0.0);	                                          //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);     	                                  //Scales the ellipse
    //gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                               //Sets ellipse color
	glRasterPos2f(-0.85,0.47);                                            //to provide position for rasterization
    Write1("COLOR CUBE");

    glColor3f (0.6,0.4,0.5);			                                  //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,0.3,0.0);	                                          //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);                                           //Scales the ellipse
   // gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
    glRasterPos2f(-0.79,0.27);                                             //to provide position for rasterization
    Write1("HOUSE");

    glColor3f (0.7,0.3,0.4);			                                   //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,0.1,0.0);	                                           //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		                                   //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
    glRasterPos2f(-0.95,0.07);                                             //to provide position for rasterization
    Write1("COHEN SUTHERLAND");

    glColor3f (0.8,0.45,0.0);			                                   //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,-0.9,0.0);                                           //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		                                   //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
    glRasterPos2f(-0.88,-0.93);                                            //to provide position for rasterization
    Write1("LIANG-BARSKY");

    glColor3f (0.9,0.4,0.1);			                                   //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,-0.7,0.0);                                           //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		    	                           //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Translates the ellipse
    glRasterPos2f(-0.97,-0.73);                                            //to provide position for rasterization
    Write1("CYLINDER AND IIPIPED");

    glColor3f (0.85,0.3,0.1);			                                   //Sets ellipse color
	glPushMatrix();
	glTranslatef(-0.7,-0.5,0.0);                                           //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		    	                           //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
    glRasterPos2f(-0.97,-0.53);                                            //to provide position for rasterization
    Write1("PERSPECTIVE VIEWING");

    glColor3f (0.85,0.2,0.1);		                                       //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,-0.3,0.0);                                           //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		                                   //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                                //Sets ellipse color
    glRasterPos2f(-0.77,-0.33);                                            //to provide position for rasterization
    Write1("MESH");

    glColor3f (0.8,0.1,0.1);			                                  //Sets ellipse color
    glPushMatrix();
	glTranslatef(-0.7,-0.1,0.0);                                          //Translates the ellipse
	glScalef(0.35, 0.089, 0.0);    		    	                          //Scales the ellipse
	//gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                               //Sets ellipse color
    glRasterPos2f(-0.90,-0.13);                                           //to provide position for rasterization
    Write1("SCANLINE AREA");

     //new button

    glColor3f (0.5,0.4,0.6);			                                  //Sets ellipse color
    glPushMatrix();
	glTranslatef(+0.84,0.5,0.0);	                                          //Translates the ellipse
	glScalef(0.15, 0.089, 0.0);     	                                  //Scales the ellipse
    //gluDisk(quadricObj, 0.0,0.75, 100, 100);
	glPopMatrix();
	glColor3f(1.0,1.0,1.0);                                               //Sets ellipse color
	glRasterPos2f(+0.80,0.48);                                            //to provide position for rasterization
    Write1("S&Q");
    glRasterPos2f(+0.75,0.2);
     Write2("(Stack ");
     glRasterPos2f(+0.75,0);
      Write2("and");
      glRasterPos2f(+0.75,-0.2);
      Write2("queue");
      glRasterPos2f(+0.75,-0.4);
      Write2("implementation)");
    glutSwapBuffers();
    glFlush();
 }

int main(int argc,char **argv)                                            //main function
{
   	glutInit(&argc,argv);                                                 //initializes GLUT
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);                            //defines the display mode
	glutInitWindowSize(1175,600);                                         //choose the window size
	glutInitWindowPosition(100,100);                                      //establish the window position
	glutCreateWindow("PROJECT MENU CHART");                               //create the window
	glutMouseFunc(OnMouseClick);                                          //for mouse callback
    glutDisplayFunc(display);                                             //for display callback
    glutMainLoop();
}

