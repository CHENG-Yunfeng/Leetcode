class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> wordId;
        vector<vector<int>> edge;
        int id = 0;

        for (string& word: wordList) {
            addEdge(word, wordId, id, edge);
        }
        if (wordId.find(beginWord) == wordId.end()) {
            addEdge(beginWord, wordId, id, edge);
        }
        if(wordId.find(endWord) == wordId.end()) {
            return 0;
        }


        queue<int> que;
        que.push(wordId[beginWord]);
        vector<int> dis(id, INT_MAX);
        dis[wordId[beginWord]] = 0;
        while (que.size()) {
            int head = que.front();
            que.pop();
            if (head == wordId[endWord]) {
                return dis[wordId[endWord]] / 2 + 1;
            }

            for (int& it: edge[head]) {
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[head] + 1;
                    que.push(it);
                }
            }
        }
        return 0;


    }

    void addEdge(string& word, unordered_map<string, int>& wordId, int& id, vector<vector<int>>& edge) {
        addWord(word, wordId, id, edge);
            int node = wordId[word];
            for (char& c: word) {
                char tmp = c;
                c = '*';
                addWord(word, wordId, id, edge);
                int node1 = wordId[word];
                edge[node].push_back(node1);
                edge[node1].push_back(node);
                c = tmp;
            }
    }

    void addWord(string& word, unordered_map<string, int>& wordId, int& id, vector<vector<int>>& edge) {
        if (wordId.find(word) == wordId.end()) {
            wordId[word] = id++;
            edge.emplace_back();
        }
    }
};