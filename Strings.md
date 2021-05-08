### [Palindrome String](https://www.interviewbit.com/problems/palindrome-string/)

```cpp
int Solution::isPalindrome(string a) {
    int n = a.size();
    string nw = "";
    for(int i = 0;i < n;i++) {
        if(isalnum(a[i])) nw+=a[i];
    }
    transform(nw.begin(), nw.end(), nw.begin(), ::tolower);
    n = nw.size();
    // cout<<nw<<"\n";
    int i = 0, j = n - 1;
    while (i<j) {
        if (nw[i]!=nw[j]) return 0;
        else {
            i++;
            j--;
        }
    }
    return 1;
}
```

### [Longest Common Prefix](https://www.interviewbit.com/problems/longest-common-prefix/)

```cpp
string Solution::longestCommonPrefix(vector<string> &a) {
    string ans = "", cur = a[0];
    for(auto str : a) {
        ans = "";
        int i = 0, j = 0;
        while (i<cur.size() && j<str.size()) {
            if (cur[i]==str[j]) ans+=str[i];
            else break;
            i++; j++;
        }
        cur = ans;
    }
    return ans;
}
```

### [Count And Say](https://www.interviewbit.com/problems/count-and-say/)

```cpp
string Solution::countAndSay(int a) {
    vector<string> ans = {"1"};
    a-=1;
    for(int i=1;i<=a;i++) {
        string last = ans[i-1];
        int cnt=1; char prev=last[0];
        string add = "";
        for(int i=1;i<last.size();i++) {
            if (last[i]==last[i-1]) cnt++;
            else {
                add+=(char(cnt+48));
                add+=prev;
                cnt=1;
                prev=last[i];
            }
        }
        // cout<<last<<"\n";
        add+=(char(cnt+48));
        add+=prev;
        ans.push_back(add);
    }
    return ans[a];
}
```

### [Amazing Subarrays](https://www.interviewbit.com/problems/amazing-subarrays/)

```cpp
int Solution::solve(string s) {
    int n = s.size(),ans=0;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout<<s<<"\n";
    for(int i=0;i<n;i++) {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            ans+=(n-i);
            ans%=10003;
        }
    }
    return ans;
}
```

### [Implement StrStr (Star Marked)](https://www.interviewbit.com/problems/implement-strstr/)

```cpp
int Solution::strStr(const string a, const string b) {
    int n = a.size(), m = b.size(), val = max(n,m);
    if (n==0 || m==0) return -1;
    vector<int> lps(val + 5,0);

    // gen_lps
      int i = 1, pre_match = 0;
      while (i < m) {
        if (b[i] == b[pre_match]) {
          pre_match += 1;
          lps[i] = pre_match;
          i++;
        }
        else {
          if (pre_match == 0) {lps[i] = 0; i++;}
          else pre_match = lps[pre_match - 1];
        }
      }
      i=0;
      int j = 0, note;
      bool found = false;
      while (i < n) {
        if (j == m) {
          note = i - 1;
          found = true;
          break;
        }
        if (a[i] == b[j]) {
            i++; j++;
            if (j == m && i == n) {
                note = i - 1;
                found = true;
                break;
            }
        }
        else {
          if (j == 0) i++;
          else j = lps[j - 1];
        }
      }
    // if (found) cout<<"found"<<"\n";
    // else cout<<"not found"<<"\n";
      if (found) return note-m+1;
      else return -1;
}
```

### [Minimum Characters required to make a String Palindromic (Star Marked)](https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/)

```cpp
int Solution::solve(string a) {
    int question_mark = a.size(), original_size = a.size();
    string b; b.resize(a.size()); reverse_copy(a.begin(), a.end(), b.begin());
    a = (a + "?" + b);
    int n = a.size();
    int pre_match = 0, i = 1;
    vector<int> lps(n,0);
    while (i<n) {
        if (a[i] == a[pre_match]) {
            pre_match++;
            lps[i] = pre_match;
            i++;
        }
        else {
            if (pre_match == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                pre_match = lps[pre_match - 1];
            }
        }
    }
    int max_size_of_palindrome = 0;
    max_size_of_palindrome = max(max_size_of_palindrome,lps[n-1]);
    int ans = (original_size  - max_size_of_palindrome);
    ans = min(ans,original_size - 1);
    return ans;
}
```

