#include "Stack.h"

using namespace std;

int main(){
        StackT<int> myStack, nothing;
//Moving a stack
        cout << "Moving a stack" << endl;
        try {
        StackT<int> thisArray;
        thisArray.Push(10);
        thisArray.Push(12);
        thisArray.Push(10);
        cout << thisArray.Top();

    //Testing the move constructor
        StackT secondArray(move(thisArray));
        StackT<int> thirdArray;
        cout << "Thisarray top before the overload assignment operator" << thisArray.Top() << endl;
        thirdArray = thisArray;
        cout << "Third Array top is : " << thirdArray.Top() << " size is " << thirdArray.Size() << endl
        << "ThisArray top is : " << thisArray.Top() << " size is " << thisArray.Size() << endl;
        thirdArray.Pop();
        thisArray.Pop();
        cout << "thisarray size is " << thisArray.Size() << endl;
        cout << "thirdArray size is " << thirdArray.Size() << endl;
        cout << "Secondarray top is " << secondArray.Top() << " size is " << secondArray.Size()<< endl;
        secondArray.Pop();
        cout << "Secondarray top is " << secondArray.Top() << " size is " << secondArray.Size()<< endl;
        
//
        //cout << secondArray.Top() << endl
        //cout << "Now wanting to overwrite thisArray using the copy assignment operator" << endl;
//Testing the copy assignment operator
        //thisArray = MakeStack();
        cout << "Now we created a stack set it equal to thisArray using the move assignment operator bc MakeStack is a rhsvalue" << endl;

        cout << "thisArray top is now " << thisArray.Top() << endl << "thisArray size is " << thisArray.Size() << endl << endl << endl;
    
//Testing regular push
        cout << "Pushing 60,2,56" << endl;
        myStack.Push(60);
        myStack.Push(2);
        myStack.Push(56);

        cout << "Mystack Top is " << myStack.Top() << endl;
        cout << "Size is " << myStack.Size() << endl
            << endl
            << "Pushing 1 in nothing and copying myStack to copiedS" << endl;
//trying to copy
        StackT copiedS(myStack);
        cout << "copiedS top is " << myStack.Top() << endl;
        cout << "copiedS size is " << copiedS.Size() << endl;
        cout << "Pushing 1 in copiedS" << endl;
        copiedS.Push(1);
        cout << "copiedS top is " << copiedS.Top() << endl;
        cout << "copiedS size is " << copiedS.Size() << endl;
        cout << "myStack size is " << myStack.Size() << endl << endl;

        nothing.Push(6);
        cout << "Top in nothing is " << nothing.Top() << endl
             << "Size in nothing is " << nothing.Size() << endl
             << "SETTING nothing = myStack" << endl;
        nothing = myStack;
        nothing.Push(1);
        cout << "Top in nothing is " << nothing.Top() << endl
             << "Size nothing is " << nothing.Size() << endl;
        nothing.Pop();
        nothing.Pop();
        nothing.Pop();
        nothing.Pop();
        cout << "nothing size is " << nothing.Size() << endl;
        nothing.Pop();
    } catch (const bad_stack_op & oor){
        cout << oor.what() << endl;
    }
    
    return 0;
}