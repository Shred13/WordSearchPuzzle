#include <string>
#include <iostream>
#include <ctime>
#include "JumblePuzzle.h"
using namespace std;

// Displays the puzzle to the screen.
// Row and column numbers are added to the display.
void showJumble(const charArrayPtr* jumble, const int size) {
    int i, j;
    cout << "\n  ";
    for (i = 0; i < size; i++)
        if (i < 10)
            cout << " " << i << " ";
        else
            cout << i << " ";
    cout << endl;
    for (i = 0; i < size; i++) {
        if (i < 10)
            cout << " " << i << " ";
        else
            cout << i << " ";
        for (j = 0; j < size; j++)
            cout << jumble[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
} // end showJumble

// How quickly can you find the hidden string?
void playGame() {
    string toHide;
    string difficulty;
    int guessRow, guessCol;
    int start, finish;
    char guessDirection;

    cout << "Provide a string to hide in the puzzle, all lower case: ";
    cin >> toHide;
    cout << "\nChoose your difficulty level: \"easy\", \"medium\" or \"hard\": ";
    cin >> difficulty;

    JumblePuzzle* jp;
    try {
        jp = new JumblePuzzle(toHide, difficulty);
    } catch (BadJumbleException& e) {
        cerr << e.what();
        return;
    }
    showJumble(jp->getJumble(), jp->getSize());
    start = static_cast<int>(time(nullptr));
    cout << "Enter row location: ";
    cin >> guessRow;
    cout << "Enter column location: ";
    cin >> guessCol;
    cout << "Enter direction (\"n\", \"e\", \"s\" or \"w\"): ";
    cin >> guessDirection;
    finish = static_cast<int>(time(nullptr));
    if (guessRow == jp->getRowPos() && guessCol == jp->getColPos() &&
        guessDirection == jp->getDirection())
        cout << "You found it!" << endl;
    else {
        cout << "Wrong location..." << endl;
        cout << "The location is row: " << jp->getRowPos() << " col: " << jp->getColPos()
             << ", direction: " << jp->getDirection() << endl;
    }
    cout << "You took " << (finish - start) << " seconds." << endl;
    delete jp;
    jp = nullptr;
} // end playGame


void testJumble() {

    // Test copy constructor for proper operation
    cout << "Testing copy constructor:" << endl;
    // While debugging, you can use capital letters to make the hidden string easier to locate
    JumblePuzzle jp1("HELLO", "easy");
    showJumble(jp1.getJumble(), jp1.getSize());
    JumblePuzzle jp2(jp1);
    cout << "Should look the same:" << endl;
    showJumble(jp2.getJumble(), jp2.getSize());

    // Test aliasing from copy constructor
    charArrayPtr* puzzle = jp2.getJumble();
    int sz = jp2.getSize();
    for (int i = 0; i < sz; i++)
        puzzle[i][i] = '.';
    cout << "Dotted diagonal:" << endl;
    showJumble(puzzle, sz);
    cout << "Should be same as original 1:" << endl;
    showJumble(jp1.getJumble(), sz);
    cout << "Should be same as original 2:" << endl;
    showJumble(jp2.getJumble(), sz);

    // Test assignment operator for proper operation
    cout << "Testing assignment operator:" << endl;
    JumblePuzzle jp3("BYE", "easy");
    showJumble(jp3.getJumble(), jp3.getSize());
    JumblePuzzle jp4 = jp3;
    cout << "Should look the same:" << endl;
    showJumble(jp4.getJumble(), jp4.getSize());

    // Test aliasing from assignment operator
    puzzle = jp4.getJumble();
    sz = jp4.getSize();
    for (int i = 0; i < sz; i++)
        puzzle[i][i] = '*';
    cout << "Star diagonal:" << endl;
    showJumble(puzzle, sz);
    cout << "Should be same as original 3:" << endl;
    showJumble(jp3.getJumble(), sz);
    cout << "Should be same as original 4:" << endl;
    showJumble(jp4.getJumble(), sz);

    // Test self-assignment
    // This shows as a "bug", which it should do.  However, you should still
    // be able to build and run your program.
    jp4 = jp4;
    cout << "Should be same as original 4:" << endl;
    showJumble(jp4.getJumble(), sz);
    int loopLimit = 1000;
    for (int i = 0; i < loopLimit; i++)
        JumblePuzzle jp("HIDDENWORD", "hard");
    cout << "\nPassed memory leak test!" << endl;

} // end testJumble
void blackbox(){
    /*
     * Blackbox function that tests the various accessors and exceptions. The console statements explain each of the tests.
     */
    bool test1,test2,test3,test4,test5,test6,test7,test8,test9;
    bool test10 = false;
    bool test11 = false;
    bool test12=false;
    string testString = "HELLO";
    JumblePuzzle jp1(testString, "easy");
    if (jp1.getSize()==testString.size()*2){
        cout<<"Test to check the easy size passed"<<endl;
        test1 = true;
    }
    else{
        cout<<"Test to check the easy size failed"<<endl;
        test1 = false;
    }
    JumblePuzzle jp2 (testString, "medium");
    if (jp2.getSize()==testString.size()*3){
        cout<<"Test to check the medium size passed"<<endl;
        test2 = true;
    }
    else{
        cout<<"Test to check the medium size failed"<<endl;
        test2 = false;
    }
    JumblePuzzle jp3 (testString, "hard");
    if (jp3.getSize()==testString.size()*4){
        cout<<"Test to check the hard size passed"<<endl;
        test3 = true;
    }
    else{
        cout<<"Test to check the hard size failed"<<endl;
        test3 = false;
    }
    if(jp1.getDirection()=='n'||jp1.getDirection()=='s'||jp1.getDirection()=='e'||jp1.getDirection()=='w'){
        cout<<"test 1 passed for direction"<<endl;
        test4 = true;
    }
    else{
        cout<<"test 1 failed for direction"<<endl;
        test4 = false;
    }
    if(jp2.getDirection()=='n'||jp2.getDirection()=='s'||jp2.getDirection()=='e'||jp2.getDirection()=='w'){
        cout<<"test 2 passed for direction"<<endl;
        test5 = true;
    }
    else{
        cout<<"test 2 failed for direction"<<endl;
        test5 = false;
    }
    if(jp3.getDirection()=='n'||jp3.getDirection()=='s'||jp3.getDirection()=='e'||jp3.getDirection()=='w'){
        cout<<"test 3 passed for direction"<<endl;
        test6 = true;
    }
    else{
        cout<<"test 3 failed for direction"<<endl;
        test6 = false;
    }
    if (jp1.getJumble()[jp1.getRowPos()][jp1.getColPos()]==testString[0]){
        cout<<"test 1 passed for Jumble, RowPos, ColPos accessors"<<endl;
        test7 = true;
    }
    else {
        cout<<"test 1 failed for Jumble, RowPos, ColPos accessors"<<endl;
        test7 = false;
    }
    if (jp2.getJumble()[jp2.getRowPos()][jp2.getColPos()]==testString[0]){
        cout<<"test 2 passed for Jumble, RowPos, ColPos accessors"<<endl;
        test8 = true;
    }
    else {
        test8 = false;
        cout<<"test 2 failed for Jumble, RowPos, ColPos accessors"<<endl;
    }
    if (jp3.getJumble()[jp3.getRowPos()][jp3.getColPos()]==testString[0]){
        cout<<"test 3 passed for Jumble, RowPos, ColPos accessors"<<endl;
        test9 = true;
    }
    else {
        cout<<"test 3 failed for Jumble, RowPos, ColPos accessors"<<endl;
        test9 = false;
    }
    try {JumblePuzzle jp4("h", "medium");}
    catch (BadJumbleException &e){
        cout<<"Too small string exception test passed"<<endl;
        test10 = true;
    }
    try {JumblePuzzle jp4("hhjviadshnfiuelwhfiuoewqhjaio", "medium");}
    catch (BadJumbleException &e){
        cout<<"Too large string exception test passed"<<endl;
        test11=true;
    }
    try {JumblePuzzle jp4("hie", "hiyageorgie");}
    catch (BadJumbleException &e){
        cout<<"Bad difficulty exception test passed"<<endl;
        test12=true;
    }
    if(test1&&test2&&test3&&test4&&test5&&test6&&test7&&test8&&test9&&test10&&test11&&test12){
        cout<<"ALL TESTS PASSED"<<endl;
    }
    else{
        cout<<"NOT ALL TESTS HAVE PASSED"<<endl;
    }
}
int main() {

    testJumble();
//    playGame();
    blackbox();
    return 0;
} // end main