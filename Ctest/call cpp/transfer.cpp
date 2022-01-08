//transfer.cpp
void transfer(int *a,int *b) //形參a,b都是指標
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
