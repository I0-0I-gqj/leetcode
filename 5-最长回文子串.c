char * longestPalindrome(char * s){
        char *step = s;
        char *p_left, *p_right, *str = s;
        int str_len = 1, len;

        p_left = step;
        
        while (*step != '\0') {
                
                p_right = step+1;
                
                len = 0;
                p_left = step;
                while (p_left >= s && *p_left == *p_right && *p_right != '\0') {
                        len++;
                        p_left = p_left-1;
                        p_right = p_right+1;
                }
                if (len*2 > str_len) {
                        str = p_left + 1;
                        str_len = len*2;
                }

                if (step > s) {
                    len = 0;
                    p_left = step-1;
                    p_right = step+1;
                    while (p_left >= s && *p_left == *p_right && *p_right != '\0') {
                            len++;
                            p_left = p_left-1;
                            p_right = p_right+1;
                    }
                    if (len*2+1 > str_len) {
                            str = p_left+1;
                            str_len = len*2+1;
                    }
                }
                
                step+=1;
        }

        str[str_len] = '\0';
        return str;
}
