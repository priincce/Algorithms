#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to hold segment information
struct Segment {
    int l = -1, r = -1, id;
};

// Global segment tree vector and its size
vector<int> seg;
int N_POSITIONS;

// Point update: adds 'val' to position 'pos'
void update(int pos, int val, int node, int start, int end) {
    if (start == end) {
        seg[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    if (start <= pos && pos <= mid) {
        update(pos, val, 2 * node, start, mid);
    } else {
        update(pos, val, 2 * node + 1, mid + 1, end);
    }
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

// Range query: returns sum in [l, r]
int query(int l, int r, int node, int start, int end) {
    if (r < start || end < l || l > r) {
        return 0;
    }
    if (l <= start && end <= r) {
        return seg[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(l, r, 2 * node, start, mid);
    int p2 = query(l, r, 2 * node + 1, mid + 1, end);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    N_POSITIONS = 2 * n;
    vector<Segment> segments(n);
    vector<int> first_pos(n + 1, -1);

    // 1. Parse Input
    for (int i = 0; i < N_POSITIONS; ++i) {
        int val;
        cin >> val;
        if (first_pos[val] == -1) {
            first_pos[val] = i;
        } else {
            segments[val - 1] = {first_pos[val], i, val};
        }
    }

    vector<int> starts_inside(n + 1);
    vector<int> ends_inside(n + 1);
    vector<int> nested_count(n + 1);

    // 2. Calculate Total Starts Inside
    seg.assign(4 * N_POSITIONS, 0);
    for (const auto& s : segments) {
        update(s.l, 1, 1, 0, N_POSITIONS - 1);
    }
    for (const auto& s : segments) {
        starts_inside[s.id] = query(s.l + 1, s.r - 1, 1, 0, N_POSITIONS - 1);
    }

    // 3. Calculate Total Ends Inside
    seg.assign(4 * N_POSITIONS, 0);
    for (const auto& s : segments) {
        update(s.r, 1, 1, 0, N_POSITIONS - 1);
    }
    for (const auto& s : segments) {
        ends_inside[s.id] = query(s.l + 1, s.r - 1, 1, 0, N_POSITIONS - 1);
    }

    // 4. Calculate Nested Segments using a sweep-line
    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.r < b.r;
    });

    seg.assign(4 * N_POSITIONS, 0);
    for (const auto& s : segments) {
        nested_count[s.id] = query(s.l + 1, s.r - 1, 1, 0, N_POSITIONS - 1);
        update(s.l, 1, 1, 0, N_POSITIONS - 1);
    }

    // 5. Compute and Print Final Answer
    for (int i = 1; i <= n; ++i) {
        int ans = starts_inside[i] + ends_inside[i] - 2 * nested_count[i];
        cout << ans << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}