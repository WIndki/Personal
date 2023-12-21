#include <iostream>
using namespace std;

class magicMatrix
{
private:
    int row;
    int column;
    int **matrix;

public:
    void *Create2DimArray(int m, int n)
    {
        int **processmatrix = new int *[m + 1]; // 创建动态二维数组
        for (int i = 1; i <= m; i++)
        {
            processmatrix[i] = new int[n + 1];
            for (int j = 1; j <= n; j++)
            {
                processmatrix[i][j] = 0;
            }
        }
        return processmatrix;
    }

    void createMagicMatrix(int n)
    {
        matrix = (int **)Create2DimArray(n, n);
        row = 1;                 // 初始化行
        column = (n + 1) / 2;    // 初始化列
        matrix[row][column] = 1; // 初始化第一个数
        for (int i = 2; i <= n * n; i++)
        {
            row--;    // 行减1
            column++; // 列加1
            if (row < 1 && column > n)
            { // 对角线上的值必然已经存在。所以当行小于1且列大于n时，行加2，列减1
                row = row + 2;
                column = column - 1;
            }
            else
            {
                if (row < 1)
                {
                    row = n;
                }
                if (column > n)
                {
                    column = 1;
                }
            }
            if (matrix[row][column] != 0)
            {
                row = row + 2;
                column = column - 1;
            }
            matrix[row][column] = i;
        }
        row = n;
        column = n;
    }

    void printMagicMatrix()//输出
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void deleteMAtrix()//释放内存
    {
        for (int i = 1; i <= column; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main()
{
    system("chcp 65001");
    cout << "请输入奇数n：";
    int n;
    cin>>n;
    magicMatrix m;
    m.createMagicMatrix(n);
    m.printMagicMatrix();
    m.deleteMAtrix();
    return 0;
}
