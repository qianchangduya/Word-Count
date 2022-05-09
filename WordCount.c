#include <stdio.h>
#include <string.h>
int *getCharNum(char *filename, int *totalNum);
int main(){
	char filename[30];
	char state[10];
	// totalNum[0]: 总字符数  totalNum[1]: 总单词数
	int totalNum[2] = { 0, 0};

	printf("Input file name: ");
	scanf("%s", state);
	scanf("%s", filename);


	if(getCharNum(filename, totalNum)){
		if(strcmp(state,"-c")==0){
			printf("字符数：%d\n",  totalNum[0]+1);// 加上最后一行多减去的结束符
		}if(strcmp(state,"-w")==0){
			printf("单词数：%d\n",totalNum[1]);
		}
	}else{
		printf("Error!\n");
	}
	return 0;
}
/**
 * 统计文件的字符数、单词数、行数
 *
 * @param  filename  文件名
 * @param  totalNum  文件统计数据
 *
 * @return  成功返回统计数据，否则返回NULL
 **/
int *getCharNum(char *filename, int *totalNum){
	FILE *fp;  // 指向文件的指针
	char buffer[1003];  //缓冲区，存储读取到的每行的内容
	int bufferLen;  // 缓冲区中实际存储的内容的长度
	int i;  // 当前读到缓冲区的第i个字符
	char c;  // 读取到的字符
	int wordNum = 1; // 当前的单词数
	int charNum = 0;
	if( (fp=fopen(filename, "rb")) == NULL ){
		perror(filename);
		return NULL;
	}
	
	// 读取每一行数据，保存到buffer，最多只能有1000个字符
	while(fgets(buffer, 1003, fp) != NULL){
		bufferLen = strlen(buffer);
		charNum = bufferLen-1; // 减去结束符\0
//		printf("%d",charNum);
		// 遍历缓冲区的内容
		for(i=0; i<bufferLen; i++){
			c = buffer[i];

			if( c==' ' || c==','){  // 遇到空格或者逗号，那么单词数加1
				wordNum++;
			}
		}
		totalNum[0] += charNum;  // 总字符数
		totalNum[1] = wordNum;  // 总单词数
	}

	return totalNum;
}
