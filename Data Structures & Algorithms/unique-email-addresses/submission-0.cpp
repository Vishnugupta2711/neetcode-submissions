class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (string email : emails) {
            int at = email.find('@');

            string local = email.substr(0, at);
            string domain = email.substr(at + 1);

            string clean;

            for (char c : local) {
                if (c == '+')
                    break;

                if (c != '.')
                    clean += c;
            }

            unique.insert(clean + "@" + domain);
        }

        return unique.size();
    }
};