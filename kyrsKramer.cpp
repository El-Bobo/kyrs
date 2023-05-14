#include <iostream>

using namespace std;

double det2x2(double matrix[][2])
{
    double det;
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    if (det == 0) {
        cout << "Система має нескінчену кількість рішень або не має їх взагалі." << endl;
        return 0;
    }
    return det;
}

double det3x3(double matrix[][3])
{
    double det;
    det = matrix[0][0] * matrix[1][1] * matrix[2][2] +
        matrix[0][1] * matrix[1][2] * matrix[2][0] +
        matrix[0][2] * matrix[1][0] * matrix[2][1] -
        matrix[0][2] * matrix[1][1] * matrix[2][0] -
        matrix[0][0] * matrix[1][2] * matrix[2][1] -
        matrix[0][1] * matrix[1][0] * matrix[2][2];
    if (det == 0) {
        cout << "Система має нескінчену кількість рішень або не має їх взагалі." << endl;
        return 0;
    }
    return det;
}

double det4x4(double matrix[][4], int n)
{
    double det = 0;
    double submatrix[4][4];
    int sign = 1;
    if (n == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        if (det == 0) {
            cout << "Система має нескінчену кількість рішень або не має їх взагалі." << endl;
            return 0;
        }
    }
    else {
        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = 0;
            for (int row = 1; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (col != k) {
                        submatrix[i][j++] = matrix[row][col];
                        if (j == n - 1) {
                            i++;
                            j = 0;
                        }
                    }
                }
            }
            det += sign * matrix[0][k] * det4x4(submatrix, n - 1);
            sign = -sign;
        }
    }
    return det;
}

int matrix2x2()
{
    double a[2][2];
    double b[2];
    cout << "Запишіть коефіцієнтів при невідомих 2х2:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Запишіть відому частину 2х1:" << endl;
    for (int i = 0; i < 2; i++) {
        cin >> b[i];
    }
    double det_A = det2x2(a);

    double A1[2][2] = { {b[0], a[0][1]},
                       {b[1], a[1][1]} };
    double det_A1 = det2x2(A1);

    double A2[2][2] = { {a[0][0], b[0]},
                        {a[1][0], b[1]} };
    double det_A2 = det2x2(A2);

    cout << "x1 = " << det_A1 / det_A << " x2 = " << det_A2 / det_A << endl;

    return 0;
}

int matrix3x3()
{
    double a[3][3];
    double b[3];

    cout << "Запишіть коефіцієнтів при невідомих 3х3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Запишіть відому частину 3х1:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    double detA = det3x3(a);

    double A1[3][3] = { {b[0], a[0][1], a[0][2]},
                         {b[1], a[1][1], a[1][2]},
                         {b[2], a[2][1], a[2][2]} };
    double det_A1 = det3x3(A1);

    double A2[3][3] = { {a[0][0], b[0], a[0][2]},
                         {a[1][0], b[1], a[1][2]},
                         {a[2][0], b[2], a[2][2]} };
    double det_A2 = det3x3(A2);

    double A3[3][3] = { {a[0][0], a[0][1], b[0]},
                         {a[1][0], a[1][1], b[1]},
                         {a[2][0], a[2][1], b[2]} };
    double det_A3 = det3x3(A3);

    cout << "x1 = " << det_A1 / detA << " x2 = " << det_A2 / detA << " x3 = " << det_A3 / detA << endl;

    return 0;
}

int matrix4x4()
{
    double A[4][4];
    double B[4];

    cout << "Запишіть коефіцієнтів при невідомих 4х4:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Запишіть відому частину 4х1:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> B[i];
    }

    double det_A = det4x4(A, 4);

    double A1[4][4] = { {B[0], A[0][1], A[0][2], A[0][3]},
                        {B[1], A[1][1], A[1][2], A[1][3]},
                        {B[2], A[2][1], A[2][2], A[2][3]},
                        {B[3], A[3][1], A[3][2], A[3][3]} };
    double det_A1 = det4x4(A1, 4);

    double A2[4][4] = { {A[0][0], B[0], A[0][2], A[0][3]},
                        {A[1][0], B[1], A[1][2], A[1][3]},
                        {A[2][0], B[2], A[2][2], A[2][3]},
                        {A[3][0], B[3], A[3][2], A[3][3]} };
    double det_A2 = det4x4(A2, 4);

    double A3[4][4] = { {A[0][0], A[0][1], B[0], A[0][3]},
                        {A[1][0], A[1][1], B[1], A[1][3]},
                        {A[2][0], A[2][1], B[2], A[2][3]},
                        {A[3][0], A[3][1], B[3], A[3][3]} };
    double det_A3 = det4x4(A3, 4);

    double A4[4][4] = { {A[0][0], A[0][1], A[0][2], B[0]},
                        {A[1][0], A[1][1], A[1][2], B[1]},
                        {A[2][0], A[2][1], A[2][2], B[2]},
                        {A[3][0], A[3][1], A[3][2], B[3]} };
    double det_A4 = det4x4(A4, 4);

    cout << "x1 = " << det_A1 / det_A << " x2 = " << det_A2 / det_A << " x3 = " << det_A3 / det_A << " x4 = " << det_A4 / det_A << endl;

    return 0;
}

void menu()
{
    cout << "1.Рішення системи лінійного рівняння другого порядку" << endl;
    cout << "2.Рішення системи лінійного рівняння третього порядку" << endl;
    cout << "3.Рішення системи лінійного рівняння четвертого порядку" << endl;
    cout << "4.Як записувати систему лінійного рівняння" << endl;
}

int main()
{
    while (1)
    {
        int choice;
        cout << "Виберіть режим програми" << endl;
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1: {matrix2x2();
            choice = 0;
            break;
        }
        case 2: {matrix3x3();
            choice = 0;
            break;
        }
        case 3: {matrix4x4();
            choice = 0;
            break;
        }
        case 4: {cout << "Спочатку запишіть коефіцієнтів при невідомих в вигляді матриці, потім все останнє також в вигляді матриці " << endl;
            choice = 0;
            break;
        }
        }
    }
    return 0;
}
