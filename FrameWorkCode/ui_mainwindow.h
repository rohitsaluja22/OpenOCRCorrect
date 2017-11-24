/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionNew;
    QAction *actionSpell_Check;
    QAction *actionLoad_Next_Page;
    QAction *actionLoad_Prev_Page;
    QAction *actionLoadGDocPage;
    QAction *actionToDevanagari;
    QAction *actionLoadData;
    QAction *actionLoadDict;
    QAction *actionLoadOCRWords;
    QAction *actionLoadDomain;
    QAction *actionLoadSubPS;
    QAction *actionLoadConfusions;
    QAction *actionSugg;
    QAction *actionCreateBest2OCR;
    QAction *actionToSlp1;
    QAction *actionCreateSuggestionLog;
    QAction *actionCreateSuggestionLogNearestPriority;
    QAction *actionErrorDetectionRep;
    QAction *actionErrorDetectWithoutAdaptation;
    QAction *actionCPair;
    QAction *actionToSlp1_2;
    QAction *actionToDev;
    QAction *actionExtractDev;
    QAction *actionPrimarySecOCRPair;
    QAction *actionCPairIEROcrVsCorrect;
    QAction *actionEditDistRep;
    QAction *actionConfusionFreqHist;
    QAction *actionCPairGEROcrVsCorrect;
    QAction *actionFilterOutGT50EditDisPairs;
    QAction *actionPrepareFeatures;
    QAction *actionErrorDetectionRepUniq;
    QAction *actionSanskrit;
    QAction *actionHindi;
    QAction *actionEnglish;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuOCR_Correction_Window;
    QMenu *menuCreateReports;
    QMenu *menuSaveVariables;
    QMenu *menuConvertFiles;
    QMenu *menuFeatureExtraction;
    QMenu *menuSelectLanguage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1369, 736);
        MainWindow->setMouseTracking(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon3);
        actionSpell_Check = new QAction(MainWindow);
        actionSpell_Check->setObjectName(QStringLiteral("actionSpell_Check"));
        actionLoad_Next_Page = new QAction(MainWindow);
        actionLoad_Next_Page->setObjectName(QStringLiteral("actionLoad_Next_Page"));
        actionLoad_Prev_Page = new QAction(MainWindow);
        actionLoad_Prev_Page->setObjectName(QStringLiteral("actionLoad_Prev_Page"));
        actionLoadGDocPage = new QAction(MainWindow);
        actionLoadGDocPage->setObjectName(QStringLiteral("actionLoadGDocPage"));
        actionToDevanagari = new QAction(MainWindow);
        actionToDevanagari->setObjectName(QStringLiteral("actionToDevanagari"));
        actionLoadData = new QAction(MainWindow);
        actionLoadData->setObjectName(QStringLiteral("actionLoadData"));
        actionLoadDict = new QAction(MainWindow);
        actionLoadDict->setObjectName(QStringLiteral("actionLoadDict"));
        actionLoadOCRWords = new QAction(MainWindow);
        actionLoadOCRWords->setObjectName(QStringLiteral("actionLoadOCRWords"));
        actionLoadDomain = new QAction(MainWindow);
        actionLoadDomain->setObjectName(QStringLiteral("actionLoadDomain"));
        actionLoadSubPS = new QAction(MainWindow);
        actionLoadSubPS->setObjectName(QStringLiteral("actionLoadSubPS"));
        actionLoadConfusions = new QAction(MainWindow);
        actionLoadConfusions->setObjectName(QStringLiteral("actionLoadConfusions"));
        actionSugg = new QAction(MainWindow);
        actionSugg->setObjectName(QStringLiteral("actionSugg"));
        actionCreateBest2OCR = new QAction(MainWindow);
        actionCreateBest2OCR->setObjectName(QStringLiteral("actionCreateBest2OCR"));
        actionToSlp1 = new QAction(MainWindow);
        actionToSlp1->setObjectName(QStringLiteral("actionToSlp1"));
        actionCreateSuggestionLog = new QAction(MainWindow);
        actionCreateSuggestionLog->setObjectName(QStringLiteral("actionCreateSuggestionLog"));
        actionCreateSuggestionLogNearestPriority = new QAction(MainWindow);
        actionCreateSuggestionLogNearestPriority->setObjectName(QStringLiteral("actionCreateSuggestionLogNearestPriority"));
        actionErrorDetectionRep = new QAction(MainWindow);
        actionErrorDetectionRep->setObjectName(QStringLiteral("actionErrorDetectionRep"));
        actionErrorDetectWithoutAdaptation = new QAction(MainWindow);
        actionErrorDetectWithoutAdaptation->setObjectName(QStringLiteral("actionErrorDetectWithoutAdaptation"));
        actionCPair = new QAction(MainWindow);
        actionCPair->setObjectName(QStringLiteral("actionCPair"));
        actionToSlp1_2 = new QAction(MainWindow);
        actionToSlp1_2->setObjectName(QStringLiteral("actionToSlp1_2"));
        actionToDev = new QAction(MainWindow);
        actionToDev->setObjectName(QStringLiteral("actionToDev"));
        actionExtractDev = new QAction(MainWindow);
        actionExtractDev->setObjectName(QStringLiteral("actionExtractDev"));
        actionPrimarySecOCRPair = new QAction(MainWindow);
        actionPrimarySecOCRPair->setObjectName(QStringLiteral("actionPrimarySecOCRPair"));
        actionCPairIEROcrVsCorrect = new QAction(MainWindow);
        actionCPairIEROcrVsCorrect->setObjectName(QStringLiteral("actionCPairIEROcrVsCorrect"));
        actionEditDistRep = new QAction(MainWindow);
        actionEditDistRep->setObjectName(QStringLiteral("actionEditDistRep"));
        actionConfusionFreqHist = new QAction(MainWindow);
        actionConfusionFreqHist->setObjectName(QStringLiteral("actionConfusionFreqHist"));
        actionCPairGEROcrVsCorrect = new QAction(MainWindow);
        actionCPairGEROcrVsCorrect->setObjectName(QStringLiteral("actionCPairGEROcrVsCorrect"));
        actionFilterOutGT50EditDisPairs = new QAction(MainWindow);
        actionFilterOutGT50EditDisPairs->setObjectName(QStringLiteral("actionFilterOutGT50EditDisPairs"));
        actionPrepareFeatures = new QAction(MainWindow);
        actionPrepareFeatures->setObjectName(QStringLiteral("actionPrepareFeatures"));
        actionErrorDetectionRepUniq = new QAction(MainWindow);
        actionErrorDetectionRepUniq->setObjectName(QStringLiteral("actionErrorDetectionRepUniq"));
        actionSanskrit = new QAction(MainWindow);
        actionSanskrit->setObjectName(QStringLiteral("actionSanskrit"));
        actionHindi = new QAction(MainWindow);
        actionHindi->setObjectName(QStringLiteral("actionHindi"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(500, 16777215));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(progressBar);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(120, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("FreeSans"));
        font.setItalic(true);
        textEdit->setFont(font);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit->setReadOnly(true);

        horizontalLayout->addWidget(textEdit);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QFont font1;
        font1.setFamily(QStringLiteral("Shobhika"));
        font1.setPointSize(24);
        font1.setItalic(false);
        textBrowser->setFont(font1);
        textBrowser->setMouseTracking(true);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setUndoRedoEnabled(true);
        textBrowser->setReadOnly(false);
        textBrowser->setAcceptRichText(true);
        textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(textBrowser);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setRenderHints(QPainter::NonCosmeticDefaultPen);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);

        horizontalLayout->addWidget(graphicsView);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        lineEdit->raise();
        progressBar->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1369, 22));
        menuOCR_Correction_Window = new QMenu(menuBar);
        menuOCR_Correction_Window->setObjectName(QStringLiteral("menuOCR_Correction_Window"));
        menuCreateReports = new QMenu(menuBar);
        menuCreateReports->setObjectName(QStringLiteral("menuCreateReports"));
        menuSaveVariables = new QMenu(menuBar);
        menuSaveVariables->setObjectName(QStringLiteral("menuSaveVariables"));
        menuConvertFiles = new QMenu(menuBar);
        menuConvertFiles->setObjectName(QStringLiteral("menuConvertFiles"));
        menuFeatureExtraction = new QMenu(menuBar);
        menuFeatureExtraction->setObjectName(QStringLiteral("menuFeatureExtraction"));
        menuSelectLanguage = new QMenu(menuBar);
        menuSelectLanguage->setObjectName(QStringLiteral("menuSelectLanguage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(textBrowser, graphicsView);

        menuBar->addAction(menuSelectLanguage->menuAction());
        menuBar->addAction(menuOCR_Correction_Window->menuAction());
        menuBar->addAction(menuCreateReports->menuAction());
        menuBar->addAction(menuSaveVariables->menuAction());
        menuBar->addAction(menuConvertFiles->menuAction());
        menuBar->addAction(menuFeatureExtraction->menuAction());
        menuOCR_Correction_Window->addAction(actionNew);
        menuOCR_Correction_Window->addAction(actionOpen);
        menuOCR_Correction_Window->addAction(actionSave);
        menuOCR_Correction_Window->addAction(actionSave_As);
        menuOCR_Correction_Window->addAction(actionSpell_Check);
        menuOCR_Correction_Window->addAction(actionLoad_Next_Page);
        menuOCR_Correction_Window->addAction(actionLoad_Prev_Page);
        menuOCR_Correction_Window->addSeparator();
        menuOCR_Correction_Window->addAction(actionLoadGDocPage);
        menuOCR_Correction_Window->addAction(actionToDevanagari);
        menuOCR_Correction_Window->addAction(actionLoadData);
        menuOCR_Correction_Window->addAction(actionLoadDict);
        menuOCR_Correction_Window->addAction(actionLoadOCRWords);
        menuOCR_Correction_Window->addAction(actionLoadDomain);
        menuOCR_Correction_Window->addAction(actionLoadSubPS);
        menuOCR_Correction_Window->addAction(actionLoadConfusions);
        menuOCR_Correction_Window->addAction(actionSugg);
        menuOCR_Correction_Window->addAction(actionToSlp1);
        menuCreateReports->addAction(actionCreateBest2OCR);
        menuCreateReports->addAction(actionCreateSuggestionLog);
        menuCreateReports->addAction(actionCreateSuggestionLogNearestPriority);
        menuCreateReports->addAction(actionErrorDetectionRep);
        menuCreateReports->addAction(actionErrorDetectWithoutAdaptation);
        menuCreateReports->addAction(actionErrorDetectionRepUniq);
        menuSaveVariables->addAction(actionCPair);
        menuSaveVariables->addAction(actionPrimarySecOCRPair);
        menuSaveVariables->addAction(actionCPairIEROcrVsCorrect);
        menuSaveVariables->addAction(actionCPairGEROcrVsCorrect);
        menuConvertFiles->addAction(actionToSlp1_2);
        menuConvertFiles->addAction(actionToDev);
        menuConvertFiles->addAction(actionExtractDev);
        menuConvertFiles->addAction(actionEditDistRep);
        menuConvertFiles->addAction(actionConfusionFreqHist);
        menuConvertFiles->addAction(actionFilterOutGT50EditDisPairs);
        menuFeatureExtraction->addAction(actionPrepareFeatures);
        menuSelectLanguage->addAction(actionSanskrit);
        menuSelectLanguage->addAction(actionHindi);
        menuSelectLanguage->addAction(actionEnglish);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addAction(actionLoadData);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSpell_Check);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoad_Prev_Page);
        mainToolBar->addAction(actionLoad_Next_Page);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoadGDocPage);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSanskrit);
        mainToolBar->addAction(actionEnglish);
        mainToolBar->addAction(actionHindi);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToDevanagari);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionSpell_Check->setText(QApplication::translate("MainWindow", "Spell Check(CntrlShftC)", 0));
        actionSpell_Check->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", 0));
        actionLoad_Next_Page->setText(QApplication::translate("MainWindow", "Page(CntlShiftR)>>", 0));
