/** Reverse Polish Notation Calculator
 * 
 * We're going to read lines and calculate the value of each line in reverse
 * polish notation.
 * 
 * Alex, Tram
 * 9/27/2017
 */

//Imports list
#include "Stack.h"
#include "DLL.h"
#include <iostream>
#include <string>
#include <cstdlib>

//Main method
int main(){
    using namespace std;
    
    //First, we're going to create a stack for our lines to be put in the form of a double.
    Stack<double> calc;
    //We are going to talk to our user and ask for input
    cout<<"Welcome to the Doane RPN Calculator!" << endl;
    cout<<"Please enter an expression in postfix, EOF to quit" << endl;;
     
    //Create a string  and use cin to read input lines.
    string token
    //While we have a token, we go through our loop.
    while (cin>>token){
        
        //If our token is our + sign, we pull our 2 things from the stack and operate.
        if(token == "+"){
            double a = calc.pop();
            double b = calc.pop();
            double sum = a+b;
  
            calc.push(sum);
  
        }
    
        //If our token is our - sign, we pull our 2 things from the stack and operate.
        else if(token == "-"){
            double a = calc.pop();
            double b = calc.pop();
            double sum = a-b;
            calc.push(sum);
        }
   
        //If our token is our * sign, we pull our 2 things from the stack and operate.
        else if (token == "*"){
            double a = calc.pop();
            double b = calc.pop();
            double sum = a*b;
            calc.push(sum);
        }
  
        //If our token is our / sign, we pull our 2 things from the stack and operate.
        else if (token == "/"){
            double a = calc.pop();
            double b = calc.pop();
            double sum = a/b;
            calc.push(sum);
        }
    
        //If our token is our Endline, we just pull out our output and give it to them.
        else if ( token == "E"){
            double final = calc.pop();
            std::cout << ">>> " << final  << endl;
            calc.clear();
        }
    
        //When it is something we want to put in our stack we just throw it in there I guess.
        else{
            double val = atof(token.c_str());
            calc.push(val);
        }//End else statement.
    }//end while loop

    //When we break from the loop we say bye
    std::cout<<"Goodbye!" << endl;
   

    return EXIT_SUCCESS;
}//End Main Method

