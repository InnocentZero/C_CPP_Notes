# algorithms

## Sorting Algos

- Bubble Sort:

```cpp
int arr[] = {1,3,6,2,5,4,8,9};

for (int i = 0; i < 8; i++){
    for (int j = 0; j < 7 - i; j++){
        if (arr[j] < arr[j+1]){
            std::swap(arr[j], arr[j + 1]);
        }
    }
}
```

- Insertion Sort:

```cpp
int arr[] = {1,3,6,2,5,4,8,9};

for (int i = 0; i < 8; i++) {
    int x = arr[i];
    int j = i;
    for (j = i; j >= 0 && arr[j] > x, j--) {
        arr[j] = arr[j - 1];
    }
    arr[j] = x;
}
```

- Selection Sort:

```cpp
int arr[] = {1,3,6,2,5,4,8,9};

for (int i = 0; i < 8; i++) {
    int min_idx = i;
    for (int j = i; j < 8; j++) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }
    std::swap(arr[i], arr[min_idx]);
}
```

- Merge Sort:

```cpp
// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(A[], B[], n)
{
    CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
    TopDownSplitMerge(A, 0, n, B);   // sort data from B[] into A[]
}

// Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(B[], iBegin, iEnd, A[])
{
    if (iEnd - iBegin <= 1)                     // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(B[], iBegin, iMiddle, iEnd, A[])
{
    i = iBegin, j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void CopyArray(A[], iBegin, iEnd, B[])
{
    for (k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}
```

- Quick sort:

```cpp

void quicksort(int A[], int low, int high) {
    if (low >= high) return;
    if (low + 1 == high) {
        if (A[high] < A[low]) {
            std::swap(A[low], A[high]);
        }
        return;
    } 

    int pivot = A[high];
    int i = low;
    int j = high - 1;

    while (true) {
        while (i < high && A[i] <= pivot) i++;
        while (j >= low && A[j] >= pivot) j--;
    }

    if (i < j) {
        std::swap(A[i], A[j]);
        i++; j--;
    } else {
        break;
    }

    std::swap(A[i], A[high]);
}
```

## MST algorithms

- Kruskal's Algorithm:

```cpp

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
};

int nodes;

std::vector<Edge> edges; // original edges

std::vector<std::pair<int, int>> List; // final list containing our answer

std::vector<int> parent(nodes);
std::vector<int> rank(nodes);

for (int i = 0; i < nodes; i++) {
    parent[i] = i;
    rank[i] = 0;

}

int find_set(int v) {
    std::vector<int> compress_path;
    while (v != parent[v]) {
        compress_path.push_back(v);
        v = parent[v];
    }
    for (auto &i: compress_path) {
        parent[i] = v;
    }
    return v;
}

void union_sets(int a, int b, int wt) {
    int c = find_set(a);
    int d = find_set(b);

    if (c != d) {
        List.push_back({a, b, wt});
        if (rank[c] < rank[c]) 
            std::swap(c, d);

        parent[d] = c;
        rank[d]++;
    }
}

sort(edges.begin(), edges.end());

for (auto &e: edges) {
    union_sets(e.u, e.v, e.weight);
}

```

- Prim's Algorithm:

```cpp

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
};

int nodes;

std::list<Edge> adj(nodes);

std::vector<Edge> edges; // original edges

std::vector<std::pair<int, int>> List; // final list containing our answer

std::unordered_set<int> vertices;

void prims() {
    vertices.insert(0);
    while (vertices.size() != nodes) {
        Edge min = {-1, -1, INT_MAX};

        for (auto &i: vertices) {
            for (auto &j : adj[i]) {
                if (j.weight < min.weight) {
                    min = j;
                }
            }
        }

        vertices.insert(min.u);
        vertices.insert(min.v);

        List.push_back(min);

    }
}
```
