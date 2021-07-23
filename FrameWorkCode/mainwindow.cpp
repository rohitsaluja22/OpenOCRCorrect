#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eddis.h"
#include "slpNPatternDict.h" //as included through lcsqt.h
#include "trieEditdis.h"
#include "meanStdPage.h"
#include <math.h>





//gs -dNOPAUSE -dBATCH -sDEVICE=jpeg -r300 -sOutputFile='page-%00d.jpeg' Book.pdf
map<string, int> Dict, GBook, IBook, PWords, PWordsP,ConfPmap,ConfPmapFont,CPairRight;
trie TDict,TGBook,TGBookP, newtrie,TPWords,TPWordsP;
vector<string> vGBook,vIBook;
QImage imageOrig;
vector<QString> vs; vector<int> vx,vy,vw,vh;
map<string, vector<string>> SRules;
map<string, string> TopConfusions;
map<string, int> TopConfusionsMask;
bool prevTRig = 0;
//map<string, int> GPage; trie TGPage;
//map<string, int> PWords;//Common/Possitive OCR Words // already defined before
map<string, string> CPair;//Correction Pairs



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setMouseTracking(true);
    ui->textBrowser->installEventFilter(this);
    ui->textBrowser->setLineWrapColumnOrWidth(QTextEdit::NoWrap);
    //QObject::connect(ui->textBrowser,SIGNAL(textChanged()),this,SLOT(textChangedSlot()));
    // connect(ui->actionBold, &QAction::triggered, this, &MainWindow::on_actionBold_triggered);
    QString str = "SLP1 Guide:";
    str += "\n";
    str += "डॉ,, ड़,, ढ़,, अ   - a,, आ/ ा   - A,, इ/ ि   - i,, ई/ ी   - I,, उ/ ु   - u,, ऊ/ ू   - U,, ऋ/ ृ   - f,, ॠ/ ॄ   - F,, ऌ/ ॢ   - x,, ॡ/ \"ॣ\”   - X,, ए/ े   - e,, ऐ/ ै   - E,, ओ/ ो   - o,, औ/ ौ   - O,, ं   - M,, ः   - H,, ँ    - ~,, ऽ   - $,, ॐ   - %,, ज्ञ   - jYa ,, ळ ,, त्र   - tra,, श्र   - Sra,, क्ष्/क्ष   - kz/kza,, द्य्/द्य   - dy/dya,, क्/क   - k/ka,, ख्/ख   - K/Ka,, ग्/ग   - g/ga,, घ्/घ   - G/Ga,, ङ्/ङ   - N/Na,, च्/च   - c/ca,, छ्/छ   - C/Ca,, ज्/ज   - j/ja,, झ्/झ   - J/Ja,, ञ्/ञ   - Y/Ya,, ट्/ट   - w/wa,, ठ्/ठ   - W/Wa,, ड्/ड   - q/qa,, ढ्/ढ   - Q/Qa,, ण्/ण   - R/Ra,, त्/त   - t/ta,, थ्/थ   - T/Ta,, द्/द   - d/da,, ध्/ध   - D/Da,, न्/न   - n/na,, प्/प   - p/pa,, फ्/फ   - P/Pa,, ब्/ब   - b/ba,, भ्/भ   - B/Ba,, म्/म   - m/ma,, य्/य   - y/ya,, र्/र   - r/ra,, ल्/ल   - l/la,, व्/व   - v/va,, श्/श   - S/Sa,, ष्/ष   - z/za,, स्/स   - s/sa,, ह्/ह   - h/ha,, ळ्/ळ   - &/&a,, ऩ्  -%,, फ़्  - ^,, य़्  - L,, ऱ्  - V,,१   - 1,, २   - 2,, ३   - 3,, ४   - 4,, ५   - 5,, ६   - 6,, ७   - 7,, ८   - 8,, ९   - 9,, ०   - 0,, ।   - |,, ॥   - ||";

    str.replace(",, ", "\n");
   // str.replace(", ","\t");
    ui->textEdit->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}



/*

bool fileFlag = 0;
void MainWindow::on_actionLoad_Next_Page_triggered()
{   QString file = "";
    string localFilename = mFilenamejpeg.toUtf8().constData();
    string nos = "0123456789";
    size_t loc = localFilename.find(".jpeg");
    string s = localFilename.substr(loc-1,1);
    string no;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilename.substr(loc-1,1);  }
    //cout << stoi(no) + 1 << endl;
    localFilename.replace(loc,no.size(),to_string(stoi(no) + 1));

    mFilenamejpeg = QString::fromStdString(localFilename); fileFlag = 1;
    imageOrig.load(mFilenamejpeg);
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(imageOrig));
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->adjustSize();
    ui->graphicsView->fitInView(graphic->itemsBoundingRect(),Qt::KeepAspectRatio);
    //localmFilename = mFilename;
    //on_actionOpen_triggered();

    //imageOrig.load(localFilename.replace(QString("txt"),QString("jpeg")));

}



void MainWindow::on_actionLoad_Prev_Page_triggered()
{   QString file = "";
    string localFilename = mFilenamejpeg.toUtf8().constData();
    string nos = "0123456789";
    size_t loc = localFilename.find(".txt");
    string s = localFilename.substr(loc-1,1);
    string no;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilename.substr(loc-1,1);  }
    //cout << stoi(no) + 1 << endl;
    localFilename.replace(loc,no.size(),to_string(stoi(no) - 1));
    mFilenamejpeg = QString::fromStdString(localFilename); fileFlag = 1;
    imageOrig.load(mFilenamejpeg);
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(imageOrig));
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->adjustSize();
    ui->graphicsView->fitInView(graphic->itemsBoundingRect(),Qt::KeepAspectRatio);
    //localmFilename = mFilename;
    //on_actionOpen_triggered();

    //imageOrig.load(localFilename.replace(QString("txt"),QString("jpeg")));
}*/


//bool OPENSPELLFLAG = 1;// TO NOT CONVERT ASCII STRINGS TO DEVANAGARI ON OPENING WHEN SPELLCHECK IS CLICKED
QString file = "";
bool fileFlag = 0;
void MainWindow::on_actionLoad_Next_Page_triggered()
{   if(mFilename.size()>0){
    string localFilename = mFilename.toUtf8().constData();
    string nos = "0123456789";
    size_t loc = localFilename.find(".txt");
    string s = localFilename.substr(loc-1,1);
    string no;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilename.substr(loc-1,1);  }
    //cout << stoi(no) + 1 << endl;
    localFilename.replace(loc,no.size(),to_string(stoi(no) + 1));
    //cout << localFilename << endl;
    file = QString::fromStdString(localFilename); fileFlag = 1;
    //OPENSPELLFLAG = 1;
    on_actionOpen_triggered();
    }
    //imageOrig.load(localFilename.replace(QString("txt"),QString("jpeg")));

}


void MainWindow::on_actionLoad_Prev_Page_triggered()
{   if(mFilename.size() >0 ){
    string localFilename = mFilename.toUtf8().constData();
    string nos = "0123456789";
    size_t loc = localFilename.find(".txt");
    string s = localFilename.substr(loc-1,1);
    string no;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilename.substr(loc-1,1);  }
    //cout << stoi(no) + 1 << endl;
    localFilename.replace(loc,no.size(),to_string(stoi(no) - 1));
    file = QString::fromStdString(localFilename); fileFlag = 1;
    //OPENSPELLFLAG = 1;
    prevTRig =1;
    on_actionOpen_triggered();
    prevTRig =0;
    }

    //imageOrig.load(localFilename.replace(QString("txt"),QString("jpeg")));
}
QTime myTimer;
int secs;
bool FirstFlag = 1;
vector<string> vGPage, vIPage, vCPage; // for calculating WER

vector<string> vBest;
void MainWindow::on_actionCreateBest2OCR_triggered()
{
    // vGBook and vIBook contain the loaded words from both OCR

    int vGsz = vGBook.size(), vIsz =  vIBook.size();
    //cout << vGsz << " " << vIsz << endl;
    int win = vGsz  - vIsz;
    if(win<0) win = -1*win;
    win = maxIG(win,5);

    //float WER = 0;
    int mineEdDis = 1000;
    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
    //cout << win << endl;
    string localFilename = mFilename.toUtf8().constData();
    size_t loc = localFilename.find("Inds");
    localFilename = localFilename.substr(0,loc);
    localFilename = localFilename + "Best2ocrRep.txt";
    cout<< "writing to" << localFilename << " please wait"<< endl;
    std::ofstream best2(localFilename);
    for(int t = 0; t < vIsz;t++){
        mineEdDis = 1000;
        //cout << mineEdDis << endl;
        string BestString1;
        //cout << vIBook[t] << endl;
        string s1 = vIBook[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
        //cout << s1 << "s1 " ;
        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){

            int EdDis = editDist(vGBook[t1],s1);
            if(EdDis < mineEdDis) {mineEdDis = EdDis; BestString1 = vGBook[t1];}
            if (vGBook[t1] == s1) {BestString1 = s1; break;}
        }
        //cout << BestString1 << "BestString1 " ;

        if(s1 == BestString1){vBest.push_back(s1); best2 << toDev(s1) << " ";}
        else{ string s22 = bestIG(s1,BestString1,Dict); vBest.push_back(s22); best2 << toDev(s22) << " ";

        }
    }
    best2 << endl;
}


