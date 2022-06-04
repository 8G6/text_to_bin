void std(unsigned long long int ips){
    const unsigned long long int exp[] = {1,1000,1000000,1000000000,1000000000000};
    char sym[] = " kMBT",c; 
    int i=0,cu;
    for(i=0;i<5;i++){
        if(ips>=exp[i]){
            c=sym[i];
            cu=i;
        }
    }
    printf("%0.3f%c ",(double) ips/exp[cu],c);
}

int bench(char text[],unsigned long long int max,int trials,int fun(char a,int b[])){
    clock_t start,end;
    int i=0,j=0,a[8],k=0;
    double time=0,avg=0;
    unsigned long long int total = max*trials;
    for(i=0;i<trials;i++){
        start = clock();
        for(j=0;j<max;j++){
            while(text[k]!='\0'){
                fun(text[k],a);
                k++;
            }
        }
        end = clock();
        time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d %f\n",i+1,time);
        avg += time;
    }
    printf("Avarage time took to exicute %lld times is %f ",total,avg/trials);
    printf("( ");
    std((unsigned long long int) total/(avg/trials));
    printf("itrations per second )\n");
}