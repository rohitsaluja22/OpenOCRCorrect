#ifndef TRIEEDITDIS_H
#define TRIEEDITDIS_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <vector>
//#include <boost/range/adaptor/reversed.hpp>

/*
 * Algorithm: Edit distance using a trie-tree (Dynamic Programming)
 * Author: Murilo Adriano Vasconcelos <muriloufg@gmail.com>
 */

using namespace std;

// Trie's node
struct trie
{
    typedef map<char, trie*> next_t;

    // The set with all the letters which this node is prefix
    next_t next;

    // If word is equal to "" is because there is no word in the
    //  dictionary which ends here.
    string word;

    trie() : next(map<char, trie*>()) {}

    void clear() { next.clear(); }

    void insert(string w)
    {
        w = string("$") + w;

        int sz = w.size();

        trie* n = this;
        for (int i = 0; i < sz; ++i) {
            if (n->next.find(w[i]) == n->next.end()) {
                n->next[w[i]] = new trie();
            }

            n = n->next[w[i]];
        }

        n->word = w;
    }
};



    int min_cost;
    //trie tree;
    //vector<pair<int,string>> min_str;



    void search_impl(trie* tree, char ch, vector<int> last_row, const string& word, vector<pair<int,string>>& min_str)
    {
        int sz = last_row.size();

        vector<int> current_row(sz);
        current_row[0] = last_row[0] + 1;

        // Calculate the min cost of insertion, deletion, match or substution
        int insert_or_del, replace;
        for (int i = 1; i < sz; ++i) {
            insert_or_del = min(current_row[i-1] + 1, last_row[i] + 1);
            replace = (word[i-1] == ch) ? last_row[i-1] : (last_row[i-1] + 1);

            current_row[i] = min(insert_or_del, replace);
        }

        // When we find a cost that is less than the min_cost, is because
        // it is the minimum until the current row, so we update
        string treeword =(tree->word);

        if ((current_row[sz-1] < min_cost + 1) && (treeword != "")) {
             min_str.push_back(make_pair(current_row[sz-1],(treeword).substr(1,treeword.size()-1))); //cout << "edit dis and instance = "<< current_row[sz-1] <<" " << treeword << endl;
        }
        if ((current_row[sz-1] < min_cost) && (treeword != "")) min_cost = current_row[sz-1];

        // If there is an element wich is smaller than the current minimum cost,
        //  we can have another cost smaller than the current minimum cost
        if (*min_element(current_row.begin(), current_row.end()) < min_cost) {
            for (trie::next_t::iterator it = tree->next.begin(); it != tree->next.end(); ++it) {
                search_impl(it->second, it->first, current_row, word,min_str);
            }
        }
    }

    vector<pair<int,string>> searchTrie(trie& tree, string word)
    {   vector<pair<int,string>> min_str;
        min_str.clear();
        word = string("$") + word;

        int sz = word.size();
        min_cost = 0x3f3f3f3f;
        //min_str = "";

        vector<int> current_row(sz + 1);

        // Naive DP initialization
        for (int i = 0; i < sz; ++i) current_row[i] = i;
        current_row[sz] = sz;



        // For each letter in the root map wich matches with a
        //  letter in word, we must call the search
        for (int i = 0 ; i < sz; ++i) {
            if (tree.next.find(word[i]) != tree.next.end()) {
                search_impl(tree.next[word[i]], word[i], current_row, word, min_str);
            }
        }

        return min_str;
    }

// treeonesearch Starts

        void search_impl1(trie* tree, char ch, vector<int> last_row, const string& word, string& min_str)
        {
            int sz = last_row.size();

            vector<int> current_row(sz);
            current_row[0] = last_row[0] + 1;

            // Calculate the min cost of insertion, deletion, match or substution
            int insert_or_del, replace;
            for (int i = 1; i < sz; ++i) {
                insert_or_del = min(current_row[i-1] + 1, last_row[i] + 1);
                replace = (word[i-1] == ch) ? last_row[i-1] : (last_row[i-1] + 1);

                current_row[i] = min(insert_or_del, replace);
            }

            // When we find a cost that is less than the min_cost, is because
            // it is the minimum until the current row, so we update
            string treeword =(tree->word);

            if ((current_row[sz-1] < min_cost + 1) && (treeword != "")) {
                 min_str = (treeword).substr(1,treeword.size()-1); //cout << "edit dis and instance = "<< current_row[sz-1] <<" " << treeword << endl;
            }
            if ((current_row[sz-1] < min_cost) && (treeword != "")) min_cost = current_row[sz-1];

            // If there is an element wich is smaller than the current minimum cost,
            //  we can have another cost smaller than the current minimum cost
            if (*min_element(current_row.begin(), current_row.end()) < min_cost) {
                for (trie::next_t::iterator it = tree->next.begin(); it != tree->next.end(); ++it) {
                    search_impl1(it->second, it->first, current_row, word,min_str);
                }
            }
        }

        string searchTrie1(trie& tree, string word)
        {   string min_str;
            min_str.clear();
            word = string("$") + word;

            int sz = word.size();
            min_cost = 0x3f3f3f3f;
            //min_str = "";

            vector<int> current_row(sz + 1);

            // Naive DP initialization
            for (int i = 0; i < sz; ++i) current_row[i] = i;
            current_row[sz] = sz;



            // For each letter in the root map wich matches with a
            //  letter in word, we must call the search
            for (int i = 0 ; i < sz; ++i) {
                if (tree.next.find(word[i]) != tree.next.end()) {
                    search_impl1(tree.next[word[i]], word[i], current_row, word, min_str);
                }
            }

            return min_str;
        }


