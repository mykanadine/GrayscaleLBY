# LBYARCH x86-to-C: Grayscale Image Conversion From Int to Float

This project performs mapping from uint8 based integer grayscale to double precision float representation
## Video demo link
https://drive.google.com/file/d/1kQGe8YkT6Toy6vpe1xnYEF8Vh2zTPCrZ/view?usp=sharing

## Execution Time and Short Analysis of Performance

The table below shows execution times for different input sizes:
| Input Size  | Average Execution Time (30 runs) |
|------------|----------------------------------|
| 10×10         |0.0020 seconds                |
| 100×100     |   0.2885 seconds             |
| 1000×1000   |  30.1470 seconds    |

### Short analysis
- For small inputs (10×10), the program runs almost instantly.
- For medium inputs (100×100), it slows down to almost a third of a second
- For large inputs (1000×1000), it takes around 30 seconds each run.
- The execution  time grows as the input size increases
- Printing is included in the recorded time, so the actual computation may be a bit faster if printing is removed.

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







