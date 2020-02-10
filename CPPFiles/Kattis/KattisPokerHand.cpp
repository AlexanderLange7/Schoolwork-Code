/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <algorithm>
using namespace std;
int main(){

char n[14];
string faces;
cin.get(n,14);

//Get index 0,3,6,9,12 from n.
for(int i = 0; i < 14; i++){
    
    if(i%3==0){
    faces+=(n[i]);
    }
    i+=2;
}
int currentfrequency = 1;
int storedmax = 0;


sort(faces.begin(), faces.end());


//cout << faces << endl;


for(int i = 1; i < 5; i++){
   if(faces[i-1]==faces[i]){
       currentfrequency++;
   }else if(currentfrequency> storedmax){
       storedmax = currentfrequency;
       currentfrequency=1;
   }
    
}


if(storedmax<currentfrequency){
    cout<< currentfrequency << endl;
}
else{
    cout << storedmax << endl;
}
return 0;
}