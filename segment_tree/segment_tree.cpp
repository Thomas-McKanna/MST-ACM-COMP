#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
    vi st, A;       // vi is: typedef vector<int> vi;
    int n;
    int left(int p) { return p << 1; }     // << 1 multiplies by 2
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {   // O(n)
        if (L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {    // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
        if (L >= i && R <= j) return st[p]; // inside query range

        // compute the min position in the left and right part of interval
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R)/ 2 + 1, R, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] < A[p2]) ? p1 : p2;
    }

    void update(int p, int L, int R, int i) {
        if (i < L || i > R || L == R) return;

        update(left(p), L, (L + R) / 2, i);
        update(right(p), (L + R)/ 2 + 1, R, i);

        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] = (p1 < p2) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

    void update(int i, int val) {
        if (i >= n) return;
        A[i] = val;
        update(1, 0, n - 1, i);
    }
};

int main() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vi A(arr, arr + 7);
    SegmentTree st(A);
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));
    printf("RMQ(2, 6) = %d\n", st.rmq(2, 6));
    st.update(5, 99);
    printf("A[5] = 99\n");
    printf("RMQ(2, 6) = %d\n", st.rmq(2, 6));
    st.update(2, 99);
    printf("A[2] = 99\n");
    printf("RMQ(2, 6) = %d\n", st.rmq(2, 6));
    return 0;
}