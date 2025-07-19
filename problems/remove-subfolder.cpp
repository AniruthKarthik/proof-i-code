#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

//INCOMPLETE

int main(){
    std::vector<std::string> vec={"/a","/a/b","/c/d","/c/d/e","/c/f"};
    std::sort(vec.begin(),vec.end());
    for(auto i:vec){
        std::cout<<i;
        std::cout<<"\n";
    }


    return 0;
}
