class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        
        for(auto c:tokens)
        {
            if(c=="+"||c=="*"||c=="-"||c=="/")
            {
                int b=s.top();
                s.pop();
                int a =s.top();
                s.pop();
                if(c=="+")
                {
                    int d =a+b;
                    s.push(d);
                }
                 if(c=="-")
                {
                    int d =a-b;
                    s.push(d);
                } if(c=="*")
                {
                    int d =a*b;
                    s.push(d);
                } if(c=="/")
                {
                    int d =a/b;
                    s.push(d);
                }

            }
            else{
                int a = stoi(c);
                s.push(a);
            }
        }
        return s.top();    }
};