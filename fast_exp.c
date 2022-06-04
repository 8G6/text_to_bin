const int P[] = {1,2,4,8,16,32,64,128,256};
int bin(char y,int a[]){
    int i,n=y;
    for(i=7;i>=0;i--){
        a[7-i]=(n/P[i])%2;
    }
}