void MainWindow::on_actionOpen_triggered()
{
    if(!fileFlag) {
        file = QFileDialog::getOpenFileName(this,"Open a File");
    }
       //qDebug() <<"here" << file <<endl;
        QString localmFilename1;
        if(!file.isEmpty())
        { //CPair["BApyopetam"] = "BAzyopetam"; CPairRight["BAzyopetam"]++;
            QFile sFile(file);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                mFilename = file;
                localmFilename1 = mFilename;

                // load vIPage and vCPage for calculating WER if corresponding CPage exist
                /*vIPage.clear(); vCPage.clear();
                //QString localmFilename1 = mFilename;
                std::ifstream ssIPage(localmFilename1.toUtf8().constData());
                string localstr;
                while(ssIPage >> localstr) vIPage.push_back(localstr); ssIPage.close();
                localmFilename1.replace("Inds","Correct");
                std::ifstream ssCPage(localmFilename1.toUtf8().constData()); localmFilename1 = mFilename;

                vCPage.clear();
                if (ssCPage.is_open()){
                 while(ssCPage >> localstr) {vCPage.push_back(localstr); } ssCPage.close();
                    int vGsz = vCPage.size(), vIsz =  vIPage.size();
                    cout << vGsz << " " << vIsz << endl;
                    int win = vGsz  - vIsz;
                    if(win<0) win = -1*win;
                    win = maxIG(win,5);
                    cout << win << endl;
                    float WER = 0;
                    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
                    for(int t = 0; t < vIsz;t++){
                        string s1 = vIPage[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
                        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
                            if (vCPage[t1] == s1) {WER++; break;}
                        }
                    }
                    cout << vIsz - WER << endl;
                    ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
                }
                */
                // load and set data in Browzer
                // if file exist in corrected open that else open file in Indz
                myTimer.start();
                //int nMilliseconds = myTimer.elapsed();
                // do something..
                secs = 0;
                int mins = secs/60;
                secs = secs - mins*60;
                ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
                QString newFile = mFilename;
                newFile.replace("Inds","Corrected");
                QFile sFile1(newFile);
                if(sFile1.open(QFile::ReadOnly | QFile::Text))
                {
                    QTextStream in(&sFile1);
                    QString text = in.readAll();
                    sFile.close();
                    ui->textBrowser->setPlainText(text);
                } else {
                    QTextStream in(&sFile);
                    QString text = in.readAll();
                    sFile.close();
                    ui->textBrowser->setPlainText(text);
                }
                // load and show image:
                QString localmFilename = mFilename;
                localmFilename.replace("txt","jpeg");
                //system("cd localmFilename");
                //localmFilename = "gs -dNOPAUSE -dBATCH -sDEVICE=jpeg -r300 -sOutputFile='page-%00d.jpeg' " + localmFilename;
                //string s2= localmFilename.toUtf8().constData();
                //system(localmFilename.toStdString().c_str());
                //localmFilename = mFilename;
                //mFilenamejpeg = "page-1.jpeg";
                imageOrig.load(localmFilename);
                localmFilename = mFilename;

                QGraphicsScene *graphic = new QGraphicsScene(this);
                graphic->addPixmap(QPixmap::fromImage(imageOrig));
                ui->graphicsView->setScene(graphic);
                ui->graphicsView->adjustSize();
                ui->graphicsView->fitInView(graphic->itemsBoundingRect(),Qt::KeepAspectRatio);
                localmFilename = mFilename;
                //mFilename.replace(QString("jpeg"),QString("txt"));*/

                //GPage.clear(); TGPage.clear();
                localmFilename.replace(QString("Inds"),QString("GDoc"));
                //loadMap(localmFilename.toUtf8().constData(),GPage, "GPage");  localmFilename = mFilename;
                //loadmaptoTrie(TGPage,GPage);
                if (!prevTRig) on_actionSpell_Check_triggered();
                //OPENSPELLFLAG = 0;

                Graphics_view_zoom* z = new Graphics_view_zoom(ui->graphicsView);
                z->set_modifiers(Qt::NoModifier);
                // fill indexes according to Tesseract
                /*
                Pix * image1;
                image1 = pixRead((localmFilename.replace(QString("txt"),QString("jpeg"))).toUtf8().constData());//phototest.tif
                localmFilename = mFilename;
                tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
                api->Init(NULL, "hin+san");
                api->SetImage(image1);
                Boxa* boxes = api->GetComponentImages(tesseract::RIL_WORD, true, NULL, NULL);//RIL_SYMBOL
                //printf("Found %d textline image components.\n", boxes->n);
                vs.clear();vx.clear();vy.clear();vw.clear();vh.clear();
                vs.push_back(""); vx.push_back(1); vy.push_back(1); vw.push_back(1); vh.push_back(1);
                for(int i = 0; i < boxes->n; i++){
                    BOX* box = boxaGetBox(boxes, i, L_CLONE);
                    api->SetRectangle(box->x, box->y, box->w, box->h);
                    string ocrResult = api->GetUTF8Text(); //string ocrResultstr = ocrResult;
                    QString qstr = QString::fromStdString(ocrResult);
                    vs.push_back(qstr); vx.push_back(box->x); vy.push_back(box->y); vw.push_back(box->w); vh.push_back(box->h);
                    //qDebug() << qstr << endl;

                 } */

            } //if(sFile.open(QFile::ReadOnly | QFile::Text))


        } // if(!file.isEmpty())

}//MainWindow::on_actionOpen_triggered()

map<string, int> wordLineIndex;
bool ConvertSlpDevFlag =0;
void MainWindow::on_actionSpell_Check_triggered()
{

        QString textBrowserText = ui->textBrowser->toPlainText();
        QChar ch;
        ch=textBrowserText[1];
        textBrowserText+=" ";
        string str1=textBrowserText.toUtf8().constData();

        // load no of words
        istringstream iss1(str1);
        size_t WordCount = 0; string word1;
        while(iss1 >> word1) WordCount++;

        //str1 = toslp1(str1);
        istringstream iss(str1);
        string strHtml = "<html><body>"; string line;


        int value = 0;
        while (getline(iss, line)) {
                    istringstream issw(line);
                    string word;

                    while(issw >> word){
                        if(ConvertSlpDevFlag){
                            string word1 = word;
                            word = toslp1(word);
                            string wordNext;
                            if(hasM40PerAsci(word1)){wordNext = word1;}else{wordNext = toDev(word);}
                            strHtml += wordNext; strHtml += " "; //cout << strHtml << endl;
                            value ++;
                        }
                        else{
                            string word1 = word;
                            word = toslp1(word);
                            string wordNext;
                            //cout << GPage.size() <<  word << " " << GPage[word] << endl;
                            if(hasM40PerAsci(word1)){wordNext = word1;}
                            else if(GBook[(word)] > 0 ){wordNext = toDev(word); PWords[word]++;}
                            //else if(CPairRight[word] >0) {wordNext = "<font color=\'purple\'>" + toDev(CPair[word]) + "</font>";}
                            else if(PWords[word] > 0) { wordNext = "<font color=\'gray\'>" + toDev(word) + "</font>";}
                            else if((Dict[word] ==0) && (PWords[word] == 0) && (CPair[word].size() > 0)) {
                                wordNext = "<font color=\'purple\'>" + toDev(CPair[word]) + "</font>";
                            } else {
                            wordNext = findDictEntries(toslp1(word),Dict,PWords, word.size());//replace m1 with m2,m1 for combined search
                            wordNext = find_and_replace_oddInstancesblue(wordNext);
                            wordNext = find_and_replace_oddInstancesorange(wordNext);
                            }
                            strHtml += wordNext; strHtml += " "; //cout << strHtml << endl;
                            value ++;
                        }

                    //cout << GPage[(word)] << endl;
                    //Ui -> Dialog -> progressBar -> setValue(value);
                    }
            strHtml +="<br>"; // To add new line

       }
       strHtml += "</body></html>";
       ui->textBrowser->setHtml(QString::fromStdString(strHtml));
       //dialog->progressBar-> setValue(WordCount);

       //secdialog.progressBar.setValue(WordCount);


       // load wordLineIndex map for pairing with WordImages
       str1=textBrowserText.toUtf8().constData();
       // str1 = clean(str1);
       istringstream iss2(str1);
       size_t WordCount2 = 0;
       while (getline(iss2, line)) {
                   istringstream issw(line);
                   string word;
                   while(issw >> word){ wordLineIndex[(word + "###" + line)] = WordCount2; WordCount2++;} // clean(word) instead of word
       }

}

/*
string strPrev;
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{

   /.* QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    // code to copy selected string:-
    strPrev = cursor.selectedText().toUtf8().constData();/


return 1;
}
*/


/*
// refer http://stackoverflow.com/questions/28746541/qt-mousemove-event-not-being-caught-in-eventfilter
string strPrev, linePrev;
size_t ind = 0;
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{

    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    // code to copy selected string:-
    string str1 = cursor.selectedText().toUtf8().constData();;

    cursor.select(QTextCursor::LineUnderCursor);
    string line1 = cursor.selectedText().toUtf8().constData();;

    if((str1 != strPrev) || (line1 != linePrev) ) {

    strPrev = str1; linePrev = line1;
    QImage image = imageOrig;
    ind = wordLineIndex[(str1 + "###" + line1)];
    cout << wordLineIndex.size()<< " " << str1 + "###" + line1 << " " << ind << endl;

    for(int i = vx[ind]; i < (vx[ind] + vw[ind]); i++){


                image.setPixel(i,vy[ind],qRgb(150,0,0)); image.setPixel(i,vy[ind]-1,qRgb(150,0,0));  //i,vy[ind]-1,QRg
                image.setPixel(i,(vy[ind] + vh[ind]),qRgb(150,0,0));image.setPixel(i,(vy[ind] + vh[ind]+1),qRgb(150,0,0));


    }
    for(int j = vy[ind]; j < (vy[ind] + vh[ind]); j++){

                image.setPixel(vx[ind],j,qRgb(150,0,0)); image.setPixel(vx[ind]-1,j,qRgb(150,0,0));//qGray(150)
                image.setPixel((vx[ind]+vw[ind]),j,qRgb(150,0,0)); image.setPixel((vx[ind]+vw[ind] + 1 ),j,qRgb(150,0,0));

    }

    QImage imageO = image;

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(imageO));
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->fitInView(graphic->itemsBoundingRect(),Qt::KeepAspectRatio);

    } // 1st if ends

    return false;

} */



bool RightclickFlag = 0;
string selectedStr;
//GIVE EVENT TO TEXT BROWZER INSTEAD OF MAINWINDOW
void MainWindow::mousePressEvent(QMouseEvent *ev)
{   on_actionLoadData_triggered();
    ui->textBrowser->cursorForPosition(ev->pos());

    int nMilliseconds = myTimer.elapsed();
    // do something..
    secs = nMilliseconds/1000;
    int mins = secs/60;
    secs = secs - mins*60;
    ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
    if ((ev->button() == Qt::RightButton) || (RightclickFlag))
    {
        QTextCursor cursor1 = ui->textBrowser->cursorForPosition(ev->pos());
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.select(QTextCursor::WordUnderCursor);
        // code to copy selected string:-
        QString str1 = cursor.selectedText();
        selectedStr = str1.toUtf8().constData();

    // code to display options on rightclick
    ui->textBrowser->setContextMenuPolicy(Qt::CustomContextMenu);//IMP TO AVOID UNDO ETC AFTER SELECTING A SUGGESTION
    QMenu* popup_menu = ui->textBrowser->createStandardContextMenu();
    QMenu* spell_menu;
    spell_menu = new QMenu("suggestions",this);
    //QAction* action = tr("tihor");
    QAction* act;
    //vector<string> Words =  print5NearestEntries(TGPage,selectedStr);
    vector<string>  Words1 =  print5NearestEntries(TGBook,selectedStr);
    vector<string> Alligned =  print5NearestEntries(TGBookP,selectedStr);
    vector<string> PWords1 =  print5NearestEntries(TPWords,selectedStr);
    string PairSugg = print2OCRSugg(selectedStr, Alligned[0], ConfPmap,Dict); // map<string,int>&
    vector<string>  Words = print1OCRNearestEntries(toslp1(selectedStr),vIBook);
    //cout <<" here " << toDev(Words[0]) << endl;


    // find nearest confirming to OCR Sugg from Book
    string nearestCOnfconfirmingSuggvec;
    vector<string> vec = Words1;
    int min= 100;
        for (size_t t=0;t<vec.size();t++){
        vector<string> wordConfusions; vector<int> wCindex;
        int minFactor = loadWConfusionsNindex1(selectedStr,vec[t],ConfPmap,wordConfusions,wCindex);
        wordConfusions.clear(); wCindex.clear();
        if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];}
        }

    // find nearest confirming to OCR Sugg from PWords
    string nearestCOnfconfirmingSuggvec1;
        vector<string> vec1 = PWords1;
        min= 100;
            for (size_t t=0;t<vec1.size();t++){
            vector<string> wordConfusions; vector<int> wCindex;
            int minFactor = loadWConfusionsNindex1(selectedStr,vec1[t],ConfPmap,wordConfusions,wCindex);
            wordConfusions.clear(); wCindex.clear();
            if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t];}
            }

    vector<pair<int,string>> vecSugg,vecSugg1;
    map<string, int> mapSugg;
    string CSugg = CPair[toslp1(selectedStr)];
    if(CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
    if(Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
    if(Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
    if(PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
    if(PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;
    mapSugg[SamasBreakLRCorrect(toslp1(selectedStr),Dict,PWords,TPWords,TPWordsP)]++;
    string s1 = toslp1(selectedStr);
    string nearestCOnfconfirmingSuggvecFont = "";
    min= 100;
    for (size_t t=0;t<vec.size();t++){
        vector<string> wordConfusions; vector<int> wCindex;
        int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmapFont,wordConfusions,wCindex);
        wordConfusions.clear(); wCindex.clear();
        if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t];}
    }
    if(nearestCOnfconfirmingSuggvecFont.size() >0 ) mapSugg[nearestCOnfconfirmingSuggvecFont]++;

    string PairSuggFont = "";
    if(Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);
    if(PairSuggFont.size() >0 ) mapSugg[PairSuggFont]++;

    string sugg9 = "";
    sugg9 = generatePossibilitesNsuggest(s1,TopConfusions,TopConfusionsMask,Dict,SRules);
    if(sugg9.size() >0 ) mapSugg[sugg9]++;

    map<string, int> mapSugg1;
    for(size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
    if(Words.size() > ksugg1)  mapSugg1[toslp1(Words[ksugg1])]++;
    if(Words1.size() > ksugg1) mapSugg1[toslp1(Words1[ksugg1])]++;
    if(PWords1.size() > ksugg1) mapSugg1[toslp1(PWords1[ksugg1])]++;
    }


    for( map<string,int>::const_iterator eptr=mapSugg.begin(); eptr!=mapSugg.end(); eptr++){
        vecSugg.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
    }

    for( map<string,int>::const_iterator eptr=mapSugg1.begin(); eptr!=mapSugg1.end(); eptr++){
        vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
    }


    //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),selectedStr),selectedStr));
    //if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words[0])),Words[0]));
    //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words1[0])),Words1[0]));
    //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(PairSugg)),PairSugg));
    sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
    //cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
    //Words = suggestions((selectedStr));
    for ( uint bitarrayi = 0; bitarrayi < vecSugg.size(); bitarrayi++) {
        act = new QAction( QString::fromStdString(toDev(vecSugg[bitarrayi].second)) , spell_menu);
        //cout<<vecSugg[bitarrayi].first<<endl;
        spell_menu->addAction(act);
        }

    for ( uint bitarrayi = 0; bitarrayi < vecSugg1.size(); bitarrayi++) {
        if(mapSugg[vecSugg1[bitarrayi].second] < 1){
        act = new QAction(QString::fromStdString(toDev(vecSugg1[bitarrayi].second)), spell_menu);
        //cout<<vecSugg1[bitarrayi].first<<endl;
        spell_menu->addAction(act);
        }
        }
    /*Words =  print5NearestEntries(TDict,selectedStr);
    if (Words.size() > 0) {
        act = new QAction(QString::fromStdString(toDev(Words[0])), spell_menu);

        spell_menu->addAction(act);

    }*/

    popup_menu->insertSeparator(popup_menu->actions()[0]);
    popup_menu->insertMenu(popup_menu->actions()[0],spell_menu);
    connect(spell_menu, SIGNAL(triggered(QAction*)), this, SLOT(menuSelection(QAction*)));
    popup_menu->exec(ev->globalPos());
    popup_menu->close(); popup_menu->clear();
    //ui->textBrowser->createStandardContextMenu()->clear();
    //cursor.select(QTextCursor::WordUnderCursor);
    vecSugg.clear(); Words1.clear(); Words.clear(); Alligned.clear(); PairSugg.clear();
    } // if right click

}// if mouse event

