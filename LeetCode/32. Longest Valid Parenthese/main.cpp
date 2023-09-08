class Solution {
public:

    void stackPrint(stack<int> s){
        cout << '[';
        while(!s.empty()){
            cout << s.top() << ',';
            s.pop();
        }
        cout << ']' << endl;
    }

    int longestValidParentheses(string s) {
        int maximum = 0;
        stack<int> myStack;
        // Initialize the stack with something there
        myStack.push(-1);
        for(int i=0; i<s.length(); ++i){
            // If s[i] is ) we push it to the stack
            if(s[i] == '('){
                myStack.push(i);
            } else {
                // If s[i] is ) we pop
                myStack.pop();
                // If the stack is empty (1st char was a ')' )
                if(myStack.empty()){
                    // We push i into the stack as a starting point
                    myStack.push(i);
                } else {
                    // If the stack is not empty, set maximum to the max between the current maximum 
                    // and i - stack.top (since stack.top will be the most recent i added that didnt work)
                    maximum = max(maximum, i - myStack.top());
                }
            }
        }
        // return maximum
        return maximum;
    }
};
