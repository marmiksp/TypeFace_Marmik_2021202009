#include<bits/stdc++.h>
using namespace std;


int minx,miny,maxx,maxy;


void solve(vector<vector<int>> &mat, int i, int j)
{
    int m = mat.size();
    int n = mat[0].size();

    if(i<0 || j<0 || i>=m || j>=n || mat[i][j]==0) return;

    mat[i][j] = 0;
    minx = min(minx,j);
    maxx = max(maxx,j);
    
    miny = min(miny,i);
    maxy = max(maxy,i);

    solve(mat, i+1,j);
    solve(mat, i,j+1);
    solve(mat, i-1,j);
    solve(mat, i,j-1);
    return;
}

/*

Example to verify:
8
8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 1 1 1 0 0 0
0 0 1 1 1 0 0 0
0 0 1 1 1 0 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 1 1 0
0 0 0 0 0 1 1 0

*/

int main()
{
    int m,n;
    cin>>m>>n;

    vector<vector<int>> mat(m,vector<int>(n));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            mat[i][j]=a;
        }
    }
    vector<vector<double>> ans;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0) {continue;}
            minx = j;
            maxx = j;
            miny = i;
            maxy = i;
            solve(mat,i,j);

            double centerx = (double)minx + ((double)maxx-(double)minx)/2;
            double centery = (double)miny + ((double)maxy-(double)miny)/2;
            double width = (double)maxx - (double)minx;
            double height = (double)maxy - (double)miny;
            ans.push_back({centerx, centery, width, height});
            cout<<centerx<<" "<< centery<<" "<< width+1<<" "<< height+1<<" "<<"\n";
        }
    }



    return 0;
}