/*
QString strPrev = "";
void MainWindow::textChangedSlot(){
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.select(QTextCursor::WordUnderCursor);
        // code to copy selected string:-
        QString strPrev1 = cursor.selectedText();
        if( editDist(toslp1(strPrev1.toUtf8().constData()),toslp1(strPrev.toUtf8().constData())) > 0) {
        strPrev = cursor.selectedText();
        QString text = strPrev;
        QMessageBox* box = new QMessageBox();
        box->setWindowTitle(QString("Hello"));
        box->setText(QString("Current Text:\""+text+"\""));
        box->show();
        }
}
*/


void MainWindow::menuSelection(QAction* action)
{
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    cursor.beginEditBlock();
    cursor.removeSelectedText();

    //cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");

    string target  = (action->text().toUtf8().constData());
    CPair[toslp1(selectedStr)] = toslp1(target);
    PWords[toslp1(target)]++; //CPairRight[toslp1(target)]++;
    cursor.insertText(action->text());
    //cout <<target << CPair.size() << " "<< GBook.size() << " " << IBook.size() << endl;
    //on_actionSpell_Check_triggered();
    //cout << selectedStr << " to " << target << " " << CPair[toslp1(selectedStr)] <<" " << IBook[toslp1(selectedStr)] + 1 << "Corrections made"<< endl;

    // replace words with name same as selectedStr and are underlined
    // underlined:-
    //strHtml += "<a href='xxx'>";
    //strHtml += word;
    //strHtml += "</a>";

    //QTextDocument *doc=ui->textBrowser->document();
    //QString html=doc->toHtml();
    //string html0=html.toUtf8().constData();

    //cout<<selectedStr<<endl;
    cursor.endEditBlock();

    /*
    QString textBrowserText = ui->textBrowser->toPlainText();
    string alltext=(textBrowserText.toUtf8().constData()); //toslp1
    istringstream ss(alltext);
    string word="";
    //int len = alltext.length(),a=0;
    int noCorr = 0;
    ss >> word;
    cursor.setPosition(0,QTextCursor::MoveAnchor);
    size_t cnt = 1;
    while( ss >> word) cnt++;
    for(size_t c1 = 0; c1 < cnt + 10; c1++){ cursor.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
        cursor.select(QTextCursor::WordUnderCursor);
        QString str1 = cursor.selectedText();
        word = str1.toUtf8().constData();
        if(word==(selectedStr)){
        //cursor.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
        //cursor.select(QTextCursor::WordUnderCursor);
        cursor.beginEditBlock();
        cursor.removeSelectedText();
        cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");
        noCorr++;
        cursor.endEditBlock();
        }
        }
    cout << "noCOrr made on this Page " << noCorr << endl;
    */
    /*
    while(a<len)
    {
        if(alltext[a]==' ')
        {
            if(word==toslp1(selectedStr))
            {   cursor.setPosition(a-1,QTextCursor::MoveAnchor);
                cursor.setPosition(a-1,QTextCursor::MoveAnchor);
                cursor.select(QTextCursor::WordUnderCursor);
                cursor.beginEditBlock();
                cursor.removeSelectedText();
                cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");
                noCorr++;
                cursor.endEditBlock();
            }
            word="";
        }
        else
            word+=alltext[a];
        a++;
    }*/


    // write code to pick word one by one in string word
/*
    // code to search for a string in another string
    // say word has 1st word from Text Browzer
    int pos = word.find("</a>", 0);
    if(pos != static_cast<int>(string::npos)){
        // then delete extra things that underline the word
        //if this remaining string matches selectedStr(rohlt) replace it with action->text()
            //action->text() might be Qstring
            alltextnew + = action->text();// convert this Qstring to string it has rohit
        else  alltextnew + = word;
    }else alltextnew + = word;
    */
  //qDebug() << "Triggered: " << action->text();
}

void MainWindow::on_actionNew_triggered()
{

    mFilename = "Untitled";
    ui->textBrowser->setPlainText("");
}

void MainWindow::on_actionSave_triggered()
{   int nMilliseconds = myTimer.elapsed();
    secs = nMilliseconds/1000;
    int mins = secs/60;
    secs = secs - mins*60;
    ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
    ConvertSlpDevFlag =1;
    //on_actionSpell_Check_triggered();
    if (mFilename=="Untitled"){
        on_actionSave_As_triggered();
    }else{ QString localFilename = mFilename; localFilename.replace("Inds","Corrected");
                QFile sFile(localFilename);
                  if(sFile.open(QFile::WriteOnly | QFile::Text))
                  {
                      QTextStream out(&sFile);
                      out << ui->textBrowser->toPlainText();
                      sFile.flush();
                      sFile.close();
                  }
    }
    ConvertSlpDevFlag =0;
    //on_actionSpell_Check_triggered();

}

void MainWindow::on_actionLoadGDocPage_triggered()
{
    if (mFilename=="Untitled"){
        on_actionSave_As_triggered();
    }else{
                QString str1 = mFilename;
                str1.replace("Inds","Corrected");
                QFile sFile(str1);
                  if(sFile.open(QFile::WriteOnly | QFile::Text))
                  {
                      QTextStream out(&sFile);
                      out << ui->textBrowser->toPlainText();
                      sFile.flush();
                      sFile.close();
                  }
                  //qDebug() << str1 << endl;
                  loadMap(str1.toUtf8().constData(),PWords,"PWords");

                  map<string, int> PWordspage;
                  loadMap(str1.toUtf8().constData(),PWordspage,"PWordspage");
                  loadmaptoTrie(TPWords, PWordspage);

                  vector<string> wrong,right;
                  QString str2 = str1; str2.replace("Corrected","Inds");
                  generateCorrectionPairs(wrong,right,str2.toUtf8().constData(), str1.toUtf8().constData());
                  loadConfusionsFont(wrong,right,ConfPmapFont);
                  loadConfusionsFont(wrong,right,ConfPmap);
                  TopConfusions.clear(); TopConfusionsMask.clear();
                  loadTopConfusions(ConfPmap,TopConfusions,TopConfusionsMask);

                  //on_actionSpell_Check_triggered();
    }

}


void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open a File");
    if(!file.isEmpty())
    {
        mFilename = file;
        on_actionSave_triggered();
    }

}




void MainWindow::on_actionToDevanagari_triggered()
{
    int nMilliseconds = myTimer.elapsed();
    secs = nMilliseconds/1000;
    int mins = secs/60;
    secs = secs - mins*60;
    ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QString str1 = cursor.selectedText();
    selectedStr = str1.toUtf8().constData();
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(QString::fromStdString(toDev(toslp1(selectedStr))));
    cursor.endEditBlock();

}



