#include"parking_lot.h"

//持久化层
//将信息写入文件

void FileWrite(Car_list* myBycycleList)
{
	FILE *fp = fopen("Test.txt", "w");
	CarNode *p = myBycycleList->first;
	assert(p != NULL);
	while (p != NULL)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %d %d ", p->Owner, p->Age, p->Sex, p->IDcard, p->number, p->partingTime.Year, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
		p = p->next;
	}
	fclose(fp);
	printf("信息写入成功\n");
	getchar();
}



