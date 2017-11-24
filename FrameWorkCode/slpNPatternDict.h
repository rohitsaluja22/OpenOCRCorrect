#ifndef SLPNPATTERNDICT_H
#define SLPNPATTERNDICT_H
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
//#include <boost/serialization/map.hpp>
//#include <boost/serialization/vector.hpp>
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/unordered_map.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include "toFromslp1.h"
using namespace std;
bool HinFlag = 0, SanFlag = 1;

string ReplaceString(string subject, const string& search, const string& replace)
{
    size_t pos=0;
    while((pos=subject.find(search, pos)) != string::npos)
    {
        subject.replace(pos, search.length(),replace);
        pos+=1;
    }
    return subject;
}

string ReplaceStringRestricted(string subject, const string& search, const string& replace)
{
    size_t pos=0;
    char c;
    string replace_new=replace+"a";
    // replace_new=replace_new+m;
    //cout<<"here "<<subject<<endl;
    while((pos=subject.find(search, pos)) != string::npos)
    {   if(pos == subject.size()) break;
        //cout << subject<< " "<<pos <<" "<<subject.size()<< endl;
        if( subject.size() == pos + 3) c=subject.at(pos+2); else c=subject.at(pos+3);
          //CHANGE TO 3 IF EVERYTHING DOES NOT WORK
        if(c=='A' || c=='i' || c=='I' || c=='u' || c=='U' || c=='f' || c=='F' || c=='x' || c=='X' || c=='e' || c=='E' || c=='o' || c=='O')
            subject.replace(pos, search.length(),replace);
        else
            subject.replace(pos, search.length(),replace_new);
        pos+=1;
    }
    //cout<<"here21 "<<subject<<endl;
    return subject;
}



