# LBYARCH x86-to-C: Grayscale Image Conversion From Int to Float
Created By:
- Chua, Myka Nadine
- Lim, Julienne Skye

This project converts a pixel values in a grayscale image from 8-bit unsigned integer to double float.

[Video Demo](https://drive.google.com/file/d/1IQG-6NCI7la9Z0P02fqc5C3-24TFTG93/view?usp=sharing)

## Execution Time and Short Analysis of Performance

The table below shows execution times for the .asm function with different sizes:
| Input Size  | Average Execution Time (30 runs) |
|-------------|------------------|
| 10×10       | 0.000000 seconds |
| 100×100     | 0.000033 seconds |
| 1000×1000   | 0.002500 seconds |

*Note: These times only take into account how long it takes for the entire image to be processed. Display time is not included. This was tested using a separate script that is shown below.*

### Short analysis

The **imgCvtGrayIntToDouble** function takes a very short time to run for all tested image sizes. For the 10×10 image, the measured execution time was 0.000000 seconds, indicating that the conversion completed faster than the timer could accurately measure. As the image size increased to 100×100 and 1000×1000, the execution time also increased because more pixels had to be processed. However, even for the 1000×1000 image, the function completed the conversion in less than 3 milliseconds, showing how efficient the assembly implementation is.


## Execution Time Outputs

### 10 x 10
<img width="465" height="791" alt="image" src="https://github.com/user-attachments/assets/eb3eed41-9bbc-464c-bca2-b8bb6d8f9dc0" />

### 100 x 100
<img width="1613" height="845" alt="image" src="https://github.com/user-attachments/assets/d8584e6c-fadc-4d85-b94f-6fef84a508f6" />
<img width="2010" height="838" alt="image" src="https://github.com/user-attachments/assets/4ad16223-bead-4d34-8a83-978fdab2bd4d" />
<img width="2007" height="838" alt="image" src="https://github.com/user-attachments/assets/e50e36e3-6d79-4762-a6d2-9852beac713b" />

### 1000 x 1000
*Full output is too large to be shown*
<img width="1089" height="490" alt="image" src="https://github.com/user-attachments/assets/5e8ad935-39c5-437c-bd03-213ecca7c9e0" />

## Correctness Check
<img width="475" height="801" alt="image" src="https://github.com/user-attachments/assets/9199b985-9f97-4f78-8fb6-f6a7cc943205" /><br>
<img width="424" height="560" alt="image" src="https://github.com/user-attachments/assets/2e3673b7-f9f1-4ff6-b125-215be8666273" /><br>
<img width="425" height="370" alt="image" src="https://github.com/user-attachments/assets/fccd2120-e131-4b3a-bec0-8c5f120e847a" />

## Code used to record average times:
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double imgCvtGrayIntToDouble(int pixel);

int main() {

    int row, col;
    double output;

    scanf_s("%d %d", &row, &col);

    int* image_int = (int*)malloc(row * col * sizeof(int));
    double* image_double = (double*)malloc(row * col * sizeof(double));

    srand((unsigned)time(NULL));
    for (int i = 0; i < row * col; i++) {
        image_int[i] = rand() % 256;
    }

    double average_time;
    double total = 0;

    for (int i = 0; i < 30; i++) {
        clock_t start = clock();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                image_double[i * col + j] = imgCvtGrayIntToDouble(image_int[i * col + j]);
            }
        }
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;
        total += time;
    }

    average_time = total / 30;

    printf("Average time: %f seconds\n", average_time);
    free(image_int);

    return 0;
}
```





