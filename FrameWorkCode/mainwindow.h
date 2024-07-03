#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QInputDialog>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include<string>
#include<QFontDialog>
#include<QFont>
#include<QFile>
//#include<hash_map>
#include <unordered_map>
//#include <std::codecvt>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <QAction>
#include <QtDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
#include <QPlainTextEdit>
//#include "toFromslp1.h"
#include "zoom.h"
#include<QMessageBox>
#include<QTime>
//#include"staticDict.h"
//#include "lcsqt.h"


//#include <set>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    //void textChangedSlot();

private slots:

    //Changes by Kaushal-04
    void on_actionBold_triggered();
    void on_actionUnbold_triggered();
    void on_actionSubscript_triggered();
    void on_actionSuperscript_triggered();


    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionSpell_Check_triggered();

    void mousePressEvent(QMouseEvent *ev);

    //void mouseMoveEvent(QMouseEvent *event);

    void menuSelection(QAction* action);

    //void mouseMoveEvent(QMouseEvent* e) override { e->ignore(); }

    //bool eventFilter(QObject *object, QEvent *event);


    void on_actionLoad_Next_Page_triggered();

    void on_actionLoad_Prev_Page_triggered();

    void on_actionLoadGDocPage_triggered();

    void on_actionToDevanagari_triggered();

    void on_actionLoadData_triggered();

    void on_actionLoadDict_triggered();

    void on_actionLoadOCRWords_triggered();

    void on_actionLoadDomain_triggered();

    void on_actionLoadSubPS_triggered();

    void on_actionLoadConfusions_triggered();

    void on_actionSugg_triggered();

    void on_actionCreateBest2OCR_triggered();

    void on_actionToSlp1_triggered();

    void on_actionCreateSuggestionLog_triggered();

    void on_actionCreateSuggestionLogNearestPriority_triggered();

    void on_actionErrorDetectionRep_triggered();

    void on_actionErrorDetectWithoutAdaptation_triggered();

    void on_actionCPair_triggered();

    void on_actionToSlp1_2_triggered();

    void on_actionToDev_triggered();

    void on_actionExtractDev_triggered();

    void on_actionPrimarySecOCRPair_triggered();

    void on_actionCPairIEROcrVsCorrect_triggered();

    void on_actionEditDistRep_triggered();

    void on_actionConfusionFreqHist_triggered();

    void on_actionCPairGEROcrVsCorrect_triggered();

    //void on_actionCPairGEROcrVsCorrectSeparate_triggered();

    void on_actionFilterOutGT50EditDisPairs_triggered();

    void on_actionPrepareFeatures_triggered();

    void on_actionErrorDetectionRepUniq_triggered();

    void on_actionSanskrit_triggered();

    void on_actionHindi_triggered();

    void on_actionEnglish_triggered();

private:
    Ui::MainWindow *ui;

    QString mFilename;
    QString mFilenamejpeg;
};

#endif // MAINWINDOW_H
