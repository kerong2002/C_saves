//transfer.cpp
void transfer(int *a,int *b) //�ΰ�a,b���O����
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