### [Longest Palindromic Substring (Star Marked)](https://www.interviewbit.com/problems/longest-palindromic-substring/)

```cpp
string Solution::longestPalindrome(string s) {
    int n = s.size();
    vector<int> d1(n, 0);
    vector<int> d2(n, 0);
  int l = 0, r = - 1;
  for(int i=0;i<n;i++) {
    // k here is the number of palindromes i can have with index i as centre
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while ((i + k) < n && (i - k) >= 0 && s[i + k] == s[i - k]) {
      k++;
    }
    d1[i] = k;
    if ((i + k - 1) > r) {
      l = (i - k + 1);
      r = (i + k - 1);
    }
  }
  l = 0, r = -1;
  // in case of palindrome of even length, i signifies the latter of the
  // two center indices
  for(int i=1;i<n;i++) {
    // k here is the number of palindromes i can have with index i as centre
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i);
    while ((i + k) < n && (i - k - 1) >= 0 && s[i + k] == s[i - k - 1]) {
      k++;
    }
    d2[i] = k;
    if ((i + k - 1) > r) {
      l = i - k;
      r = (i + k - 1);
    }
  }

  int ans = max(*max_element(d1.begin(), d1.end()), *max_element(d2.begin(), d2.end()));
  string palindrome = "";
  for(int i=0;i<n;i++) {
          if (d2[i] == ans) {
      for (int j = i - d2[i]; j < i + d2[i]; j++) {
        palindrome += s[j];
      }
      return palindrome;
    }
  }
  for(int i=0;i<n;i++) {
    if (d1[i] == ans) {
      for (int j = i - d1[i] + 1; j < i + d1[i]; j++) {
        palindrome += s[j];
      }
      return palindrome;
    }

  }
}
```

### [Length of Last Word](https://www.interviewbit.com/problems/length-of-last-word/)

```cpp
int Solution::lengthOfLastWord(const string a) {
    int n = a.size(),note=-1;
    for(int i=n-1;i>=0;i--) {
        if (a[i]!=' ') {
            note=i;
            break;
        }
    }
    if (note==-1) return 0;
    string ans = "";
    for(int i=note;i>=0;i--) {
        if (a[i]==' ') break;
        ans+=a[i];
    }
    return ans.size();
}
```

### [Reverse the String](https://www.interviewbit.com/problems/reverse-the-string/)

```cpp
string Solution::solve(string a) {
    string ans = "", words = "";
    int n = a.size(), i = 0;
    while (true) {
        int j = i, note = -1;
        words = "";
        for(int k = j;k<n;k++) {
            if (a[k]!=' ') {
                note = k;
                break;
            }
        }
        if (note == -1) break;
        j = note;
        while (j<n && a[j]!=' ') {
            words += a[j];
            j++;
        }
        if (ans.size()) ans = words + " " + ans;
        else ans=words+ans;
        i = j;
        if (i>=n) break;
    }
    return ans;
}
```

### [Compare Version Numbers (Star Marked)](https://www.interviewbit.com/problems/compare-version-numbers/)

