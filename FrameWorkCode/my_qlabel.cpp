#include "my_qlabel.h"

my_qlabel::my_qlabel(QWidget *parent) :
    QLabel(parent)
{
}

void my_qlabel::mouseMoveEvent(QMouseEvent *ev){
qDebug() << "here11" << endl;

}
