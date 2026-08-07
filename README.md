# LBYARCH x86-to-C: Grayscale Image Conversion From Int to Float
Created By:
- Chua, Myka Nadine
- Lim, Julienne Skye

This project converts a pixel values in a grayscale image from 8-bit unsigned integer to double float.

[Video Demo]()

## Execution Time and Short Analysis of Performance

The table below shows execution times for the .asm function with different sizes:
| Input Size  | Average Execution Time (30 runs) |
|-------------|------------------|
| 10×10       | 0.000000 seconds |
| 100×100     | 0.000033 seconds |
| 1000×1000   | 0.002500 seconds |

*Note: These times only take into account how long it takes for the entire image to be processed. Display time is not included. This was tested using a separate script that is shown below.*

### Short analysis

The **imgCvtGrayIntToDouble** function takes a very short time to run for a 10x10 image. We attempted to print up to 15 decimal places for the average execution time, but even then it was still all 0. This means that it took less than a quadrillionth of a second to convert. Even when the size of the image increases exponentially (100x100 and 1000x1000), the function still only takes less than 3 ms to completely convert the pixels. This increase is still a significant jump from the initial 10x10 image. The time taken to completely convert the larger images increased by more than 2000 times. However, it is interesting that we do not observe the same phenomena occur when increasing from 100x100 to 1000x1000. The jump from 100 to 1000 is significantly smaller compared to the jump from 10 to 100. 

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
<img width="475" height="801" alt="image" src="https://github.com/user-attachments/assets/9199b985-9f97-4f78-8fb6-f6a7cc943205" />
<img width="424" height="560" alt="image" src="https://github.com/user-attachments/assets/2e3673b7-f9f1-4ff6-b125-215be8666273" />
<img width="425" height="370" alt="image" src="https://github.com/user-attachments/assets/fccd2120-e131-4b3a-bec0-8c5f120e847a" />

## Code used to record average times:






