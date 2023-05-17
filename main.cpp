/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a FIFO stack using a linked list
*/

#include "main.h"

int main(int argc, char **argv) {

    Fifo fifo;

    //************************************************************************************************
    //EMPTY TESTS
    //Test peek(), pull(), and isEmpty() operations when stack is empty. push() will be tested on empty
    //stack when tests on filling are conducted
    //************************************************************************************************

    cout << "Test peek(), pull(), and isEmpty() operations when stack is empty." << endl;
    cout << "=================================================================" << endl;

    //Testing isEmpty() on empty stack
    cout << "Result of isEmpty(): ";
    if (fifo.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }

    //Testing peek() on empty stack
    cout << "Result of peek(): ";

    //Create 'empty' struct to pass to stack
    Data peeker;

    if(fifo.peek(&peeker)){
        cout << "Struct with following attributes successfully peeked:" << endl;
        cout << "ID: " << peeker.id << endl;
        cout << "Information: " << peeker.data << endl;
    }else{
        cout << "Peek underflow error: stack is empty" << endl;
    }

    //Testing pull() on empty stack
    cout << "Result of pull(): ";

    //Create 'empty' struct to pass to stack
    Data puller;

    if(fifo.pull(&puller)){
        cout << "Struct with following attributes successfully pulled from stack:" << endl;
        cout << "ID: " << puller.id << endl;
        cout << "Information: " << puller.data << endl;
    }else{
        cout << "pull underflow error: stack is empty" << endl;
    }
    cout << endl;

    //************************************************************************************************
    //FILLING AND FULL TESTS
    //************************************************************************************************

    cout << "Testing all operations when stack is filling and full." << endl;
    cout << "=================================================================" << endl;

    //Test filling stack with invalid ID and information values
    //Test with negative ID value 
    cout << "Test filling stack with negative and therefore invalid ID:" << endl;

    int testID = (rand() % 10)* -1;
    string testInfo = "Testing a struct with a negative ID";
    if(fifo.push(testID, &testInfo)){
        cout << "Struct successfully pushed" << endl;
    }else{
        cout << "Struct not pushed" << endl;
    }
    cout << endl;
    
    //Test with empty information value
    cout << "Test filling stack with empty and therefore invalid information:" << endl;

    testID = rand() % 10;
    testInfo = "";
    if(fifo.push(testID, &testInfo)){
        cout << "Struct successfully pushed" << endl;
    }else{
        cout << "Struct not pushed" << endl;
    }
    cout << endl;

    //Testing filling the stack and overflow
    cout << "Filling the stack until overflow error occurs:" << endl;

    bool overflow = false;

    while(!overflow){
        //Create random id
        testID = (rand() % MAX_INT + 1);
        //Create random string
        int numLetters = rand() % 10 + 1;
        char letters [numLetters];
        for(int i; i < numLetters; i++){
            letters[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
        }
        testInfo = letters;
        if(fifo.push(testID, &testInfo)){
            cout << "Struct with following attributes successfully pushed to stack:" << endl;
            cout << "ID: " << testID << endl;
            cout << "Information: " << testInfo << endl;
        }else{
            cout << "Struct not pushed: overflow error" << endl;
            overflow = true;
        }
    }
    cout << endl;

    //Testing isEmpty() on full stack
    cout << "Result of isEmpty(): ";

    if (fifo.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }
    cout << endl;

    //Testing peek() on full stack
    cout << "Result of peek(): " << endl;

    if(fifo.peek(&peeker)){
        cout << "Struct with following attributes successfully peeked:" << endl;
        cout << "ID: " << peeker.id << endl;
        cout << "Information: " << peeker.data << endl;
    }else{
        cout << "Peek underflow error: stack is empty" << endl;
    }
    cout << endl;



    //************************************************************************************************
    //EMPTYING AND EMPTY TESTS
    //************************************************************************************************

    std::cout << "Testing peek() and pull() until stack is empty" << std::endl;
    std::cout << "=================================================================" << std::endl;

    //Testing pull() on full stack. pull each struct until stack is empty and underflow error occurs.
    cout << "Calling pull() until underflow error occurs:" << endl;

    for (int i = 0; i <= STACK_SIZE + 1; i++) {
        std::cout << "Result of peek(): " << std::endl;
        if(fifo.peek(&peeker)){
            std::cout << "Struct with following attributes successfully peeked:" << std::endl;
            std::cout << "ID: " << peeker.id << std::endl;
            std::cout << "Information: " << peeker.data << std::endl;
        }else{
            std::cout << "Peek underflow error: stack is empty" << std::endl;
        }

        std::cout << "Result of pull():" << std::endl;
        if(fifo.pull(&puller)){
            std::cout << "Struct with following attributes successfully pullped from stack:" << std::endl;
            std::cout << "ID: " << puller.id << std::endl;
            std::cout << "Information: " << puller.data << std::endl;
        }else{
            std::cout << "pull underflow error: stack is empty" << std::endl;
        }
    }
    std::cout << std::endl;

    //Testing isEmpty() on an empty stack
    std::cout << "Result of isEmpty(): ";
    if (fifo.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is NOT empty" << std::endl;
    }
    std::cout << std::endl;

    //Testing peek() on empty stack
    std::cout << "Result of peek(): ";

    if(fifo.peek(&peeker)){
        std::cout << "Struct with following attributes successfully peeked:" << std::endl;
        std::cout << "ID: " << peeker.id << std::endl;
        std::cout << "Information: " << peeker.data << std::endl;
    }else{
        std::cout << "Peek underflow error: stack is empty" << std::endl;
    }
    std::cout << std::endl;

    //Testing pull() on empty stack
    std::cout << "Result of pull(): ";

    if(fifo.pull(&puller)){
        std::cout << "Struct with following attributes successfully pullped from stack:" << std::endl;
        std::cout << "ID: " << puller.id << std::endl;
        std::cout << "Information: " << puller.data << std::endl;
    }else{
        std::cout << "pull underflow error: stack is empty" << std::endl;
    }
    std::cout << std::endl;
    
    //************************************************************************************************
    //MID-STACK TESTS
    //************************************************************************************************

    //************************************************************************************************
    //RANDOM TESTS
    //************************************************************************************************

    std::cout << "Random testing..." << std::endl;
    std::cout << "=================================================================" << std::endl;

    //Empty the stack
    while(!fifo.isEmpty()){
        fifo.pull(&puller);
    }

    //Fill the stack halfway with random data to begin random tests
    std::cout << "Filling stack halfway..." << std::endl;
    for(int i = 0; i < (int)(STACK_SIZE/2); i++){
        //Create random id
        testID = (rand() % MAX_INT + 1);
        //Create random string
        int numLetters = rand() % 10 + 1;
        char letters [numLetters];
        for(int i; i < numLetters; i++){
            letters[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
        }
        testInfo = letters;
        if(fifo.push(testID, &testInfo)){
            std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
            std::cout << "ID: " << testID << std::endl;
            std::cout << "Information: " << testInfo << std::endl;
        }else{
            std::cout << "Overflow error: stack is full." << std::endl;
        }
    }
    std::cout << std::endl;

    //Test random operations
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < STACK_SIZE*RANDOM_MULTIPLIER; i++) {
        switch (choice) {
            case 1:
            case 2:{
                std::cout << "Result of push():" << std::endl;
                //Create random id
                testID = (rand() % MAX_INT + 1);
                //Create random string
                int numLetters = rand() % 10 + 1;
                char letters [numLetters];
                for(int i; i < numLetters; i++){
                    letters[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
                }
                testInfo = letters;
                if(fifo.push(testID, &testInfo)){
                    std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                    std::cout << "ID: " << testID << std::endl;
                    std::cout << "Information: " << testInfo << std::endl;
                }else{
                    std::cout << "Overflow error: stack is full." << std::endl;
                }
                break;
            }
            case 3:
            case 4:
                std::cout << "Result of pull():" << std::endl;
                if(fifo.pull(&puller)){
                    std::cout << "Struct with following attributes successfully pullped from stack:" << std::endl;
                    std::cout << "ID: " << puller.id << std::endl;
                    std::cout << "Information: " << puller.data << std::endl;
                }else{
                    std::cout << "pull underflow error: stack is empty" << std::endl;
                }
                break;
            case 5:
                std::cout << "Result of peek(): ";
                if(fifo.peek(&peeker)){
                    std::cout << "Struct with following attributes successfully peeked:" << std::endl;
                    std::cout << "ID: " << peeker.id << std::endl;
                    std::cout << "Information: " << peeker.data << std::endl;
                }else{
                    std::cout << "Peek underflow error: stack is empty" << std::endl;
                }
                break;
            case 6:
                std::cout << "Result of isEmpty(): ";
                if (fifo.isEmpty()) {
                    std::cout << "Stack is empty" << std::endl;
                } else {
                    std::cout << "Stack is NOT empty" << std::endl;
                }
        }
        choice = rand() % CHOICES + 1;
    }
    std::cout << std::endl;

    std::cout << "Testing complete." << std::endl;

    return 0;
}