```cpp
# define ll long long
# define pb push_back

string remove(string x) {
    string ans="";
    bool first=true;
    for(int i=0;i<x.size();i++) {
        if (x[i]=='0' && !first) ans+='0';
        if (x[i]!='0') {
            first=false;
            ans+=x[i];
        }
    }
    if (ans.size()==0) ans+="0";
    return ans;
}

int comp(string a, string b) {
    string ca = remove(a);
    string cb = remove(b);
    // cout<<a<<" "<<b<<" "<<ca<<" "<<cb<<"\n";
    if (ca.size()>cb.size()) return 1;
    if (ca.size()<cb.size()) return -1;
    for(int i=0;i<ca.size();i++) {
        if (ca[i]-'0'>cb[i]-'0') return 1;
        if (ca[i]-'0'<cb[i]-'0') return -1;
    }
    return 0;
}

int Solution::compareVersion(string a, string b) {
    int n = a.size(), m = b.size();
    string num = "";
    vector<string> num1, num2;
    for(int i=0;i<n;i++) {
        if (a[i]=='.') {
            num1.pb(num);
            num="";
        }
        else {
            num+=a[i];
        }
    }
    if (num.size()>0) num1.pb(num);
    num = "";
    for(int i=0;i<m;i++) {
        if (b[i]=='.') {
            num2.pb(num);
            num="";
        }
        else {
            num+=b[i];
        }
    }
    if (num.size()>0) num2.pb(num);
    int swp=0;
    if (num1.size()>num2.size()) {
        num1.swap(num2);
        swp=1;
    }
    n = num1.size(), m = num2.size();
    for(int i=0;i<n;i++) {
        int cmp = comp(num1[i],num2[i]);
        // cout<<num1[i]<<" "<<num2[i]<<" "<<cmp<<"\n";
        if (cmp==1 && swp==0) return 1;
        else if (cmp==-1 && swp==0) return -1;
        if (cmp==1 && swp==1) return -1;
        else if (cmp==-1 && swp==1) return 1;
    }
    if (n==m) return 0;
    int zero=1;
    for(int i=n;i<m;i++) {
        if (num2[i]!="0") {
            zero=0;
            break;
        }
    }
    if (zero) return 0;
    if (swp) return 1;
    return -1;
}
```

### [Valid Number (Star Marked)](https://www.interviewbit.com/problems/valid-number/)

```python
class Solution:
    # @param A : string
    # @return an integer

    def isNumber(self, a):
        cnt,cnt_,cnt2,cntp=0,0,0,0
        a=a.strip()
        if len(a)==0:
            return 0
        for i in range(len(a)):
            ele=a[i]
            if ord(ele)<ord('0') or ord(ele)>ord('9'):
                # print(ele)
                if i==(len(a)-1):
                    return 0
                if ele=="e":
                    if cnt or i==0:
                        return 0
                    if a[i-1]=='.':
                        return 0
                    cnt+=1
                elif ele==" ":
                    return 0
                elif ele=='-':
                    if i==0:
                        cnt_+=1
                        continue
                    if a[i-1]=="e":
                        cnt_+=1
                        continue
                    return 0
                elif ele=='+':
                    if i==0:
                        cntp+=1
                        continue
                    if a[i-1]=="e":
                        cntp+=1
                        continue
                    return 0
                elif ele=='.':
                    if cnt2>=1 or cnt:
                        return 0
                    cnt2+=1
                else:
                    return 0
        return 1
```

### [Atoi (Star Marked)](https://www.interviewbit.com/problems/atoi/)

```cpp
int Solution::atoi(const string A) {
    string s=A;
    int flag=1;

    while(s[0]==' ')
        s.erase(s.begin());


    if(s[0]=='-') {
        flag= -1;
        s.erase(s.begin());
    }

    if(s[0]=='+')
        s.erase(s.begin());


    long long k=0,i=0;


    while(s[i] >= 48 && s[i] <= 57)
    {

        k = k * 10 + (s[i] - 48);
        i++;

        long long max_val = (long long)INT_MAX;
        long long min_val = (long long)INT_MIN*-1;

        if (flag==1 && k>max_val) {
            return INT_MAX;
        }
        if (flag==-1 && k>min_val) return INT_MIN;
    }

    return flag*k;
}
```

### [Valid Ip Addresses](https://www.interviewbit.com/problems/valid-ip-addresses/)

```cpp
int perfect(string s) {
    int n = s.size();
    if (n>=2 && s[0]=='0') return 0;
    int num = 0;
    for(int i=0;i<n;i++) {
        num*=10;
        num+=(s[i]-'0');
    }
    if (num>=0 && num<=255) return 1;
    return 0;
}

vector<string> Solution::restoreIpAddresses(string a) {
    int n = a.size();
    vector<string> ans;
    if (n>12) return {""};
    for(int w=1;w<n;w++) {
        string s1 = "";
        for(int i=0;i<w;i++) s1+=a[i];
        if (perfect(s1)) {
            for(int x=w+1;x<n;x++) {
                string s2 = "";
                for(int i=w;i<x;i++) s2+=a[i];
                if (perfect(s2)) {
                    for(int y=x+1;y<n;y++) {
                        string s3 = "";
                        for(int i=x;i<y;i++) s3+=a[i];
                        if (perfect(s3)) {
                            string s4 = "";
                            for(int i=y;i<n;i++) s4+=a[i];
                            if (perfect(s4)) {
                                string enter = s1 + "." + s2 + "." + s3 + "." + s4;
                                ans.push_back(enter);
                            }

                        }
                    }
                }
            }
        }
    }
    return ans;
}
```

