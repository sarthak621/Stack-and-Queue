#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    string str="-9/*+5346";
    stack<string>val;
    for(int i=str.length()-1;i>=0;i--){
        char ch=str[i];
        int ascii=(int)ch;
        if(ascii>48 && ascii<=57){
            string s=string(1,ch);
            val.push(s);
        }
        else{
            //means no. nahi hai so op hi hoga
            string v1=val.top();
            val.pop();
            string v2=val.top();
            val.pop();
            char op=ch;
            string t=v1+v2+op;
            val.push(t);        

    }

   }
    cout<<val.top();
}