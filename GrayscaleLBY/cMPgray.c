#include <stdio.h>
#include <stdlib.h>

extern double imgCvtGrayIntToDouble(int pixel);

int main() {

    int row, col; // size of image
    double output;

    //input 

    scanf_s("%d %d", &row, &col);

    // declare dynamic 2d array
    int* image_int = (int*)malloc(row * col * sizeof(int));

    // just in case
    if (image_int == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // input image in int
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf_s("%d", &image_int[i * col + j]);
        }
    }
    printf("Output:\n");

    // output image
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            output = imgCvtGrayIntToDouble(image_int[i * col + j]);
            printf("%.2f ", output);
        }
        printf("\n");
    }

    free(image_int);

    return 0;
}