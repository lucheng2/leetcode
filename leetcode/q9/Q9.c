#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/**
* Q9
* ˼·����ת���֣�Ȼ��ȽϷ�ת�������ԭ���Ƚϣ������Ϊ��������
* ��һ�������Ƿ�ת�������ֻ�����������Ŀ��ܣ����Կ��Ƿ�תһ������֡�
* ��תһ������֣����ΰ�x�����λ������ת����reversedNumber�����һλ����ȥ��x�����λ��ֱ��x<=reversedNumber��
* x��reversedNumber���ȸպ���ȣ�����x��reversedNumber��1λ
* ������ȸպ���ȣ���x==reversedNumberʱ��Ϊ������
* ���x��reversedNumber��1λ����x==reversedNumber/10ʱ��Ϊ������
* �߽�������x<0ʱ�����ǻ�����
**/
bool isPalindrome(int x) {
	// ���������
		// ������������ x < 0 ʱ��x ���ǻ�������
		// ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
		// �����һλ����ҲӦ���� 0
		// ֻ�� 0 ������һ����
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	int revertedNumber = 0;
	while (x > revertedNumber) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	// �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
	// ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
	// ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
	return x == revertedNumber || x == revertedNumber / 10;

}

int main() {

	int test = 2112;
	printf("%d", isPalindrome(test));

	return 0;
}
