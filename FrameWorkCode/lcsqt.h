#ifndef LCSQT_H
#define LCSQT_H
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
#include <samasBreakCombineqt.h>
using namespace std;

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

// ALSO INCLUDING ONE/TWO CHARS and ignoring Words with Halanta having more than 4 chars
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
size_t max = str1.size() ; if(max < str2.size() ) max = str2.size() ;

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
    str1 = "@" + toslp11(str1) + "#"; str2 = "@" + toslp11(str2) + "#";
    string str3;
    lcs(str1,str2,str3);
    allignlcsnew(str1,str2,str3);
    removeEndCommonSpaces(str1,str2);
    findConfisions(str1,str2,vec);
    //return vec;

}

string appendConfusionsPairsNindex(string str1, string str2, vector<string>& vec, vector<int>& vecind){
    str1 = "@" + toslp11(str1) + "#"; str2 = "@" + toslp11(str2) + "#";
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

void loadTopConfusions(map<string,int>& ConfPmap,map<string, string>& TopConfusions,map<string, int>& TopConfusionsMask){
map<string, int> TopSuggFreq;
for(map<string, int >::const_iterator it = ConfPmap.begin();
        it != ConfPmap.end(); ++it)
        {
        //std::cout << it->first << " " << it->second<< "\n";
    string rule = it->first; istringstream s(rule);string l,r; s>>l; s>>r;
    if(TopSuggFreq[l] < it->second){
        TopSuggFreq[l] = it->second;
        TopConfusions[l] = r;
        TopConfusionsMask[l] ++;
        }
    l.clear(); r.clear();
    }
}

std::string tokenize(const std::string& s) {
   if (!s.size()) {
     return "";
   }
   std::stringstream ss;
   ss << s[0];
   for (size_t i = 1; i < s.size(); i++) {
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


// str1cnt = minsize_t(cntSamas(SamasLR(toslp1(str1),Dict,SmasWords),partsLR), cntSamas(SamasRL(toslp1(str1),Dict,SmasWords),partsRL),FlagLR);
size_t minsize_t(size_t a,size_t b,bool& FlagLR){
if (b < a) {FlagLR = 0; return b;} else {FlagLR =1; return a;}
}


//print2OCRSugg("RemGOCR",ConfPmap,Dict,SmasWords)
string print2OCRSugg(string str1, string str2, map<string,int>& ConfPmap,map<string,int>& Dict){//,map<string,int> SmasWords

        cout << "generating Pair Sugg for "<<str1<< " ";//<<"suggestion for " << endl
        if((str2 == "") || (str2 == " ") || (str2 == "  ")) {cout << "no suggestion" << endl; return "";}
        string partsLR,partsRL;
        string twoOCRsugg = str1;
        bool FlagLR,Flag1stSuggGenerated; Flag1stSuggGenerated =1; //Flag1stSuggGenerated :- if cnt 8 for str1 and <=8 for a suggestion then look for cnt <8 hence forth
        size_t str1cnt = minsize_t(cntSamas(SamasLR(toslp11(str1),Dict),partsLR), cntSamas(SamasRL(toslp11(str1),Dict),partsRL),FlagLR);//,SmasWords,SmasWords
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
        cout << toDev1(twoOCRsugg)<<endl;
        wordConfusions.clear();
        wCindex.clear();
        return twoOCRsugg;
        //break;
}
#endif // LCSQT_H
