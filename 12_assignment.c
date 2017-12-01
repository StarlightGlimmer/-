/*
 * 提出課題：文字種類のカウント
 * 下記URLにあるテキストファイルを(ダウンロードした上で)入力として、
 * そのファイル中でどの文字が何回使われているかを調べ、それをファイルに出力するプログラムを作成せよ。
 * 「文字」とは、アルファベット(大文字、小文字)、数字、記号のすべて。記号には空白を含む。特殊記号(改行、タブなど)は含まない
 * http://box.jnlp.org/BNC.txt
 */

#define MAX_CHARACTERS_PER_LINE 256
#define ASCII_CODES 256
#define ASCII_SPACE 32
#define ASCII_DEL 127
#define OUTPUT_FILENAME "character count.txt"

#include <stdio.h>

int main(void) {
	FILE *fp;
	fopen_s(&fp, "BNC.txt", "r");
	int characters[ASCII_CODES] = { 0 };
	char one_line_string[MAX_CHARACTERS_PER_LINE + 1] ;
	while (fgets(one_line_string, MAX_CHARACTERS_PER_LINE, fp) != 0) {
		int i = 0;
		while (one_line_string[i] != 0) {
			characters[one_line_string[i]] += 1;
			i += 1;
		}
	}

	fopen_s(&fp, OUTPUT_FILENAME, "a");
	for (int j = ASCII_SPACE; j < ASCII_DEL; j++) {
		fputc(j, fp);
		fputs(": ", fp);
		fprintf(fp,"%d",characters[j]);
		fputc((int)'\n', fp);
	}
	fclose(fp);

	return 0;
}