string toDev(string s)
{ //Hin:-
    if (HinFlag){
    string vowel_dn[]={"अ","आ","इ","ई","उ","ऊ","ऋ","ए","ऐ","ओ","औ","ऑ","ं","ः","ँ","ॅ"};
        string vowel_dn_joiner[]={"","ा","ि","ी","ु","ू","ृ","े","ै","ो","ौ","ॉ"};
        string vowel_slp1[]={"a","A","i","I","u","U","f","e","E","o","O","Z","M","H","*","~"};
        string consonants_dn[]={"क","ख","ग","घ","ङ","च","छ","ज","झ","ञ","ट","ठ","ड","ढ","ण","त","थ","द","ध","न","प","फ","ब","भ","म","य","र","ल","व","श","ष","स","ह","क़","ख़","ग़","ज़","ड़","ढ़","ऩ","फ़","य़","ऱ","ळ"};
        string consonants_dn_halanta[]={"क्","ख्","ग्","घ्","ङ्","च्","छ्","ज्","झ्","ञ्","ट्","ठ्","ड्","ढ्","ण्","त्","थ्","द्","ध्","न्","प्","फ्","ब्","भ्","म्","य्","र्","ल्","व्","श्","ष्","स्","ह्","क़्","ख़्","ग़्","ज़्","ड़्","ढ़्","ऩ्","फ़्","य़्","ऱ्","ळ्"};
        string consonants_slp1[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","@","#","$","F","x","X","%","^","L","V","&"};
        string no_dn[]={"०","१","२","३","४","५","६","७","८","९","॥","।","–","—"};
        string no_slp1[]={"0","1","2","3","4","5","6","7","8","9","||","|","-","-"};

        for(int i=0;i<44;i++)
                {
                    s=ReplaceString(s,consonants_slp1[i],consonants_dn_halanta[i]);
                }
                for(int i=0;i<12;i++)
                {
                    s=ReplaceString(s,"्"+vowel_slp1[i],vowel_dn_joiner[i]);
                }
                for(int i=0;i<16;i++)
                {
                    s=ReplaceString(s,vowel_slp1[i],vowel_dn[i]);
                }
                for(int i=0;i<13;i++)
                {
                    s=ReplaceString(s,no_slp1[i],no_dn[i]);
                }
    }
else if(SanFlag ){
    string vowel_dn[]={"अ","आ","इ","ई","उ","ऊ","ऋ","ॠ","ऌ","ॡ","ए","ऐ","ओ","औ","ं","ः","ँ","ᳲ","ᳳ","ऽ","ॐ"};
    string vowel_dn_joiner[]={"","ा","ि","ी","ु","ू","ृ","ॄ","ॢ","ॣ","े","ै","ो","ौ"};
    //string consonants_dn[]={"क","ख","ग","घ","ङ","च","छ","ज","झ","ञ","ट","ठ","ड","ढ","ण","त","थ","द","ध","न","प","फ","ब","भ","म","य","र","ल","व","श","ष","स","ह","ळ"};
    string consonants_dn_halanta[]={"क्","ख्","ग्","घ्","ङ्","च्","छ्","ज्","झ्","ञ्","ट्","ठ्","ड्","ढ्","ण्","त्","थ्","द्","ध्","न्","प्","फ्","ब्","भ्","म्","य्","र्","ल्","व्","श्","ष्","स्","ह्","ळ्"};
    string vowel_slp1[]={"a","A","i","I","u","U","f","F","x","X","e","E","o","O","M","H","~","Z","V","$","%"};
    string consonants_slp1[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","L"};
    string numbers_etc_dn[]={"१","२","३","४","५","६","७","८","९","०","।","॥","॰","ऽ","’","‘","”","“","ॐ"};
    string numbers_eng[]={"1","2","3","4","5","6","7","8","9","0","|","||","0","$","'","'","''","''","%"};


        for(int i=0;i<34;i++)
        {
            s=ReplaceString(s,consonants_slp1[i],consonants_dn_halanta[i]);
        }
        //cout << "here1 " << s <<endl;
        for(int i=0;i<14;i++)
        {
            s=ReplaceString(s,"्"+vowel_slp1[i],vowel_dn_joiner[i]);
        }
        //cout << "here2 " << s <<endl;
        for(int i=0;i<21;i++)
        {
            s=ReplaceString(s,vowel_slp1[i],vowel_dn[i]);
        }
        //cout << "here3 " << s <<endl;
        for(unsigned int i=0;i<(sizeof(numbers_etc_dn)/sizeof(numbers_etc_dn[0]));i++)
        {
            s=ReplaceString(s,numbers_eng[i],numbers_etc_dn[i]);
        }
        //cout << "here3 " << s <<endl;
        //cout<<s<<endl;
    }

    return s;
}


string toslp1(string s)
{ //Hin:-
    if (HinFlag){
        string vowel_dn[]={"अ","आ","इ","ई","उ","ऊ","ऋ","ए","ऐ","ओ","औ","ऑ","ं","ः","ँ","ॅ"};
        string vowel_dn_joiner[]={"ा","ि","ी","ु","ू","ृ","े","ै","ो","ौ","ॉ"};
        string vowel_slp1[]={"a","A","i","I","u","U","f","e","E","o","O","Z","M","H","*","~"};
        string consonants_dn[]={"क","ख","ग","घ","ङ","च","छ","ज","झ","ञ","ट","ठ","ड","ढ","ण","त","थ","द","ध","न","प","फ","ब","भ","म","य","र","ल","व","श","ष","स","ह","क़","ख़","ग़","ज़","ड़","ढ़","ऩ","फ़","य़","ऱ","ळ"};
        string consonants_dn_halanta[]={"क्","ख्","ग्","घ्","ङ्","च्","छ्","ज्","झ्","ञ्","ट्","ठ्","ड्","ढ्","ण्","त्","थ्","द्","ध्","न्","प्","फ्","ब्","भ्","म्","य्","र्","ल्","व्","श्","ष्","स्","ह्","क़्","ख़्","ग़्","ज़्","ड़्","ढ़्","ऩ्","फ़्","य़्","ऱ्","ळ्"};
        string consonants_slp1[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","@","#","$","F","x","X","%","^","L","V","&"};
        string no_dn[]={"०","१","२","३","४","५","६","७","८","९","।","॥","–","—"};
        string no_slp1[]={"0","1","2","3","4","5","6","7","8","9","|","||","-","-"};

        for(int i=0;i<44;i++)
                {
                    s=ReplaceString(s,consonants_dn_halanta[i],consonants_slp1[i]);
                }
                for(int i=0;i<11;i++)
                {
                    s=ReplaceString(s,vowel_dn_joiner[i],vowel_slp1[i+1]);
                }
                for(int i=0;i<16;i++)
                {
                    s=ReplaceString(s,vowel_dn[i],vowel_slp1[i]);
                }
                for(int i=0;i<43;i++)
                {
                    s=ReplaceStringRestricted(s,consonants_dn[i],consonants_slp1[i]);
                }
                for(int i=0;i<14;i++)
                {
                    s=ReplaceString(s,no_dn[i],no_slp1[i]);
                }

    }
    else if(SanFlag){
 //San:-
        string vowel_dn[]={"अ","आ","इ","ई","उ","ऊ","ऋ","ॠ","ऌ","ॡ","ए","ऐ","ओ","औ","ं","ः","ँ","ᳲ","ᳳ"};
        string vowel_dn_joiner[]={"ा","ि","ी","ु","ू","ृ","ॄ","ॢ","ॣ","े","ै","ो","ौ"};
        string consonants_dn[]={"क","ख","ग","घ","ङ","च","छ","ज","झ","ञ","ट","ठ","ड","ढ","ण","त","थ","द","ध","न","प","फ","ब","भ","म","य","र","ल","व","श","ष","स","ह","ळ"};
        string consonants_dn_halanta[]={"क्","ख्","ग्","घ्","ङ्","च्","छ्","ज्","झ्","ञ्","ट्","ठ्","ड्","ढ्","ण्","त्","थ्","द्","ध्","न्","प्","फ्","ब्","भ्","म्","य्","र्","ल्","व्","श्","ष्","स्","ह्","ळ्"};
        string vowel_slp1[]={"a","A","i","I","u","U","f","F","x","X","e","E","o","O","M","H","~","Z","V"};
        string consonants_slp1[]={"k","K","g","G","N","c","C","j","J","Y","w","W","q","Q","R","t","T","d","D","n","p","P","b","B","m","y","r","l","v","S","z","s","h","L"};
        //cout<<s<<endl;
        size_t pos = 0;
        while((pos=s.find("ॆ", pos)) != string::npos)
        s.replace(pos, 3,"े");

        pos = 0;
        while((pos=s.find("ऎ", pos)) != string::npos)
        s.replace(pos, 3,"एे");

        size_t pos1 = 0;
        while((pos1=s.find("ॊ", pos1)) != string::npos)
        s.replace(pos1, 3,"ो");
        //cout<<s<<endl;
        pos1 = 0;
        //cout<<s<<" "<<s.find("ऴ्", pos1)<<endl;
        while((pos1=s.find("ऴ्", pos1)) != string::npos)//"ळ" is valid, dot below "ळ" is invalid char
        {s.replace(pos1, 6,"ळ्"); }
        //cout<<s<<endl;
        pos1 = 0;
        //cout<<s<<" "<<s.find("ऴ", pos1)<<endl;
        while((pos1=s.find("ऴ", pos1)) != string::npos)//"ळ" is valid, dot below "ळ" is invalid char
        {s.replace(pos1, 6,"ळ"); }
        //cout<<s<<endl;

        for(int i=0;i<34;i++)
        {
            s=ReplaceString(s,consonants_dn_halanta[i],consonants_slp1[i]);
        }

        for(int i=0;i<13;i++)
        {
            s=ReplaceString(s,vowel_dn_joiner[i],vowel_slp1[i+1]);
        }

        for(int i=0;i<19;i++)
        {
            s=ReplaceString(s,vowel_dn[i],vowel_slp1[i]);
        }
        //cout<<"here "<< s<<endl;
        for(int i=0;i<34;i++)
        {   //cout<< i << " " << consonants_dn[i] << " " << consonants_slp1[i] << endl;
            s=ReplaceStringRestricted(s,consonants_dn[i],consonants_slp1[i]);
        }
        //cout<<"here1 "<< s<<endl;
        //cout<<s<<"…"<<s.find("…", pos1)<<endl;
        string numbers_etc_dn[]={"१","२","३","४","५","६","७","८","९","०","।","॥","॰","ऽ","’","‘","”","“","ॐ"};
        string numbers_eng[]={"1","2","3","4","5","6","7","8","9","0","|","||","0","$","'","'","''","''","%"};
        for(uint i=0;i<(sizeof(numbers_etc_dn)/sizeof(numbers_etc_dn[0]));i++)
        {
            s=ReplaceString(s,numbers_etc_dn[i],numbers_eng[i]);
        }
    } //ifSanflag over
return s;
}

void printmapinDev(map<string,int> m1){

/*std::ofstream ss1("ppi.bin");
   boost::archive::text_oarchive oarch1(ss1);
   oarch1 << PatWInst;*/
for( map<string,int>::const_iterator eptr=m1.begin(); eptr!=m1.end(); eptr++)
               cout << toDev(eptr->first) << endl;
}

void printmap(map<string,int>& m1){

/*std::ofstream ss1("ppi.bin");
   boost::archive::text_oarchive oarch1(ss1);
   oarch1 << PatWInst;*/
for( map<string,int>::const_iterator eptr=m1.begin(); eptr!=m1.end(); eptr++)
               cout << (eptr->first) << endl;
}

void printmapstrstr(map<string,string>& m1){

/*std::ofstream ss1("ppi.bin");
   boost::archive::text_oarchive oarch1(ss1);
   oarch1 << PatWInst;*/
for( map<string,string>::const_iterator eptr=m1.begin(); eptr!=m1.end(); eptr++)
               cout << (eptr->first) << " " <<(eptr->second) << endl;
}

void printmapWFreq(map<string,int>& m1){

/*std::ofstream ss1("ppi.bin");
   boost::archive::text_oarchive oarch1(ss1);
   oarch1 << PatWInst;*/
for( map<string,int>::const_iterator eptr=m1.begin(); eptr!=m1.end(); eptr++)
               cout << (eptr->first) << " " <<(eptr->second) << endl;
}



void loadCwordsPair(string wordL,string wordR, map<string, string>& CPair,map<string,int>& Dict,map<string,int>&  PWords){
if ((Dict[wordL] ==0) && (PWords[wordL] == 0)) CPair[wordL] = wordR;
}

void loadCPair(string filename, map<string, string>& CPair,map<string,int>&  Dict, map<string,int>&  PWords){
ifstream myfile(filename);
          if (myfile.is_open())
          { string str1, str2;
        while (myfile >> str1 ) {myfile >> str2;
loadCwordsPair(toslp1(str1),toslp1(str2),CPair,Dict,PWords);}
        cout <<"CPairs " << CPair.size() <<  " loaded" << endl;
          } else cout <<"Error:" << filename <<  "CPair NOT there/loaded" << endl;
}

void loadMapNV(string fileName, map<string,int>& OCRWords, vector<string>& vec, string GBook){
ifstream myfile(fileName);
      if (myfile.is_open())
      { string str1;
    while (myfile >> str1 ) { str1 = toslp1(str1); OCRWords[str1] = OCRWords[str1] + 1;vec.push_back(str1);}
    cout <<GBook <<" " <<OCRWords.size() <<" Words Loaded in mapNvector" << endl;
    } else cout <<"Error:" << GBook<<  "Words NOT Loaded in mapNvector" << endl;
}

int minIG(int a, int b){ if(a>b)return b; else return a;}
int maxIG(int a, int b){ if(a<b)return b; else return a;}


void loadMapPWords(vector<string>& vGBook,vector<string>& vIBook, map<string,int>& PWords){
    int vGsz = vGBook.size(), vIsz =  vIBook.size();
    int win = vGsz  - vIsz;
    if(win<0) win = -1*win;
    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
    for(int t = 0; t < vIsz;t++){
        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
            string s1 = vIBook[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            if( (vGBook[t1].find(s1) != string::npos)|| (vGBook[t1].find(s1 + " ") != string::npos) || (vGBook[t1].find(" " + s1) != string::npos)) {PWords[s1]++; break;}
        }
    }
cout << PWords.size() << " words loaded in PWords" << endl;
}

string findDictEntries1(string s1,  map<string, int>& m2, map<string, int>& m1, int size) { //unordered_

if((s1.size() == 0) || (s1 == "")) return "";

//cout << "s1  "<< s1 << endl;

//cout << s1 << endl;
//rAmaAnand
for(size_t j =0; j < s1.size() ; j++){ //- i +1 j= 0:8
    for(size_t i = s1.size() - j; i > 0; i--){// j0 i = 9:1 rAmaAnand rAmaAnan rAmaAna.. , j1  8:2
    string str = s1.substr(j,i); //&&((str.size() >= 3)|| ( (str.size()==2) && (str[1] != 'a') &&( size< 3) ) || ((str.size() ==1)&&( size< 2) ) ))
    //cout << "str  "<< str << endl;
    if((m2[str]>0)||(m1[str]>0)) { //cout << "here "<< str << "L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
            //colorFlag = !colorFlag;
            //string strcolor = color[colorFlag];// << endl;
            //cout << "str  "<< str << endl;
            return findDictEntries1(s1.substr(0,j),m2,m1,size) + "<font color=\'" + "green" + "\'>" + toDev(str) + "</font>" +  findDictEntries1(s1.substr(j+i,s1.size()-i),m2,m1,size);


            }
    }
    }
//cout << "here2 "<< str << "sd"<< endl;
return ("<font color=\'red\'>" + toDev(s1) + "</font>");
}

string findDictEntries(string s1,  map<string, int>& m2, map<string, int>& m1, int size) { //unordered_
m2["rAma"]++;
m2["rAm"]++;
string s = findDictEntries1(s1,m2,m1, size);

string vowel_dn[]={"आ","इ","ई","उ","ऊ","ऋ","ॠ","ऌ","ॡ","ए","ऐ","ओ","औ"};
string vowel_dn_joiner[]={"ा","ि","ी","ु","ू","ृ","ॄ","ॢ","ॣ","े","ै","ो","ौ"};
//cout << s << endl;
size_t t1 = s.find("\'>");
string sL = s.substr(0,t1+3);
string sR = s.substr(t1+3,s.size()-t1-3);
//cout << sL << " " << sR << endl;
for(size_t t =0; t< 12; t++){
    string tofind = "\'>" + vowel_dn[t];
while((sR.find(tofind) != string::npos)){
    //cout << s << endl; cout << s.find(tofind) << endl;
   sR.replace(sR.find(tofind),tofind.size(), "\'>" + vowel_dn_joiner[t]); //cout << s << endl;
}
}
return sL + sR;

}

bool hasM40PerAsci(string word1){
    if(SanFlag||HinFlag){
    string asc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    size_t sz = word1.size();
    double cnt = 0;
    for(size_t t =0; t < sz; t++){
        if(asc.find(word1.substr(t,1)) != string::npos) cnt ++;
        if (cnt/(0.4) >= sz) return 1;
    }
    }
    return 0;
}

bool hasNoAsci(string word1){
    string asc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    size_t sz = word1.size();
    for(size_t t =0; t < sz; t++){
        if(asc.find(word1.substr(t,1)) != string::npos) {return 0; }
    }
    return 1;
}

void loadMap(string fileName, map<string,int>& OCRWords, string GBook){
    size_t szp = OCRWords.size();
ifstream myfile(fileName);
      if (myfile.is_open())
      { string str1;
    while (myfile >> str1 ) { if(!hasM40PerAsci(str1)) {str1 = toslp1(str1); /*cout <<str1<<endl;*/ OCRWords[str1] = OCRWords[str1] + 1;}}
    cout << GBook <<" " <<OCRWords.size() - szp<<" Words Loaded" << endl;
    } else cout <<"Error:" << GBook<<  "Words NOT Loaded" << endl;
}

// ADDED FOR FEATYRE EXTRACTION
bool insertPatternstoMap(string str, map<string,int>& TPWordsP, size_t& count ,size_t& count6){ //map<string,int >&  PWordsP
    size_t sz = str.size();
    if(sz == 0) return 1;
    for(size_t i = 0; i < (sz+1); i++){
        string s1 = str.substr(0,i);
        if (s1.size()<9) count6++;
       TPWordsP[s1]++; count++;//PWordsP[s1]++;
    }
    return insertPatternstoMap(str.substr(1,sz-1),TPWordsP,count,count6);//PWordsP
}

// ADDED FOR FEATYRE EXTRACTION
//loadPWordsPatternstoTrie(TPWordsP,PWordsP,PWords);
size_t loadDictPatternstoMap(map<string,int >& TPWordsP, map<string,int >& PWords,size_t& count6){ // arg1(strt from 0) ,map<string,int >& PWordsP
    size_t count = 0,maxsiz = 0;
        for( map<string,int >::const_iterator ptr=PWords.begin();
             ptr!=PWords.end(); ptr++) {
           insertPatternstoMap(ptr->first, TPWordsP,count,count6);
           if (ptr->first.size() > maxsiz) maxsiz = ptr->first.size();
        }
        cout << count <<" patterns loaded " << endl;
               //cout << "m2 size " << m2.size() << endl;
        return maxsiz;
    }
// ADDED FOR FEATYRE EXTRACTION
bool getNgramFeaturesinVect(string str,map<string,int>& Dict,vector<bool>& vb,vector<size_t>& vbf, size_t& count){
    size_t sz = str.size();
    //cout<<sz<<endl;
    if(sz == 1) return 1;
    for(size_t i = 2; i < (sz+1); i++){
        string s1 = str.substr(0,i);
        //cout<<s1<<endl;
       if(s1.size() < 9){
       if (Dict[s1]>0){vb.push_back(1); vbf.push_back(Dict[s1]);} else {vb.push_back(0); vbf.push_back(0);}
       count++;
       }
       //cout << vb[count]<<endl;
    }
    return getNgramFeaturesinVect(str.substr(1,sz-1),Dict,vb,vbf, count);//PWordsP
}



// ADDED FOR FEATYRE EXTRACTION
//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
bool endsWith(const std::string& s, const std::string& suffix)
{
    return s.size() >= suffix.size() &&
           s.substr(s.size() - suffix.size()) == suffix;
}
// ADDED FOR FEATYRE EXTRACTION
std::vector<std::string> split(const std::string& s, const std::string& delimiter, const bool& removeEmptyEntries = false)
{
    std::vector<std::string> tokens;

    for (size_t start = 0, end; start < s.length(); start = end + delimiter.length())
    {
         size_t position = s.find(delimiter, start);
         end = position != string::npos ? position : s.length();

         std::string token = s.substr(start, end - start);
         if (!removeEmptyEntries || !token.empty())
         {
             tokens.push_back(token);
         }
    }

    if (!removeEmptyEntries &&
        (s.empty() || endsWith(s, delimiter)))
    {
        tokens.push_back("");
    }

    return tokens;
}


//ADDED FOR ERROR DETECTION REPORT

bool searchS1inGVec(string s1,size_t iocrdone,vector<string>& gocr,size_t winig){
    for(int t1 = maxIG(iocrdone-winig,0); t1 < min(iocrdone+winig,gocr.size()); t1++){
        if (s1 == gocr[t1]) return 1;
    }
    return 0;

}

string findDictEntries(string s1,  map<string, int>& m2, map<string, int>& m1) {//unordered_

if((s1.size() == 0) || (s1 == "")) return "";



//cout << s1 << endl;
for(size_t i = s1.size(); i > 0; i --){
    for(size_t j =0; j < s1.size() - i +1; j++){
    string str = s1.substr(j,i);
    if((m1[str]>0) ) { //cout << "here "<< str << "L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
        return findDictEntries(s1.substr(0,j),m2,m1) + "<font color=\'" + "green" + "\'>" + toDev(str) + "</font>" +  findDictEntries(s1.substr(j+i,s1.size()-i),m2,m1);
            } else if(m2[str]>4) {//cout << "here "<< str << "L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
        return findDictEntries(s1.substr(0,j),m2,m1) + "<font color=\'" + "cyan" + "\'>" + toDev(str) + "</font>" +  findDictEntries(s1.substr(j+i,s1.size()-i),m2,m1);
        }
    }
}
//cout << "here2 "<< str << "sd"<< endl;
return ("<font color=\'red\'>" + toDev(s1) + "</font>");//("#" + s1 + "#");//
}


void find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

string find_and_replace_oddInstancesblue(string source)
{
    string find = "green";
    string replace = "blue";

    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace); //cout << source << endl;
        if ( replace ==  "blue") replace = "green"; else replace = "blue";
        i += replace.length();
    }
    return source;
}

string find_and_replace_oddInstancesorange(string source)
{
    string find = "cyan";
    string replace = "orange";

    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace); //cout << source << endl;
        if ( replace ==  "orange") replace = "cyan"; else replace = "orange";
        i += replace.length();
    }
    return source;
}

