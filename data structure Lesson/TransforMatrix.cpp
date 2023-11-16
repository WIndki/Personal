#include <iostream>
using namespace std;

const int MAXSIZE = 100;
struct Tupnode
{
    int row, col;
    int value;
    // Tupnode(int x, int y, int data) : row(x), col(y), value(data) {}
};

class Matrix
{
private:
    int rows, cols, nums;
    Tupnode data[5];

public:
    Matrix(int r,int c){
        rows = r;
        cols = c;
        nums = 0;
    }
    Matrix(int r, int c, int n, int d[], int rowptr[], int colptr[])
    {
        rows = r;
        cols = c;
        nums = n;
        for (int i = 0; i < n; i++)
        {
            data[i].row = rowptr[i]-1;
            data[i].col = colptr[i]-1;
            data[i].value = d[i];
        }
    }
    ~Matrix() {}
    void Transpose()
    {
        int k = 0;
        Tupnode b[5];
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < nums; j++)
            {
                if (data[j].col == i)
                {
                    b[k].row = data[j].col;
                    b[k].col = data[j].row;
                    b[k].value = data[j].value;
                    k++;
                }
            }
        }
        for (int i = 0; i < nums; i++)
        {
            data[i].row = b[i].row;
            data[i].col = b[i].col;
            data[i].value = b[i].value;
        }
        int temp = rows;
        rows = cols;
        cols = temp;
    }
    void Add(Matrix &b)
    {
        int k = 0;
        Tupnode c[5];
        for (int i = 0; i < nums; i++)
        {
            for (int j = 0; j < b.nums; j++)
            {
                if (data[i].row == b.data[j].row && data[i].col == b.data[j].col)
                {
                    c[k].row = data[i].row;
                    c[k].col = data[i].col;
                    c[k].value = data[i].value + b.data[j].value;
                    k++;
                }
            }
        }
        for (int i = 0; i < nums; i++)
        {
            data[i].row = c[i].row;
            data[i].col = c[i].col;
            data[i].value = c[i].value;
        }
    }
    void print()
    {
        int k = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (data[k].row == i && data[k].col == j)
                {
                    cout << data[k].value;
                    k++;
                }
                else
                {
                    cout << "0";
                }
                if(j<cols-1)cout<<" ";
            }
            cout << endl;
        }
    }
};
int main(){
    int rows,cols,nums;
    while(cin>>rows>>cols>>nums){
        int d[nums],rowptr[nums],colptr[nums];
        for(int i=0;i<nums;i++){
            cin>>rowptr[i]>>colptr[i]>>d[i];
        }
        Matrix a(rows,cols,nums,d,rowptr,colptr);
        a.Transpose();
        a.print();
    }
    return 0;
}