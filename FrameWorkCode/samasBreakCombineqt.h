#ifndef SAMASBREAKCOMBINEQT_H
#define SAMASBREAKCOMBINEQT_H

#include <string>
using namespace std;

string ReplaceString1(string subject, const string& search, const string& replace)
{
    size_t pos=0;
    while((pos=subject.find(search, pos)) != string::npos)
    {
        subject.replace(pos, search.length(),replace);
        pos+=1;
    }
    return subject;
}

string ReplaceString1Restricted(string subject, const string& search, const string& replace)
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

string toDev1(string s)
{

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
            s=ReplaceString1(s,consonants_slp1[i],consonants_dn_halanta[i]);
        }
        //cout << "here1 " << s <<endl;
        for(int i=0;i<14;i++)
        {
            s=ReplaceString1(s,"्"+vowel_slp1[i],vowel_dn_joiner[i]);
        }
        //cout << "here2 " << s <<endl;
        for(int i=0;i<21;i++)
        {
            s=ReplaceString1(s,vowel_slp1[i],vowel_dn[i]);
        }

        for(unsigned int i=0;i<(sizeof(numbers_etc_dn)/sizeof(numbers_etc_dn[0]));i++)
        {
            s=ReplaceString1(s,numbers_eng[i],numbers_etc_dn[i]);
        }
        //cout << "here3 " << s <<endl;
        //cout<<s<<endl;


    return s;
}

string toslp11(string s)
{

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
    {s.replace(pos1, 6,"ळ्"); /*cout<<s<<endl;*/}
    //cout<<s<<endl;
    pos1 = 0;
    //cout<<s<<" "<<s.find("ऴ", pos1)<<endl;
    while((pos1=s.find("ऴ", pos1)) != string::npos)//"ळ" is valid, dot below "ळ" is invalid char
    {s.replace(pos1, 6,"ळ"); }
    //cout<<s<<endl;

    for(int i=0;i<34;i++)
    {
        s=ReplaceString1(s,consonants_dn_halanta[i],consonants_slp1[i]);
    }

    for(int i=0;i<13;i++)
    {
        s=ReplaceString1(s,vowel_dn_joiner[i],vowel_slp1[i+1]);
    }

    for(int i=0;i<19;i++)
    {
        s=ReplaceString1(s,vowel_dn[i],vowel_slp1[i]);
    }
    //cout<<"here "<< s<<endl;
    for(int i=0;i<34;i++)
    {   //cout<< i << " " << consonants_dn[i] << " " << consonants_slp1[i] << endl;
        s=ReplaceString1Restricted(s,consonants_dn[i],consonants_slp1[i]);
    }
    //cout<<"here1 "<< s<<endl;
    //cout<<s<<"…"<<s.find("…", pos1)<<endl;
    string numbers_etc_dn[]={"१","२","३","४","५","६","७","८","९","०","।","॥","॰","ऽ","’","‘","”","“","ॐ"};
    string numbers_eng[]={"1","2","3","4","5","6","7","8","9","0","|","||","0","$","'","'","''","''","%"};
    for(uint i=0;i<(sizeof(numbers_etc_dn)/sizeof(numbers_etc_dn[0]));i++)
    {
        s=ReplaceString1(s,numbers_etc_dn[i],numbers_eng[i]);
    }

return s;
}


#endif // SAMASBREAKCOMBINEQT_H