// lcs code:-

/*
  C++ implementation of
  "A linear space algorithm for computing maximal common subsequences"
  D. S. Hirschberg
  http://portal.acm.org/citation.cfm?id=360861

  See also: http://wordaligned.org/articles/longest-common-subsquence.html
*/
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void allignlcsnew(string& str1,string& str2,string& str3){
string str1new, str2new;
size_t t1 = 0;
size_t t2 =0;
size_t t3 =0;
string s1,s2,s3;


// while1
// a) addition if s1 == s3, and s2 differs add space to s1n, append t2 only so that we can reach close to s1 == s3 == s2
// b) deletion if s2 == s3, and s1 differs add space to s2n, append t1 only so that we can reach close to s2 == s3 == s1
// substitution if s1 != s2 != s3 s1n += s1, s2n += s2 append t1 and t2
// nothing if s1 == s2 == s3 s1n += s1, s2n += s2 append t1 and t2 and t3; if t3 == str3.size() Up3Flag = 1 break;

// if Up3Flag find which is smaller, add spaces in end of smaller smallstr = min(str1.size() - t1,str2.size() - t2);

while(1){
    s1 = str1.substr(t1,1); s2 = str2.substr(t2,1); s3 = str3.substr(t3,1);
    //a) add
    //cout << t1 << " " << t2 << " " << t3<< endl;
    //cout << s1 << " " << s2 << " " << s3<< endl;
    if((s1 == s3) && (s2 != s3)) {str1new += " "; str2new += s2; t2++; /*cout << "a growing str1new " << str1new <<endl;*/  }
    if((s2 == s3) && (s1 != s3)) {str2new += " ";  str1new += s1; t1++; /*cout << "d growing str2new " << str2new <<endl;*/ } // b)
    if((s2 != s3) && (s1 != s3)) {str1new += s1; str2new += s2; t1++; t2++; /*cout << "s growing str12new " << str1new<<" " <<str2new <<endl;*/ } //c)
    if((s2 == s3) && (s1 == s3)) {str1new += s1; str2new += s2; t1++; t2++;t3++;   /*cout << "n growing str12new " << str1new<<" " <<str2new <<endl;*/  if(t3 == str3.size()) {break;}} //d)
}
//cout << " " << str1new << " " << str2new << endl;
uint max = str1.size() ; if(max < str2.size() ) max = str2.size() ;

//cout << t1 << " " << t2 << " " << max<< endl;
while(1)
{   if((t1>=max) && (t2>=max)) break;
    if(t1<str1.size()) s1 = str1.substr(t1,1); else s1 = " "; if(t2<str2.size()) s2 = str2.substr(t2,1); else s2 = " ";
    //cout << t1 << " " << t2 << " " << max<< endl;
    //cout << s1 << " " << s2 << " " << endl;
    if(t1 < max) str1new += s1; else str1new += " ";
    if(t2 < max) str2new += s2; else str2new += " ";
    t1++; t2++;
}
str1 = str1new;
str2 = str2new;

}


