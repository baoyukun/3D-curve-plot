#include <QtOpenGL>
#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{
    dMax=0;
    xRot =0; yRot =0; zRot =0;
    xtran=0; ytran=0;
    scal=1;

    QVector<double> rl(7), gl(7), bl(7);
    rl[0]=1.0; rl[1]=1.0; rl[2]=1.0; rl[3]=0.0; rl[4]=0.0; rl[5]=0.0; rl[6]=1.0;
    gl[0]=0.0; gl[1]=0.5; gl[2]=1.0; gl[3]=1.0; gl[4]=0.0; gl[5]=1.0; gl[6]=0.0;
    bl[0]=0.0; bl[1]=0.0; bl[2]=0.0; bl[3]=0.0; bl[4]=1.0; bl[5]=1.0; bl[6]=1.0;
    r=rl; g=gl; b=bl;
}

MyGLWidget::~MyGLWidget(){}

void MyGLWidget::setData(QVector<double> x, QVector<double> y, QVector<double> z)
{
    dSize=x.size(); dx=x; dy=y; dz=z;
    for (int i=0;i<dSize;i++)
    {
        dMax=qMax(dMax,dx.at(i));
        dMax=qMax(dMax,dy.at(i));
        dMax=qMax(dMax,dz.at(i));
    }
}

void MyGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
}

void MyGLWidget::resizeGL(int width, int height)
{
    int border=qMax(width,height);
    glViewport((width-border)/2, (height-border)/2, border, border);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dMax*1.5, +dMax*1.5, -dMax*1.5, +dMax*1.5, -dMax*10.0, dMax*10.0);
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glScalef(scal,scal,scal);
    glTranslatef(xtran, ytran, 0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    qglClearColor(Qt::gray);
    glBegin(GL_LINES);
      glColor3f(0.0f,0.0f,0.0f);
      glVertex3f(-dMax, 0.0f, 0.0f);
      glVertex3f(dMax,0.0f, 0.0f);

      glVertex3f(dMax,0.0f, 0.0f);
      glVertex3f(dMax-0.05*dMax,0.05*dMax, 0.0f);
      glVertex3f(dMax,0.0f, 0.0f);
      glVertex3f(dMax-0.05*dMax,-0.05*dMax, 0.0f);

      glColor3f(0.0f,0.0f,0.0f);
      glVertex3f(0, -dMax, 0.0f);
      glVertex3f(0,dMax, 0.0f);

      glVertex3f(0,dMax, 0.0f);
      glVertex3f(0.05*dMax,dMax-0.05*dMax, 0.0f);
      glVertex3f(0,dMax, 0.0f);
      glVertex3f(-0.05*dMax,dMax-0.05*dMax, 0.0f);

      glColor3f(0.0f,0.0f,0.0f);
      glVertex3f(0, 0, -dMax);
      glVertex3f(0, 0, dMax);

      glVertex3f(0,0, dMax);
      glVertex3f(0,0.05*dMax, dMax-0.05*dMax);
      glVertex3f(0,0, dMax);
      glVertex3f(0,-0.05*dMax, dMax-0.05*dMax);
    glEnd();

    glBegin(GL_LINES);
      glColor3f(1.0f,1.0f,1.0f);

      glVertex3f(-dMax*1.1, -dMax*1.1, -dMax*1.1);
      glVertex3f(-dMax*1.1, -dMax*1.1, dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, -dMax*1.1);
      glVertex3f(-dMax*1.1, -dMax*1.1, -dMax*1.1);
      glVertex3f(-dMax*1.1, -dMax*1.1, -dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, -dMax*1.1);

      glVertex3f(+dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, -dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, +dMax*1.1);

      glVertex3f(-dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, -dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, +dMax*1.1);
      glVertex3f(-dMax*1.1, -dMax*1.1, +dMax*1.1);

      glVertex3f(-dMax*1.1, -dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, +dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, -dMax*1.1);
      glVertex3f(+dMax*1.1, -dMax*1.1, -dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, -dMax*1.1);
      glVertex3f(+dMax*1.1, +dMax*1.1, -dMax*1.1);
      glVertex3f(-dMax*1.1, +dMax*1.1, -dMax*1.1);
    glEnd();

    int i=1, j;
    while (i<dSize)
    {
        j=floor(i*1.0/dSize*7);
        glBegin(GL_LINES);
           glColor3f(r.at(j),g.at(j),b.at(j));
           glVertex3f( dx.at(i-1), dy.at(i-1), dz.at(i-1));
           glVertex3f( dx.at(i),   dy.at(i),   dz.at(i));
        glEnd();
        i++;
    }
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_1) setXRotation(xRot + 18);
    if (e->key() == Qt::Key_2) setYRotation(yRot + 18);
    if (e->key() == Qt::Key_3) setZRotation(zRot + 18);

    if (e->key() == Qt::Key_W) setYtran(dMax/10);
    if (e->key() == Qt::Key_S) setYtran(-dMax/10);
    if (e->key() == Qt::Key_A) setXtran(-dMax/10);
    if (e->key() == Qt::Key_D) setXtran(dMax/10);

    if (e->key() == Qt::Key_Q) setScale(0.1);
    if (e->key() == Qt::Key_E) setScale(-0.1);
}

void MyGLWidget::wheelEvent(QWheelEvent *e)
{
    if (e->delta()>0) setScale(0.1);
    if (e->delta()<0) setScale(-0.1);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setXtran(double x)
{
    xtran+=x;
    updateGL();
}

void MyGLWidget::setYtran(double x)
{
    ytran+=x;
    updateGL();
}

void MyGLWidget::setScale(double x)
{
    scal*=(1+x);
    updateGL();
}
