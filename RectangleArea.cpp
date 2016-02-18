class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A) * (D-B) + (G-E) * (H-F);
        if(min(C,G) > max(A,E) && min(D,H) > max(B,F))
            return area - max(min(C,G) - max(A,E), 0) * max(min(D,H) - max(B,F), 0);
        else
            return area;
    }
};
