struct st_t {
        char s[1024];
        int idx;
} ;

char * convert(char *s, int numRows) {

        char * str = malloc(1024);
        struct st_t *st = malloc(numRows*sizeof(struct st_t));
        memset(st, 0, numRows*sizeof(struct st_t));

        int i, len = 0, flag = 0;

        i=0;
        while (*s != '\0') {
                st[i].s[st[i].idx++] = *s;
                s += 1;

                if (numRows > 1) {
                    if (i >= numRows-1) {
                        flag = 0;
                    } else if (i <= 0) {
                            flag = 1;
                    }

                    if (flag == 1) {
                            i++;
                    } else {
                            i--;
                    }
                }
                
        }

        for (i=0; i<numRows; i++) {
                memcpy(str+len, st[i].s, st[i].idx);
                len += st[i].idx;
        }
        str[len] = '\0';
        free(st);

        return str;
}
