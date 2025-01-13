#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    // string str="9-5+3*4/6";
    string infix="9-(5+3)*4/6";
    cout<<infix<<endl;
         
     // 9-5+3*4/6--->6
     // 9-(5+3)*4/6--->4
     
     stack<string>val;
     stack<char>op;

     for(int i=0;i<infix.size();i++){
        char ch=infix[i];
        int ascii=(int) ch;
        if(ascii>48 && ascii<=57){
            // 0 to 9
            string s=string(1,ch);  //covert char to string
            val.push(s);
        }
        else if(op.size()==0 || ch=='(' || op.top()=='(') op.push(ch);
        
        else if(ch==')'){
            //work
            while(op.top()!='('){
                string v2=val.top();
                val.pop();
                string v1=val.top();
                val.pop();

                char o= op.top();
                op.pop();
                string t=o+v1+v2;  //append
                val.push(t);

            }
            op.pop(); //'(' hata dia isko bhi
        }

        else{
            if(ch=='+' || ch=='-'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '+' || op.top() == '-')){
                string v2=val.top();
                val.pop();
                string v1=val.top();
                val.pop();

                char o= op.top();
                op.pop();
                string t=o+v1+v2;  //append
                val.push(t);
                }
                op.push(ch);
            }

            else if(ch=='*' || ch=='/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                string v2=val.top();
                val.pop();
                string v1=val.top();
                val.pop();

                char o= op.top();
                op.pop();
                string t=o+v1+v2;  //append
                val.push(t);
                }
                  op.push(ch);
                
            }


        }

     }

            while(!op.empty()){
                string v2=val.top();
                val.pop();
                string v1=val.top();
                val.pop();

                char o= op.top();
                op.pop();
                string t=o+v1+v2;  //append
                val.push(t);
                

            }
            string prefix=val.top();
            val.pop();
            cout<<prefix;

      
}