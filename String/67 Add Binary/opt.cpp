class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int cout = 0, i = a.length() - 1, j = b.length() - 1;
        for(; i >= 0 || j >= 0 || cout == 1; i--, j--){
            int sum = cout;
            sum += i >= 0 ? a[i] - '0' : 0;
            sum += j >= 0 ? b[j] - '0' : 0;
            if(sum > 1)
                cout = 1;
            else
                cout = 0;
            s += to_string(sum % 2);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
