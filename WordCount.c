#include <stdio.h>
#include <string.h>
int *getCharNum(char *filename, int *totalNum);
int main(){
	char filename[30];
	char state[10];
	// totalNum[0]: ���ַ���  totalNum[1]: �ܵ�����
	int totalNum[2] = { 0, 0};

	printf("Input file name: ");
	scanf("%s", state);
	scanf("%s", filename);


	if(getCharNum(filename, totalNum)){
		if(strcmp(state,"-c")==0){
			printf("�ַ�����%d\n",  totalNum[0]+1);// �������һ�ж��ȥ�Ľ�����
		}if(strcmp(state,"-w")==0){
			printf("��������%d\n",totalNum[1]);
		}
	}else{
		printf("Error!\n");
	}
	return 0;
}
/**
 * ͳ���ļ����ַ�����������������
 *
 * @param  filename  �ļ���
 * @param  totalNum  �ļ�ͳ������
 *
 * @return  �ɹ�����ͳ�����ݣ����򷵻�NULL
 **/
int *getCharNum(char *filename, int *totalNum){
	FILE *fp;  // ָ���ļ���ָ��
	char buffer[1003];  //���������洢��ȡ����ÿ�е�����
	int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
	int i;  // ��ǰ�����������ĵ�i���ַ�
	char c;  // ��ȡ�����ַ�
	int wordNum = 1; // ��ǰ�ĵ�����
	int charNum = 0;
	if( (fp=fopen(filename, "rb")) == NULL ){
		perror(filename);
		return NULL;
	}
	
	// ��ȡÿһ�����ݣ����浽buffer�����ֻ����1000���ַ�
	while(fgets(buffer, 1003, fp) != NULL){
		bufferLen = strlen(buffer);
		charNum = bufferLen-1; // ��ȥ������\0
//		printf("%d",charNum);
		// ����������������
		for(i=0; i<bufferLen; i++){
			c = buffer[i];

			if( c==' ' || c==','){  // �����ո���߶��ţ���ô��������1
				wordNum++;
			}
		}
		totalNum[0] += charNum;  // ���ַ���
		totalNum[1] = wordNum;  // �ܵ�����
	}

	return totalNum;
}