QString mFilename1, loadStr, loadStr1;
void MainWindow::on_actionLoadData_triggered()
{
    //cout << " here reached" << endl;
    if(FirstFlag){
       QString  localmFilename1 = mFilename;

        // loading Dictionary locally
        string localmFilename1n = localmFilename1.toUtf8().constData();
        localmFilename1n = localmFilename1n.substr(0,localmFilename1n.find("page"));

        localmFilename1 = QString::fromStdString(localmFilename1n);
        mFilename1 = localmFilename1;

        loadStr = "Loading Dict Words";
        loadStr1 = loadStr + " Please wait...";
        ui->textBrowser->setPlainText(loadStr1);
        on_actionLoadDict_triggered();
        loadStr += "\n";
        ui->progressBar->setValue(20);
        //cout << "here1" << endl;

        loadStr += "\n \nLoading OCR Words";
        loadStr1 = loadStr + " Please wait...";
        ui->textBrowser->setPlainText(loadStr1);
        on_actionLoadOCRWords_triggered();
         ui->progressBar->setValue(40);

         loadStr += "\n \n Loading Domain Words";
         loadStr1 = loadStr + " Please wait...";
         ui->textBrowser->setPlainText(loadStr1);
         on_actionLoadDomain_triggered();
          ui->progressBar->setValue(60);

          loadStr += "\n \nLoading Substrings and Sandhi Rules";
          loadStr1 = loadStr + " Please wait...";
          ui->textBrowser->setPlainText(loadStr1);
          on_actionLoadSubPS_triggered();
           ui->progressBar->setValue(80);

           loadStr += "\n \nLoading Confusions";
           loadStr1 = loadStr + " Please wait...";
           ui->textBrowser->setPlainText(loadStr1);
           on_actionLoadConfusions_triggered();
            ui->progressBar->setValue(100);

        /*


        //cout << "More PWords loaded" << PWords.size();
        loadPWordsPatternstoTrie(TPWordsP,PWords);// justsubstrings not patterns exactly // PWordsP,
        localmFilename1.replace("Inds/","CPair");
        loadCPair(localmFilename1.toUtf8().constData(),CPair,Dict,PWords); localmFilename1 = mFilename1;
        loadmaptoTrie(TPWords, PWords);
        loadmaptoTrie(TDict,Dict);
        loadmaptoTrie(TGBook,GBook);
        loadPWordsPatternstoTrie(TGBookP,GBook);

        //loadConfusions("1kECPairs",ConfPmap); //printmap(ConfPmap);
        //loadConfusions2("/home/rohit/Exp4/C++QTFINAL_update2/NEW/allperms/WrongAllLeft","/home/rohit/Exp4/C++QTFINAL_update2/NEW/allperms/WrongAllRight",ConfPmap);

        // code for loading COnfMap
        /.*localmFilename1.replace("Inds/page-1.txt","WrongAllLeft"); cout << localmFilename1.toUtf8().constData() << endl;
         * loadConfusions("1kECPairs",ConfPmap); //printmap(ConfPmap);
        QString lfR = mFilename; lfR.replace("Inds/page-1.txt","WrongAllRight");
        loadConfusions2(localmFilename1.toUtf8().constData(), lfR.toUtf8().constData(), ConfPmap);localmFilename1 = mFilename;
        loadCPair(localmFilename1.toUtf8().constData(), lfR.toUtf8().constData(), CPair);*./
        localmFilename1.replace("Inds/","ConfPmap.bin");
        std::ifstream ss2(localmFilename1.toUtf8().constData());localmFilename1 = mFilename;
        boost::archive::text_iarchive oarch2(ss2);
        oarch2 >> ConfPmap; ss2.close();
        qDebug() << ConfPmap.size() << "Confusions Loaded " << endl;

        */
        FirstFlag = 0;
        on_actionLoad_Next_Page_triggered();
        on_actionLoad_Prev_Page_triggered();

        // Plotting Graph for Black and Gray Words
        //cout<< " Loading Graph values and performing Significance test on Word Length" << endl;
        /*
        // generate some data:
        QVector<double> x, y,z,w;
        float maxy; maxy = 0;
        // page1
        float pageno =1;
        QString localmFilename1 = mFilename;
        localmFilename1.replace("Inds","Correct");
        QString localmFilename2 = mFilename;
        double mean, std,error;
        qDebug() << localmFilename1 << " " << localmFilename2 << endl;
        if(findMeanStd(mean, std, error, localmFilename1, localmFilename2,  GBook, PWords)){
        if(error > maxy) maxy = error;
        w.push_back(error/10), z.push_back(std); y.push_back(mean); x.push_back(pageno); pageno++;}
        cout << mean << " " << std <<" " << error << endl;
        string nos = "0123456789";
        string localFilename = mFilename.toUtf8().constData();
        while(1){
            size_t loc = localFilename.find(".txt");
            string s = localFilename.substr(loc-1,1);
            string no;
            while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilename.substr(loc-1,1);  }
            //cout << stoi(no) + 1 << endl;
            localFilename.replace(loc,no.size(),to_string(stoi(no) + 1));
            localmFilename2 = QString::fromStdString(localFilename);
            localmFilename1 = localmFilename2; localmFilename1.replace("Inds","Correct");

            double mean, std,error;
            qDebug() << localmFilename1 << " " << localmFilename2 << endl;
            if(findMeanStd(mean, std, error, localmFilename1, localmFilename2,  GBook, PWords)){
            if(mean > error) maxy = error;
            w.push_back(error/10), z.push_back(std); y.push_back(mean); x.push_back(pageno); pageno++;} else break;
            //cout << y.size() << endl;
            cout << mean << " " << std << " " <<error << endl;

        }


        //cout << y.size() << endl;
        // create graph and assign data to it
        ui->widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
        ui->widget->legend->setVisible(true);
        QFont legendFont = font();  // start out with MainWindow's font..
        legendFont.setPointSize(9); // and make a bit smaller for legend
        ui->widget->legend->setFont(legendFont);
        ui->widget->legend->setBrush(QBrush(QColor(255,255,255,230)));
        ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        ui->widget->graph(0)->setName("Black/Gray Word Length Mean");


        ui->widget->addGraph();
        ui->widget->graph(1)->setPen(QPen(Qt::red));
        ui->widget->graph(1)->setName("Black/Gray Word Length Std");
        ui->widget->graph(1)->setData(x, z);

        ui->widget->addGraph();
        ui->widget->graph(2)->setPen(QPen(Qt::cyan));
        ui->widget->graph(2)->setName("Black Gray Words Error %age/10");
        ui->widget->graph(2)->setData(x, w);
        // give the axes some labels:
        ui->widget->xAxis->setLabel("Page No.");
        ui->widget->yAxis->setLabel("Mean/Std/ %Error ");
        // set axes ranges, so we see all data:

        ui->widget->xAxis->setRange(1, x.size()+100);
        ui->widget->yAxis->setRange(0, 10);
        ui->widget->replot();

        /.*
        while(1){
            string nos = "0123456789";
            size_t loc = localFilename.find(".txt");
            string s = localFilename.substr(loc-1,1);
            string no;
            while(nos.find(s) != string::npos) { no = s + no; loc--; s = localmFilename1.substr(loc-1,1);  }
            //cout << stoi(no) + 1 << endl;
            localmFilename1.replace(loc,no.size(),to_string(stoi(no) + 1));
        std::ifstream ssIPage(localmFilename1.toUtf8().constData());
        string localstr;
        while(ssIPage >> localstr)
        if((GBook[(localstr)] > 0) || (PWords[localstr] > 0)){


        }*/
        }// if(FirstFlag)
}

void MainWindow::on_actionLoadDict_triggered()
{   QString localmFilename1 = mFilename1;
    localmFilename1.replace("Inds/","Dict");
    //localmFilename1n = localmFilename1.toUtf8().constData();
    //cout <<localmFilename1.toUtf8().constData() << endl;
    loadMap(localmFilename1.toUtf8().constData(),Dict,"Dict");
    /*std::ofstream ss1(localmFilename1.toUtf8().constData());
    boost::archive::text_oarchive oarch1(ss1);
    //ui->lineEdit->setText("Loading Dictionary Words.. Please wait..");
    Dict >> oarch1 ; ss1.close();
    localmFilename1.replace("Dict","Dict.bin");
    std::ifstream ss(localmFilename1.toUtf8().constData());
    boost::archive::text_iarchive oarch(ss);
    //ui->lineEdit->setText("Loading Dictionary Words.. Please wait..");
    oarch >> Dict; ss.close(); */
    loadStr += "\n" + QString::number((Dict.size())) + "Dict Words Loaded";
    loadStr1 = loadStr + "\nLoading OCR Files Please wait.." ;
    //cout << Dict.size() << " Dict Words Loaded" << endl;
    //cout << "here" << endl;
    ui->textBrowser->setPlainText(loadStr1);
}

void MainWindow::on_actionLoadOCRWords_triggered()
{   QString localmFilename1 = mFilename1;
    localmFilename1.replace("Inds/","GEROCR");
    cout << localmFilename1.toUtf8().constData() << endl;
    loadMapNV(localmFilename1.toUtf8().constData(),GBook,vGBook,"GBook"); localmFilename1 = mFilename1;
    cout << localmFilename1.toUtf8().constData() << endl;
    localmFilename1.replace("Inds/","IEROCR");
    loadMapNV(localmFilename1.toUtf8().constData(),IBook,vIBook,"IBook");
    cout << GBook.size() << " " << IBook.size() << endl;
    loadStr += "\n" + QString::number((IBook.size())) + " Indsenz Words Loaded & ";
    loadStr += "\n" + QString::number((GBook.size())) + " Google Doc Words Loaded.";
    loadStr1 = loadStr + "Please wait...";
    ui->textBrowser->setPlainText(loadStr1);
}

void MainWindow::on_actionLoadDomain_triggered()
{
    QString localmFilename1 = mFilename1;
    localmFilename1.replace("Inds/","PWords");
    loadMap(localmFilename1.toUtf8().constData(),PWords,"PWords"); localmFilename1 = mFilename1;
    //cout << "PWords loaded" << PWords.size();
    loadMapPWords(vGBook,vIBook,PWords);
    loadStr += "\n" + QString::number((PWords.size())) + " Domain Words Loaded.";
    loadStr1 = loadStr + "Please wait...";
    ui->textBrowser->setPlainText(loadStr1);
}

map<string, string> LSTM;
void MainWindow::on_actionLoadSubPS_triggered()
{
    QString localmFilename1 = mFilename1;
    size_t count = loadPWordsPatternstoTrie(TPWordsP,PWords);// justsubstrings not patterns exactly // PWordsP,
    localmFilename1.replace("Inds/","CPair");
    loadCPair(localmFilename1.toUtf8().constData(),CPair,Dict,PWords); localmFilename1 = mFilename1;

    localmFilename1.replace("Inds/","LSTM");
    ifstream myfile(localmFilename1.toUtf8().constData());
              if (myfile.is_open())
              { string str1, str2,line;
            while (getline(myfile,line)) {istringstream slinenew(line); slinenew >> str1; slinenew >> str2;
                if(str2.size() >0) LSTM[str1] = str2;}
              }
    cout<< LSTM.size() << "LSTM Pairs Loaded";
    localmFilename1 = mFilename1;

    loadmaptoTrie(TPWords, PWords);
    loadmaptoTrie(TDict,Dict);
    loadmaptoTrie(TGBook,GBook);
    loadPWordsPatternstoTrie(TGBookP,GBook);
    loadStr += "\n" + QString::number(count) + " Substrings and 71 Sandhi Rules Loaded.";
    loadStr1 = loadStr + "Please wait...";
    ui->textBrowser->setPlainText(loadStr1);
}



void MainWindow::on_actionLoadConfusions_triggered()
{
    //QString lfR = mFilename; lfR.replace("Inds/page-1.txt","WrongAllRight");
    QString localmFilename1 = mFilename;
    localmFilename1.replace("Inds/","CPair");
   loadConfusions(localmFilename1.toUtf8().constData(), ConfPmap);localmFilename1 = mFilename;
   //loadCPair(localmFilename1.toUtf8().constData(), lfR.toUtf8().constData(), CPair);*./

    //QString localmFilename1 = mFilename1;
     /*localmFilename1.replace("Inds/","ConfPmap.bin");
    std::ifstream ss2(localmFilename1.toUtf8().constData());
    boost::archive::text_iarchive oarch2(ss2);
    oarch2 >> ConfPmap; ss2.close();*/

    //localmFilename1.replace("Inds/","CPair");
    //loadConfusions(localmFilename1.toUtf8().constData(),ConfPmap);
    //if ConfpConfPmap.size() == 0)


    loadStr += "\n" + QString::number(ConfPmap.size()) + " Confusions Loaded.";
    loadSandhiRules("SRules",SRules);
    loadTopConfusions(ConfPmap,TopConfusions,TopConfusionsMask);

    ui->textBrowser->setPlainText(loadStr1);

}


/*
class MyTimer : public QObject
{
    Q_OBJECT
public :
    MyTimer(){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
        timer->start(1000);
    }

    QTimer *timer;

public slots:
    void MySlot(){
    secs++;
    ui->lineEdit->settext(stoi(secs) + " secs passed");
    }
};*/

void MainWindow::on_actionSugg_triggered()
{
    RightclickFlag = 1;
    QMouseEvent *ev1;
    //ev1->button() = Qt::RightButton; ->RightButton;
    mousePressEvent(ev1);
    RightclickFlag = 0;

}



void MainWindow::on_actionToSlp1_triggered()
{

        int nMilliseconds = myTimer.elapsed();
        secs = nMilliseconds/1000;
        int mins = secs/60;
        secs = secs - mins*60;
        ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
        QTextCursor cursor = ui->textBrowser->textCursor();
        //cursor.select(QTextCursor::WordUnderCursor);
        QString str1 = cursor.selectedText();
        selectedStr = str1.toUtf8().constData();
        cursor.beginEditBlock();
        cursor.removeSelectedText();
        cursor.insertText(QString::fromStdString((toslp1(selectedStr))));
        cursor.endEditBlock();

}

