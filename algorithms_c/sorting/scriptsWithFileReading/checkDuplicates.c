int get_num_duplicates(long* a, int n){
    int i, j;
    int num_duplicates = 0;
    sort(a, 0, n -1);
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] == a[j]){
                num_duplicates++;
            }else{
                break;
            }
        }
    }
    return num_duplicates;
}
