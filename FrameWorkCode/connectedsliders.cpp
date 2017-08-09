#include "connectedsliders.h"


ConnectedSliders::ConnectedSliders(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Sliders");

    slider = new QSlider(Qt::Horizontal);

    slider->setMinimum(0);
    slider->setMaximum(100);

    auto layout = new QVBoxLayout(this);
    layout -> addWidget(slider);

}


ConnectedSliders::~ConnectedSliders(){}
