#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.


int arr[5001][5001];
int commonChild(string s1, string s2) {

    int n = s1.length();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==0 || j==0)
            {
                if (s1[i]==s2[j])
                {
                    arr[i][j]=1;
                }
                else
                {
                    arr[i][j]=0;
                }
            }
            else
            {
                if (s1[i]==s2[j])
                {
                    arr[i][j]=1 + arr[i-1][j-1];
                }
                else
                {
                    arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
                }
            }
        }
    }
    return arr[n-1][n-1];
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    cout<<commonChild(s1,s2)<<endl;
}