### [Integer To Roman](https://www.interviewbit.com/problems/integer-to-roman/)

```python
class Solution:
    # @param A : integer
    # @return a strings
    def intToRoman(self, a):
        d={1:"I",4:"IV",5:"V",9:"IX",10:"X",40:"XL",50:"L",90:"XC",100:"C",400:"CD",500:"D",900:"CM",1000:"M"}
        ans = ""
        while a:
            note = -1
            for ele in d:
                if a>=ele:
                    note=max(note,ele)
            ans+=d[note]
            a-=note
        return ans
```

### [Roman To Integer](https://www.interviewbit.com/problems/roman-to-integer/)

```cpp
int Solution::romanToInt(string a) {
    int n = a.size(),i=0,ans=0;
    while(i<n) {
        if (a[i]=='M') {ans+=1000;i+=1;}
        else if (a[i]=='D') {ans+=500;i+=1;}
        if (a[i]=='C') {
            if ((i+1)<n && a[i+1]=='M')  {ans+=900; i+=2;}
            else if ((i+1)<n && a[i+1]=='D')  {ans+=400; i+=2;}
            else {ans+=100;i+=1;}
        }
        else if (a[i]=='L') {ans+=50;i+=1;}
        else if (a[i]=='X') {
            if ((i+1)<n && a[i+1]=='C') {ans+=90;i+=2;}
            else if ((i+1)<n && a[i+1]=='L') {ans+=40;i+=2;}
            else {ans+=10;i+=1;}
        }
        else if (a[i]=='V') {ans+=5;i+=1;}
        else if (a[i]=='I') {
            if ((i+1)<n && a[i+1]=='X') {ans+=9;i+=2;}
            else if ((i+1)<n && a[i+1]=='V') {ans+=4;i+=2;}
            else {ans+=1;i+=1;}
        }
    }
    return ans;
}
```

### [Add Binary Strings](https://www.interviewbit.com/problems/add-binary-strings/)

```cpp
string Solution::addBinary(string a, string b) {
        if (b.size()>a.size()) a.swap(b);

        int n = a.size(), m = b.size();
        int i = n - 1, j = m - 1, carry=0;
        string ans="";
        while (j>=0) {
            if (a[i]=='1' && b[j]=='1') {
                if (carry) ans+='1';
                else ans+='0';
                carry=1;
            }
            else if ((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1')) {
                if (carry) {ans+='0'; carry=1;}
                else ans+='1';
            }
            else if (a[i]=='0' && b[j]=='0') {
                if (carry) {ans+='1';carry=0;}
                else ans+='0';
            }
            i--;j--;
        }
        while (i>=0) {
            if (a[i]=='1') {
                if (carry) {ans+='0';carry=1;}
                else ans+='1';
            }
            else {
                if (carry) {ans+='1';carry=0;}
                else ans+='0';
            }
            i--;
        }
        if (carry) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
}
```

### [Power of 2 (Star Marked)](https://www.interviewbit.com/problems/power-of-2/)

```cpp
int Solution::power(string a) {
    while (true) {
        string total_quotient = "";
        int buffer = 0;
        if (a=="2") break;
        for(int i = 0;i<a.size();i++) {
            if (buffer*10 + (a[i]-'0')<2) {
                // this must mean that buffer is 0 and a[i] is 1
                // therefore we will put buffer as 1
                if (i!=0) total_quotient+="0";
                if (a[i]=='1') buffer = 1;
            }
            else {
                int val = buffer*10 + (a[i]-'0');
                int quotient = val/2;
                total_quotient += (quotient + '0');
                int rem = val%2;
                if (rem) buffer = 1;
                else buffer = 0;
            }
        }
        if (buffer || total_quotient=="0") return 0;
        // if after the execution for for loop the buffer is 1 it must mean
        // that the number is odd.
        // if the number was 1 then the buffer would be 0 and total_quotient
        // would also be 0
        a = total_quotient;
    }
    return 1;
}
```