typedef std::vector<int> lengths;

/*
  The "members" type is used as a sparse set for LCS calculations.
  Given a sequence, xs, and members, m, then
  if m[i] is true, xs[i] is in the LCS.
*/
typedef std::vector<bool> members;

/*
  Fill the LCS sequence from the members of a sequence, xs
  x - an iterator into the sequence xs
  xs_in_lcs - members of xs
  lcs - an output results iterator
*/
template <typename it, typename ot>
void set_lcs(it x, members const & xs_in_lcs, ot lcs)
{
    for (members::const_iterator xs_in = xs_in_lcs.begin();
         xs_in != xs_in_lcs.end(); ++xs_in, ++x)
    {
        if (*xs_in)
        {
            *lcs++ = *x;
        }
    }
}

/*
  Calculate LCS row lengths given iterator ranges into two sequences.
  On completion, `lens` holds LCS lengths in the final row.
*/
template <typename it>
void lcs_lens(it xlo, it xhi, it ylo, it yhi, lengths & lens)
{
    // Two rows of workspace.
    // Careful! We need the 1 for the leftmost column.
    lengths curr(1 + distance(ylo, yhi), 0);
    lengths prev(curr);

    for (it x = xlo; x != xhi; ++x)
    {
        swap(prev, curr);
        int i = 0;
        for (it y = ylo; y != yhi; ++y, ++i)
        {
            curr[i + 1] = *x == *y
                ? prev[i] + 1
                : std::max(curr[i], prev[i + 1]);
        }
    }
    swap(lens, curr);
}

/*
  Recursive LCS calculation.
  See Hirschberg for the theory!
  This is a divide and conquer algorithm.
  In the recursive case, we split the xrange in two.
  Then, by calculating lengths of LCSes from the start and end
  corners of the [xlo, xhi] x [ylo, yhi] grid, we determine where
  the yrange should be split.

  xo is the origin (element 0) of the xs sequence
  xlo, xhi is the range of xs being processed
  ylo, yhi is the range of ys being processed
  Parameter xs_in_lcs holds the members of xs in the LCS.
*/
template <typename it>
void
calculate_lcs(it xo, it xlo, it xhi, it ylo, it yhi, members & xs_in_lcs)
{
    unsigned const nx = distance(xlo, xhi);

    if (nx == 0)
    {
        // empty range. all done
    }
    else if (nx == 1)
    {
        // single item in x range.
        // If it's in the yrange, mark its position in the LCS
        xs_in_lcs[distance(xo, xlo)] = find(ylo, yhi, *xlo) != yhi;
    }
    else
    {
        // split the xrange
        it xmid = xlo + nx / 2;

        // Find LCS lengths at xmid, working from both ends of the range
        lengths ll_b, ll_e;
        std::reverse_iterator<it> hix(xhi), midx(xmid), hiy(yhi), loy(ylo);

        lcs_lens(xlo, xmid, ylo, yhi, ll_b);
        lcs_lens(hix, midx, hiy, loy, ll_e);

        // Find the optimal place to split the y range
        lengths::const_reverse_iterator e = ll_e.rbegin();
        int lmax = -1;
        it y = ylo, ymid = ylo;

        for (lengths::const_iterator b = ll_b.begin();
             b != ll_b.end(); ++b, ++e)
        {
            if (*b + *e > lmax)
            {
                lmax = *b + *e;
                ymid = y;
            }
            // Care needed here!
            // ll_b and ll_e contain one more value than the range [ylo, yhi)
            // As b and e range over dereferenceable values of ll_b and ll_e,
            // y ranges over iterator positions [ylo, yhi] _including_ yhi.
            // That's fine, y is used to split [ylo, yhi), we do not
            // dereference it. However, y cannot go beyond ++yhi.
            if (y != yhi)
            {
                ++y;
            }
        }
        // Split the range and recurse
        calculate_lcs(xo, xlo, xmid, ylo, ymid, xs_in_lcs);
        calculate_lcs(xo, xmid, xhi, ymid, yhi, xs_in_lcs);
    }
}

// Calculate an LCS of (xs, ys), returning the result in an_lcs.
template <typename seq>
void lcs(seq const & xs, seq const & ys, seq & an_lcs)
{
    members xs_in_lcs(xs.size(), false);
    calculate_lcs(xs.begin(), xs.begin(), xs.end(),
                  ys.begin(), ys.end(), xs_in_lcs);
    set_lcs(xs.begin(), xs_in_lcs, back_inserter(an_lcs));
}


bool isNonVowel(string ocrp){
    string a = "aeiouAEIOU";
    for(size_t t =0; t< a.size(); t ++){
    if (ocrp == a.substr(t,1)) return 0;
    }
    return 1;

}

string removeSpaces(string input)
{ string output;
  int length = input.length();
  for (int i = 0; i < length; i++) {
     if(input[i] != ' ') output+= input[i];
  }
  return output;
}

void findConfisions(string ocr, string correct, vector<string>& vec){
    //vector<string> vec;
    //ocrp = “”; correctp = “”;
    // for( t = 0 t< s.size) // load ocrp correctp if t > 0 with substr(t-1,1)
    //ocr == “”; correct = “”
    // while(s1 != s2) ocr += s1; correct += s2;  t++;// s1 s2 are chars from each word
    // of ocrp == “”load ocrnext in ocrp wiht substr(t,1)
    // subss add if ocr != “” :- // if ocrp is a non-vowel vec.push_back(ocrp+ocr, correctp+correct) else vec.push_back(ocr, correct)
    //ocrp = s1; correctp = s2;

    size_t sz = ocr.size();
    string ocrp = "";
    size_t t = 0;
    while(1){
        string ocrn ="";
        string correctn ="";
        string s1 = ocr.substr(t,1), s2 = correct.substr(t,1);
        //cout << "t = " << t << " " << sz << endl;
        // deletion
        if(s2 == " ") {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if(ocrp != "") vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn)); else if(t < sz) vec.push_back(removeSpaces(ocrn + s1) + " " + removeSpaces(correctn + s1)); else vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn));
        }
        // addition
        else if(s1 == " ") {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if((ocrp != "")&&(isNonVowel(ocrp))) vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn)); else if(t < sz) vec.push_back(removeSpaces(ocrn + s1) + " " + removeSpaces(correctn + s1)); else vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn));
        }
        else if(s1 != s2) {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if((ocrp != "")&&(isNonVowel(ocrp))) vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn));/*else if(t < sz) cout << "s " << ocrn + s1 << " " << correctn + s1<< endl;*/ else vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn));
        } else t++;




        ocrp = s1;
        if(t >= sz) break;
    }
