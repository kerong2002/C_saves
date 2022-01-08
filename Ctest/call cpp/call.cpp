# include <iostream>
# include "transfer.cpp"

int main()
{
    int para1 = 1;
    int para2 = 2;
    transfer(&para1,&para2); //©I¥stransfer¨ç¦¡
    std::cout << para1 <<","<< para2 <<std::endl;
}
