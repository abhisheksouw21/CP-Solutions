class Solution {
    void dfs(int r, int c, vector<vector<int>>&ans,vector<vector<int>>& image,int newColor,int dr[],int dc[],int iniColor){
        ans[r][c]=newColor;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;++i){
            int a= r+dr[i];
            int b= c+ dc[i];
            if(a>=0 && a<n && b>=0 && b<m && image[a][b]==iniColor && ans[a][b]!=newColor){
               dfs(a,b,ans,image,newColor,dr,dc,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>>ans=image;
        int dr[] = {-1, 1, 0, 0};
         int dc[] = {0, 0, -1, 1};
        dfs(sr,sc,ans,image,color,dr,dc,iniColor);
        return ans;
    }
};