//return vec;
}


void findConfisionsNindex(string ocr, string correct, vector<string>& vec, vector<int>& vind){
    //vector<string> vec;
    //ocrp = “”; correctp = “”;
    // for( t = 0 t< s.size) // load ocrp correctp if t > 0 with substr(t-1,1)
    //ocr == “”; correct = “”
    // while(s1 != s2) ocr += s1; correct += s2;  t++;// s1 s2 are chars from each word
    // of ocrp == “”load ocrnext in ocrp wiht substr(t,1)
    // subss add if ocr != “” :- // if ocrp is a non-vowel vec.push_back(ocrp+ocr, correctp+correct) else vec.push_back(ocr, correct)
    //ocrp = s1; correctp = s2;

    size_t sz = ocr.size();
    string ocrp = "";
    size_t t = 0;
    int s1p;

    while(1){
        string ocrn ="";
        string correctn ="";
        string s1 = ocr.substr(t,1), s2 = correct.substr(t,1);
    int s1t = t;
        //cout << "t = " << t << " " << sz << endl;
        // deletion
        if(s2 == " ") {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if(ocrp != "") {vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn)); vind.push_back(s1p);}else if(t < sz) {vec.push_back(removeSpaces(ocrn + s1) + " " + removeSpaces(correctn + s1)); vind.push_back(s1t);} else {vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn)); vind.push_back(s1t);}
        }
        // addition
        else if(s1 == " ") {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if((ocrp != "")&&(isNonVowel(ocrp))) {vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn)); vind.push_back(s1p);} else if(t < sz) {vec.push_back(removeSpaces(ocrn + s1) + " " + removeSpaces(correctn + s1)); vind.push_back(s1t);} else {vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn)); vind.push_back(s1t);}
        }
        else if(s1 != s2) {
            while(s1 != s2) {ocrn += s1; correctn += s2; t++;  if(t >= sz) break; s1 = ocr.substr(t,1); s2 = correct.substr(t,1);}
            if((ocrp != "")&&(isNonVowel(ocrp))) {vec.push_back(removeSpaces(ocrp+ocrn) + " " + removeSpaces(ocrp+correctn)); vind.push_back(s1p);}/*else if(t < sz) cout << "s " << ocrn + s1 << " " << correctn + s1<< endl;*/ else {vec.push_back(removeSpaces(ocrn) + " " + removeSpaces(correctn)); vind.push_back(s1t);}
        } else {t++;}




        ocrp = s1; s1p = s1t;
        if(t >= sz) break;
    }
//return vec;
}

void removeEndCommonSpaces(string& str1, string& str2){
    size_t t = str1.size();
    string s1 = str1.substr(t-1,1), s2 = str1.substr(t-1,1);
    while((s1 == " ") && (s2 == " ")) {str1 = str1.substr(0,t-1); str2 = str2.substr(0,t-1); t = str1.size(); s1 = str1.substr(t-1,1), s2 = str1.substr(t-1,1);}

}

/*
vector<string> findConfisionsPair(string str1, string str2){
    string str3;
    lcs(str1,str2,str3);
    allignlcsnew(str1,str2,str3);
    removeEndCommonSpaces(str1,str2);
    vector<string> vec = findConfisions(str1,str2);
    return vec;

}*/

void appendConfusionsPairs(string str1, string str2, vector<string>& vec){
    str1 = "@" + toslp1(str1) + "#"; str2 = "@" + toslp1(str2) + "#";
    string str3;
    lcs(str1,str2,str3);
    allignlcsnew(str1,str2,str3);
    removeEndCommonSpaces(str1,str2);
    findConfisions(str1,str2,vec);
    //return vec;

}

string appendConfusionsPairsNindex(string str1, string str2, vector<string>& vec, vector<int>& vecind){
    str1 = "@" + toslp1(str1) + "#"; str2 = "@" + toslp1(str2) + "#";
    string str3;
    lcs(str1,str2,str3);
    allignlcsnew(str1,str2,str3);
    removeEndCommonSpaces(str1,str2);
    findConfisionsNindex(str1,str2,vec,vecind);
    return str1;
    //return vec;

}

void loadvectomap(vector<string> ConfP, map<string,int>& ConfPmap){

for(size_t t = 0; t<ConfP.size(); t++) ConfPmap[ConfP[t]]++;

}

void printvecstr(vector<string> ConfP){

for(size_t t = 0; t<ConfP.size(); t++) cout << ConfP[t] << endl;

}

void printvecint(vector<int> ConfP){

for(size_t t = 0; t<ConfP.size(); t++) cout << ConfP[t] << endl;

}

//loadConfusions("1kECPairs",ConfPmap)
void loadConfusions(string fileName,map<string,int>& ConfPmap){
    vector<string> ConfP;
    string str1, str2;
    ifstream myfile(fileName);
        if (myfile.is_open())
      { while(myfile >> str1){
        myfile >> str2;
        appendConfusionsPairs((str1),(str2),ConfP);//toslp1
    //cout << str1 << " " << str2 << endl;

    //vec.clear();

    } cout << ConfP.size() << " Confusions Loaded" << endl;} else cout <<"Error Confusions NOT Loaded" << endl;
    loadvectomap(ConfP,ConfPmap);

}

void loadConfusions2(string fileName1,string fileName2,map<string,int>& ConfPmap){
    vector<string> ConfP;
    string str1, str2;
    ifstream myfile(fileName1);
    ifstream myfile2(fileName2);
        if ((myfile.is_open()) && (myfile2.is_open()))
      { while(myfile >> str1){
        myfile2 >> str2;
        appendConfusionsPairs((str1),(str2),ConfP);//toslp1
    //cout << str1 << " " << str2 << endl;

    //vec.clear();

    } cout <<ConfP.size() << " Confusions Loaded" << endl;} else cout <<"Error Confusions NOT Loaded" << endl;
    loadvectomap(ConfP,ConfPmap);

}

void loadConfusionsFont(vector<string> fileName1,vector<string> fileName2,map<string,int>& ConfPmap){
    vector<string> ConfP;
        if (fileName1.size() > 0)
      { for(size_t i =0;i < fileName1.size(); i++ ){

        appendConfusionsPairs(fileName1[i],fileName2[i],ConfP);//toslp1

    } cout << ConfP.size() << " Confusions Loaded from" << fileName1.size() <<" pairs"<< endl;} else cout <<"Error Confusions NOT Loaded" << endl;
    loadvectomap(ConfP,ConfPmap);
}

void generateCorrectionPairs(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC){
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) {cout << "cannot open inds/corrected file" <<endl;  return;} // break the while loop for page_no
        string localstr;
        map<string, bool> isEngOrNOT;
        while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while(sCpage >> localstr) { vecpC.push_back(toslp1(localstr)); sIpage.close(); if(hasM40PerAsci(localstr)) isEngOrNOT[toslp1(localstr)] = 1;}
        int sizew = wrong.size();
        // if 1st word is wrong generate suggestions
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

            if((s1 != sC) && (/*isEngOrNOT[sC] != */1)) {wrong.push_back(s1); right.push_back(sC); /*cout << s1 <<" " << sC << endl;*/}
        }
        cout << wrong.size() - sizew << " new correction pairs loaded" << endl;
}

