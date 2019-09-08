#include<bits/stdc++.h>
using namespace std;

/*
Apple's coding exercise:
1. find words that can be formed by a sequence of adjacent (top, bottom, left, right, diagonal) 
letters.Words must be 3 or more letters.You may move to any of 8 adjacent letters, however, 
a word should not have multiple instances of the same cell.

2. To check if a string is a valid word you may implement a naive dictionary solution for simplicity.
This is meant to be open ended. The only requirement is that the code is easily reviewable by the Tech 
Screener on your next interview.
*/
class WordSearcher{
private:
    unordered_set<string> _dictionary;
    bool _searchWord(const vector<vector<char>>& board,int x,int y,string word,int start,vector<bool>& vis){
        if(start == word.length()) return true;
        assert(!board.empty()&&!board[0].empty());
        int m = board.size();
        int n = board[0].size();
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                if(i!=0 || j!=0){
                    int xx = x+i;
                    int yy = y+j;
                    if(xx>=0 && xx<m && yy>=0 && yy<n && vis[xx*n+yy]==false && word[start]==board[xx][yy]){
                        vis[xx*n+yy] = true;
                        bool valid = _searchWord(board,xx,yy,word,start+1,vis);
                        vis[xx*n+yy] = false;
                        if(valid) return true;
                    }
                }
            }
        }
        return false;
    }
    bool _isWordInDict(const string& word){
        return _dictionary.count(word)==0?false:true;
    }
public:
    // Init with a given dictionary that doesn't contain duplicates and empty string
    WordSearcher(const vector<string>& dictionary){
        for(auto word:dictionary) _dictionary.insert(word);
    }
    // search if the word is valid and can be formed by the  given board
    bool isValidWord(const vector<vector<char>>& board, const string word){
        if(!_isWordInDict(word)) return false;       // not found in dict
        // check input
        if(board.empty()||board[0].empty()) return false;
        if(word.length()<3) return false;
        int m = board.size();
        int n = board[0].size();
        
        vector<bool> vis(m*n,false);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]==word[0] && vis[i*n+j]==false){
                    vis[i*n+j]=true;
                    bool valid = _searchWord(board,i,j,word,1,vis);
                    if(valid) return true;
                    vis[i*n+j] = false;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<string> dict;
    vector<vector<char>> board;
    // read input
    ifstream fin("input.txt");
    int m,n; fin>>m>>n;
    board.resize(m,vector<char>(n));

    for(int i = 0;i<m;i++){
        string line;
        fin>>line;
        for(int j = 0;j<n;j++) board[i][j] = line[j];
    }
    int dict_size; fin>>dict_size;
    for(int i = 0;i<dict_size;i++) {
        string word; fin>>word;
        dict.push_back(word);
    }
    fin.close();
    
    auto  ws = WordSearcher(dict);
    vector<string> queries({"david","see","apple","siri","interview","hi"});
    for(auto query:queries){
        cout<<query<<":"<<ws.isValidWord(board,query)<<endl;
    }
    return 0;
}