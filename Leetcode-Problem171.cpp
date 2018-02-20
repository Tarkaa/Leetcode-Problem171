//这个题让我想起了之前的一些翻译题，比如之前的罗马和字母转ASCII码
//总的来说包含了权重思想的编码方式都可以这么算
class Solution {
public:
    int titleToNumber(string s) {
        int res=0,n=s.size(),param;
        for(int i=0;i<n;i++)
        {
            param=s[i]-'A'+1;
            res=param+res*26;
        }
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().titleToNumber(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}