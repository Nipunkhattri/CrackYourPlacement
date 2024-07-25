int solve(int start,int end){
    if(start > end) return 1;

    if(start == end) return 1;
    int total = 0;
    for(int i = start;i<=end;i++){
        int LeftBsts = solve(start,i-1);
        int RightBsts = solve(i+1,end);
        total += LeftBsts*RightBsts;
    }
    return total;
}
int numTrees(int n) {
    return solve(1,n);
}