#ifndef QT_NO_TOOLTIP
        actionLoad_Next_Page->setToolTip(QApplication::translate("MainWindow", "Page(CntlShiftR)>>", 0));
#endif // QT_NO_TOOLTIP
        actionLoad_Next_Page->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+R", 0));
        actionLoad_Prev_Page->setText(QApplication::translate("MainWindow", "<<Page(CntrlShftL)", 0));
#ifndef QT_NO_TOOLTIP
        actionLoad_Prev_Page->setToolTip(QApplication::translate("MainWindow", "<<Page(CntrlShftL)", 0));
#endif // QT_NO_TOOLTIP
        actionLoad_Prev_Page->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", 0));
        actionLoadGDocPage->setText(QApplication::translate("MainWindow", "Save&LoadPWords(CntrlShftP)", 0));
        actionLoadGDocPage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", 0));
        actionToDevanagari->setText(QApplication::translate("MainWindow", "toDevanagari(CntrlD)", 0));
        actionToDevanagari->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionLoadData->setText(QApplication::translate("MainWindow", "LoadData", 0));
        actionLoadDict->setText(QApplication::translate("MainWindow", "LoadDict", 0));
        actionLoadOCRWords->setText(QApplication::translate("MainWindow", "LoadOCRWords", 0));
        actionLoadDomain->setText(QApplication::translate("MainWindow", "LoadDomain", 0));
        actionLoadSubPS->setText(QApplication::translate("MainWindow", "LoadSubPS", 0));
        actionLoadConfusions->setText(QApplication::translate("MainWindow", "LoadConfusions", 0));
        actionSugg->setText(QApplication::translate("MainWindow", "sugg", 0));
        actionSugg->setShortcut(QApplication::translate("MainWindow", "Menu", 0));
        actionCreateBest2OCR->setText(QApplication::translate("MainWindow", "CreateBest2OCR", 0));
        actionToSlp1->setText(QApplication::translate("MainWindow", "toSlp1", 0));
        actionToSlp1->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        actionCreateSuggestionLog->setText(QApplication::translate("MainWindow", "CreateSuggestionLog", 0));
        actionCreateSuggestionLogNearestPriority->setText(QApplication::translate("MainWindow", "CreateSuggestionLogNearestPriority", 0));
        actionErrorDetectionRep->setText(QApplication::translate("MainWindow", "ErrorDetectionRep", 0));
        actionErrorDetectWithoutAdaptation->setText(QApplication::translate("MainWindow", "ErrorDetectWithoutAdaptation", 0));
        actionCPair->setText(QApplication::translate("MainWindow", "CPair", 0));
        actionToSlp1_2->setText(QApplication::translate("MainWindow", "toSlp1", 0));
        actionToDev->setText(QApplication::translate("MainWindow", "toDev", 0));
        actionExtractDev->setText(QApplication::translate("MainWindow", "ExtractDevWords", 0));
