#define true 1
#define false 0
double xmin2=50,ymin2=50,xmax2=100,ymax2=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
float X0,Y0,X1,Y1;
void init5()
{
     glClearColor(1.0,1.0,1.0,1.0);
     glColor3f(1.0,0.0,0.0);
     glPointSize(1.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,499.0,0.0,499.0);
}

int cliptest(double p,double q,double *t1,double *t2)
{
    double t=q/p;
    if(p<0.0)
    {
             if(t>*t1) *t1=t;
             if(t>*t2) return(false);
    }
    else
        if(p>0.0)
        {
                 if(t<*t2) *t2=t;
                 if(t<*t1) return(false);
        }
        else
            if(p==0.0)
            {
                          if(q<0.0) return(false);
            }
            return(true);
}
void Liang(double x0,double y0, double x1, double y1)
{
     GLdouble te=0.0,t1=1.0,dx1=x1-x0,dy1=y1-y0;
     glColor3f(1.0,0.0,0.0);

                            glBegin(GL_LINE_LOOP);
                            glVertex2f(xvmin,yvmin);
                            glVertex2f(xvmax,yvmin);
                            glVertex2f(xvmax,yvmax);
                            glVertex2f(xvmin,yvmax);
                            glEnd();
     if(cliptest(-dx1,x0-xmin2,&te,&t1))
      if(cliptest(dx1,xmax2-x0,&te,&t1))
       if(cliptest(-dy1,y0-ymin2,&te,&t1))
        if(cliptest(dy1,ymax2-y0,&te,&t1))
        {
                                      if(t1<1.0)
                                      {
                                                    x1=x0+t1*dx1;
                                                    y1=y0+t1*dy1;
                                      }
                                      if(te>0.0)
                                      {
                                                    x0=x0+te*dx1;
                                                    y0=y0+te*dy1;
                                      }
                                      printf("\n%f  %f:  %f  %f",x0,y0,x1,y1);
                                      double sx=(xvmax-xvmin)/(xmax2-xmin2);
                                      double sy=(yvmax-yvmin)/(ymax2-ymin2);
                                      double vx0=xvmin+(x0-xmin2)*sx;
                                      double vy0=yvmin+(y0-ymin2)*sy;
                                      double vx1=xvmin+(x1-xmin2)*sx;
                                      double vy1=yvmin+(y1-ymin2)*sy;
                                      glColor3f(0.0,0.0,1.0);
                                      glBegin(GL_LINES);
                                      glVertex2d(vx0,vy0);
                                      glVertex2d(vx1,vy1);
                                      glEnd();
      }
}
void disp2()
{

     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_LINES);
     glVertex2d(40,50);
     glVertex2d(40,100);
     glEnd();
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(xmin2,ymin2);
     glVertex2f(xmax2,ymin2);
     glVertex2f(xmax2,ymax2);
     glVertex2f(xmin2,ymax2);
     glEnd();
     Liang(40,50,40,100);
     glFlush();
}
