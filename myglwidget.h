#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
    void setData(QVector<double> , QVector<double>, QVector<double>);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    void setXtran(double x);
    void setYtran(double x);

    void setScale(double x);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    double xRot, yRot, zRot;
    double xtran, ytran;
    double scal;
    double dMax;
    QVector<double> dx, dy, dz, r, g, b;
    int dSize;
    QPoint lastPos;
};

#endif // MYGLWIDGET_H

