#include <bits/stdc++.h>

using namespace std;

struct Matrix
{
    int row, col;
    int **data;

    Matrix() : row(0), col(0), data(nullptr) {}

    void create(int r = 0, int c = 0, bool flag = false) {
        row = r;
        col = c;

        data = new int*[row];
        for (int i = 0; i < row; i++)
            data[i] = new int[col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (!flag)
                    data[i][j] = 0;
                else
                    data[i][j] = rand() % 21 - 10; // random in range of [-10,10]
    }

    void print(const string & message = "") {
        cout << endl << message << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
        cout << "------\n";
    }

    static Matrix mul(const Matrix & a, const Matrix & b) {
        if (a.row != b.col || a.col != b.row) {
            throw invalid_argument("Matrix dimensions not compatible for multiplication");
        }

        struct Matrix res;
        res.create(a.row, b.col);


        for (int i = 0; i < a.row; i++)
            for (int j = 0; j < b.col; j++)
                for (int k = 0; k < a.col; k++)
                    res.data[i][j] += a.data[i][k] * b.data[k][j];

        return res;
    }

    void destroy(const string & message = "") {
        if (data != nullptr) {
            for (int i = 0; i < row; i++) {
                free(data[i]);
            }
            free(data);
            data = nullptr;
            cout << message << endl;
        }
    }

    ~Matrix() {
        destroy("Release completed!");
    }
};


int main(int, char**) {
    // all of 0
    Matrix m;
    m.create(3, 4);
    m.print("Matrix 0");

    // random value
    Matrix m2;
    m2.create(2, 3, true);
    m2.print("Matrix random 1:");

    // multiplication
    Matrix m3;
    m3.create(3, 2, true);
    m3.print("Matrix random 2:");

    Matrix m4 = Matrix::mul(m2,m3);
    m4.print("Multiplication matrix:");

    m.destroy();
    m2.destroy();

    return 0;
}
