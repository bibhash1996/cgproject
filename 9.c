float xo1,x2,x3,x4,yo1,y2,y3,y4;

void edgedetect(GLfloat xo1, GLfloat yo1, GLfloat x2, GLfloat y2,GLint *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-yo1)<0)	
	{
		temp=yo1;yo1=y2;y2=temp;
		temp=xo1;xo1=x2;x2=temp;
	}
	if((y2-yo1)!=0)	
		mx=(x2-xo1)/(y2-yo1);
	else
		mx=x2-xo1;
	x=xo1;
	for(i=yo1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}
void draw_pixels(GLint x, GLint y, GLfloat v)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void scanfill(float xo1,float yo1, float x2, float y2,float x3, float y3,float x4, float y4)
{
	int le[500],re[500];
	int i,scanline;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
    edgedetect(xo1,yo1,x2,y2,le,re);	
    edgedetect(x2,y2,x3,y3,le,re);	
    edgedetect(x3,y3,x4,y4,le,re);	
    edgedetect(x4,y4,xo1,yo1,le,re);	
	for(scanline=0; scanline<500; scanline++)
	{
		if(le[scanline]<=re[scanline])
		    for(i=(int)le[scanline];i<(int)re[scanline];i++)
			draw_pixels(i,scanline,0);		
	}

}
void display6()
{
     xo1=200.0;yo1=200.0;x2=100.0;y2=300.0;x3=200.0;y3=400.0;x4=300.0;y4=300.0;
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xo1,yo1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
	scanfill(xo1,yo1,x2,y2,x3,y3,x4,y4);
	glFlush();
}
void myinit2()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
