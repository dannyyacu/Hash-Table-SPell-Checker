/*
 * Daniel Yacu:
 * Date Submitted: 3/09
 * Lab Section: 4
 * Assignment Name: Spell Checker using Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     string fileName = "wordlist.txt"; // i did filename shit
     loadStringset(words, fileName); //and this
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
     ifstream infile(filename);
     string inputWord;

     if(infile.fail()){
         cout << "ERROR OPENING FILE\n";
         exit(1);
     }
        while(getline(infile, inputWord)){
            words.insert(inputWord);
        }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
    vector<string> checkedWords;
    string temp = word;
     for(int i = 0; i < word.length(); i++){
        temp = word;
        for(char x = 'a'; x <= 'z'; x++){
            temp[i] = x;
            if(words.find(temp) == true){
                if(temp != word){
                    checkedWords.push_back(temp);
                }
            }
        }
     }
     return checkedWords;
 }