#ifndef QT_NO_TOOLTIP
        actionExtractDev->setToolTip(QApplication::translate("MainWindow", "ExtractDevWords", 0));
#endif // QT_NO_TOOLTIP
        actionPrimarySecOCRPair->setText(QApplication::translate("MainWindow", "PrimarySecOCRPairs", 0));
        actionCPairIEROcrVsCorrect->setText(QApplication::translate("MainWindow", "CPairIEROcrVsCorrect", 0));
        actionEditDistRep->setText(QApplication::translate("MainWindow", "EditDistRep", 0));
        actionConfusionFreqHist->setText(QApplication::translate("MainWindow", "ConfusionFreqHist", 0));
        actionCPairGEROcrVsCorrect->setText(QApplication::translate("MainWindow", "CPairGEROcrVsCorrect", 0));
        actionFilterOutGT50EditDisPairs->setText(QApplication::translate("MainWindow", "FilterOutGT50EditDisPairs", 0));
        actionPrepareFeatures->setText(QApplication::translate("MainWindow", "PrepareFeatures", 0));
        actionErrorDetectionRepUniq->setText(QApplication::translate("MainWindow", "ErrorSuggRepUniq", 0));
        actionSanskrit->setText(QApplication::translate("MainWindow", "Sanskrit", 0));
        actionHindi->setText(QApplication::translate("MainWindow", "Hindi/Marathi", 0));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", 0));
#ifndef QT_NO_TOOLTIP
        actionEnglish->setToolTip(QApplication::translate("MainWindow", "English", 0));
#endif // QT_NO_TOOLTIP
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:24pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">Please Select the Language from top left menu before loading any document.</span></p></body></html>", 0));
        menuOCR_Correction_Window->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuCreateReports->setTitle(QApplication::translate("MainWindow", "CreateReports", 0));
        menuSaveVariables->setTitle(QApplication::translate("MainWindow", "SaveVariables", 0));
        menuConvertFiles->setTitle(QApplication::translate("MainWindow", "ConvertFiles", 0));
        menuFeatureExtraction->setTitle(QApplication::translate("MainWindow", "FeatureExtraction", 0));
        menuSelectLanguage->setTitle(QApplication::translate("MainWindow", "SelectLanguage", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
