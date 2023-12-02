#include <iostream>
using namespace std;

class matrix{
    private:
            int row;
            int col;
            int **mat;
    public:
            matrix(int r=0,int c=0){
                row=r;
                col=c;
                mat=new int*[row];
                for(int i=0;i<row;i++){
                    mat[i]=new int[col];
                }
            }
            ~matrix(){
                for(int i=0;i<row;i++){
                    delete [] mat[i];
                }
                delete [] mat;
            }
            void input(){
                for(int i=0;i<row;i++){
                    for(int j=0;j<col;j++){
                        cin>>mat[i][j];
                    }
                }
            }
            void display(){
                for(int i=0;i<row;i++){
                    for(int j=0;j<col;j++){
                        cout<<mat[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            matrix operator*(const matrix &m){
                matrix temp(row,m.col);
                for(int i=0;i<row;i++){
                    for(int j=0;j<m.col;j++){
                        temp.mat[i][j]=0;
                        for(int k=0;k<col;k++){
                            temp.mat[i][j]+=mat[i][k]*m.mat[k][j];
                        }
                    }
                }
                return temp;
            }
                   
};
