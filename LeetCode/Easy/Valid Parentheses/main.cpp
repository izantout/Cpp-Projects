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
