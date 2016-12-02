#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

string promptUserForFile(ifstream &stream);
char getChars(string word, int i);
void createEmptyGrid();
int checkRow(int column, char c);
int checkColumn(int row, char c);
int randomNum(int maxNum);
char addToGrid(int row, int column,char c);
void displayAddedGrid();
void intializeGrid();

string words[16]; //array set for all of our 16 words
char word[4];  //this might be useless because but this is the characters in the chosen word
char table[4][4]; // this is our 4x4 array

int main()
{
    ifstream infile; //infile typical file stuff
    promptUserForFile(infile);// this just assigns input.txt as the file name to read
    srand(time(NULL)); //this initializes some stuff for our randomn number, this needs wokr i think
    int oneThroughSixteen = randomNum(16); // this sets a standard for which word we will use from our 16
    string line; // how we will read the word from the file

    for(int i = 0; i < 16; i++) // this populates our words with the infile
    {
        getline(infile,line);
        words[i] = line;
    }
    string startWord = words[randomNum(16)]; // this sets our word to startWord

    cout << startWord << endl; // this is for testing, to see what the word is

    for(int i = 0; i < 4;i++){ // this might be useless, it sets our string to an array which it already is. idk man
        word[i] = getChars(startWord, i);
    }

    createEmptyGrid();// just for visualization, also assigns ' ' to each element
    intializeGrid(); //puts letters in 4 spaces
    displayAddedGrid(); //shows the letters in the spaces

    infile.close();

}

string promptUserForFile(ifstream &stream) // changed this to automatically assign input.txt
{
   while (true)
    {
      string filename;
      filename = "input.txt";
      stream.open(filename.c_str());
      if (!stream.fail()) return filename;
      stream.clear();
      cout << "Unable to open that file.  Try again." << endl;
    }
}

char getChars(string word, int i){

    return word.at(i); //again this function might be useless

}

void createEmptyGrid(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){ // nested for loop to display grid
            table[i][j] = ' ';
        }
    }
}

int checkRow(int column, char c){
    for(int i = 0; i <= 4; i++){
        if(table[i][column] == c){
        return 1;
        }
    }
    return 0;
}
int checkColumn(int row, char c){
    for(int i = 0; i <= 4; i++){
        if(table[row][i] == c){
            return 1;
        }
    }
    return 0;
}

int randomNum(int maxNum){


    return rand() % maxNum + 0;

}

char addToGrid(int row, int column,char c){ // this function takes in the row and column you want
                                            // basically the position. also takes the letter you want
                                            // to put in. this only works if checkRow and Column
                                            // return a 0, which they only do if the fucntion works

    if(checkRow(column, c) == 0 && checkColumn(row,c) == 0 && table[row][column] == ' '){
             //cout << "Added" << endl;
        return c;
    }
    else{
        //cout << "Not added " << endl;
        return table[row][column];
    }
}

void displayAddedGrid(){ // couts the actual values
cout << "    1    2    3    4" << endl;
    for(int i = 0; i < 4; i++){
            cout << i + 1 << " ";
        for(int j = 0; j < 4; j++){
            cout << "[ " << table[i][j] << " ]" ;
        }
        cout << endl << endl;
    }
}
void intializeGrid(){

int j = 0;
while(j < 4){

        int row = randomNum(3);
        int column = randomNum(3);
        char letter = word[randomNum(3)];
        if(table[row][column] == letter){
            j--;
        }
        table[row][column] = addToGrid(row,column,letter);
        if(table[row][column] == letter){
            j++;
        }
        //displayAddedGrid();
        //it seems like columns 1 and 4 are linked.??????/

}
}
