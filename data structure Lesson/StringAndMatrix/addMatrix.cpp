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
    void add(Matrix b)
    {
        Matrix c(rows, cols);
        int i = 0, j = 0, k = 0;
        while (i < nums && j < b.nums)
        {
            if (data[i].row < b.data[j].row || (data[i].row == b.data[j].row && data[i].col < b.data[j].col))
            {
                c.data[k].row = data[i].row;
                c.data[k].col = data[i].col;
                c.data[k].value = data[i].value;
                i++;
                k++;
            }
            else if (data[i].row > b.data[j].row || (data[i].row == b.data[j].row && data[i].col > b.data[j].col))
            {
                c.data[k].row = b.data[j].row;
                c.data[k].col = b.data[j].col;
                c.data[k].value = b.data[j].value;
                j++;
                k++;
            }
            else
            {
                c.data[k].row = data[i].row;
                c.data[k].col = data[i].col;
                c.data[k].value = data[i].value + b.data[j].value;
                i++;
                j++;
                k++;
            }
        }
        while (i < nums)
        {
            c.data[k].row = data[i].row;
            c.data[k].col = data[i].col;
            c.data[k].value = data[i].value;
            i++;
            k++;
        }
        while (j < b.nums)
        {
            c.data[k].row = b.data[j].row;
            c.data[k].col = b.data[j].col;
            c.data[k].value = b.data[j].value;
            j++;
            k++;
        }
        c.nums = k;
        for(int i=0;i<c.nums;i++)data[i] = c.data[i];
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
    int rows,cols;
    while(cin>>rows>>cols){
        int a_nums, b_nums;
        cin >> a_nums>>b_nums;
        int a_data[a_nums],a_rowptr[a_nums],a_colptr[a_nums];
        int b_data[b_nums],b_rowptr[b_nums],b_colptr[b_nums];
        for(int i=0;i<(a_nums+b_nums);i++){
            int row,col,value;
            cin>>row>>col>>value;
            if(i<a_nums){
                a_data[i] = value;
                a_rowptr[i] = row;
                a_colptr[i] = col;
            }
            else{
                b_data[i-a_nums] = value;
                b_rowptr[i-a_nums] = row;
                b_colptr[i-a_nums] = col;
            }
        }
        Matrix a(rows,cols,a_nums,a_data,a_rowptr,a_colptr);
        Matrix b(rows,cols,b_nums,b_data,b_rowptr,b_colptr);
        a.add(b);
        a.print();
    }
    return 0;
}