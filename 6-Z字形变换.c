struct st_t {
        char s[1024];
        int idx;
} ;
/* 
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

*/
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
/* 
       打印Z字形
*/
char * convert(char *s, int numRows) {

        char * str = malloc(1024);
        struct st_t *st = malloc(numRows*sizeof(struct st_t));
        memset(st, 0, numRows*sizeof(struct st_t));

        int i, len = 0, flag = 0, idx = 0, tt = 0;

        i=0;
        while (*s != '\0') {
                st[i].s[idx] = *s;
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
                                idx++;
                        }
                }
        }
        printf("idx: %d \n", idx);
        for (i=0; i<numRows; i++) {
                int j;
                for (j=0; j<=idx; j++) {
                        printf("%c", st[i].s[j]==0?' ':st[i].s[j]);
                }
                printf("\n");
        }

        free(st);

        return str;
}