void MainWindow::on_actionCreateSuggestionLog_triggered()
{
    map<size_t, size_t> mapCorrect,mapinCorrect,mapTyping,mapSugg1,mapSugg2,mapSugg3,mapSugg4,mapSugg5,mapSugg6,mapSugg7,mapSugg8,mapSugg9,mapSugg10;

    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while(1) {

    string nos = "0123456789";
    string localFilenameI = strI.toUtf8().constData();
    size_t loc = localFilenameI.find(".txt");
    string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
    string no;

    vector<string> wrong, right;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
    //cout << stoi(no) + 1 << endl;
    localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
    //cout << localFilename << endl;
    //QString fileI = QString::fromStdString(localFilenameI);

    //Load page1 of C

    string localFilenameC = strC.toUtf8().constData();
    loc = localFilenameC.find(".txt");
    s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
    no ="";
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
    //cout << stoi(no) + 1 << endl;
    localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
    //cout << localFilename << endl;
   // QString fileC = QString::fromStdString(localFilenameC);

    // NOW localFilenameI and localFilenameC has page1 of both
    //cout << localFilenameI << " " << localFilenameC << endl;
    // load fileI in vecpI and
    vector<string> vecpI, vecpC;
    map<string, bool> isAscii;
    std::ifstream sIpage(localFilenameI);
    if (!(sIpage.is_open())) break; // break the while loop for page_no
    string localstr;
    while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
    std::ifstream sCpage(localFilenameC);
    while(sCpage >> localstr) { if(hasM40PerAsci(localstr)){isAscii[toslp1(localstr)] = 1;}  vecpC.push_back(toslp1(localstr));} sIpage.close();

    // if 1st word is wrong generate suggestions
    int vGsz = vecpC.size(), vIsz =  vecpI.size();
    if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
    //cout << vGsz << " " << vIsz << endl;
    int win = vGsz  - vIsz;
    if(win<0) win = -1*win;
    win = maxIG(win,5);
    //cout << win << endl;
    //float WER = 0;
    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
    for(int t = 0; t < vIsz;t++){
        size_t minedit = 1000;
        string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
        string sC;
        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
            string sCt1 = vecpC[t1];
            size_t mineditIC = editDist(s1,sCt1);
            if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1;   }
            if (sCt1 == s1) {/*WER++;*/ break;}
        }

        // now we have IndsWord in s1 and correct word in sC
        //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
        if((sC == (s1))){
        mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
        }else if(!isAscii[sC]) { wrong.push_back(s1); right.push_back(sC);
            //cout<< " inside incorrect words ke liye else" << endl;
            vector<string>  Words1 =  print5NearestEntries(TGBook,s1); //2
            if(Words1.size() == 0) Words1.push_back("");
            string nearestCOnfconfirmingSuggvec; //1
            vector<string> vec = Words1;
            int min= 100;
                for (size_t t=0;t<vec.size();t++){
                vector<string> wordConfusions; vector<int> wCindex;
                int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmap,wordConfusions,wCindex);
                wordConfusions.clear(); wCindex.clear();
                if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];}
                }
            //cout << "sz" << Words1.size() << " "<< Words1[0]<< endl;
            if(nearestCOnfconfirmingSuggvec == (sC)){mapSugg1[page_no]++; }
            /*else*/ if((Words1[0] == (sC))){mapSugg2[page_no]++; }
            /*else*/ {

                vector<string> Alligned =  print5NearestEntries(TGBookP,s1); //6
                if(Alligned.size() == 0) Alligned.push_back("");

                string PairSugg = "";
                if(Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);//3
                //cout << sC << "PairSugg " << PairSugg<<endl;
                if(PairSugg == sC) {  mapSugg3[page_no]++;}
                /*else*/{ vector<string>  Words = print1OCRNearestEntries(toslp1(s1),vIBook); // 4 primary doc based
                    if(Words.size() == 0) Words.push_back("");
                    if(Words[0] == (sC)) { mapSugg4[page_no]++;  }
                    /*else*/ { string samassugg = SamasBreakLRCorrect(toslp1(s1),Dict,PWords,TPWords,TPWordsP); // 5
                        if(samassugg == sC) { mapSugg5[page_no]++; }
                         /*else*/ {
                            vector<string> PWords1 =  print5NearestEntries(TPWords,s1); // 6
                            if(PWords1.size() == 0) PWords1.push_back("");
                            if(PWords1[0] == (sC)) { mapSugg6[page_no]++; }
                             /*else*/ {string nearestCOnfconfirmingSuggvecFont;
                                int min= 100;
                                    for (size_t t=0;t<vec.size();t++){
                                    vector<string> wordConfusions; vector<int> wCindex;
                                    int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmapFont,wordConfusions,wCindex);
                                    wordConfusions.clear(); wCindex.clear();
                                    if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t];}
                                    }
                                if(nearestCOnfconfirmingSuggvecFont == sC) {mapSugg7[page_no]++;}
                                /*else*/{
                                    /*string PairSuggFont = "";
                                    if(Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);//3
                                    //cout << sC << "PairSugg " << PairSugg<<endl;
                                    if(PairSuggFont == sC) {  mapSugg8[page_no]++;}*/
                                    vector<string> Wordsdict;  {Wordsdict =  print5NearestEntries(TDict,s1);}
                                    if((Wordsdict.size()>0)&&(Wordsdict[0] == sC)) {  mapSugg8[page_no]++; }
                                    /*else*/{
                                        string sugg9 = generatePossibilitesNsuggest(s1,TopConfusions,TopConfusionsMask,Dict,SRules);
                                        if(sugg9 == sC) {  mapSugg9[page_no]++;
                                        //cout << s1 << " "<<sC << endl;
                                        }
                                        /*else*/{ if(LSTM[s1] == sC) {mapSugg10[page_no]++;
                                            cout << s1 << " lstm " << sC <<endl;}
                                            else mapTyping[page_no]++;}
                                    }
                                }
                            }
                        }
                    }
                }

            }

        } else{mapTyping[page_no]++;} // else
    //cout << mapCorrect[1]<< " " << mapTyping[1]<< " " <<mapSugg1[1]<< " " <<mapSugg2[1]<< " " <<mapSugg3[1]<< " " <<mapSugg4[1]<< " " <<mapSugg5[1]<< " " <<mapSugg6[1]<<endl;
    //cout << "here" << endl;
    }// for 1st page ends
    mapinCorrect[page_no] = vIsz - mapCorrect[page_no];
    //Loading PWords:-
    cout << "page_no = "<< page_no << endl;
    loadMap(localFilenameC,PWords,"PWords");
    map<string, int> PWordspage;
    loadMap(localFilenameC,PWordspage,"PWordspage");
    loadmaptoTrie(TPWords, PWordspage);
    //generateCorrectionPairs(wrong,right,str2.toUtf8().constData(), str1.toUtf8().constData());
    loadConfusionsFont(wrong,right,ConfPmap);
    loadConfusionsFont(wrong,right,ConfPmapFont);
    TopConfusions.clear(); TopConfusionsMask.clear();
    loadTopConfusions(ConfPmap,TopConfusions,TopConfusionsMask);



    //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
    //cout << vIsz - WER << endl;
    //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
    page_no++;
    filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends
    page_no--;
    filereport.replace(("Corrected/page-"+ QString::number(page_no) + ".txt"), "SuggReport1.txt" );
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for( size_t i =1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for( size_t i =1; i <= page_no; i++) rep << mapTyping[i]<< " "; rep << "];" << endl;
    rep << "y3 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg1[i]<< " "; rep << "];" << endl;
    rep << "y4 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg2[i]<< " "; rep << "];" << endl;
    rep << "y5 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg3[i]<< " "; rep << "];" << endl;
    rep << "y6 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg4[i]<< " "; rep << "];" << endl;
    rep << "y7 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg5[i]<< " "; rep << "];" << endl;
    rep << "y8 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg6[i]<< " "; rep << "];" << endl;
    rep << "y9 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg7[i]<< " "; rep << "];" << endl;
    rep << "y10 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg8[i]<< " "; rep << "];" << endl;
    rep << "y11 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg9[i]<< " "; rep << "];" << endl;
    rep << "y12 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg10[i]<< " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8,x,y9,x,y10,x,y11);"<< endl;
    rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#CorrectSugg1\',\'#CorrectSugg2\',\'#CorrectSugg3\',\'#CorrectSugg4\',\'#CorrectSugg5\',\'#CorrectSugg6\',\'#CorrectSugg7\',\'#CorrectSugg8\',\'#CorrectSugg9\' )" << endl;
    rep <<"TotalSuggestions =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11)" << endl;
    rep <<"TotalSuggestionsWithLSTM =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11+y12)" << endl;
}


/*
 // 3 map<string,int>&

//cout <<" here " << toDev(Words[0]) << endl;


// find nearest confirming to OCR Sugg from 2ndary Book //1


// find nearest confirming to OCR Sugg from PWords
string nearestCOnfconfirmingSuggvec1;
    vector<string> vec1 = PWords1;
    min= 100;
        for (size_t t=0;t<vec1.size();t++){
        vector<string> wordConfusions; vector<int> wCindex;
        int minFactor = loadWConfusionsNindex1(selectedStr,vec1[t],ConfPmap,wordConfusions,wCindex);
        wordConfusions.clear(); wCindex.clear();
        if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t];}
        }

vector<pair<int,string>> vecSugg,vecSugg1;
map<string, int> mapSugg;
string CSugg = CPair[toslp1(selectedStr)];
if(CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
if(Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
if(Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
if(PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
if(PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;



map<string, int> mapSugg1;
for(size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
if(Words.size() > ksugg1)  mapSugg1[toslp1(Words[ksugg1])]++;
if(Words1.size() > ksugg1) mapSugg1[toslp1(Words1[ksugg1])]++;
if(PWords1.size() > ksugg1) mapSugg1[toslp1(PWords1[ksugg1])]++;
}


for( map<string,int>::const_iterator eptr=mapSugg.begin(); eptr!=mapSugg.end(); eptr++){
    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
}

for( map<string,int>::const_iterator eptr=mapSugg1.begin(); eptr!=mapSugg1.end(); eptr++){
    vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
}


//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),selectedStr),selectedStr));
//if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words[0])),Words[0]));
//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words1[0])),Words1[0]));
//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(PairSugg)),PairSugg));
sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
//cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
//Words = suggestions((selectedStr));
for ( uint bitarrayi = 0; bitarrayi < vecSugg.size(); bitarrayi++) {
    act = new QAction( QString::fromStdString(toDev(vecSugg[bitarrayi].second)) , spell_menu);
    //cout<<vecSugg[bitarrayi].first<<endl;
    spell_menu->addAction(act);
    }

for ( uint bitarrayi = 0; bitarrayi < vecSugg1.size(); bitarrayi++) {
    if(mapSugg[vecSugg1[bitarrayi].second] < 1){
    act = new QAction(QString::fromStdString(toDev(vecSugg1[bitarrayi].second)), spell_menu);
    //cout<<vecSugg1[bitarrayi].first<<endl;
    spell_menu->addAction(act);
    }
    }
*/


