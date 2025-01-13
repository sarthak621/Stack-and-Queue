#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    // string str="9-5+3*4/6";
    string str="9-5+3*4/6";

     
     // 9-5+3*4/6--->6
     // 9-(5+3)*4/6--->4
     
     stack<int>val;
     stack<int>op;

     for(int i=0;i<str.size();i++){
        char ch=str[i];
        int ascii=(int) ch;
        if(ascii>48 && ascii<=57) val.push(ascii-48);
        else if(op.size()==0 || ch=='(' || op.top()=='(') op.push(ch);
        
        else if(ch==')'){
            //work
            while(op.top()!='('){
                int v2=val.top();
                val.pop();
                int v1=val.top();
                val.pop();

                if(op.top()=='-' ) val.push(v1-v2);
                if(op.top()=='+' ) val.push(v1+v2);
                if(op.top()=='*' ) val.push(v1*v2);
                if(op.top()=='/' ) val.push(v1/v2);
                op.pop();
             
            }
            op.pop(); //'(' hata dia isko bhi
        }

        else{
            if(ch=='+' || ch=='-'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '+' || op.top() == '-')){

                    int v2=val.top();
                    val.pop();
                    int v1=val.top();
                    val.pop();
    
                    if(op.top()=='-' ) val.push(v1-v2);
                    if(op.top()=='+' ) val.push(v1+v2);
                    if(op.top()=='*' ) val.push(v1*v2);
                    if(op.top()=='/' ) val.push(v1/v2);
                    op.pop();
                }
                op.push(ch);
            }

             if(ch=='*' || ch=='/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    int v2=val.top();
                    val.pop();
                    int v1=val.top();
                    val.pop();
                   
                    if(op.top()=='-' ) val.push(v1-v2);
                    if(op.top()=='+' ) val.push(v1+v2);
                    if(op.top()=='*' ) val.push(v1*v2);
                    if(op.top()=='/' ) val.push(v1/v2);
                    op.pop();
                
                }

                 op.push(ch);
                
            }


        }

     }


            while(!op.empty()){    
                int v2=val.top();
                val.pop();

                int v1=val.top();
                val.pop();

                if(op.top()=='-' ) val.push(v1-v2);
                if(op.top()=='+' ) val.push(v1+v2);
                if(op.top()=='*' ) val.push(v1*v2);
                if(op.top()=='/' ) val.push(v1/v2);

                op.pop();

            }
            cout<<val.top();

      
}