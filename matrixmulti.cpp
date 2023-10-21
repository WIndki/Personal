#include <iostream>
using namespace std;

const int MAXN = 20;

class Matrix {
public:
    int row, col;
    int data[MAXN][MAXN];

    Matrix(int r = 0, int c = 0): row(r), col(c) { //初始化矩阵
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }
    }
    void input() { //输入矩阵元素
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> data[i][j];
            }
        }
    }
    void output() { //输出矩阵元素
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout.width(6);
                cout << data[i][j];
            }
            cout << endl;
        }
    }
    // Matrix operator*(const Matrix& B) const { //重载运算符函数
    //     Matrix C(row, B.col);
    //     for (int i = 0; i < row; i++) {  //矩阵乘法 复杂度O(n^3)
    //         for (int j = 0; j < B.col; j++) {
    //             for (int k = 0; k < col; k++) {
    //                 C.data[i][j] += data[i][k] * B.data[k][j];
    //             }
    //         }
    //     }
    //     return C;
    // }
};

Matrix multiMatrix(const Matrix A, const Matrix B) {
    Matrix C(A.row, B.col);
    for (int i=0;i<A.row;i++){
        for (int j=0;j<B.col;j++){
            for (int k=0;k<A.col;k++){
                C.data[i][j]+=A.data[i][k]*B.data[k][j];
            }
        }
    }
    return C;
}

int main() {
    int r1, c1, r2, c2;
    while (cin >> r1 >> c1) {
        Matrix A(r1, c1);
        A.input();
        cin >> r2 >> c2;
        Matrix B(r2, c2);
        B.input();
        Matrix C = multiMatrix(A, B);
        C.output();
    }
    return 0;
}
