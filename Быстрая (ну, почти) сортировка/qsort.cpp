#include <iostream>
#include <sstream>
#include <chrono>
#include <fstream>
void mqs(int * ar, int left,int right)
{
    if (left>=right)
        return;
    int l_end = left, r_end = right,num = (ar[left]+ar[right])/2;
    do
    {
        while(ar[l_end]<num)
            l_end++;
        while(ar[r_end]>num)
            r_end--;
        if (l_end<=r_end){
            std::swap(ar[l_end],ar[r_end]);
            r_end--;
            l_end++;
        }
    }while (l_end < r_end);

    if(left< r_end)
        mqs(ar,left,r_end);


    if (l_end<right)
        mqs(ar,l_end,right);


}

int main(int argc,char *argv[])
{
    int n;
    std::ifstream file;
   file.open(argv[1]);
    file >>n;
    int *a;
    a=new int [n];
    for (int i=0;i<n;i++)
    {
        file>> a[i];
    }
    file.close();//закончился скан данных a[n]- массив элементов,n- кол-во элементов

    auto t1= std::chrono::high_resolution_clock::now(); //часы
    mqs(a,0,n-1);
    auto t2=std::chrono::high_resolution_clock::now();//часы
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);//часы
    std::cout<<n<<"\r";
    std::cout<<duration.count()<<"\r";//часы
    for (int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
    delete[] a;
    return 0;
}
