#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class my_qlabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_qlabel(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);


signals:
    void mouse_Pressed();
    void mouse_Pos();
    void mouse_Left();

public slots:

};

#endif // MY_QLABEL_H
