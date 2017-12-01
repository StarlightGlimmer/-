/*
 * 提出課題：文字種類のカウント
 * 下記URLにあるテキストファイルを(ダウンロードした上で)入力として、
 * そのファイル中でどの文字が何回使われているかを調べ、それをファイルに出力するプログラムを作成せよ。
 * 「文字」とは、アルファベット(大文字、小文字)、数字、記号のすべて。記号には空白を含む。特殊記号(改行、タブなど)は含まない
 * http://box.jnlp.org/BNC.txt
 */

#define MAX_CHARACTERS_PER_LINE 256
#define ASCII_CODES 256
#define ASCII_CODE_SPACE 32
#define ASCII_CODE_DEL 127

#include <stdio.h>

int main(void) {
	const char INPUT_FILENAME[] = "BNC.txt";
	int characters[ASCII_CODES] = { 0 };
	char one_line_string[MAX_CHARACTERS_PER_LINE + 1];
	FILE *character_count_text;
	fopen_s(&character_count_text, INPUT_FILENAME, "r");
	while (fgets(one_line_string, MAX_CHARACTERS_PER_LINE, character_count_text) != 0) {
		int i = 0;
		while (one_line_string[i] != 0) {
			characters[one_line_string[i]] += 1;
			i += 1;
		}
	}
	fclose(character_count_text);
	
	FILE *output_text;
	const char OUTPUT_FILENAME[] = "character count.txt";
	fopen_s(&output_text, OUTPUT_FILENAME, "a");
	for (int j = ASCII_CODE_SPACE; j < ASCII_CODE_DEL; j++) {
		fputc(j, output_text);
		fputs(": ", output_text);
		fprintf(output_text,"%d",characters[j]);
		fputc((int)'\n', output_text);
	}
	fclose(output_text);

	return 0;
}