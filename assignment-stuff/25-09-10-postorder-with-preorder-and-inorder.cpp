#include<iostream>
#include<vector>
using namespace std;


string find_postorder(string pre,string in){
    string res="";
    if(pre.empty()||in.empty()) return res;
    char root=pre[0];

    int rootindex=in.find(root);
    string inleft=in.substr(0,rootindex);
    string inright=in.substr(rootindex+1);
    string preleft=pre.substr(1,inleft.size());
    string preright=pre.substr(inleft.size()+1);

    string leftpost=find_postorder(preleft,inleft);
    string rightpost=find_postorder(preright,inright);

    return leftpost+rightpost+root;
    }

int main(){
    string preorder="ABDECFG";
    string inorder="DBEAFCG";

    cout<<find_postorder(preorder,inorder);
    
    return 0;
}