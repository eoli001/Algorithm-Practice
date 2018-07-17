

//Find Maxlength of square between points
// you can also use imports, for example:
 import java.util.*;
 import java.lang.Math;


// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");



class Solution {
    int sumofSquare(int one, int two, int three, int four){
        int sum = 0;
        int firstSub = (one-two);
        int secondSub = (three-four);
        sum = firstSub * firstSub + secondSub*secondSub;
        return sum;
    }
    
    public int solution(int A, int B, int C, int D) {
        // write your code in Java SE 8
        int sumofLength = 0;
        int firstSum = sumofSquare(A,B,C,D);
        int secondSum = sumofSquare(A,C,B,D);
        int thirdSum = sumofSquare(A,D,B,C);
        int[] sumArray = {firstSum, secondSum, thirdSum};
        int maxSum = 0;
        for (int sum :  sumArray){
            if (sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
    
}