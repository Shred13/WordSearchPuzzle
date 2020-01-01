//
// Created by Shreyansh Anand on 2019-11-10.
//
char alpha[26];
#include <random>
#include "JumblePuzzle.h"
using namespace std;
typedef char* charArrayPtr;

int rando() {
    //random function that returns a random integer
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 60);
    return dist(mt);
}

const char* BadJumbleException::what() const throw()
/*
 * Exception struct to return a general error
 */
{return "\nSorry! Massive error found friend.\nCheck if the input is between 3 and 10 characters and you have the right difficulty";};

JumblePuzzle::JumblePuzzle(std::string word, std::string difficulty) {
    /*
     * Constructor that creates a JumblePuzzle
     */
    for (int i = 0; i<26; i++){
        /*
         * loop that creates an array filled with lower-case letters - used
         * to randomly assign letters to the JumblePuzzle
         */
    alpha[i]= i+97;
    }
    toHide = move(word);
    difficult = move(difficulty);

    if (toHide.size()<3||toHide.size()>10){
        throw BadJumbleException();
    }

    int rand = rando();
    char direction_to_use = dir[rand%4];
    Direction = direction_to_use;
    if (difficult=="easy"){
        int arr_length = toHide.size()*2;
        result = makeArray(direction_to_use, arr_length, toHide);
        arr_size=arr_length;
    }
    else if (difficult=="medium"){
        int arr_length = toHide.size()*3;
        result = makeArray(direction_to_use, arr_length, toHide);
        arr_size = arr_length;
    }
    else if (difficult=="hard"){
        int arr_length = toHide.size()*4;
        result = makeArray(direction_to_use, arr_length, toHide);
        arr_size = arr_length;
    }
    else{
        throw BadJumbleException();
    }
}

//accessor methods
int JumblePuzzle::getColPos() {return ColPosFinal;}

int JumblePuzzle::getSize(){return arr_size;}

int JumblePuzzle::getRowPos() {return RowPosFinal;}

char JumblePuzzle::getDirection(){return Direction;}

//copy method that makes a copy of the current JumblePuzzle
JumblePuzzle::JumblePuzzle(const JumblePuzzle &p2) {
    RowPosFinal = p2.RowPosFinal;
    ColPosFinal = p2.ColPosFinal;
    Direction = p2.Direction;
    arr_size=p2.arr_size;
    result = new char*[arr_size];
    for (int i = 0; i<getSize(); i++){
        result[i] = new char[arr_size];
        for (int j = 0; j<getSize(); j++){
            result[i][j] = p2.result[i][j];
        }
    }
}

//helper function that makes the array and randomly assigns the direction and letters
charArrayPtr* JumblePuzzle::makeArray(char direction, int length, std::string& word){
    char **returnPuzzle = new char*[length];
    for (int i = 0; i<length; i++){
        returnPuzzle[i] = new char[length];
        for (int j= 0; j<length; j++){
            returnPuzzle[i][j]=alpha[rando()%26];
        }
    }
    if (direction=='n'){
        int a = rando()%length;
        while (a<word.size()){
            a = rando()%length;
        }
        int rowPos = a;
        int colPos = rando()%length;
        returnPuzzle[rowPos][colPos] = word[0];
        for (unsigned long i = word.size()-1; i>0; i--){
            returnPuzzle[rowPos-i][colPos] = word[i];
        }
        RowPosFinal = rowPos;
        ColPosFinal = colPos;
    }
    else if (direction=='w'){
        int a = rando()%length;
        while (a<word.size()){
            a = rando()%length;
        }
        int colPos = a;
        int rowPos = rando()%length;
        returnPuzzle[rowPos][colPos] = word[0];
        for (unsigned long i = word.size()-1; i>0; i--){
            returnPuzzle[rowPos][colPos-i] = word[i];
        }
        RowPosFinal = rowPos;
        ColPosFinal = colPos;
    }
    else if (direction=='e'){
        int colPos = rando()%word.size();
        int rowPos = rando()%length;
        returnPuzzle[rowPos][colPos] = word[0];
        for (unsigned long i = 1; word.size() > i; i++){
            returnPuzzle[rowPos][colPos+i]=word[i];
        }
        RowPosFinal = rowPos;
        ColPosFinal = colPos;
    }
    else if (direction=='s'){
        int rowPos = rando()%word.size();
        int colPos = rando()%length;
        returnPuzzle[rowPos][colPos] = word[0];
        for (unsigned long i = 1; word.size() > i; i++){
            returnPuzzle[rowPos+i][colPos]=word[i];
        }
        RowPosFinal = rowPos;
        ColPosFinal = colPos;
    }
    return returnPuzzle;
}

//destructor
JumblePuzzle::~JumblePuzzle() {
    for (int i =0; i<getSize(); i++){
        delete [] result[i];
    }
    delete result;
}
//accessor for the entire Jumble
char** JumblePuzzle::getJumble() {
    return result;
}

//overloads the operator =. Similar to copy
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle &JumblePuzzle) {
    if (this == &JumblePuzzle)
        return *this;
    Direction = JumblePuzzle.Direction;
    arr_size=JumblePuzzle.arr_size;
    RowPosFinal = JumblePuzzle.RowPosFinal;
    ColPosFinal = JumblePuzzle.ColPosFinal;
    result = new char*[arr_size];
    for (int i = 0; i<getSize(); i++){
        result[i] = new char[arr_size];
        for (int j = 0; j<getSize(); j++){
            result[i][j] = JumblePuzzle.result[i][j];
        }
    }
    return *this;
}