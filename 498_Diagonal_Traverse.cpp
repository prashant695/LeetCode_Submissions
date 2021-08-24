class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res,temp;
        int i=0,j,i2,j2,flg=-1;
        while(i<mat.size())
        {
            i2=i;
            j2=0;
            temp.clear();
            flg++;
            for(;i2<mat.size()&&j2<mat[0].size();i2--,j2++)
            {
                temp.push_back(mat[i2][j2]);
            }
            
            if(flg%2==0)  for(int i=0;i<temp.size();i++) res.push_back(temp[i]);
            else for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
            i++;
        }
        
        i--;
        j=1;
        while(j<mat[0].size())
        {
           i2=i; 
           j2=j;
           temp.clear();
           flg++;
           for(;i2<mat.size()&&j2<mat[0].size();i2--,j2++)
           {
               temp.push_back(mat[i2][j2]);
           }
              if(flg%2==0)  for(int i=0;i<temp.size();i++) res.push_back(temp[i]);
              else for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
         j++;
        }     
        
        return res;
    }
};