class Solution {
public:
    vector<string> res;
    int m;
    int n;
    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode(){
            trieNode *newNode=new trieNode();
            newNode->endOfWord=false;
            newNode->word="";
            for(int i=0;i<26;i++){
                newNode->children[i]=NULL;
            }
            return newNode;
    }
    void insert(trieNode* root,string &word){
    trieNode* crawler=root;
    for(int i=0;i<word.length();i++){
        char ch=word[i];
        if(crawler->children[ch-'a']==NULL){
            crawler->children[ch-'a']=getNode();
        }
        crawler=crawler->children[ch-'a'];
    }
    crawler->endOfWord=true;
    crawler->word=word;
    }
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    void findtriewords(vector<vector<char>> &board,int i,int j,trieNode *root){
        if(i>=m||i<0||j>=n||j<0) return ;
        if(board[i][j]=='$'||root->children[board[i][j]-'a']==NULL) return ;
        root=root->children[board[i][j]-'a'];
        if(root->endOfWord==true){
            res.push_back(root->word);
            root->endOfWord=false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            findtriewords(board,ni,nj,root);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        res.clear();
        trieNode* root=getNode();
        for(string &word:words){
            insert(root,word);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findtriewords(board,i,j,root);
                }
            }
        }
        return res;
    }
};