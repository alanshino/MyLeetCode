int tribonacci(int n){
    int tribonacci_array[38];     // 測資最大值
    tribonacci_array[0] = 0;      // 前三個為固定值
    tribonacci_array[1] = 1;
    tribonacci_array[2] = 1;
    for (int i = 3; i < 38; i++) {
        tribonacci_array[i] = tribonacci_array[i - 1] + tribonacci_array[i - 2] + tribonacci_array[i - 3];
        // printf("%d ",tribonacci_array[i]);
        // T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
    }
    return tribonacci_array[n];
}