void MainWindow::on_actionCreateSuggestionLogNearestPriority_triggered()
{
    map<size_t, size_t> mapCorrect,mapinCorrect,mapTyping,mapSugg1,mapSugg2,mapSugg3,mapSugg4,mapSugg5,mapSugg6,mapSugg7,mapSugg8,mapSugg9,mapSugg10;

       // Load foders in strC and strI
       QString strI = mFilename;
       QString strC = strI;
       strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");

       // load text files one by one

       //Load page1 of Inds
       size_t page_no = 1;
       QString filereport;

       while(1) {

       string nos = "0123456789";
       string localFilenameI = strI.toUtf8().constData();
       size_t loc = localFilenameI.find(".txt");
       string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
       string no;


       while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
       //cout << stoi(no) + 1 << endl;
       localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
       //cout << localFilename << endl;
       //QString fileI = QString::fromStdString(localFilenameI);

       //Load page1 of C

       string localFilenameC = strC.toUtf8().constData();
       loc = localFilenameC.find(".txt");
       s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
       no ="";
       while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
       //cout << stoi(no) + 1 << endl;
       localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
       //cout << localFilename << endl;
      // QString fileC = QString::fromStdString(localFilenameC);

       // NOW localFilenameI and localFilenameC has page1 of both
       //cout << localFilenameI << " " << localFilenameC << endl;
       // load fileI in vecpI and
       vector<string> vecpI, vecpC;
       std::ifstream sIpage(localFilenameI);
       if (!(sIpage.is_open())) break; // break the while loop for page_no
       string localstr;
       while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
       std::ifstream sCpage(localFilenameC);
       while(sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

       // if 1st word is wrong generate suggestions
       int vGsz = vecpC.size(), vIsz =  vecpI.size();
       if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
       //cout << vGsz << " " << vIsz << endl;
       int win = vGsz  - vIsz;
       if(win<0) win = -1*win;
       win = maxIG(win,5);
       //cout << win << endl;
       //float WER = 0;
       // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
       for(int t = 0; t < vIsz;t++){
           size_t minedit = 1000;
           string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
           string sC;
           for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
               string sCt1 = vecpC[t1];
               size_t mineditIC = editDist(s1,sCt1);
               if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1;   }
               if (sCt1 == s1) {/*WER++;*/ break;}
           }
           // now we have IndsWord in s1 and correct word in sC
           //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
           if((sC == (s1))){
           mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
           }else {
                   vector<string>  Words1 =  print5NearestEntries(TGBook,s1);
                   vector<string> Alligned =  print5NearestEntries(TGBookP,s1);
                   vector<string> PWords1 =  print5NearestEntries(TPWords,s1);
                   string PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict); // map<string,int>&
                   vector<string>  Words = print1OCRNearestEntries(toslp1(s1),vIBook);
                   //cout <<" here " << toDev(Words[0]) << endl;


                   // find nearest confirming to OCR Sugg from Book
                   string nearestCOnfconfirmingSuggvec;
                   vector<string> vec = Words1;
                   int min= 100;
                       for (size_t t=0;t<vec.size();t++){
                       vector<string> wordConfusions; vector<int> wCindex;
                       int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmap,wordConfusions,wCindex);
                       wordConfusions.clear(); wCindex.clear();
                       if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];}
                       }

                   // find nearest confirming to OCR Sugg from PWords
                   string nearestCOnfconfirmingSuggvec1;
                       vector<string> vec1 = PWords1;
                       min= 100;
                           for (size_t t=0;t<vec1.size();t++){
                           vector<string> wordConfusions; vector<int> wCindex;
                           int minFactor = loadWConfusionsNindex1(s1,vec1[t],ConfPmap,wordConfusions,wCindex);
                           wordConfusions.clear(); wCindex.clear();
                           if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t];}
                           }

                   vector<pair<int,string>> vecSugg,vecSugg1;
                   map<string, int> mapSugg;
                   string CSugg = CPair[toslp1(s1)];
                   if(CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
                   if(Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
                   if(Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
                   if(PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
                   if(PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;
                   mapSugg[SamasBreakLRCorrect(toslp1(s1),Dict,PWords,TPWords,TPWordsP)]++;

                   map<string, int> mapsugg1;
                   for(size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
                   if(Words.size() > ksugg1)  mapsugg1[toslp1(Words[ksugg1])]++;
                   if(Words1.size() > ksugg1) mapsugg1[toslp1(Words1[ksugg1])]++;
                   if(PWords1.size() > ksugg1) mapsugg1[toslp1(PWords1[ksugg1])]++;
                   }


                   for( map<string,int>::const_iterator eptr=mapSugg.begin(); eptr!=mapSugg.end(); eptr++){
                       vecSugg.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(s1)),eptr->first));
                   }

                   for( map<string,int>::const_iterator eptr=mapsugg1.begin(); eptr!=mapsugg1.end(); eptr++){
                       vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(s1)),eptr->first));
                   }


                   //vecSugg.push_back(make_pair(editDist(toslp1(s1),s1),s1));
                   //if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(Words[0])),Words[0]));
                   //vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(Words1[0])),Words1[0]));
                   //vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(PairSugg)),PairSugg));
                   sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
                   //cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
                   //Words = suggestions((s1));
                   vecSugg.insert(vecSugg.end(), vecSugg1.begin(), vecSugg1.end());

                   if((vecSugg.size() > 0) && (vecSugg[0].second == sC )) mapSugg1[page_no]++;
                   else if((vecSugg.size() > 1) && (vecSugg[1].second == sC )) mapSugg2[page_no]++;
                   else if((vecSugg.size() > 2) && (vecSugg[2].second == sC )) mapSugg3[page_no]++;
                   else if((vecSugg.size() > 3) && (vecSugg[3].second == sC )) mapSugg4[page_no]++;
                   else if((vecSugg.size() > 4) && (vecSugg[4].second == sC )) mapSugg5[page_no]++;
                   else if((vecSugg.size() > 5) && (vecSugg[5].second == sC )) mapSugg6[page_no]++;
                   else mapTyping[page_no]++;

           }

       //cout << mapCorrect[1]<< " " << mapTyping[1]<< " " <<mapSugg1[1]<< " " <<mapSugg2[1]<< " " <<mapSugg3[1]<< " " <<mapSugg4[1]<< " " <<mapSugg5[1]<< " " <<mapSugg6[1]<<endl;
       //cout << "here" << endl;
       }// for 1st page ends
        mapinCorrect[page_no] = vGsz - mapCorrect[page_no];
       loadMap(localFilenameC,PWords,"PWords");
       map<string, int> PWordspage;
       loadMap(localFilenameC,PWordspage,"PWordspage");
       loadmaptoTrie(TPWords, PWordspage);
       //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
       //cout << vIsz - WER << endl;
       //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
       page_no++;
       filereport = QString::fromStdString(localFilenameC);
       } //  while(1) ends
       page_no--;
       filereport.replace(("Corrected/page-"+ QString::number(page_no) + ".txt"), "SuggReportNearestPriority.txt" );
       std::ofstream rep(filereport.toUtf8().constData());
       rep << "y0 = ["; for( size_t i =1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
       rep << "y1 = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
       rep << "y2 = ["; for( size_t i =1; i <= page_no; i++) rep << mapTyping[i]<< " "; rep << "];" << endl;
       rep << "y3 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg1[i]<< " "; rep << "];" << endl;
       rep << "y4 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg2[i]<< " "; rep << "];" << endl;
       rep << "y5 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg3[i]<< " "; rep << "];" << endl;
       rep << "y6 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg4[i]<< " "; rep << "];" << endl;
       rep << "y7 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg5[i]<< " "; rep << "];" << endl;
       rep << "y8 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg6[i]<< " "; rep << "];" << endl;
       rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8);"<< endl;
       rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#UniqueCorrectSugg1\',\'#UniqueCorrectSugg2\',\'#UniqueCorrectSugg3\',\'#UniqueCorrectSugg4\',\'#UniqueCorrectSugg5\',\'#UniqueCorrectSugg6\' )" << endl;
}

void MainWindow::on_actionErrorDetectionRep_triggered()
{
    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI, strG = strI, strIF = strI, strCF = strI;
    strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");
    strG.replace("Corrected/page-1.txt","GEROCR");strG.replace("Inds/page-1.txt","GEROCR");
    strIF.replace("Corrected/page-1.txt","IEROCR");strIF.replace("Inds/page-1.txt","IEROCR");
    strCF.replace("Corrected/page-1.txt","Corrected.txt");strCF.replace("Inds/page-1.txt","Corrected.txt");//Dict Corrected.txt for lower upper baseline resp
    // load text files one by one
    string locstr;
    vector<string> iocr, gocr;
    std::ifstream sG(strG.toUtf8().constData());
    while(sG >> locstr) gocr.push_back(toslp1(locstr)); sG.close();
    std::ifstream sInd(strIF.toUtf8().constData());
    while(sInd >> locstr) iocr.push_back(toslp1(locstr)); sInd.close();
    cout << strG.toUtf8().constData() << " " << strIF.toUtf8().constData() << endl;
    cout << gocr.size() << " " << iocr.size() << endl;
    size_t winig = iocr.size() - gocr.size();
    if (iocr.size() < gocr.size()) winig = -1*winig;
    size_t iocrdone = 0;// will be used in each page of IEROCR
    map<string,int> mapCF;// F for Full Book
    loadMap(strCF.toUtf8().constData(),mapCF,"Corrected.txt");
    cout << mapCF.size() << endl;
    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    map<size_t, size_t> mapCorrect, mapInCorrect, mapCorrectMarkedCorrect,mapInCorrectMarkedCorrect;

    while(1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
        string no;

        while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
        //QString fileI = QString::fromStdString(localFilenameI);

        //Load page1 of C

        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
        no ="";
        while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
       // QString fileC = QString::fromStdString(localFilenameC);

        // NOW localFilenameI and localFilenameC has page1 of both
        //cout << localFilenameI << " " << localFilenameC << endl;
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while(sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        // if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz =  vecpI.size();
        //if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
        //cout << vGsz << " " << vIsz << endl;
        int win = vGsz  - vIsz;
        if(win<0) win = -1*win;
        win = maxIG(win,5);
        //cout << win << endl;
        //float WER = 0;
        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for(int t = 0; t < vIsz;t++){
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1,sCt1);
                if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1;   }
                if (sCt1 == s1) {/*WER++;*/ break;}
            }
            // now we have IndsWord in s1 and correct word in sC
            //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;

            if((sC == (s1))) {mapCorrect[page_no]++;
            if (searchS1inGVec(s1,iocrdone,gocr,winig)) mapCorrectMarkedCorrect[page_no]++;// else mapCorrectMarkedIncorrect[page_no]++;
            } else {mapInCorrect[page_no]++;  if (searchS1inGVec(s1,iocrdone,gocr,winig)) mapInCorrectMarkedCorrect[page_no]++; }  //(GBook[s1] >0) ||
            iocrdone ++; //(PWords[s1] >0) searchS1inGVec(s1,iocrdone,gocr,winig) mapCF[s1]>0|| Dict[s1]>0
        }

        //loadMap(localFilenameC,PWords,"PWords");
        //map<string, int> PWordspage;
        //loadMap(localFilenameC,PWordspage,"PWordspage");
        //loadmaptoTrie(TPWords, PWordspage);
        //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
        //cout << vIsz - WER << endl;
        //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends
        page_no--;
        filereport.replace(("Corrected/page-"+ QString::number(page_no) + ".txt"), "ErrorDetect.txt" );
        std::ofstream rep(filereport.toUtf8().constData());
        rep << "y0A = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
        rep << "y1A = ["; for( size_t i =1; i <= page_no; i++) rep << mapInCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
        rep << "y2A = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrect[i]<< " "; rep << "];" << endl;
        rep << "y3A = ["; for( size_t i =1; i <= page_no; i++) rep << mapInCorrect[i]<< " "; rep << "];" << endl;

        rep << "x = 1:" << page_no << ";" << endl << "plot(x,y2A,x,y3A,x,y0A,x,y1A);"<< endl;
        rep << "legend(\'CorrectA\',\'InCorrectA\',\'CorrectMarkedcorrectA\', \'InCorrectMarkedCorrectA\')" << endl;

}

