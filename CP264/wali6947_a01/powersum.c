/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n){
    //compute b^n with a loop, let [p = 1, for i to n, check
    //if p*b is overflow by making a temp = p*b and seeing if temp/b = p. otherwise, set p = p*b
    int p = 1;
    for (int i  = 0; i <= n;i++){
        int temp = p*b;
        if(temp/b != p){
            return 1;
        }
        p = p*b;
    }
    return 0;
}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
//check for overflow
int mypower(int b, int n){
    //if the base is 0 return 0, if we raise to 0 we return 1
if (b==0){
    return 0;
}
else if (n == 0){
    return 1;
}
if (power_overflow(b,n) == 1){
    return 0;
}
//take the number 1 and multiply it by the base # n times
int curr = 1;
for(int i = 0;i<=n;i++){
    curr*=b;
    }
return curr;
}

/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n){

}