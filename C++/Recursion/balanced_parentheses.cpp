#include <bits/stdc++.h>
using namespace std;

// <--------------------------------PROBLEM STATEMENT ---------------------------------->
// Generate Balanced Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Input: n = 1
// Output: ["()"]


// <-----------------------------------SOLUTION-------------------------------------------->

void paren(int o, int c, string ans, vector<string>& v){
    // o -> no. of opening braces
    // c -> no. of closing braces
    if(o==0 && c==0){
        v.push_back(ans);
        return ;
    }
    
    if (o!=0)
    {
        string op1 = ans;
        op1.push_back('(');
        paren(o-1, c, op1, v);
    }
    if(c>o)
    {
        string op2 = ans;
        op2.push_back(')');
        paren(o, c-1, op2, v);
    }
    return ;
}

vector<string> func(int n){
    vector<string> v;
    int o=n, c=n;
    string ans="";
    paren(o, c, ans, v);
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v = func(n);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}
