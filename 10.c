#define maxx 10
#define maxy 15
#define dx 15
#define dy 10
GLfloat xx[maxx]={0.0},yy[maxy]={0.0};
GLfloat xz1=50,yz1=50;
GLint i,j;

void init2()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
	//glutPostRedisplay();
}

void display7(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	for(i=0;i<maxx;i++)
	xx[i]=xz1+i*dx;
	for(j=0;j<maxy;j++)
	yy[j]=yz1+j*dy;

	glColor3f(1.0,0.0,0.0);
	for(i=0;i<maxx-1;i++)
	for(j=0;j<maxy-1;j++)
	{
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xx[i],yy[j]);
		glVertex2f(xx[i],yy[j+1]);
		glVertex2f(xx[i+1],yy[j+1]);
		glVertex2f(xx[i+1],yy[j]);
		glEnd();
		glFlush();
	}
}
