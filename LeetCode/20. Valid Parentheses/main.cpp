int main(){
  string s = "()[]{}";
  string final = "";
  bool flag;
  for(int i=0; i<s.length(); i++){
    if (s[i] == '(' || s[i] == '{' || s[i] == '['){
      final += s[i];
    }
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
      if (final[final.length()-1] == '(' && s[i] == ')'){
        final.pop_back();
      }
      else if (final[final.length()-1] == '{' && s[i] == '}'){
        final.pop_back();
      }
      else if (final[final.length()-1] == '[' && s[i] == ']'){
        final.pop_back();
      }
      else{
        final += s[i];
      }
    }
  }
  cout << final << endl;
  if (final.length() == 0){
    flag = true;
  }
  else{
    flag = false;
  }
  cout << "final length is " << final.length() << endl;
  cout << "flag is " << flag << endl;
  return flag;
}


// stack solution found online
class Solution {
    vector<char> my_stack;
public:
    bool isValid(string s) {
		if (s.size() % 2 != 0)
            return false;
        if (s.size() == 0)
            return true;
        for (int i = 0; i < s.size(); i++)
        {
                my_stack.push_back(s[i]);
				// checking if char pushed on stack is closing brace
                if (my_stack[my_stack.size() - 1] == '}')
                {
				    // if it's a closing brace and is not pushed on empty stack
                    if (my_stack.size() > 1){
					// check for pairs
                    if(my_stack[my_stack.size() - 2] == '{')
                    {
					   // pop if pairs formed
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }
                else if (my_stack[my_stack.size() - 1] == ')')
                {
                    if (my_stack.size() > 1){
                    if(my_stack[my_stack.size() - 2] == '(')
                    {
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }
                else if (my_stack[my_stack.size() - 1] == ']')
                {
                    if (my_stack.size() > 1){
                    if(my_stack[my_stack.size() - 2] == '[')
                    {
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }  
        }
        if (!my_stack.empty())
            return false;
        return true;
    }
};