void generatePairs(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC){
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) {cout << "cannot open inds/corrected file" <<endl;  return;} // break the while loop for page_no
        string localstr;
        map<string, bool> isEngOrNOT;
        while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while(sCpage >> localstr) { vecpC.push_back(toslp1(localstr)); sIpage.close(); if(hasM40PerAsci(localstr)) isEngOrNOT[toslp1(localstr)] = 1;}
        int sizew = wrong.size();
        // if 1st word is wrong generate suggestions
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
            size_t minedit = 1000,minediti;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1,sCt1);
                if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1; minediti = t1;  }
                if (sCt1 == s1) {/*WER++;*/ sC = s1; vecpC[t1] = ""; break;}
                /*size_t szt = sCt1.find(s1); size_t sCt1sz = sCt1.size();
                if((szt != string::npos) && (szt == 0)){/WER++;/ sC = s1; vecpC[t1] = sCt1.substr(s1.size(),sCt1sz - s1.size()); break;}
                if((szt != string::npos) && (szt == sCt1sz - s1.size())){ sC = s1; vecpC[t1] = sCt1.substr(0,sCt1sz - s1.size()); break;}
                */
            }
            if(sC != s1) vecpC[minediti] = "";
            if( (/*isEngOrNOT[sC] != */1)) {wrong.push_back(s1); right.push_back(sC); /*cout << s1 <<" " << sC << endl;*/} //(s1 != sC) &&
        }
        cout << wrong.size() - sizew << " new correction pairs loaded" << endl;
        if(wrong.size() != right.size()) cout <<"ERROR (wrong.size() != right.size() ) "<<endl;
}

void generatePairsIEROCR(string localFilenameI,string localFilenameC, string Rep, string Repy){
    vector<string> vecpI, vecpC;
    std::ofstream repPair(Rep);
    std::ofstream repPairy(Repy);
    std::ifstream sIpage(localFilenameI);
    if (!(sIpage.is_open())) {cout << "cannot open inds/corrected file" <<endl;  return;} // break the while loop for page_no
    string localstr;
    map<string, bool> isEngOrNOT;
    while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
    std::ifstream sCpage(localFilenameC);
    while(sCpage >> localstr) { vecpC.push_back(toslp1(localstr)); sIpage.close(); if(hasM40PerAsci(localstr)) isEngOrNOT[toslp1(localstr)] = 1;}
    //int sizew = wrong.size();
    // if 1st word is wrong generate suggestions
    int vGsz = vecpC.size(), vIsz =  vecpI.size();
    //if (vGsz >vIsz ) mapTyping[page_no] = vGsz - vIsz;
    //cout << vGsz << " " << vIsz << endl;
    int win = vGsz  - vIsz;
    if(win<0) win = -1*win;
    win = maxIG(win,20);
    //cout << win << endl;
    //float WER = 0;
    // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
    for(int t = 0; t < vIsz;t++){
        size_t minedit = 1000,minediti;
        string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
        string sC;
        for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
            string sCt1 = vecpC[t1];
            size_t mineditIC = editDist(s1,sCt1);
            if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1; minediti = t1;  }
            if (sCt1 == s1) {/*WER++;*/ sC = s1; vecpC[t1] = ""; break;}
            /*size_t szt = sCt1.find(s1); size_t sCt1sz = sCt1.size();
            if((szt != string::npos) && (szt == 0)){/WER++;/ sC = s1; vecpC[t1] = sCt1.substr(s1.size(),sCt1sz - s1.size()); break;}
            if((szt != string::npos) && (szt == sCt1sz - s1.size())){ sC = s1; vecpC[t1] = sCt1.substr(0,sCt1sz - s1.size()); break;}
            */
        }
        if( (/*isEngOrNOT[sC] != */1) && (sC != "")) {
        repPair << s1 << endl; repPairy << sC << endl;
        }
    }
    repPairy.close(); repPair.close(); sIpage.close();sCpage.close();
}



void generatePairsSpaced(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC){
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) {cout << "cannot open inds/corrected file" <<endl;  return;} // break the while loop for page_no
        string localstr;
        map<string, bool> isEngOrNOT;
        while(sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while(sCpage >> localstr) { vecpC.push_back(toslp1(localstr)); sIpage.close(); if(hasM40PerAsci(localstr)) isEngOrNOT[toslp1(localstr)] = 1;}
        int sizew = wrong.size();
        // if 1st word is wrong generate suggestions
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
            size_t minedit = 1000,minediti;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for(int t1 = maxIG(t-win,0); t1 < min(t+win,vGsz); t1++){
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1,sCt1);
                if(mineditIC < minedit) {minedit = mineditIC; sC = sCt1; minediti = t1;  }
                if (sCt1 == s1) {/*WER++;*/ sC = s1; vecpC[t1] = ""; break;}
                /*size_t szt = sCt1.find(s1); size_t sCt1sz = sCt1.size();
                if((szt != string::npos) && (szt == 0)){/WER++;/ sC = s1; vecpC[t1] = sCt1.substr(s1.size(),sCt1sz - s1.size()); break;}
                if((szt != string::npos) && (szt == sCt1sz - s1.size())){ sC = s1; vecpC[t1] = sCt1.substr(0,sCt1sz - s1.size()); break;}
                */
            }
            if(sC != s1) {vecpC[minediti] = "";}
            if( (/*isEngOrNOT[sC] != */1)) {wrong.push_back(s1); right.push_back(sC); /*cout << s1 <<" " << sC << endl;*/} else {wrong.push_back(s1); right.push_back("");}//(s1 != sC) &&
        }
        cout << wrong.size() - sizew << " new correction pairs loaded" << endl;
        if(wrong.size() != right.size()) cout <<"ERROR (wrong.size() != right.size() ) "<<endl;
}

void loadCPair(string fileName1,string fileName2,map<string,string>& CPair){
    string str1, str2;
    ifstream myfile(fileName1);
    ifstream myfile2(fileName2);
        if ((myfile.is_open()) && (myfile2.is_open()))
      { while(myfile >> str1){
        myfile2 >> str2;
        CPair[str1] = str2;//toslp1
    //cout << str1 << " " << str2 << endl;

    //vec.clear();

    } cout <<CPair.size() << " CPairs Loaded" << endl;} else cout <<"Error CPairs NOT Loaded" << endl;
    //loadvectomap(ConfP,ConfPmap);

}

void loadTopConfusions(map<string,int>& ConfPmap,map<string, string>& TopConfusions,map<string, int>& TopConfusionsMask){
map<string, int> TopSuggFreq;
for(map<string, int >::const_iterator it = ConfPmap.begin();
        it != ConfPmap.end(); ++it)
        {
        //std::cout << it->first << " " << it->second<< "\n";
    string rule = it->first; istringstream s(rule);string l,r; s>>l; s>>r;
    //if(TopSuggFreq[l] < it->second){
        TopSuggFreq[l] = it->second;
        TopConfusions[l] = r;
        TopConfusionsMask[l] ++;
        //}
    l.clear(); r.clear();
    }
}

std::string tokenize(const std::string& s) {
   if (!s.size()) {
     return "";
   }
   std::stringstream ss;
   ss << s[0];
   for (uint i = 1; i < s.size(); i++) {
     ss << ' ' << s[i];
   }
   return ss.str();
}


// print only rules in Pattern Miner's Rule Input form
void printConfusionRulesmap(map<string,int>& ConfPmap){
    map<string,vector<string> > rulesCorrectFormat;
   // print the Map rule and correct the format
    for(map<string, int >::const_iterator it = ConfPmap.begin();
        it != ConfPmap.end(); ++it)
    {
        //std::cout << it->first << " " << it->second<< "\n";
    string rule = it->first; istringstream s(rule);  string l,r; s>>l; s>>r;
        if((l.size() < 3) && (r.size() < 3)) rulesCorrectFormat[r].push_back(l);
    }
    //file.close();

    // print in correct format

    for( map<string,vector<string> >::const_iterator ptr=rulesCorrectFormat.begin();
             ptr!=rulesCorrectFormat.end(); ptr++) { string s = (ptr->first);
            cout << tokenize(s) << " -> ";
            for( vector<string>::const_iterator eptr=ptr->second.begin();
                 eptr!=ptr->second.end(); eptr++){ string s1 = *eptr;
                    cout << tokenize(s1) << " ! "; }
            cout << endl;
        }

}




//for choosing best out of nearest suggestions:-
int loadWConfusionsNindex1(string str1,string str2,map<string,int>& ConfPmap,vector<string>& wordConfusions,vector<int>& wCindex){
string str1New = appendConfusionsPairsNindex(str1,str2,wordConfusions,wCindex);
int szold = wordConfusions.size();// more confusions more szold
        //filter confusions:-
        //cout<< str1New << endl;
        for(size_t t = 0; t<wordConfusions.size(); t++) { if(ConfPmap[wordConfusions[t]]>0) {/*cout << wCindex[t] << " "<< toDev(wordConfusions[t]) << endl;*/} else {wordConfusions.erase(wordConfusions.begin() + t); wCindex.erase(wCindex.begin() + t); t--;}}
    return 	(szold - wordConfusions.size());//  more confusions are Indsenz OCR Confusions, less will be difference
}

