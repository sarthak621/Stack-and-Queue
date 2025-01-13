#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    string str="953+4*6/-";
    stack<int>val;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        int ascii=(int)ch;
        if(ascii>48 && ascii<=57){
            val.push(ascii-48);
        }
        else{
            //means no. nahi hai so op hi hoga
            int v2=val.top();
            val.pop();
            int v1=val.top();
            val.pop();
            if(ch=='-' ) val.push(v1-v2);
            if(ch=='+' ) val.push(v1+v2);
            if(ch=='*' ) val.push(v1*v2);
            if(ch=='/' ) val.push(v1/v2);
        

    }

   }
    cout<<val.top();
}