#include<bits/stdc++.h>
using namespace std;

int main()
{    
    vector <string> a;

    a = {"000001000000011", "000000000000000", "000000010001000", "010000000000000", "000000010000000", "100010000000000", "100001100000000", "011000000001000", "000000000110000", "000000000000000", "001000000000000", "000000000000000", "000000000000000", "000000001000011", "010000000100101", "000000000000000", "010000010000000", "000001101100000", "000010000011000", "000001000000010", "000000011010000", "000000000000000", "000000000001000", "000000000000000", "000000001000000", "101001000000010", "000000000000001", "000000011000000", "001000000000010", "000000000000100", "000000000000000", "001000100000000", "001000000000100", "000000000000000", "000000001000010", "001100000000000", "000000010010000", "000000001000000", "000000000000010", "001001000000100", "000001010100000", "000100001000000", "000000000000000", "000000101000000", "000100010000000", "000100100000000", "010001000000000", "000000000000001", "000000000000100", "000000000100000", "000000010000001", "000000000000000", "000000000000010", "000000000000000", "110000000010100", "010000000000000", "000000000000000", "000000000000000", "010000000000000", "010000100000010", "000000100010000", "000000100000000", "000000000000000", "001100000100000", "000000000000000", "000000000100010", "000000001001000", "011000000010000", "000000000000000", "000001000010000", "000000000000001", "000000000000000", "000000000001000", "000001100000001", "010000000000000", "000000000000000", "000000000000000", "010000001000000", "000100000000001", "100000000000000", "100000000000000", "000000000010000", "000000000000000", "000000000000000", "000000010001000", "000000000000000", "000000000100001", "100000000000001", "000000000000000", "000001000001000", "101000100000000", "000100000100100", "000100000000100", "000000000010000", "000000000000000", "001000010000000", "000100000000000", "000000000000101", "000000000001010", "101000000000010", "000000000000000", "001000001000010", "000000000000000", "000000000000000", "000101000000000", "000000100000000", "000000000000000", "000000000000000", "010100000000000", "000000000100000", "000000100000000", "000000000000000", "000000000000000", "010000000100000", "000000000000000", "000000000000100", "000000000000000", "000000000000000", "000000000000001", "000000110000000", "000000000000001", "001001000001000", "000000101000000", "010001000000000", "000000000000000", "000000000000000", "001000000000010", "000000000000000", "000000100000000", "000000000000000", "000000000000000", "000000000000000", "000000000000000", "000000101000000", "000000000010000", "000010010000110", "100000000000100", "000000000000100", "000000100000000" };
    int ans;

    int rows = a.size();
    int cols = a[0].size();
    
    if(a[0][1] == '1' && a[1][0] == '1')
    {
        ans = 0;
    }
        
    vector < vector <int> > mat1(rows, vector <int> (cols, 0));
    vector < vector <int> > mat2(rows, vector <int> (cols, 0));
    
    mat1[0][0] = 1;
    mat2[0][0] = 1;
    int i, j;
    
     for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;

    for(i = 1; i < 2; i++)
    {
        if(a[i][0] == '0')
            mat1[i][0] = mat1[i - 1][0];
    }

     for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    } 

    cout << endl;
    for(i = 1; i < 2; i++)
    {
        if(a[0][i] == '0')
            mat2[0][i] = mat2[0][i - 1];
    }
    
     for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    } 

    cout << endl;

   if(a[0][1] == '0')
    {
        for(i = 1; i < rows; i++)
        {
            for(j = 1; j < cols; j++)
            {
                if(a[i][j] == '0')
                {
                    if(mat2[i - 1][j] > 0 || mat2[i][j - 1] > 0)
                        mat2[i][j] = 1;
                }
                    
            }
        }
    }
    
    if(a[1][0] == '0')
    {
        for(i = 1; i < rows; i++)
        {
            for(j = 1; j < cols; j++)
            {
                if(a[i][j] == '0')
                {
                    if(mat1[i - 1][j] > 0 || mat1[i][j - 1] > 0)
                        mat1[i][j] = 1;
                }
            }
        }
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    } 

    cout << endl;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }    

    cout << endl;
    cout << mat2[rows - 1][cols - 1] << " " << mat1[rows - 1][cols - 1] << endl;
    if(rows == 1)
    {
        if(mat2[0][cols - 1] > 0)
            return 1;
        return 0;
    }
    if(cols == 1)
    {
        if(mat1[rows - 1][0] > 0)
            return 1;
        return 0;
    }
    
    if(mat2[rows - 1][cols - 1] > 0 && mat1[rows - 1][cols - 1] > 0)
    {
        cout << 2 << endl;
        return 0;
    }
    if(mat2[rows - 1][cols - 1] == 0 && mat1[rows - 1][cols - 1] > 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if(mat2[rows - 1][cols - 1] > 0 && mat1[rows - 1][cols - 1] == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if(mat2[rows - 1][cols - 1] == 0 && mat1[rows - 1][cols - 1] == 0)
        cout << 2;

return 0;
}