// for alligning OCR Pair words
string loadWConfusionsNindex(string str1,string str2,map<string,int>& ConfPmap,vector<string>& wordConfusions,vector<int>& wCindex){
string str1New = appendConfusionsPairsNindex(str1,str2,wordConfusions,wCindex);

        //filter confusions:-
        //cout<< str1New << endl;
        for(size_t t = 0; t<wordConfusions.size(); t++) { if(ConfPmap[wordConfusions[t]]>0) {/*cout << wCindex[t] << " "<< toDev(wordConfusions[t]) << endl;*/} else {wordConfusions.erase(wordConfusions.begin() + t); wCindex.erase(wCindex.begin() + t); t--;}}
    return 	str1New;
}



void replacestrcnf(string& newstring,size_t i,string cnfn)
{
istringstream s(cnfn);
string lhs,rhs;
s >> lhs; s >> rhs;
newstring = newstring.replace(i,lhs.length(),rhs);

}

// parts from SamasBreakComb.hpp
bool endswithHalanta(string str) {
if (str.size() <= 2) return 1; //ALSO INCLUDING ONE/TWO CHARS
if (str.size() >= 4) return 0; //ignoring Words with Halanta having more than 4 chars
string lastchar = str.substr(str.size()-1,1);
string str1 = "aeiouAEIOUH";
for(size_t i = 0; i < str1.size(); i++) {
    if(str1.substr(i,1) == lastchar) return 0;
}
return 1;
}

void removeEndSpaces(string& str1){
    size_t t = str1.size();
    string s1 = str1.substr(t-1,1);
    //cout << "1 s1 " << s1<< endl;
    while((s1 == " ")) {str1 = str1.substr(0,t-1); t = str1.size(); s1 = str1.substr(t-1,1);}
    //cout << "2 s1 " << s1<< endl;
    s1 = str1.substr(0,1);
    //cout << "3 s1 " << s1<< endl;
    while((s1 == " ")) {str1 = str1.substr(1,t-1); t = str1.size(); s1 = str1.substr(0,1);}
    //cout << "4 s1 " << s1<< endl;
}

// parts from SamasBreakComb.hpp

// samas corrector.h starts

string deletePoornaVirams(string input){
string out;
for(size_t t = 0; t < input.size(); t++){
string s; s += input[t];
if( s != "|") out += s;
}
return out;
}

/* applicable when trieeditdisone is used as searchTrie will give str as output, else it give vector<string>
string SamasBreakLRCorrect(string s1, unordered_map<string, int>& m1, unordered_map<string, int>& PWordsNew) {

if((s1.size() == 0) || (s1 == "")) return "";
if((m1[s1]>0)||PWordsNew[s1]>0) return " " + s1 + " ";
//cout << "s1 "<< s1 << endl;
for(size_t i = s1.size(); i > 0; i --){// DASOAHAM 8
    for(size_t j =0; j < s1.size() - i+1; j++){ // i determinze size of substring
    string str = s1.substr(j,i);//  i = 8, j = 0:0 DASOAHAM ; i = 7, j = 0:1  DASOAHA ASOAHAM..... ;i =1, j = 0:7 D A S O A H A M
    // checking str
    //cout <<"str outside " << str << endl;
    if((m1[str]>0)||PWordsNew[str]>0) { //cout << "here "<< str << " L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
    //cout <<"str inside " << str << endl;
    //cout <<"left "<< s1.substr(0,j) << " nearest "<< searchTrie(s1.substr(0,j)) << endl;
    //cout <<"right "<< s1.substr(j+i,s1.size()-i) << " nearest "<< searchTrie(s1.substr(j+i,s1.size()-i)) << endl;
    return deletePoornaVirams(searchTrie(s1.substr(0,j)) + (str) + searchTrie(s1.substr(j+i,s1.size()-i)) );
            }
    }
}
return "";
//
//return ((s1));//("#" + s1 + "#");//
}*/


size_t cntSamas(string in, string& out){
out = "";
size_t cnt = 0;
string word;
removeEndSpaces(in);
istringstream s(in);
while(s >> word) {out += word + " "; cnt ++; /*cout << cnt << " " << word << " " << out << endl;*/}
if(endswithHalanta(word)) cnt++;
return cnt;
}

string SamasLR(string s1, map<string, int>& m1) {//, map<string, int>& PWordsNew

if((s1.size() == 0) || (s1 == "")) return "";
if((m1[s1]>0)) return " " + s1 + " ";//||PWordsNew[s1]>0
//cout << "s1 "<< s1 << endl;
for(size_t i = s1.size(); i > 0; i --){// DASOAHAM 8
    for(size_t j =0; j < s1.size() - i+1; j++){ // i determinze size of substring
    string str = s1.substr(j,i);//  i = 8, j = 0:0 DASOAHAM ; i = 7, j = 0:1  DASOAHA ASOAHAM..... ;i =1, j = 0:7 D A S O A H A M
    // checking str
    //cout <<"str outside " << str << endl;
    if((m1[str]>0)) {//||PWordsNew[str]>0 //cout << "here "<< str << " L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
    //cout <<"str inside " << str << endl;
    //cout <<"left "<< s1.substr(0,j) << " nearest "<< searchTrie(s1.substr(0,j)) << endl;
    //cout <<"right "<< s1.substr(j+i,s1.size()-i) << " nearest "<< searchTrie(s1.substr(j+i,s1.size()-i)) << endl;
    return (SamasLR(s1.substr(0,j),m1) + " " + (str)+ " " + SamasLR(s1.substr(j+i,s1.size()-i),m1) ); //,PWordsNew,PWordsNew
            }
    }
}
return (" #" + s1 + "# ");
//
//return ((s1));//("#" + s1 + "#");//
}




string SamasRL(string s1, map<string, int>& m1) { //, map<string, int>& PWordsNew

if((s1.size() == 0) || (s1 == "")) return "";
if((m1[s1]>0)) return " " + s1 + " ";//||PWordsNew[s1]>0
//cout << "s1 "<< s1 << endl;
for(size_t i = s1.size(); i > 0; i --){// DASOAHAM 8
    for(size_t j =0; j < s1.size() - i+1; j++){ // i determinze size of substring
    //cout << s1.size() << " " << j << endl;
    size_t jd =s1.size() - i - j;
    string str = s1.substr(jd,i);
    if((m1[str]>0)) {//||PWordsNew[str]>0 //cout << "here "<< str << " L " << s1.substr(0,j) << "R " << s1.substr(j+i,s1.size()-i) << endl;
    //cout <<"str inside " << str << endl;
    //cout <<"left "<< s1.substr(0,j) << " nearest "<< searchTrie(s1.substr(0,j)) << endl;
    //cout <<"right "<< s1.substr(j+i,s1.size()-i) << " nearest "<< searchTrie(s1.substr(j+i,s1.size()-i)) << endl;
    return (SamasRL(s1.substr(0,jd),m1) + " " + (str)+ " " + SamasRL(s1.substr(jd+i,s1.size()-i),m1) );//,PWordsNew,PWordsNew
            }
    }
}
return (" #" + s1 + "# ");
//
//return ((s1));//("#" + s1 + "#");//
}


// samas corrector.h ends

// str1cnt = minsize_t(cntSamas(SamasLR(toslp1(str1),Dict,SmasWords),partsLR), cntSamas(SamasRL(toslp1(str1),Dict,SmasWords),partsRL),FlagLR);
size_t minsize_t(size_t a,size_t b,bool& FlagLR){
if (b < a) {FlagLR = 0; return b;} else {FlagLR =1; return a;}
}

