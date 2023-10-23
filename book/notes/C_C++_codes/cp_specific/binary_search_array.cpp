uint64_t n = 6;
uint64_t arr[n] = {1, 2, 3, 4, 5, 6};
uint64_t start = 0, end = n - 1, mid = start + (end - start)/2;
while (end - start >= 0) {
    mid = start + (end - start)/2
    if (arr[mid] == key) {
        cout << mid << '\n';
        break;
    } else if (arr[mid] < key) start = mid + 1;
    else end = mid - 1;
}
if (arr[mid] != key)
cout << "Not present\n";

