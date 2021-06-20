import java.util.Scanner;

class Solution {
    public static int myAtoi(String s) {
        s = s.strip();
        long res = 0;
        int len = s.length();
        int i = 0;
        boolean isNeg = false;
        char current;

        if (len == 0) {
            return 0;
        }

        if (s.charAt(0) == '-') {
            isNeg = true;
            i++;
        }

        if (s.charAt(0) == '+') {
            i++;
        }

        for (i = i; i < len; i++) {
            current = s.charAt(i);
            if (!Character.isDigit(current)) {
                break;
            }
            res = res * 10 + (current - '0');

            if (res > Integer.MAX_VALUE) {
                return isNeg? Integer.MIN_VALUE : Integer.MAX_VALUE ;
            }
        }

        if (isNeg) {
            res *= -1;
        }

        return (int) res;
    }

}

class Program {
    public static void main(String[] args) {
        String s = "-91283472332";
        System.out.println(Solution.myAtoi(s));
    }
}
