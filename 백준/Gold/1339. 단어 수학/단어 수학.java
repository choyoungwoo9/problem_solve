import java.util.Scanner;

public class Main {

    static String used_alphabet = "";
    static int max = 0;

    static int word_count;
    static String[] word;

    static int gogo(int val[], int depth, boolean[] is_used_num){
        if(depth == used_alphabet.length()){
            int sum = 0;
            for(int i = 0; i < word.length; i = i + 1){
                int temp_wordsum = 0;
                for(int j = 0; j <word[i].length(); j = j + 1){
                    int temp_num = 0;
                    int place_value = 1;
                    for(int k = 0; k < used_alphabet.length(); k = k + 1){
                        if(used_alphabet.charAt(k) == word[i].charAt(j)){
                            temp_num = val[k];
                        }
                    }
                    for(int x = 0; x < word[i].length()-j-1; x = x+1){
                        place_value = place_value*10;
                    }
                    temp_wordsum = temp_wordsum + temp_num*place_value;

                }
                sum = sum + temp_wordsum;
            }
            if(sum > max){
                max = sum;
            }
            return 0;
        }

        for(int i = 0; i < 10; i = i + 1){
            if(is_used_num[i] == false){
                val[depth] = i;
                is_used_num[i] = true;
                gogo(val, depth+1, is_used_num);
                is_used_num[i] = false;
            }
        }
        return 0;
    }

    public static void main(String args[]){


        Scanner SC = new Scanner(System.in);
        word_count = SC.nextInt();
        word = new String[word_count];
        boolean[] is_used_alphabet = {
                false, false, false, false, false,
                false, false, false, false, false,
                false, false, false, false, false,
                false, false, false, false, false,
                false, false, false, false, false,
                false};
        for(int i = 0; i < word_count; i = i + 1){
            word[i] = SC.next();
            for(int j = 0; j < word[i].length(); j = j + 1){
                int alpha_index = Character.hashCode(word[i].charAt(j))-Character.hashCode('A');
                is_used_alphabet[alpha_index] = true;
            }

        }

        for(int i = 0; i < is_used_alphabet.length; i = i + 1){
            if(is_used_alphabet[i] == true){
                used_alphabet = used_alphabet + Character.toString('A'+i);
            }
        }

        boolean[] is_used_num = {
                false, false, false, false, false,
                false, false, false, false, false};
        int val[] = new int[used_alphabet.length()];

        gogo(val, 0, is_used_num);
        System.out.print(max);
    }
}

/*
for(int i = 0; i < val.length; i = i +1){
                System.out.print(val[i]);
            }
            int sum = 0;
            for(int i = 0; i < word_count; i = i +1) {
                for(int j = 0; j < word[i].length(); j = j +1){
                    int alpha_num = 0;
                    int place_value = 1;
                    for(int k = 0; k < used_alphabet.length(); k = k +1){
                        if(used_alphabet.charAt(k) == word[i].charAt(j)){
                            alpha_num = k;
                        }
                    }
                    for(int l = 0; l < word[i].length()-j-1; l = l + 1){
                        place_value = place_value * 10;
                    }
                    sum = sum + alpha_num*place_value;

                }
            }

            if(sum > max){
                max = sum;
            }
            return 0;
 */
