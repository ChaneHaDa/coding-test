#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;

    int ans=0, temp=1;
    stack<char> st;

    for(int i=0; i<s.size(); i++) {
        char c=s[i];
        if(c=='(') {
            temp *= 2;
            st.push(c);
        }else if(c=='[') {
            temp *= 3;
            st.push(c);
        }else if(c==')') {
            if(st.empty() || st.top()!='(') {
                ans=0;
                break;
            }
            if(s[i-1]=='(') {
                ans+=temp;
                temp/=2;
                st.pop();
            }else {
                temp/=2;
                st.pop();
            }
        }else if(c==']') {
            if(st.empty() || st.top()!='[') {
                ans=0;
                break;
            }
            if(s[i-1]=='[') {
                ans+=temp;
                temp/=3;
                st.pop();
            }else {
                temp/=3;
                st.pop();
            }
        }
    }
    if(!st.empty()) ans = 0;

    cout<<ans<<'\n';
    

    return 0;
}