class Solution {
    public String reverseWords(String s) {
        
        // Splitting the string's words into an array
        String[] words = s.split(" +");

        // Using StringBuilder to modify a string
        StringBuilder sb = new StringBuilder();

        for(int i = words.length-1; i>=0; i--){
            sb.append(words[i]);
            sb.append(" ");
        }
        // Convert into string, eliminate leading & trailing
        // spaces and return the string
        return sb.toString().trim();
    }
}