# algorithms

## Sorting Algos

- Bubble Sort:

```cpp
int arr[] = {1,3,6,2,5,4,8,9}

for (int i = 0; i < 8; i++){
    for (int j = 0; j < 7 - i; j++){
        if (arr[j] < arr[j+1]){
            std::swap(arr[j], arr[j + 1]);
        }
    }
}
```
