class j09_WordExample {
    private String strdata;

    // Parameterized constructor
    j09_WordExample(String str) {
        strdata = str;
    }

    // Check if a word begins and ends with a vowel
    private boolean isVowelWord(String word) {
        char first = word.charAt(0);
        char last = word.charAt(word.length() - 1);
        return "AEIOU".indexOf(first) != -1 && "AEIOU".indexOf(last) != -1;
    }

    // Count words beginning and ending with a vowel
    void countWord() {
        String sentence = strdata.substring(0, strdata.length() - 1); // remove punctuation
        String[] words = sentence.trim().split("\\s+");

        int count = 0;
        for (String w : words) {
            if (isVowelWord(w)) {
                count++;
            }
        }
        System.out.println("Count of vowel words: " + count);
    }

    // Rearrange words
    void placeWord() {
        String sentence = strdata.substring(0, strdata.length() - 1);
        String[] words = sentence.trim().split("\\s+");

        StringBuilder vowelWords = new StringBuilder();
        StringBuilder otherWords = new StringBuilder();

        for (String w : words) {
            if (isVowelWord(w)) {
                vowelWords.append(w).append(" ");
            } else {
                otherWords.append(w).append(" ");
            }
        }

        System.out.println("Rearranged Sentence:");
        System.out.println(vowelWords.toString() + otherWords.toString());
    }

    // Main method for testing
    public static void main(String[] args) {
        j09_WordExample obj = new j09_WordExample("AREA IS UNDER A UNIQUE IDEA.");

        obj.countWord();
        obj.placeWord();
    }
}
