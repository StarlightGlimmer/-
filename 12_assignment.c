/*
 * ��o�ۑ�F������ނ̃J�E���g
 * ���LURL�ɂ���e�L�X�g�t�@�C����(�_�E�����[�h�������)���͂Ƃ��āA
 * ���̃t�@�C�����łǂ̕���������g���Ă��邩�𒲂ׁA������t�@�C���ɏo�͂���v���O�������쐬����B
 * �u�����v�Ƃ́A�A���t�@�x�b�g(�啶���A������)�A�����A�L���̂��ׂāB�L���ɂ͋󔒂��܂ށB����L��(���s�A�^�u�Ȃ�)�͊܂܂Ȃ�
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