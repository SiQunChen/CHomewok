#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int minValue(int x, int y) { return (x>y?y:x); }
int Rec(int n, int R[][1<<n], int d[][n], int v, int S){
    int t=0, ans = INF;
    if(R[v][S] >= 0) { return R[v][S]; } //�w�g�p��L�������A���ΦA�p��
    for(int i = 0 ; i < n ; i ++) {
        if(!(S>>i&1)) { //���X S�A{0, 1, 2, 3}�A�P�_��i�Ӧs�b(0���s�b)
            t = Rec(n, R, d, i, S|(1<<i)); //���X S�A�h���s�b�����@�ӡA��i�ӳ]��1
            ans = minValue(ans,d[v][i]+ t);
        }
    }
    return R[v][S] = ans;
}
void solve(){ // {0, 1, 2, 3}�s�X 0000
    int MAX_N;
    scanf(" %d",&MAX_N);
    int v = 0, S=(0|1<<v); //�qv=0�X�o�A�g�L{1, 2, 3}->{0001}
    int R[MAX_N][1<<MAX_N]; //�qv=1�X�o�A�g�L{0, 2, 3}->{0010}
    int d[MAX_N][MAX_N];
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_N;j++){
            scanf(" %d",&d[i][j]);
        }
    }
    memset(R,-1,sizeof(R));
    for (int i=0; i<MAX_N; i++) // R[1][�Ŷ��X 1111]=d[1][0]
        R[i][(1<<MAX_N)-1]=d[i][0]; // R[0][�Ŷ��X 1111]=d[0][0]=0
    printf("%d", Rec(MAX_N, R, d, v, S));
}
int main() { solve(); return 0; }