### [Multiply Strings (Star Marked)](https://www.interviewbit.com/problems/multiply-strings/)

```cpp
string Solution::multiply(string a, string b) {
    if (a=="0" || b=="0") return "0";
    int n = a.size(), m = b.size();
    string ans(n + m, '0');
    for(int i = n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            int val = (a[i]-'0')*(b[j]-'0') + (ans[i+j+1]-'0');
            ans[i+j+1] = val%10 + '0';
            ans[i+j] += val/10;
        }
    }
    for(int i=0;i<n+m;i++) {
        if (ans[i]!='0') return ans.substr(i);
    }
    return "0";
}
```

### [Zigzag String](https://www.interviewbit.com/problems/zigzag-string/)

```cpp
string Solution::convert(string a, int b) {
    string ans = "";
    int mn=0,mx=2*b-2,n=a.size();
    for(int i=0;i<b;i++) {
        int j=i;
        while (j<n) {
            ans+=a[j];
            if (mx>0) {
                j+=mx;
                mn=abs(mn);
                if (mn!=0) mx*=-1;
            }
            else if (mn>0) {
                j+=mn;
                mx=abs(mx);
                if (mx!=0) mn*=-1;
            }
            else if (mx==0 && mn==0) {
                // when b==1
                j+=1;
            }
        }
        mx=abs(mx);mn=abs(mn);
        mx-=2;
        mn+=2;
    }
    return ans;
}
```

### [Justified Text (Star Marked)](https://www.interviewbit.com/problems/justified-text/)

```cpp
vector<string> Solution::fullJustify(vector<string> &a, int b) {
    vector<string> ans;
    int n = a.size(), i = 0;
    while (i<n) {
        int cur = 0, num_words = 0;
        while (i<n && cur<=b) {
            if (num_words==0 && (cur+a[i].size())>b) break;
            else if (num_words!=0 && (cur+a[i].size()+1)>b) break;
            if (num_words==0) cur+=a[i].size();
            else cur+=(a[i].size()+1);
            num_words++;
            i++;
        }
        int last_word_pos = i - 1;
        if (last_word_pos==n-1) {
            string add = "";
            for(int j = last_word_pos - num_words + 1;j<=last_word_pos;j++) {
                add+=a[j];
                if (j!=last_word_pos) add+=" ";
                else {
                    int val = add.size();
                    for(int i = 0;i<(b-val);i++) add+=" ";
                }
            }

            ans.push_back(add);
            break;
        }
        int rem = b - (cur-(num_words-1));
        int space = 0, have_to_add = 0;
        if (num_words>1) {
            space = rem/(num_words - 1);
            have_to_add = rem%(num_words - 1);
        }
        string add = "";
        for(int j = last_word_pos - num_words + 1;j<=last_word_pos;j++) {
            add+=a[j];
            if (j!=last_word_pos) {
                if (have_to_add && rem%(num_words - 1)!=0) {
                    for(int k = 0;k<space + 1;k++) add+=" ";
                    have_to_add--;
                }
                else {
                    for(int k = 0;k<space;k++) add+=" ";
                }
            }
            else {
                // this is if the line has only one word
                int val = add.size();
                for(int i = 0;i<(b-val);i++) add+=" ";
            }
        }
        ans.push_back(add);
    }
    return ans;
}
```

### [Pretty Json (Star Marked)](https://www.interviewbit.com/problems/pretty-json/)

```python
class Solution:
    # @param A : string
    # @return a list of strings
    def prettyJSON(self, json):
        result = []
        multiplier = 0
        i = 0

        while i < len(json):
            if json[i] in ['{', '[']:
                result.append('\t' * multiplier + json[i])
                multiplier += 1
                i += 1
            elif json[i] in ['}', ']']:
                multiplier -= 1
                result.append('\t' * multiplier + json[i])
                i += 1
            elif json[i] == ',':
                result[-1]+= ','
                i += 1
            else:
                start = i
                while i < len(json) and json[i] not in ['{', '}', ',', '[', ']']:
                    i += 1
                curr_s = json[start:i]
                result.append('\t' * multiplier + curr_s)

        return result
```