void MainWindow::on_actionErrorDetectWithoutAdaptation_triggered()
{
    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;
    map<size_t, size_t> mapCorrect,mapInCorrect, mapCorrectMarkedCorrect,mapInCorrectMarkedCorrect;
    while(1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
        string no;


        while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
        //QString fileI = QString::fromStdString(localFilenameI);

        //Load page1 of C

        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
        no ="";
        while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
       // QString fileC = QString::fromStdString(localFilenameC);

        // NOW localFilenameI and localFilenameC has page1 of both
        //cout << localFilenameI << " " << localFilenameC << endl;
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while(sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        // if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz =  vecpI.size();
        //if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
        //cout << vGsz << " " << vIsz << endl;
        int win = vGsz  - vIsz;
        if(win<0) win = -1*win;
        win = maxIG(win,5);
        //cout << win << endl;
        //float WER = 0;
        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for(int t = 0; t < vIsz;t++){
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1,sCt1);
                if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1;   }
                if (sCt1 == s1) {/*WER++;*/ break;}
            }
            // now we have IndsWord in s1 and correct word in sC
            //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
            if((sC == (s1))) {mapCorrect[page_no]++;
            if ((GBook[s1] >0) ||(PWords[s1] >0)) mapCorrectMarkedCorrect[page_no]++; //else mapCorrectMarkedIncorrect[page_no]++;
            } else {mapInCorrect[page_no]++; if ((GBook[s1] >0) ||(PWords[s1] >0)) mapInCorrectMarkedCorrect[page_no]++;}
        }

        //loadMap(localFilenameC,PWords,"PWords");
        //map<string, int> PWordspage;
        //loadMap(localFilenameC,PWordspage,"PWordspage");
        //loadmaptoTrie(TPWords, PWordspage);
        //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
        //cout << vIsz - WER << endl;
        //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends
        page_no--;
        filereport.replace(("Corrected/page-"+ QString::number(page_no) + ".txt"), "ErrorDetectWOAdapt" );
        std::ofstream rep(filereport.toUtf8().constData());
        rep << "y0 = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
        rep << "y1 = ["; for( size_t i =1; i <= page_no; i++) rep << mapInCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
        rep << "y2 = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrect[i]<< " "; rep << "];" << endl;
        rep << "y3 = ["; for( size_t i =1; i <= page_no; i++) rep << mapInCorrect[i]<< " "; rep << "];" << endl;

        rep << "x = 1:" << page_no << ";" << endl << "plot(x,y2,x,y3,x,y0,x,y1);"<< endl;
        rep << "legend(\'Correct\',\'InCorrect\',\'CorrectMarkedcorrect\', \'InCorrectMarkedCorrect\')" << endl;

}

void MainWindow::on_actionCPair_triggered()
{       // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
        string localFilenameN = strI.toUtf8().constData();
        size_t loc1 = localFilenameN.find("Inds");
        string s1 = localFilenameN.substr(0,loc1);
        std::ofstream repx(s1+"Report/CPair");
        //std::ofstream repy(s1+"Report/inputy");

        while(1) {
            cout << page_no << endl;
            //if(page_no == 199) page_no++;
            string nos = "0123456789";
            string localFilenameI = strI.toUtf8().constData();
            size_t loc = localFilenameI.find(".txt");
            string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
            string no;


            while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
            //cout << stoi(no) + 1 << endl;
            localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
            //cout << localFilename << endl;
            //QString fileI = QString::fromStdString(localFilenameI);

            //Load page1 of C

            string localFilenameC = strC.toUtf8().constData();
            loc = localFilenameC.find(".txt");
            s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
            no ="";
            while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
            //cout << stoi(no) + 1 << endl;
            localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
            //cout << localFilename << endl;
           // QString fileC = QString::fromStdString(localFilenameC);

            // NOW localFilenameI and localFilenameC has page1 of both
            std::ifstream sIpage(localFilenameI);
            if (!(sIpage.is_open())) break;

            std::ifstream sCpage(localFilenameI);
            if (!(sCpage.is_open())) break;

            vector<string> wrong1,right1;
            generatePairs(wrong1,right1,localFilenameI, localFilenameC);//.toUtf8().constData()
            size_t sz = wrong1.size();
            if(sz < right1.size() ) sz = right1.size();
            for(size_t t =0; t < sz;t++){
                if (right1[t] != "") repx << wrong1[t] << "\t" << right1[t] << endl;//
            }

        page_no++;
    }
}

void MainWindow::on_actionToSlp1_2_triggered()
{
        QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

        if(!file1.isEmpty())
        {
            QFile sFile(file1);
            if(sFile.open(QFile::ReadOnly | QFile::Text)){
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN+"slp1");
            string line;
            while(getline(ip,line)) op << toslp1(line) <<endl;
            }
        }
}


void MainWindow::on_actionToDev_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        std::ifstream ip(localFilenameN);
        std::ofstream op(localFilenameN+"Dev");
        string line;
        while(getline(ip,line)) op << toDev(line) <<endl;
        }
    }
}

void MainWindow::on_actionExtractDev_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        std::ifstream ip(localFilenameN);
        std::ofstream op(localFilenameN+"Dev");
        string line;
        while(ip >> line) { if(hasNoAsci(line)) op << (line) <<endl;}
        }
    }
}

void MainWindow::on_actionPrimarySecOCRPair_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            string localFilenameN = file1.toUtf8().constData();
            int loc = localFilenameN.find("IEROCR");
            string localFilenameG = localFilenameN.substr(0,loc) + "GEROCR";
            cout << localFilenameG << endl;
            std::ofstream op(localFilenameN+"ocrPairs");
            vector<string> wrong1,right1;
            generatePairsSpaced(wrong1,right1,localFilenameN, localFilenameG);//.toUtf8().constData()
            size_t sz = wrong1.size();
            if(sz < right1.size() ) sz = right1.size();
            for(size_t t =0; t < sz;t++){
                if (right1[t] != "") op << wrong1[t] << "\t" << right1[t] << endl;//
            }
        }

    }
}



void MainWindow::on_actionCPairGEROcrVsCorrect_triggered()
{
    // Load foders in strC and strI
       QString strI1 = mFilename;

       //strI.replace("Correct", "Inds"); strC.replace("Inds","Correct");
       string strInew = strI1.toUtf8().constData();
       size_t locI = strInew.find("Inds");
       string strI = strInew.substr(0,locI) + "GEROCR";
       string strC = strInew.substr(0,locI) + "Correct";
       // load text files one by one

       //Load page1 of Inds
       //size_t page_no = 1;
           string localFilenameN = strI1.toUtf8().constData();
           size_t loc1 = localFilenameN.find("Inds");
           string s1 = localFilenameN.substr(0,loc1);
           string sRepx = s1+"Reports/inputx";
           string sRepy = s1+"Reports/inputy";
           //std::ofstream repx(s1+"Reports/CPairIEROCR_Vs_Correct");
           //std::ofstream repy(s1+"Report/inputy");

               // NOW localFilenameI and localFilenameC has page1 of both

               //cout << strI << " " << strC<< endl;
               //cout <<repx << endl;
               vector<string> wrong1,right1;
               generatePairsIEROCR(strI, strC,sRepx,sRepy);//.toUtf8().constData()
              /* size_t sz = wrong1.size();
               if(sz < right1.size() ) sz = right1.size();
               for(size_t t =0; t < sz;t++){
                   if ((right1[t] != "") && (right1[t] != "{") && (right1[t] != "}") && (right1[t] != "[") && (right1[t] != "]") )repx << wrong1[t] << "\t" << right1[t] << endl;//
               }*/

          // page_no++;
       //}
}


void MainWindow::on_actionCPairIEROcrVsCorrect_triggered()
{
    // Load foders in strC and strI
       QString strI1 = mFilename;

       //strI.replace("Correct", "Inds"); strC.replace("Inds","Correct");
       string strInew = strI1.toUtf8().constData();
       size_t locI = strInew.find("Inds");
       string strI = strInew.substr(0,locI) + "IEROCR";
       string strC = strInew.substr(0,locI) + "Correct";
       // load text files one by one

       //Load page1 of Inds
       //size_t page_no = 1;
           string localFilenameN = strI1.toUtf8().constData();
           size_t loc1 = localFilenameN.find("Inds");
           string s1 = localFilenameN.substr(0,loc1);
           string sRepx = s1+"Reports/inputx";
           string sRepy = s1+"Reports/inputy";
           //std::ofstream repx(s1+"Reports/CPairIEROCR_Vs_Correct");
           //std::ofstream repy(s1+"Report/inputy");

               // NOW localFilenameI and localFilenameC has page1 of both

               //cout << strI << " " << strC<< endl;
               //cout <<repx << endl;
               vector<string> wrong1,right1;
               generatePairsIEROCR(strI, strC,sRepx,sRepy);//.toUtf8().constData()
              /* size_t sz = wrong1.size();
               if(sz < right1.size() ) sz = right1.size();
               for(size_t t =0; t < sz;t++){
                   if ((right1[t] != "") && (right1[t] != "{") && (right1[t] != "}") && (right1[t] != "[") && (right1[t] != "]") )repx << wrong1[t] << "\t" << right1[t] << endl;//
               }*/

          // page_no++;
       //}
}

void MainWindow::on_actionEditDistRep_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        std::ifstream ip1(localFilenameN); std::ifstream ip2(localFilenameN+"y");
        std::ofstream op(localFilenameN+"EditDisRep");
        string word1,word2;
        int max = 0;
        op << "a = [";
        while(getline(ip1,word1)) {
            //istringstream l(line);
            //string word1, word2;
            //l >> word1; l >> word2;
            getline(ip2,word2);
            int ed = editDist(word1,word2);
            op << ed << " ";
            if (ed > max ) max = ed;
        }
        op << "];" << endl;
        op << " hist(a,-0.5:0.5:max(a))" << endl << "pause()" << endl;


        }
    }
}

void MainWindow::on_actionFilterOutGT50EditDisPairs_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        std::ifstream ip(localFilenameN);
        std::ofstream op(localFilenameN+"EditDisLE50FilteredRep");
        string line;
        while(getline(ip,line)) {
            stringstream l(line);
            string word1, word2;
            getline(l, word1, '\t');
            getline(l, word2, '\t');
            //data >> word1 >> word2;
            int ed = editDist(word1,word2);
            if (ed <= 50 )  op << word1 << "\t" << word2 << endl;
        }
        }
    }
}

void MainWindow::on_actionConfusionFreqHist_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        std::ifstream ip(localFilenameN);
        std::ofstream op(localFilenameN+"HistOCtaveRep");
        std::ofstream opx(localFilenameN+"HistXaxisRep");
        string line;
        op << "a = [";
        while(getline(ip,line)) {
           opx << line << "\t" << endl;
           line = "";
           getline(ip,line);
           op << line << " ";

        }
        op << "];" << endl;
        op << " hist(a,-0.5:0.5:max(a))" << endl << "pause()" << endl;


        }
    }
}





