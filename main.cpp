#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>


int main(int argc,char* argv[]){
	uint32_t ret1;
	uint32_t ret2;
	uint32_t result;

	FILE *fp1=NULL;
	FILE *fp2=NULL;
	
	try{
	fp1=fopen(argv[1],"rb");
	fp2=fopen(argv[2],"rb");
	
	if(!fp1||!fp2){
		throw 1;
	}
	
	}

	catch(int n){
	printf("File open failed.");
	if(!fp1) fclose(fp1);
	if(!fp2) fclose(fp2);
	return 1;
	}

	

	fread(&ret1,1,sizeof(uint32_t),fp1);
	fread(&ret2,1,sizeof(uint32_t),fp2);
	
	ret1=ntohl(ret1);
	ret2=ntohl(ret2);
	result=ret1+ret2;

	printf("%d(0x%x)+%d(0x%x)=%d(0x%x)\n",ret1,ret1,ret2,ret2,result,result);

	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

