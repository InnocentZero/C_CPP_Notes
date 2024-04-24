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

int n = sizeof(arr)/sizeof(arr[0]);

for (int i = 0; i < n; i++) {
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

int n = sizeof(arr)/sizeof(arr[0]);

for (int i = 0; i < n; i++) {
    int min_idx = i;
    for (int j = i; j < n; j++) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }
    std::swap(arr[i], arr[min_idx]);
}
```

- Merge Sort that counts inversions:

```cpp
void CopyArray(int A[], int iBegin, int iEnd, int B[]) {
    for (int k = iBegin; k < iEnd; k++) {
        B[k] = A[k];
    }
}

// Left source half is  A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
int TopDownMerge(int B[], int iBegin, int iMiddle, int iEnd, int A[]) {
    int i = iBegin, j = iMiddle;
    int inversions = 0;
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
            inversions += iMiddle - i;
        }
    }
    return inversions;
}

int res = 0;

// Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to
// A[] iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]) {
    if (iEnd - iBegin <= 1) {
        return;
    }
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2; // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin, iMiddle, B); // sort the left  run
    TopDownSplitMerge(A, iMiddle, iEnd, B);   // sort the right run
    // merge the resulting runs from array B[] into A[]
    res += TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int n) {
    int B[n];
    CopyArray(A, 0, n, B);         // one time copy of A[] to B[]
    TopDownSplitMerge(A, 0, n, B); // sort data from B[] into A[]
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
};

bool operator<(const Edge &first, const Edge &other) {
    return first.weight < other.weight;
}

bool operator>(const Edge &first, const Edge &other) {
    return first.weight > other.weight;
}
vector<map<int, int>> AdjList;

std::vector<Edge> edges; // original edges

std::vector<Edge> List; // final list containing our answer

int nodes;
std::vector<int> parent;
std::vector<int> size_rank;

int find_set(int v) {
    std::vector<int> compress_path;
    while (v != parent[v]) {
        compress_path.push_back(v);
        v = parent[v];
    }
    for (auto &i : compress_path) {
        parent[i] = v;
    }
    return v;
}

void union_sets(int a, int b, int wt) {
    int c = find_set(a);
    int d = find_set(b);

    if (c != d) {
        List.push_back({a, b, wt});
        if (size_rank[c] < size_rank[c]) {
            std::swap(c, d);
        }

        parent[d] = c;
        size_rank[d]++;
    }
}

void kruskals(int nodes) {

    for (int i = 0; i < nodes; i++) {
        parent[i] = i;
        size_rank[i] = 0;
    }

    sort(edges.begin(), edges.end());

    for (auto &e : edges) {
        union_sets(e.u, e.v, e.weight);
    }
}
```

- Prim's Algorithm:

```cpp
struct Edge {
    int u, v, weight;
};

bool operator<(const Edge &first, const Edge &other) {
    return first.weight < other.weight;
}

bool operator>(const Edge &first, const Edge &other) {
    return first.weight > other.weight;
}
vector<map<int, int>> AdjList;

vector<Edge> prims(int nodes) {
    bool visited[nodes];
    for (auto &i : visited) {
        i = false;
    }

    vector<Edge> res;

    set<Edge, vector<Edge>, greater<Edge>> pq;

    visited[0] = true;

    for (auto &iter : AdjList[0]) {
        pq.insert({0, iter.first, iter.second});
    }

    while (!pq.empty()) {
        auto e = pq.begin();
        pq.delete(e);

        if (visited[e->v]) {
            continue;
        }

        visited[e->v] = true;
        res.push_back(e);

        for (auto &edges: AdjList[e->v]) {
            if (!visited[edges.first]) {
                pq.push({e->v, edges.first, edges.second});
            }
        }
    }

    return res;
}
```

- Dijkstra's Algorithm

```cpp
vector<map<int,int>> AdjList;

void dijkstras(std::ofstream &ofile, int src, int nodes) {

    int dist[nodes];
    for (auto &i : dist) {
        i = INT_MAX;
    }

    int parent[nodes];
    for (auto &i : parent) {
        i = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &iter : AdjList[u]) {
            int v = iter.first;
            int weight = iter.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < nodes; i++) {
        ofile << i << " " << dist[i] << endl;
    }
}
```
