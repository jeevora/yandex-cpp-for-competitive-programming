#include <iostream>
#include <cmath>

using namespace std;

int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 8, m = 8;
    char a[n][m];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] == 'k'){
                // move up
                int iTemp = i;
                int jTemp = j;
                if(a[iTemp-2][jTemp-1] == '.' && (iTemp-2) >= 0 && (jTemp-1) >= 0 && (iTemp-2) < n && (jTemp-1) < m) a[iTemp-2][jTemp-1] = '!';
                if(a[iTemp-2][jTemp+1] == '.' && (iTemp-2) >= 0 && (jTemp+1) >= 0 && (iTemp-2) < n && (jTemp+1) < m) a[iTemp-2][jTemp+1] = '!';

                // move down
                if(a[iTemp+2][jTemp-1] == '.' && (iTemp+2) >= 0 && (jTemp-1) >= 0 && (iTemp+2) < n && (jTemp-1) < m) a[iTemp+2][jTemp-1] = '!';
                if(a[iTemp+2][jTemp+1] == '.' && (iTemp+2) >= 0 && (jTemp+1) >= 0 && (iTemp+2) < n && (jTemp+1) < m) a[iTemp+2][jTemp+1] = '!';

                // move horizontal left
                if(a[iTemp-1][jTemp-2] == '.' && (iTemp-1) >= 0 && (jTemp-2) >= 0 && (iTemp-1) < n && (jTemp-2) < m) a[iTemp-1][jTemp-2] = '!';
                if(a[iTemp+1][jTemp-2] == '.' && (iTemp+1) >= 0 && (jTemp-2) >= 0 && (iTemp+1) < n && (jTemp-2) < m) a[iTemp+1][jTemp-2] = '!';

                // move horizontal right
                if(a[iTemp-1][jTemp+2] == '.' && (iTemp-1) >= 0 && (jTemp+2) >= 0 && (iTemp-1) < n && (jTemp+2) < m) a[iTemp-1][jTemp+2] = '!';
                if(a[iTemp+1][jTemp+2] == '.' && (iTemp+1) >= 0 && (jTemp+2) >= 0 && (iTemp+1) < n && (jTemp+2) < m) a[iTemp+1][jTemp+2] = '!';
            }
        }  
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout<<endl;
    }
}