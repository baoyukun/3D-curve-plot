#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("On a réussi~~单击3D界面，旋转：123或鼠标拖动；缩放：QE或鼠标滚轮；移动：WASD。");
    w.show();

    return a.exec();
}
