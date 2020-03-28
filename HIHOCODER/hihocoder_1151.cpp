#include <iostream>
#include <map>
#include <string>

struct trie
{
    std::map<std::string, trie *> sub;
};

int count(trie *root)
{
    int ans = 0;

    for (std::map<std::string, trie *>::iterator iter = root->sub.begin(); iter != root->sub.end(); ++iter)
    {
        ans += count(iter->second);
    }
        
    return ans + 1;
}

int main()
{
    int N;
    std::cin >> N;

    trie *root = new trie();

    while (N--)
    {
        std::string s;
        std::cin >> s;

        int left = 1, right = s.find('/', left);
        trie *cur = root;

        for (int left = 1, right = s.find('/', left); right != std::string::npos; left = right + 1, right = s.find('/',left))
        {
            std::string sub_s = s.substr(left, right - left);

            if (cur->sub.find(sub_s) == cur->sub.end())
            {
                cur->sub[sub_s] = new trie();
            }
                
            cur = cur->sub[sub_s];
        }
    }

    std::cout << count(root) - 1 << std::endl;
}
