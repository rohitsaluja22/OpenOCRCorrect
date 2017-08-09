#ifndef CONNECTEDSLIDERS_H
#define CONNECTEDSLIDERS_H

#include <QSlider>
#include <QVBoxLayout>

class ConnectedSliders : public QWidget
{
    Q_OBJECT

public:
    ConnectedSliders(QWidget *parent = 0);
    ~ConnectedSliders();
     QSlider* slider;

private:

    QVBoxLayout* layout;
};

#endif // CONNECTEDSLIDERS_H
