#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    while(N !=0){
        int M = 0;
        int NU = N;
        while(N >= 10){
            M +=N%10;
            N /=10;
        }M+=N;
        
        int i = 11;
        
        bool complete = false;
        
        while(!complete){
        
            int totval = 0;
            int check = i*NU;
            
            while (check >= 10){
                totval+=check%10;
                check/=10;
            }
            
            totval+=check;
            
            if(totval == M){
            cout << i << endl;    
            complete = true;
            }
           
           i++;

        }
        cin >> N;
    }

    return 0;
}