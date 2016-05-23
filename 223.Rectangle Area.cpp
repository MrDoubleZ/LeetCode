class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int rect1=(C-A)*(D-B);
        int rect2=(G-E)*(H-F);
        int I,J,K,L;
        I=max(A,E);
        J=max(B,F);
        K=min(C,G);
        L=min(D,H);
        if(I<K&&J<L)
            return rect1+rect2-(K-I)*(L-J);
        else
            return rect1+rect2;
    }
}; 