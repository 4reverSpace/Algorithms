#include <iostream>
#include <sstream>
#include <chrono>
#include <fstream>
#include <cmath>
void checktree(int *array,int len,int i)
{
    if (i>=len-1 || 2*i+1>=len-1)
        return;
    int parent=array[i],child_1=array[2*i+1],child_2=array[2*i+2];
    if (2*i+2>len-1)
        child_2=parent;
    if( parent>=child_1 && parent>=child_2)
        return;
    else {
        if (child_1 <= child_2) {
            std::swap(array[i], array[2 * i + 2]);
            checktree(array, len, 2 * i + 2);
            return;
        }
        else {
            std::swap(array[i], array[2 * i + 1]);
            checktree(array, len, 2 * i + 1);
            return;
        }
    }
}
void mqs(int * ar, int left,int right,int deep,int max_deep)
{
    if (left>=right || deep>max_deep)
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
        mqs(ar,left,r_end,deep+1,max_deep);


    if (l_end<right)
        mqs(ar,l_end,right,deep+1,max_deep);


}

int main(int argc,char *argv[])
{
    int n;
    //std::ifstream file;
    //file.open(argv[1]);
    //file >>n;
    std::cin>>n;
    int max_deep=log(n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    //file.close();//закончился скан данных a[n]- массив элементов,n- кол-во элементов
    int max_i=0;
    while(max_i*2+3<=n-1)
        max_i++; //определение последнего i
    auto t1= std::chrono::high_resolution_clock::now(); //часы
    mqs(a,0,n-1,0,max_deep);
    for (int j=0;j<n;j++)
    {
        for(int i=max_i;i>=0;i--)
        {
            checktree(a,n-j,i);
        }
        std::swap(a[0],a[n-1-j]);
    }
    auto t2=std::chrono::high_resolution_clock::now();//часы
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);//часы
    std::cout<<n<<"\r";
    std::cout<<duration.count()<<"\r";//часы
    for (int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
    return 0;
}
