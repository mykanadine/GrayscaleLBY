#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double imgCvtGrayIntToDouble(int pixel);

int main() {

    int row, col; // size of image
    double output;

    //input 

    scanf_s("%d %d", &row, &col);

    // declare dynamic 2d array
    int* image_int = (int*)malloc(row * col * sizeof(int));
	double* image_double = (double*)malloc(row * col * sizeof(double));

    // just in case
    if (image_int == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // fill with random pixels
    srand((unsigned)time(NULL));
    for (int i = 0; i < row * col; i++) {
        image_int[i] = rand() % 256; // grayscale 0–255
    }

    // print input
    printf("===========================================\n");
    printf("=============== Input =====================\n");
    printf("===========================================\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d ", image_int[i * col + j]);
        }
        printf("\n");
    }
      
    // conversion
    clock_t start = clock();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            image_double[i * col + j] = imgCvtGrayIntToDouble(image_int[i * col + j]);
        }
    }

    clock_t end = clock();

    // time
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    // print output
    printf("============================================\n");
    printf("=============== Output =====================\n");
    printf("============================================\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f ", image_double[i * col + j]);
        }
        printf("\n");
    }

    // checker
    printf("============================================\n");
    printf("============== C output checker ============\n");
    printf("============================================\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            output = (double)image_int[i * col + j] / 255.0;
            printf("%.2f ", output);
        }
        printf("\n");
    }

    printf("Time for %dx%d image size : %f seconds\n", row, col, time);
    free(image_int);

    return 0;
}
