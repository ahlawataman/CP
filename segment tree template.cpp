int getMax(vector<int> &sT, int i, int j, int l, int r, int index) {
    // part of segment
    if(l<=i && r>=j) return sT[index];
    int mid = i + (j-i)/2;
    // excludes
    if(r<i || l>j) return 0;
    // overlaps
    return max(getMax(sT, i, mid, l, r, 2*index+1), getMax(sT, mid+1, j, l, r, 2*index+2));
}

void buildTree(vector<int> &sT, vector<int> &v, int i, int j, int index) {
    if(i==j) {
        sT[index] = v[i];
        return;
    }
    int mid = i + (j-i)/2;
    buildTree(sT, v, i, mid, 2*index + 1);
    buildTree(sT, v, mid+1, j, 2*index+2);
    sT[index] = max(sT[2*index+1], sT[2*index+2]); // adjust according to query
}

int main() {
    vector<int> v = {1,3,5,2,4};
    vector<int> sT(v.size()*4, 0);
    buildTree(sT, v, 0, v.size()-1, 0);
    int l = 0, r = 1; // query
    cout<<getMax(sT, 0, v.size()-1, l, r, 0); // query function
}
