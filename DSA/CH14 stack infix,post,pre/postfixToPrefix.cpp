#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    string str="953+4*6/-";
    stack<string>val;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        int ascii=(int)ch;
        if(ascii>48 && ascii<=57){
            string s=string(1,ch);
            val.push(s);
        }
        else{
            //means no. nahi hai so op hi hoga
            string v2=val.top();
            val.pop();
            string v1=val.top();
            val.pop();
            char op=ch;
            string t=op+v1+v2;
            val.push(t);        

    }

   }
    cout<<val.top();
}