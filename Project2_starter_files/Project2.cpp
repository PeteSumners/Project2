/* Project2.cpp
 * Peter Sumners
 * EE312, Summer 2017
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // For malloc, others.
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order

    for (int32_t i = 0; i < a_rows; i++) { // Loop through a_rows
        for (int32_t j = 0; j < b_cols; j++) { // Loop through b_cols.

            c[i * a_rows + j] = 0; // Init. result vals. to 0.
            for (int32_t k = 0; k < a_cols; k++) { // Loop through elems (a_cols), and sum.
                c[i* a_rows + j] += a[i * a_rows + k] * b[k * a_cols + j];
            }
        }
    }

}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    // a cols == b rows: no need for b rows.

    // Create matrix whose pointer will be returned.
    // Result has a_rows rows and b_cols cols.
    double** result = (double**) malloc(a_rows * sizeof (double*));

    for (int32_t i = 0; i < a_rows; i++) { // Loop through a rows
        // Make new result matrix row.
        result[i] = (double*) malloc(b_cols * sizeof(double));

        for (int32_t j = 0; j < b_cols; j++) { // Loop through b cols.

            result[i][j] = 0; // Init. matrix vals. to 0.
            for (int32_t k = 0; k < a_cols; k++) { // Loop through elems (a_cols), and sum.
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Sum is elem in row of new matrix.


    return result;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    return NULL;
}
