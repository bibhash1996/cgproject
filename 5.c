#define outcode int 
double xz,yz,xo,yo;
double xmax,ymax,xmin,ymin;

const int TOP=1;
const int BOTTAM=2;
const int RIGHT=4;
const int LEFT=8;

outcode computecode(double x,double y)
{
	outcode code=0;
	if(y>ymax)
	code |=TOP;
	if(y<ymin)
	code |=BOTTAM;
	if(x>xmax)
	code |=LEFT;
	return code;
}
void cohenclipanddraw(double xz,double yz,double xo,double yo)
{
	outcode outcode0,outcode1,outcodeout;
	double sx,sy,vx0,vy0,vx1,vy1;
	int accept=0,done=0;
	outcode0=computecode(xz,yz);
	outcode1=computecode(xo,yo);

	do
	{
		if(!(outcode0|outcode1))
		{
			accept=1;
			done=1;
		}
		else if(outcode0&outcode1)
			done=1;
		else
		{
			double x,y;
			outcodeout=outcode0?outcode0:outcode1;
			if(outcodeout&TOP)
			{
				x=xz+(xo-xz)*(ymax-yz)/(yo-yz);
				y=ymax;
			}
			else if(outcodeout&BOTTAM)
			{
				x=xz+(xo-xz)*(ymin-yz)/(yo-yz);
				y=ymin;
			}
			else if(outcodeout&RIGHT)
			{	
				y=yz+(yo-yz)*(xmax-xz)/(xo-xz);
				x=xmax;
			}
			else
			{	
				y=yz+(yo-yz)*(xmin-xz)/(xo-xz);
				x=xmin;
			}
			if(outcodeout==outcode0)
			{
				xz=x;yz=y;
				outcode0=computecode(xz,yz);
			}
			else
			{
				xo=x;yo=y;
				outcode1=computecode(xo,yo);
			}
		}
	}
	while(!done);

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin,yvmin);
		glVertex2f(xvmax,yvmin);
		glVertex2f(xvmax,yvmax);
		glVertex2f(xvmin,yvmax);
	glEnd();

	if(accept)
	{
		sx=(xvmax-xvmin)/(xmax-xmin);
	sy=(yvmax-yvmin)/(ymax-ymin);

	vx0=xvmin+(xz-xmin)*sx;
	vy0=yvmin+(yz-ymin)*sy;
	vx1=xvmin+(xo-xmin)*sx;
	vy1=yvmin+(yo-ymin)*sy;
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(vx0,vy0);
	glVertex2f(vx1,vy1);
	glEnd();
	}
}
void myinit1()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}

void display5()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(xz,yz);
		glVertex2f(xo,yo);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin,ymin);
		glVertex2f(xmax,ymin);
		glVertex2f(xmax,ymax);
		glVertex2f(xmin,ymax);
	glEnd();
    cohenclipanddraw(xz,yz,xo,yo);
	glFlush();
}
