//
// Created by Shreyansh Anand on 2019-11-10.
//
#include <string>
typedef char* charArrayPtr;
#ifndef JUMBLEPUZZLE_JUMBLEPUZZLE_H
#define JUMBLEPUZZLE_JUMBLEPUZZLE_H

#endif //JUMBLEPUZZLE_JUMBLEPUZZLE_H

// BadJumble Exception
struct BadJumbleException: public std::exception{
public:
    const char *what() const throw();
};
class JumblePuzzle{
public:
    //accessors
    int getSize();
    char** getJumble();
    int getRowPos();
    int getColPos();
    char getDirection();
    //destructor
    ~JumblePuzzle();
    //constructors
    JumblePuzzle(std::string word, std::string difficulty);
    JumblePuzzle(const JumblePuzzle &p2);
    //assignment overloading
    JumblePuzzle& operator=(const JumblePuzzle &JumblePuzzle);

private:
    //private variables, some can be accessed with accessors above
    std::string difficult;
    std::string toHide;
    char dir[4] = {'n','w','s','e'};
    char Direction;
    int arr_size;
    char** result;
    int RowPosFinal;
    int ColPosFinal;
    //makeArray function that is a helper function to create the Jumble
    charArrayPtr* makeArray(char direction, int length, std::string& word);
};
//random function to a return truly random int
int rando();