#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w;
    cin>>w;
    if(w==2)
        cout<<"NO";
    else
    {
    if(w%2)
        cout<<"NO";
    else
        cout<<"YES";
    }    
return(0);    
}