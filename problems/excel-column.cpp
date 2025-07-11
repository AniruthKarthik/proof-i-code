#include <iostream>
#include <string>

using namespace std;

int main(){

    string ans="";
    int n=28;
    int q=n/26;
    int r=n%26;
    if(q>0)ans+=(char)(64+q);
    if(r>0)ans+=((char)(r+64));
    cout<<ans;
    cout<<(char)65;
    return 0;
}
