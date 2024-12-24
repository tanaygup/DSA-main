/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsChar(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
class Trie
{

    Node *root;

public:
    /** Initialize your data structure here. */

    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int n = word.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->containsChar(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            if (!node->containsChar(word[i]))
                return false;
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsChar(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};