class LongestCommonPrefix {
    public static String longestCommonPrefix(String[] strs) {
        if(strs.length == 1){
            return strs[0];
        }

        StringBuilder pref = new StringBuilder();
        String tmp = strs[0];
        String str2;

        for (int i = 1; i < strs.length; i++) {
            pref.setLength(0);
            str2 = strs[i];

            for(int j=0; j<tmp.length() && j < str2.length(); j++){
                if(tmp.charAt(j) != str2.charAt(j)){
                    break;
                }
                pref.append(str2.charAt(j));
            }
            tmp = pref.toString();
        }

        return pref.toString();
    }

    public static void main(String[] args) {
        String[] s = {"flower", "flow", "floght"};
        System.out.println(longestCommonPrefix(s));
    }
}