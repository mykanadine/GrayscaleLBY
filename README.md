# LBYARCH x86-to-C: Grayscale Image Conversion From Int to Float
Created By:
- Chua, Myka Nadine
- Lim, Julienne Skye

This project converts a pixel values in a grayscale image from 8-bit unsigned integer to double float.


[Video Demo](https://drive.google.com/file/d/1f5JJ0toaxeiKQVWX_qjt2MJRRjngggfP/view?usp=sharing)

## Execution Time and Short Analysis of Performance

The table below shows execution times for different input sizes:
| Input Size  | Average Execution Time (30 runs) |
|-------------|-----------------|
| 10×10       | 0.0020 seconds  |
| 100×100     | 0.2885 seconds  |
| 1000×1000   | 30.1470 seconds |

### Short analysis
- For small inputs (10×10), the program runs almost instantly.
- For medium inputs (100×100), it slows down to almost a third of a second
- For large inputs (1000×1000), it takes around 30 seconds each run.
- The **imgCvtGrayIntToDouble** function alone takes less than 10 microseconds. The total time taken is inflated because it takes into account how long the output takes to print.
- The execution time grows as the input size increases.

The execution time increases significantly as the input size grows because the number of pixels processed increases. A 10×10 image contains only 100 pixels, while a 100×100 image contains 10,000 pixels (100× more), and a 1000×1000 image contains 1,000,000 pixels (10,000× more than the 10×10 image). Since each pixel needs to be converted individually from an  integer  to a double-precision floating-point value, the total processing time naturally increases with the number of pixels.

The measured average execution times (0.0020 s, 0.2885 s, and 30.1470 s) show this trend clearly. However, the increase is larger than expected from the conversion operation alone because the timing also includes console output (printf) for every pixel. Printing to the console is much slower than performing operations, making it the primary performance bottleneck.

## Execution Time Outputs

### 10 x 10
<img width="1972" height="1432" alt="image" src="https://github.com/user-attachments/assets/05d57409-6c9e-4821-b6bd-d60ec790abbf" />




### 100 x 100

<img width="2640" height="656" alt="image" src="https://github.com/user-attachments/assets/3c4d0055-d16a-4177-a563-d56c8d7455e5" />




### 1000 x 1000
<img width="2307" height="570" alt="image" src="https://github.com/user-attachments/assets/8f170a7b-d257-430d-9e6e-37c6fb7c954a" />





## Outputs with Correctness Check
<img width="1204" height="953" alt="image" src="https://github.com/user-attachments/assets/d01d58ed-f2ad-4282-a2c2-aa28c41a2294" />
<img width="2563" height="1578" alt="image" src="https://github.com/user-attachments/assets/3c355648-8ffb-44a5-bf89-2ef62c985bf3" />







