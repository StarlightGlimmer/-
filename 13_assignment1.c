#include <stdio.h>
#include <time.h>

/*
* �ۑ�F�f������
* n��2�`(n-1)�܂Ŋ�����1�x�ł��]�肪0�ɂȂ�����f���łȂ�
* �Ƃ������@�őf���𔻒肷��v���O�������쐬����B
*
* �����F
* ��������ǂ���300000�܂ł̂��ׂĂ̑f����\������v���O�������쐬����B
* ��o��
* (1) �v���O����
* (2) ���s���� (�ȉ����Q�� https://speakerdeck.com/jnlp/ji-chu-qing-bao-chu-li-yan-xi-bu-zu-shi-xing-shi-jian-falsece-ding)
* (3) �ǂ����ǂ̂悤�ɉ��ǂ������Ƃ�������
*/

/*
 * ���s���ԁF0.966 [s]
 * 
 * ���ǂ����_�F
 * �ϐ������炷���߂ɁA��ʂɍD�܂����͂Ȃ����}�W�b�N�i���o�[���g�p
 * ��300000 �� 548 �ȏ�Ŋ����Ă��Ӗ����Ȃ����߁A�ȍ~���ȗ�
 */

int isPrimeNumber(const int integer) {
	if (integer == 2) {
		return 1;
	}
	for (int i = 3; i < 548; i = i+2) {
		if (integer%i == 0) {
			return 0;
		}
	}
	return 1;
}

void makePrimeNumberList(const int *ary) {
	for (int idx = 0;;idx++)
}

int main(void) {
	const clock_t start_time = clock();
	int primeNumbers[500] = { 0 };
	for (int i = 2; i <= 300000; i++) {
		if (isPrimeNumber(i)) {
			printf("%d ", i);
		}
	}

	const clock_t end_time = clock();
	printf("time = %.3f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	return 0;
}