void MainWindow::on_actionPrepareFeatures_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this,"Open a File");

    if(!file1.isEmpty())
    {
        QFile sFile(file1);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
        string localFilenameN = file1.toUtf8().constData();
        QString strI1 = file1;
        strI1.replace("Dict", "CPair");
        string strI1s = strI1.toUtf8().constData();

        map<string,int> Dictionary;
        map<string,int> DictionaryNGrams;
        loadMap(localFilenameN,Dictionary,"Dictionary");
        size_t count6 = 0;
        loadDictPatternstoMap(DictionaryNGrams,Dictionary,count6);

        //get MaxSize of OCR word
        size_t MaxElSize = 0; string line1;
        ifstream infile1(strI1s);
        while (getline(infile1, line1)) {
            vector<std::string> x = split(line1, "\t");
                    string a2 = toslp1(x[0]);
                    if(a2.size() > MaxElSize) MaxElSize = a2.size();
        }
        infile1.close();
        cout<<"MaxElSize "<<MaxElSize<<endl;
        ifstream infile(strI1s);
        ofstream outfile;
        outfile.open(strI1s+"out");
        string line, a, b;
        size_t M = (MaxElSize*(MaxElSize-1))/2;
        while (getline(infile, line)) {
            vector<std::string> x = split(line, "\t");
                    a = toslp1(x[0]); b = toslp1(x[1]);
            if (a == b) outfile << "1 ";
            else outfile << "-1 ";

            // a is OCR word

            // Feature 1 a Freq in Dict
            if (Dictionary[a] > 0) outfile << "1:"<< Dictionary[a] << " ";
            else outfile << "1:0 ";

            //Feature 2 ngrams from a in DictionaryNGrams or not
            // vector<float> vecfreq;
            string a1 = a;
            size_t ia1 = 0;
            while (ia1 < MaxElSize - a.size()){
                a1 = a1 + "^";
                ia1 = ia1 + 1;
            }
            //cout << a1 << endl;
            vector<bool> vecBin; vector<size_t> vecBinFreq; size_t count = 0;
            getNgramFeaturesinVect(a1,DictionaryNGrams,vecBin,vecBinFreq,count);
            //cout << vecBin.size() << endl;
            size_t vBsz = vecBin.size();
            for (size_t i=0;i<vBsz;i++){
                if(vecBin[i]) outfile << i+2 << ":" << 1 <<" ";
                else outfile << i+2 << ":" << -1 <<" ";
            }
            float count6f = count6;
            //Feature3 vecBinFreq
            for (size_t i=0;i<vecBinFreq.size();i++){
                float vbnf = vecBinFreq[i];
                outfile << i+2+vBsz << ":" << vbnf/count6f <<" ";
            }


            /*for (size_t i=vecBin.size();i<M ;i++){
                outfile << i+2 << ":" << vecBin[i]<<" ";
            }*/
            outfile<<endl;
        } // WHILE CPAIR input
        outfile.close();
        infile.close();
        }
    }
}

void MainWindow::on_actionErrorDetectionRepUniq_triggered()
{
    map<size_t, size_t> mapCorrect,mapinCorrect,mapTyping,mapSugg1,mapSugg2,mapSugg3,mapSugg4,mapSugg5,mapSugg6,mapSugg7,mapSugg8,mapSugg9,mapSugg10;

    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("Corrected", "Inds"); strC.replace("Inds","Corrected");

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while(1) {

    string nos = "0123456789";
    string localFilenameI = strI.toUtf8().constData();
    size_t loc = localFilenameI.find(".txt");
    string s = localFilenameI.substr(loc-1,1); // page-123.txt s = 3
    string no;

    vector<string> wrong, right;
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
    //cout << stoi(no) + 1 << endl;
    localFilenameI.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
    //cout << localFilename << endl;
    //QString fileI = QString::fromStdString(localFilenameI);

    //Load page1 of C

    string localFilenameC = strC.toUtf8().constData();
    loc = localFilenameC.find(".txt");
    s = localFilenameC.substr(loc-1,1); // page-123.txt s = 3
    no ="";
    while(nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc-1,1);  } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
    //cout << stoi(no) + 1 << endl;
    localFilenameC.replace(loc,no.size(),to_string(page_no));//to_string(stoi(no) + 1)
    //cout << localFilename << endl;
   // QString fileC = QString::fromStdString(localFilenameC);

    // NOW localFilenameI and localFilenameC has page1 of both
    //cout << localFilenameI << " " << localFilenameC << endl;
    // load fileI in vecpI and
    vector<string> vecpI, vecpC;
    map<string, bool> isAscii;
    std::ifstream sIpage(localFilenameI);
    if (!(sIpage.is_open())) break; // break the while loop for page_no
    string localstr;
    while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
    std::ifstream sCpage(localFilenameC);
    while(sCpage >> localstr) { if(hasM40PerAsci(localstr)){isAscii[toslp1(localstr)] = 1;}  vecpC.push_back(toslp1(localstr));} sIpage.close();

    // if 1st word is wrong generate suggestions
    int vGsz = vecpC.size(), vIsz =  vecpI.size();
    if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
    //cout << vGsz << " " << vIsz << endl;
    int win = vGsz  - vIsz;
    if(win<0) win = -1*win;
    win = maxIG(win,5);
    //cout << win << endl;
    //float WER = 0;
    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
    for(int t = 0; t < vIsz;t++){
        size_t minedit = 1000;
        string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
        string sC;
        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
            string sCt1 = vecpC[t1];
            size_t mineditIC = editDist(s1,sCt1);
            if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1;   }
            if (sCt1 == s1) {/*WER++;*/ break;}
        }

        // now we have IndsWord in s1 and correct word in sC
        //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
        if((sC == (s1))){
        mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
        }else if(!isAscii[sC]) { wrong.push_back(s1); right.push_back(sC);
            //cout<< " inside incorrect words ke liye else" << endl;
            vector<string>  Words1 =  print5NearestEntries(TGBook,s1); //2
            if(Words1.size() == 0) Words1.push_back("");
            string nearestCOnfconfirmingSuggvec; //1
            vector<string> vec = Words1;
            int min= 100;
                for (size_t t=0;t<vec.size();t++){
                vector<string> wordConfusions; vector<int> wCindex;
                int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmap,wordConfusions,wCindex);
                wordConfusions.clear(); wCindex.clear();
                if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];}
                }
            //cout << "sz" << Words1.size() << " "<< Words1[0]<< endl;
            if(nearestCOnfconfirmingSuggvec == (sC)){mapSugg1[page_no]++; }
            else if((Words1[0] == (sC))){mapSugg2[page_no]++; }
            else {

                vector<string> Alligned =  print5NearestEntries(TGBookP,s1); //6
                if(Alligned.size() == 0) Alligned.push_back("");

                string PairSugg = "";
                if(Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);//3
                //cout << sC << "PairSugg " << PairSugg<<endl;
                if(PairSugg == sC) {  mapSugg3[page_no]++;}
                else{ vector<string>  Words = print1OCRNearestEntries(toslp1(s1),vIBook); // 4 primary doc based
                    if(Words.size() == 0) Words.push_back("");
                    if(Words[0] == (sC)) { mapSugg4[page_no]++;  }
                    else { string samassugg = SamasBreakLRCorrect(toslp1(s1),Dict,PWords,TPWords,TPWordsP); // 5
                        if(samassugg == sC) { mapSugg5[page_no]++; }
                         else {
                            vector<string> PWords1 =  print5NearestEntries(TPWords,s1); // 6
                            if(PWords1.size() == 0) PWords1.push_back("");
                            if(PWords1[0] == (sC)) { mapSugg6[page_no]++; }
                             else {string nearestCOnfconfirmingSuggvecFont;
                                int min= 100;
                                    for (size_t t=0;t<vec.size();t++){
                                    vector<string> wordConfusions; vector<int> wCindex;
                                    int minFactor = loadWConfusionsNindex1(s1,vec[t],ConfPmapFont,wordConfusions,wCindex);
                                    wordConfusions.clear(); wCindex.clear();
                                    if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t];}
                                    }
                                if(nearestCOnfconfirmingSuggvecFont == sC) {mapSugg7[page_no]++;}
                                else{
                                    /*string PairSuggFont = "";
                                    if(Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);//3
                                    //cout << sC << "PairSugg " << PairSugg<<endl;
                                    if(PairSuggFont == sC) {  mapSugg8[page_no]++;}*/
                                    vector<string> Wordsdict;  {Wordsdict =  print5NearestEntries(TDict,s1);}
                                    if((Wordsdict.size()>0)&&(Wordsdict[0] == sC)) {  mapSugg8[page_no]++; }
                                    else{
                                        string sugg9 = generatePossibilitesNsuggest(s1,TopConfusions,TopConfusionsMask,Dict,SRules);
                                        if(sugg9 == sC) {  mapSugg9[page_no]++;
                                        //cout << s1 << " "<<sC << endl;
                                        }
                                        else{ if(LSTM[s1] == sC) {mapSugg10[page_no]++;
                                            cout << s1 << " lstm " << sC <<endl;}
                                            else mapTyping[page_no]++;}
                                    }
                                }
                            }
                        }
                    }
                }

            }

        } else{mapTyping[page_no]++;} // else
    //cout << mapCorrect[1]<< " " << mapTyping[1]<< " " <<mapSugg1[1]<< " " <<mapSugg2[1]<< " " <<mapSugg3[1]<< " " <<mapSugg4[1]<< " " <<mapSugg5[1]<< " " <<mapSugg6[1]<<endl;
    //cout << "here" << endl;
    }// for 1st page ends
    mapinCorrect[page_no] = vIsz - mapCorrect[page_no];
    //Loading PWords:-
    cout << "page_no = "<< page_no << endl;
    loadMap(localFilenameC,PWords,"PWords");
    map<string, int> PWordspage;
    loadMap(localFilenameC,PWordspage,"PWordspage");
    loadmaptoTrie(TPWords, PWordspage);
    //generateCorrectionPairs(wrong,right,str2.toUtf8().constData(), str1.toUtf8().constData());
    loadConfusionsFont(wrong,right,ConfPmap);
    loadConfusionsFont(wrong,right,ConfPmapFont);
    TopConfusions.clear(); TopConfusionsMask.clear();
    loadTopConfusions(ConfPmap,TopConfusions,TopConfusionsMask);



    //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
    //cout << vIsz - WER << endl;
    //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
    page_no++;
    filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends
    page_no--;
    filereport.replace(("Corrected/page-"+ QString::number(page_no) + ".txt"), "SuggReportUniq1.txt" );
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for( size_t i =1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for( size_t i =1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for( size_t i =1; i <= page_no; i++) rep << mapTyping[i]<< " "; rep << "];" << endl;
    rep << "y3 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg1[i]<< " "; rep << "];" << endl;
    rep << "y4 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg2[i]<< " "; rep << "];" << endl;
    rep << "y5 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg3[i]<< " "; rep << "];" << endl;
    rep << "y6 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg4[i]<< " "; rep << "];" << endl;
    rep << "y7 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg5[i]<< " "; rep << "];" << endl;
    rep << "y8 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg6[i]<< " "; rep << "];" << endl;
    rep << "y9 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg7[i]<< " "; rep << "];" << endl;
    rep << "y10 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg8[i]<< " "; rep << "];" << endl;
    rep << "y11 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg9[i]<< " "; rep << "];" << endl;
    rep << "y12 = ["; for( size_t i =1; i <= page_no; i++) rep << mapSugg10[i]<< " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8,x,y9,x,y10,x,y11);"<< endl;
    rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#CorrectSugg1\',\'#CorrectSugg2\',\'#CorrectSugg3\',\'#CorrectSugg4\',\'#CorrectSugg5\',\'#CorrectSugg6\',\'#CorrectSugg7\',\'#CorrectSugg8\',\'#CorrectSugg9\' )" << endl;
    rep <<"TotalSuggestions =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11)" << endl;
    rep <<"TotalSuggestionsWithLSTM =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11+y12)" << endl;
}

void MainWindow::on_actionSanskrit_triggered()
{
    HinFlag = 0 , SanFlag = 1;
}

void MainWindow::on_actionHindi_triggered()
{
    HinFlag = 1 , SanFlag = 0;
}

void MainWindow::on_actionEnglish_triggered()
{
    HinFlag = 0 , SanFlag = 0;
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    checked ? ui->textBrowser->setFontWeight(QFont::Bold) : ui->textBrowser->setFontWeight(QFont::Normal);
}
