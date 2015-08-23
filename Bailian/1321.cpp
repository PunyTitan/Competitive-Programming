#include <iostream>
#include <vector>

using namespace std;

std::vector< vector<char> > chessboard;
std::vector<bool> colHasChess(8);           //The state of the columns
int n, k, c;                                //c is the output

//Search rows one by one starting from the $row-th row, with $chessLeft chess to place
void dfs(int row, int chessLeft)
{
    for(int col=0; col<n; ++col)
    {
        if(chessboard[row][col] == '#' && !colHasChess[col])
        {
            //If it comes to the end of a search path, add 1 to c. (one possible placement of k chesses)
            if(chessLeft == 1)
                ++c;
            else
            {
                colHasChess[col] = true;
                
                //Search rows one by one starting from the $beginRow 
                for(int beginRow = row+1; beginRow <= n-(chessLeft-1); ++beginRow)
                    dfs(beginRow, chessLeft-1);
                colHasChess[col] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    while((cin>>n>>k) && !(n ==-1 && k==-1))
    {
        c = 0;

        chessboard.resize(n);
        for(int i=0; i<n; ++i)
            chessboard[i].resize(n);

        fill(colHasChess.begin(), colHasChess.end(), false);

        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin>>chessboard[i][j];

        for(int i=0; i<=n-k; ++i)
            dfs(i, k);

        cout<<c<<endl;
    }    
    return 0;
}