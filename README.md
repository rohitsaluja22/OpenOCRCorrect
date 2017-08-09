# Source Code for Framework-for-Error-Detection-and-Corrections-in-Indic-OCR
The framework for assisting human while correcting the OCR errors in documents in Indian Languages.


The interactive features as of now are:-
1. Error detection.
2. Generating Suggestions (will replace this to auto-completion in Future Work).

Following information is updated on the fly, after correction of each page:-
1. A domain specific dictionary which is uploaded on the fly.
2. The domain specific dictionary is also uploaded with OCR words with high confidence as the user starts working on the document.
3. OCR confusions specific to the documents which are uploaded on the fly.

# Video demo

https://tinyurl.com/y7wbpo6m 

#Tested for Ubuntu
Compiled and Tested on Ubuntu 14.04 LTS and Ubuntu 16.04. with QT Creator 5.4.1

#Installation
Download and Install latest C++ Qt Creator 5.4.1

# How to run the code?
Open Project with Qt Creator: Open File qpadfinal/qpadfinal.pro
Press "Ctrl+R" to run the code

# Creating Databse for Framework:

The folder “data/Book1” contains:-
0) A book named “Aryabhatiyabhashya of Nilakantha III Golapada (1957).pdf” for demo example.
1) “Dict” which is text file for Sanskrit Dictionary of 1.3 million words.
2) “ConfPmap” which is optional and contain prior OCR confusions.
3) “IEROCR” text file that contains the OCR output of the book, each page separated by newline. ER represents English Removed, we ignore the words in english as Sanskrit ind-senz does not recognize English. Instead of ind-senz, output any OCR system can be used with the same filename.
4) “GEROCR” text file that contains the Google Doc output of the book, each page separated by newline. Instead of ind-senz, output any OCR system, other than one used in step 3 (above), can be used with the same filename.
5) SRules that contain 71 Sandhi Splitting Rules.
6) A text file with name "PWords" may be additionally added in folder "Book1" with Domain words, each separated by a newline, if known in advance.
7) A text file with name "CPair" may be additionally added in folder "Book1" with tab separated Correction pairs, one pair in one line, if known in advance.
6) Folder “Inds” with jpeg files for first 20 pages of book and corresponding per page output from Indsenz.
7) Folder “Correct” with correct output of corresponding 20 pages in folder “Inds”.
8) Folder “Corrected” in which the output corrected by the user would be loaded while using the application.

# How to use the Framework

1) Click on the “Open” icon on top left, or press “Ctrl+O”
2) Open the file “data/Book1/Inds/page-1.txt”. This also link the files and folders in “Book1/”.
3) Click on “Load Data” to load Dictionary, Confusions, Sandhi Rules, GEROCR , IEROCR. Common OCR words in GEROCR and IEROCR will be loaded in Domain Vocabulary. If you forget to “Load Data”, data will be loaded whenever you right click a word.
4) Finally, after loading data, page1.txt will again appear in the text browzer. Left click on the word to change the mouse cursor position and then right click on the colored words to generate suggestions.
5) Type in slp1 format and press “Cntrl+d” to change the text under cursor to Devanagari.
e.g. :-
शशरननार -> शशरननाN -> (Cntrl D) -> शशरननाड
"गनाररर्ग्यककेरलननीलकण्ठस o मससस्वववरचचित" -> "गनाररर्ग्यककेरलननीलकण्ठससोमससस्वववरचचित-”
If there are any issues in the format, just right click on the word and select the correct suggestion. Leave the correct colored words as it is.
6) Do not forget to use “Cntrl + S” to save the partially/fully corrected page to folder “Corrected”. Next time you come to the same page, the page will be uploaded from folder “Corrected” automatically.
7) Very Important: Afther the whole page is corrected load the words in Domainvocabulary by clicking “Cntrl + Shift + P”.
8) There is a timer on top left which gets updated on each right click or “Ctrl S”. It resets to 0 on loading the new page. Use “Ctrl R” to move to next page and “Ctrl L” to move to previous page.
9) As you use “Cntrl + Shift + P” to load domain words, you will observe improvement in suggestions page by page.
10) A useful tip: keep the GEROCR open in an editor as certain correct lines can be directly copied from it.

# References and code:
1. We started the code (and used icons) from: https://www.youtube.com/watch?v=x858_WCtl_Y
2. We further improved the application via ideas from "QPlainTextEdit With In Line Spell Check". Visit: https://john.nachtimwald.com/2009/08/22/qplaintextedit-with-in-line-spell-check/
3. For generating suggestions and  we used "Algorithm: Edit distance using a trie-tree (Dynamic Programming)" by Author: Murilo Adriano Vasconcelos <muriloufg@gmail.com>.
Visit: https://murilo.wordpress.com/2011/02/01/fast-and-easy-levenshtein-distance-using-a-trie-in-c/
4. For extracting OCR confusions, we used C++ implementation of "A linear space algorithm for computing maximal common subsequences" by D. S. Hirschberg for allignment. Visit  http://portal.acm.org/citation.cfm?id=360861. 
We further developed the code to extract OCR confusions from unalligned OCR text, alligned OCR text and Correct text. 