// treeonesearch ends
    void loadmaptoTrie(trie& tree,map<string,int > m2){
        for( map<string,int >::const_iterator ptr=m2.begin();
             ptr!=m2.end(); ptr++) {
            tree.insert(ptr->first);
        }
        //cout << " copied map to tree" << endl;
               //cout << "m2 size " << m2.size() << endl;
    }



    vector<string> print5NearestEntries(trie& tree,string OCRWord){
    vector<string> out;
    OCRWord = toslp1(OCRWord);
    vector<pair<int,string>> minGooglestr = searchTrie(tree,OCRWord);
        sort(minGooglestr.begin(), minGooglestr.end());
        bool boolFlag =0;
        for(size_t i = 0; i < minGooglestr.size(); i++)
        {
             if(i==5) break;
             if(minGooglestr[i].first ==0) continue;
             if (i+1 < minGooglestr.size()){
             if(minGooglestr[i].first ==0) continue;
             if(minGooglestr[i].first == minGooglestr[i+1].first){
             if (OCRWord != minGooglestr[i].second)
             out.push_back(minGooglestr[i].second);} else boolFlag =1; } else boolFlag =1; //minGooglestr[i].first << ", " <<

             if(boolFlag) {if (OCRWord != minGooglestr[i].second) out.push_back(minGooglestr[i].second); break;} //<< minGooglestr[i].first << ", " <<
        }
    return out;
        //cout << "searchTrie(str) = " <<  << endl;
    }

    vector<string> print1OCRNearestEntries(string OCRWord, vector<string> vec){

    vector<pair<int,string>> minIstr;
    size_t minEditDis = 100;
    size_t sz = vec.size();
        for(size_t t =0; t< sz; t++){
        size_t  ed = editDist(vec[t],OCRWord);
        if (ed < minEditDis) { minEditDis = ed; minIstr.push_back(make_pair(ed, vec[t]));}
        else if(ed < minEditDis+2) minIstr.push_back(make_pair(ed, vec[t]));
        }

        //cout << minEditDis << " inOCRNEAREST1 " << minIstr[0].second << endl;
        sort(minIstr.begin(), minIstr.end());
        //cout << minEditDis << " inOCRNEAREST1 " << minIstr[0].second << " " << minIstr[minIstr.size() - 1].second<< endl;
    vector<string> out;

    bool boolFlag =0;
        for(size_t i = 0; i < minIstr.size(); i++)
        {
             if(i==5) break;
             if(minIstr[i].first ==0) continue;
             if (i+1 < minIstr.size()){
             if(minIstr[i].first ==0) continue;
             if(minIstr[i].first == minIstr[i+1].first){
             if (OCRWord != minIstr[i].second)
             out.push_back(minIstr[i].second);} else boolFlag =1; } else boolFlag =1; //minIstr[i].first << ", " <<

             if(boolFlag) {if (OCRWord != minIstr[i].second) out.push_back(minIstr[i].second); break;} //<< minIstr[i].first << ", " <<
        }
    return out;

    }

bool insertPatternsOf(string str, trie& TPWordsP, size_t& count){ //map<string,int >&  PWordsP
    size_t sz = str.size();
    if(sz == 0) return 1;
    for(size_t i = 0; i < (sz+1); i++){
        string s1 = str.substr(0,i);
        TPWordsP.insert(s1); count++;//PWordsP[s1]++;
    }
    return insertPatternsOf(str.substr(1,sz-1),TPWordsP,count);//PWordsP
}

//loadPWordsPatternstoTrie(TPWordsP,PWordsP,PWords);
size_t loadPWordsPatternstoTrie(trie& TPWordsP, map<string,int >& PWords){ // arg1(strt from 0) ,map<string,int >& PWordsP
    size_t count = 0;
        for( map<string,int >::const_iterator ptr=PWords.begin();
             ptr!=PWords.end(); ptr++) {
           insertPatternsOf(ptr->first, TPWordsP,count);
        }
        //cout << count <<" patterns loaded to TPWordsP" << endl;
               //cout << "m2 size " << m2.size() << endl;
        return count;
    }

// samas corrector

//applicable when trieeditdisone is used as searchTrie will give str as output, else it give vector<string>
string SamasBreakLRCorrect(string s1, map<string, int>& m1, map<string, int>& PWordsNew,trie& tree, trie& treeP) { //unordered_
if((s1.size() == 0) || (s1 == "")) return "";
if((m1[s1]>0)||PWordsNew[s1]>0) return  s1;
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
    return searchTrie1(treeP,s1.substr(0,j)) + (str) + searchTrie1(treeP,s1.substr(j+i,s1.size()-i));
            }
    }
}
return searchTrie1(tree,s1);
//
//return ((s1));//("#" + s1 + "#");//
}
#endif // TRIEEDITDIS_H
