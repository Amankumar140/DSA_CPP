#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    char* arr;
    int top;
    public:
    Stack(){
        top = -1;
        size = 1000;
        arr= new char[size];
    }
    void push(char x){
        top++;
        arr[top] = x;
    }
    char pop(){
        char x = arr[top];
        top--;
        return x;
    }
    char Top(){
        return arr[top];
    }
    int Size(){
        return top+1;
    }
    bool empty(){
        return top == -1;
    }
};
int prec(char c){
    if(c == '^'){
        return 3;
    }else if( c== '*' || c=='/'){
        return 2;
    }else if(c == '+' || c== '-'){
        return 1;
    }
    return 0;
}
string infixtopostfix(string s){
    s = '('+s+')';
    
    Stack a;
    string result;
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        if((c>='A' && c<='Z') ||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
            result+= c;
        }
        else if(c =='('){
            a.push(c);
        }
        else if(c == ')'){
            while(!a.empty() && a.Top() != '('){
                result += a.Top();
                a.pop();
            }
            a.pop();
        }
        else{
            while(!a.empty() && (prec(s[i])<=prec(a.Top()))){
                result+= a.Top();
                a.pop();
            }
            a.push(c);
        }
    }
    while(!a.empty() ){
        result+= a.Top();
        a.pop();
    }
 
    return result;
}
string infixtoprefix(string s){
    int l = s.size();
    reverse(s.begin(),s.end());
    for(int i = 0;i<l;i++){
        if(s[i] =='('){
            s[i] =')';
            i++;
        }else if(s[i] ==')'){
            s[i] ='(';
            i++;
        }
        
    }
    string prefix = infixtopostfix(s);
    reverse(prefix.begin(),prefix.end());
    return prefix;

}
int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  string ans = infixtoprefix(exp);
  cout<<ans<<endl;
  return 0;
}