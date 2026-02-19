class Solution {
public:
void dfs(vector<vector<int>>&image,int i,int j,int currColour,int newColour){
    int n=image.size();
    int m=image[0].size();

    if(i<0|| j<0 ||i>=n || j>=m || image[i][j]!=currColour){
        return;
    }
    image[i][j]=newColour;
    dfs(image,i-1,j,currColour,newColour);
    dfs(image,i+1,j,currColour,newColour);
    dfs(image,i,j-1,currColour,newColour);
    dfs(image,i,j+1,currColour,newColour);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int currColour=image[sr][sc];
        
        if(currColour==color){
            return image;
        }
        dfs(image,sr,sc,currColour,color);

        return image;
    }
};