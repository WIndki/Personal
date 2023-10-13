#include <iostream>
using namespace std;

class magicMatrix
{
private:
    int row;
    int column;
public:
   void createMagicMatrix(int n){
         int matrix[n][n];//创建二维数组
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 matrix[i][j]=0;
             }
         }
         row = 1;//初始化行
         column = (n+1)/2;//初始化列
         matrix[row][column] = 1;//初始化第一个数
         for(int i = 2; i <= n * n; i++){
                row--;//行减1
                column++;//列加1
                if(row<1&&column>n){//对角线上的值必然已经存在。所以当行小于1且列大于n时，行加2，列减1
                    row=row+2;
                    column=column-1;
                }else{
                    if(row<1){
                        row=n;
                    }
                    if(column>n){
                        column=1;
                    } 
                }
                if(matrix[row][column] != 0){
                    row=row+2;
                    column=column-1;
                }
                matrix[row][column] = i;
         }
         for(int i = 1; i <= n; i++){
              for(int j = 1; j <= n; j++){
                cout << matrix[i][j] << " ";
              }
              cout << endl;
         }
   }
};

int main() {
    magicMatrix m;
    m.createMagicMatrix(7);
    return 0;
}
