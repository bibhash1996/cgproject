GLfloat house[3][9] = {{150.0,150.0,225.0,300.0,300.0,200.0,200.0,250.0,250.0},{150.0,250.0,300.0,250.0,150.0,150.0,200.0,200.0,150.0},{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=150.0;
GLfloat k=150.0;
GLfloat theta1=90.0;
void multiply()
{
     int i,j,l;
     for(i=0;i<3;i++)
     for(j=0;j<9;j++)
     {
                     result[i][j]=0;
                     for(l=0;l<3;l++)
                     result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
     }
}
int rotate()
{
	GLfloat m,n;
	m=-h*(cos(theta1)-1)+k*(sin(theta1));
	n=-k*(cos(theta1)-1)-h*(sin(theta1));
    rot_mat[0][0]=cos(theta1);
    rot_mat[0][1]=-sin(theta1);
    rot_mat[0][2]=m;
    rot_mat[1][0]=sin(theta1);
    rot_mat[1][1]=cos(theta1);
    rot_mat[1][2]=n;
    rot_mat[2][0]=0;
    rot_mat[2][1]=0;
    rot_mat[2][2]=1;
    multiply();
 return 0;
 }


void rhouse()
{
     glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(result[0][0],result[1][0]);
	glVertex2f(result[0][1],result[1][1]);
	glVertex2f(result[0][3],result[1][3]);
	glVertex2f(result[0][4],result[1][4]);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(result[0][5],result[1][5]);
	glVertex2f(result[0][6],result[1][6]);
	glVertex2f(result[0][7],result[1][7]);
	glVertex2f(result[0][8],result[1][8]);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(result[0][1],result[1][1]);
	glVertex2f(result[0][2],result[1][2]);
	glVertex2f(result[0][3],result[1][3]);
	glEnd();
}
void dhouse()
{
     glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][0],house[1][0]);
	glVertex2f(house[0][1],house[1][1]);
	glVertex2f(house[0][3],house[1][3]);
	glVertex2f(house[0][4],house[1][4]);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][5],house[1][5]);
	glVertex2f(house[0][6],house[1][6]);
	glVertex2f(house[0][7],house[1][7]);
	glVertex2f(house[0][8],house[1][8]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][1],house[1][1]);
	glVertex2f(house[0][2],house[1][2]);
	glVertex2f(house[0][3],house[1][3]);
	glEnd();
}
void display1()
{

	glClear(GL_COLOR_BUFFER_BIT);
	dhouse();
	rotate();
	rhouse();
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);

}
