/*
 * centence_reverse.cpp
 *
 *  Created on: Dec 16, 2016
 *      Author: liuyanan
 */



/*
	并不是简单的字符串反转，而是按给定字符串里的单词将字符串倒转过来，就是说字符串里面的单词还是保持原来的顺序，这里的每个单词用空格分开。例如：
		hello world
	经过反转后变为：
		world hello
*/
void reverse_string(char* str, int start, int end) {
	if(start > end || start<0 || end >= strlen(str))
		return;

	char t;
	while(start < end) {
		t = str[start];
		str[start] = str[end];
		str[end] = t;

		++start;
		--end;
	}
}



int main(int argc, char **argv) {

}
