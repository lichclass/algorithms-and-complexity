
| Algorithm     | Time Complexity                                                  | Space Complexity | Comparison-Based                                             | Stable  |
| ------------- | ---------------------------------------------------------------- | ---------------- | ------------------------------------------------------------ | ------- |
| Heap Sort     | **All cases:** $O(n log_n)$                                      | $O(1)$           | **Yes**                                                      | **No**  |
| Quick Sort    | **Best:** $O(nlog_n)$, **Avg:** $O(nlog_n)$, **Worst:** $O(n^2)$ | $O(log_n)$       | **Yes**                                                      | **No**  |
| Merge Sort    | **All Cases:** $O(n log_n)$                                      | $O(n)$           | **Yes**                                                      | **Yes** |
| Bucket Sort   | **Best:** $O(n+k)$, **Avg:** $O(n+k)$, **Worst:** $O(n^2+k)$     | $O(n)$           | **No** (Excluding the sorting algorithm used in the buckets) | **Yes** |
| Radix Sort    | **All cases:** $O(d(n+b))$ or $O(n * k)$                         | $O(n + k)$       | **No**                                                       | **Yes** |
| Counting Sort | **All cases:** $O(n + k)$                                        | $O(n + k)$       | **No**                                                       | **Yes** |