//print2OCRSugg("RemGOCR",ConfPmap,Dict,SmasWords)
string print2OCRSugg(string str1, string str2, map<string,int>& ConfPmap,map<string,int>& Dict){//,map<string,int> SmasWords

        //cout << "generating Pair Sugg for "<<str1<< " ";//<<"suggestion for " << endl
        if((str2 == "") || (str2 == " ") || (str2 == "  ")) {/*cout << "no suggestion" << endl;*/ return "";}
        string partsLR,partsRL;
        string twoOCRsugg = str1;
        bool FlagLR,Flag1stSuggGenerated; Flag1stSuggGenerated =1; //Flag1stSuggGenerated :- if cnt 8 for str1 and <=8 for a suggestion then look for cnt <8 hence forth
        size_t str1cnt = minsize_t(cntSamas(SamasLR(toslp1(str1),Dict),partsLR), cntSamas(SamasRL(toslp1(str1),Dict),partsRL),FlagLR);//,SmasWords,SmasWords
        vector<string> wordConfusions; vector<int> wCindex;
        string str1New = loadWConfusionsNindex(str1,str2,ConfPmap,wordConfusions,wCindex);
        //cout << str1New << endl; printvecint(wCindex); printvecstr(wordConfusions);

        //apply confusions wordConfusions.size() .. 2 1
        // lcs can give index of confusions say left are 3 6 9
        // we need to try 3 6 9, 3 6, 6 9 ,3 9, 3 , 6 ,9 if any dec no of parts through min(samasLR,samasRL) stop and give suggestion
        //cout << str1New << endl;
        size_t sz = wordConfusions.size(); //cout << sz<< endl;
        size_t max = pow(2,sz) - 1;

        for(size_t i =max; i > 0; i--){
            size_t mask = pow(2,sz-1);
            string newstring = str1New;
                for(size_t j =sz; j > 0; j--){
                //generate new string using mask say 101 i.e. 210 :-
                if((mask & i) != 0){ replacestrcnf(newstring,wCindex[log2(mask)],wordConfusions[log2(mask)]);}   mask = mask >> 1 ; }
            string newstring1 = removeSpaces(newstring.substr(1,newstring.size()-2));
            size_t cntSamasNew;
            if(FlagLR) cntSamasNew = cntSamas(SamasRL(newstring1,Dict),partsRL); // ,SmasWords
            else cntSamasNew = cntSamas(SamasLR(newstring1,Dict),partsLR); // ,SmasWords

            //cout << cntSamasNew <<" "<< str1cnt<< endl;
        //Flag1stSuggGenerated :- if cnt 8 for str1 and <=8 for a suggestion then look for cnt <8 hence forth
            if(Flag1stSuggGenerated){if(cntSamasNew <= str1cnt) {twoOCRsugg = (newstring1); str1cnt = cntSamasNew; Flag1stSuggGenerated = 0;}}
        else {if(cntSamasNew < str1cnt) {twoOCRsugg = (newstring1); str1cnt = cntSamasNew;}}

            }
        //cout << toDev(twoOCRsugg)<<endl;
        wordConfusions.clear();
        wCindex.clear();
        return twoOCRsugg;
        //break;
}

string bestIG(string s1,string s2,map<string, int>& m1){
string s11 = s1; string s21 = s2;
s1 = toslp1(s1); s2=toslp1(s2);
string RL1 = SamasRL(s1,m1); string RLout1;
size_t cRL1 = cntSamas(RL1,RLout1);
string RL2 = SamasRL(s2,m1); string RLout2;
size_t cRL2 = cntSamas(RL2,RLout2);
string LR1 = SamasLR(s1,m1); string LRout1;
size_t cLR1 = cntSamas(LR1,LRout1);
string LR2 = SamasLR(s2,m1); string LRout2;
size_t cLR2 = cntSamas(LR2,LRout2);
bool lolz;
if(minsize_t(cRL1,cLR1,lolz) < minsize_t(cRL2,cLR2,lolz)) return s11; else return s21;

}


//Sandhi Top Confusions

void loadSandhiRules(string fileName, map<string, vector<string>>& SRules){
    ifstream s(fileName);
    string sR1,sRl1, sRr1;
    while(s>>sR1) {s>>sRl1; s>>sRr1; SRules[sR1].push_back(sRl1 + " " + sRr1);}
}

void printSandhiRUles(map<string,vector<string> >& SRules){

    for( map<string,vector<string> >::const_iterator ptr=SRules.begin();
                 ptr!=SRules.end(); ptr++) { string s = (ptr->first);
                cout << (s) << " -> ";
                for( vector<string>::const_iterator eptr=ptr->second.begin();
                     eptr!=ptr->second.end(); eptr++){ string s1 = *eptr;
                        cout << (s1) << " | "; }
                cout << endl;
            }

}

bool SamasCheck(string OCRNew, map<string, int>& Dict){
if (OCRNew == "") return 1;
if (Dict[OCRNew] > 0) return 1;
//cout << endl<< "heres " << OCRNew << endl;
size_t sz = OCRNew.size();

for(size_t ts = sz ; ts > 0; ts--){// Bapyopetam Bapy 0 4 10
string s1 = OCRNew.substr(0,ts); string rem = OCRNew.substr(ts,sz-ts);
//cout << "s1 " << s1 << " rem " << rem << endl;
if((Dict[s1] > 0) &&(s1.size() >3) &&(rem.size() >3))/*try && rem.size >3*/ return SamasCheck(rem,Dict); // apply ending with a to aH, ending with consonants say c to ca etc // if not 1st leftstarting with a to remove a
}
return 0;
}


bool SandhiCheck(string OCRNew, map<string, int>& Dict,map<string, vector<string>>& SRules){
// Sandhi Check
//if (OCRNew == "") return 1;
if (Dict[OCRNew] > 0) return 1;
//cout << endl<< "hereS " << OCRNew << endl;
size_t sz = OCRNew.size();
for(size_t ts = sz ; ts > 0; ts--){// Bapyopetam Bapy 0 4 10
string s1 = OCRNew.substr(0,ts); string rem = OCRNew.substr(ts,sz-ts);

//cout << "S1 " << s1 << " " << ts << " " << sz  << endl;
if( (s1.size() >3)&&(rem.size() >2)){ //as r of S -> l+r will be added to rem
    //cout << "s1 " << s1 << endl;
    // applying o -> a u Sandhi rules i.e. k =1 for o, k = 2 for yu in yu -> yu -> i u | I u |
    size_t k = 1;
    vector<string> v = SRules[s1.substr(ts-k,k)];
    size_t vsz = v.size();
    //cout << " vsz " << vsz << endl;
        if(vsz > 0) {
            bool SandhiFlag = 0;
            for(size_t vt =0; vt < vsz; vt++) {
                istringstream s(v[vt]); string l,r; s>>l; s>>r;
                    string s1new = s1.substr(0,s1.size()-1)+l;
                    if((Dict[s1new] > 0) ){
                        //cout << "found " << s1new << endl;
                        SandhiFlag = (SandhiFlag | SamasCheck(r+rem,Dict));
                    } else { SandhiFlag = (SandhiFlag | (SandhiCheck(s1new,Dict,SRules) & SamasCheck(r+rem,Dict)) | (SamasCheck(s1new,Dict) & SamasCheck(r+rem,Dict)));} //else
                }// for
        return  SandhiFlag;
        }// if vsz >0
        }
    }
return 0;
}


//Sandhi rules

// OCR Word = BApyopetam
string generatePossibilitesNsuggest(string OCRWord,map<string,string>& TopConfusions,map<string,int>& TopConfusionsMask,map<string, int>& Dict, map<string, vector<string>>& SRules){
string OCRWordOrig = OCRWord;
size_t sz = OCRWord.size() + 2;
// one confusion one sandhi at a time
size_t tSandhi = 0;
for( size_t t2 =1; t2 < 4 ; t2++){
for( size_t t =0; t <sz- t2 + 1 ; t++){
OCRWord = "@" + OCRWordOrig + "#";
// apply a confusion
string OCRNew = OCRWord;
//cout << "OCRWord " << OCRWord << endl;
size_t tc = t; while( tc < sz - t2 + 1) {  string s1 = OCRWord.substr(tc,t2); //cout << s1<< " "<< tc << " " << t2 << endl;
if (TopConfusionsMask[s1] > 0) { OCRNew = OCRWord;  OCRNew.replace(tc,s1.size(),TopConfusions[s1]);  t = tc; break; } else tc++; }
//cout << "OCRWord1 " << OCRNew << endl;
// apply Samas s
OCRNew = OCRNew.substr(0,OCRNew.size()-1); OCRNew = OCRNew.substr(1,OCRNew.size()-1);
//cout << "OCRWord2 " << OCRNew << endl;
if (SamasCheck(OCRNew, Dict)) return OCRNew;
// apply Sandhi S Rules
if (SandhiCheck(OCRNew, Dict,SRules)) return OCRNew;
}
}
return "";
}

#endif // SLPNPATTERNDICT_H

