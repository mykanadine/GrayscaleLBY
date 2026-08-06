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
    // timing start
    clock_t start = clock();
    printf("============================================\n");
    printf("=============== Output =====================\n");
    printf("============================================\n");
    // input image in int
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            output = imgCvtGrayIntToDouble(image_int[i * col + j]);
            printf("%.2f ", output);
        }
         printf("\n");
    }
    // timing end
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    

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
   
    printf("Elapsed time for %dx%d image size : %.4f seconds\n", row, col, elapsed);
    free(image_int);

    return 0;
}