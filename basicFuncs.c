int factorial(int num){
    if (num == 0)
    {
        return 1;
    }
    if (num == 1)
    {
        return 1;
    }
    return factorial(num-1)*num;
}

int power(int x, int y){
    if (y==0){
        return 1;
    }
    else{
        return x*power(x, y-1);
    }
}

int countDigit(int num){
    int count = 0;
    while (num>0)
    {
        num = num/10;
        count++;
    } 
    return count;
}