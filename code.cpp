#include <bits/stdc++.h>
#define MAX 100
using namespace std;
 int cost[100];
int row,col;
int a=0;
string str[100];
bool isSafe(int row, int col, int m[][MAX],int r1, int c1, bool visited[][MAX])
{
    if (row == -1 || row == r1 || col == -1 ||col == c1 || visited[row][col]|| m[row][col] > 0)
        return false;
    return true;
}
 

void printPathUtil(int row, int col, int m[][MAX],int r1,int c1, string& path, vector<string>&possiblePaths, bool visited[][MAX])
{
    if (row == -1 || row == r1 || col == -1|| col == c1 || visited[row][col]|| m[row][col] > 0)
        return;
    if (row == 0 && col == c1 - 1) {
        possiblePaths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Try for all the 4 directions (down, left, right, up) 
 
    // Check if downward move is valid
 
 
    // Check if the right move is valid
    if (isSafe(row, col + 1, m, r1 , c1, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, r1 , c1 ,path, possiblePaths, visited);
        path.pop_back();

    }
 
     // Check if the upper move is valid
    if (isSafe(row - 1, col, m, r1, c1, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, r1 , c1 ,path, possiblePaths, visited);
        path.pop_back();

    }
 
       if (isSafe(row + 1, col, m, r1 , c1, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, r1, c1,path, possiblePaths, visited);
        path.pop_back();

    }
 
    // Check if the left move is valid
    if (isSafe(row, col - 1, m, r1 , c1, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, r1 , c1 ,path, possiblePaths, visited);
        path.pop_back();

    }
    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
    }
 
// Function to store and print
// all the valid paths

 
// Driver code
int main()
{
    int i,j;
    cout<<"Enter Number of Row and Coloums: "<<endl;
    cin>>row>>col;
    int m[MAX][MAX];
    cout<<"Enter the maze of the above  dimension: "<<endl;
for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>m[i][j];
        }
    }
    int c[row][col];
    cout<<"Enter cost of locations\n"<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>c[i][j];
        }
    }

   vector<string> possiblePaths;
    string path;
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
      
    // Call the utility function to
    // find the valid paths
    printPathUtil(row-1, 0, m, row,col, path,possiblePaths, visited);
    int p=1;
    

    // Print all possible paths
    for (int i = 0; i < possiblePaths.size(); i++)
        {
            p=0;
            str[a]="";
            cost[a]=0;
            int x=row-1,y=0;
            str[a]=possiblePaths[i];
            string s = str[a];
            for(j=0;j<possiblePaths[i].size();j++)
            {
                cost[a]+=c[x][y];
                if(str[a][j]=='D')
                    x++;
                if(s[j]=='R')
                    y++;
                if(possiblePaths[i].at(j)=='U')
                    x--;
                if(possiblePaths[i][j]=='L')
                    y--;
                
            }
            cost[a]+=c[0][col-1];
            a++;
        }
    int min_cost=cost[0],pos=0;
cout<<endl;
for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<a;i++)
    {
       
        if(cost[i]<min_cost)
        {
        min_cost=cost[i];
        pos=i;
        }
    }
    cout<<endl;
    if(!str[pos].empty())
        cout<<"Cost: "<<min_cost<<endl<<"Path "<<str[pos];
    else
        cout<<"No traversable path";
return 0;
}
