int twoStacks(int x, vector<int> a, vector<int> b, int indA, int indB) {
    if (x==0)
        return 0;
    if (x<0)
        return -1;  // the integer prelevated is not correct so i hadn't to add 1 to solution
    
    if (indA >= a.size()){      // a is empty
        if (indB >= b.size())   // b is empty too
            return 0;
        return 1+twoStacks(x-b[indB], a, b, indA, indB+1);
    }
    if (indB >= b.size()){ // b is empty
        return 1+twoStacks(x-a[indA], a, b, indA+1, indB);
    } 
    
    return max(1+twoStacks(x-a[indA], a, b, indA+1, indB), 1+twoStacks(x-b[indB], a, b, indA, indB+1));

}