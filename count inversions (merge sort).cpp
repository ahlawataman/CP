void mergeSort(vector<int> &A, int i, int mid, int j, int &res) {
    int l1 = i;
    int l2 = mid+1;
    int k = 0;
    vector<int> B(j+1);
    while(l1<=mid && l2<=j) {
        if(A[l2] < A[l1]) {
            res += mid-l1+1;
            B[k++] = A[l2++];
        } else {
            B[k++] = A[l1++];
        }
    }
    while(l1<=mid) B[k++] = A[l1++];
    while(l2<=j) B[k++] = A[l2++];
    for(int p=i; p<=j; p++) {
        A[p] = B[p-i];
    }
}

void merge(vector<int> &A, int i, int j, int &res) {
    if(i<j) {
        int mid = i + (j-i)/2;
        merge(A, i, mid, res);
        merge(A, mid+1, j, res);
        mergeSort(A, i, mid, j, res);
    }
}

int main() {
    vector<int> A = {3,2,1};
    int res = 0;
    merge(A, 0, A.size()-1, res);
    // for(int i=0; i<A.size(); i++) {
    //     cout<<A[i]<<" ";
    // }
    cout<<res;
}
