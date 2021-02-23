#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/**
* Q9
* 思路：反转数字，然后比较反转后的数与原数比较，相等则为回文数。
* 有一个问题是反转所有数字会有整数溢出的可能，所以考虑反转一半的数字。
* 反转一半的数字：依次把x的最低位当做反转数字reversedNumber的最后一位，并去掉x的最低位；直到x<=reversedNumber。
* x与reversedNumber长度刚好相等，或者x比reversedNumber少1位
* 如果长度刚好相等，则当x==reversedNumber时，为回文数
* 如果x比reversedNumber少1位，则当x==reversedNumber/10时，为回文数
* 边界条件：x<0时，不是回文数
**/
bool isPalindrome(int x) {
	// 特殊情况：
		// 如上所述，当 x < 0 时，x 不是回文数。
		// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
		// 则其第一位数字也应该是 0
		// 只有 0 满足这一属性
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	int revertedNumber = 0;
	while (x > revertedNumber) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
	// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
	// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
	return x == revertedNumber || x == revertedNumber / 10;

}

int main() {

	int test = 2112;
	printf("%d", isPalindrome(test));

	return 0;
}
