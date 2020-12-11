#include <iostream>
#include <sstream>
#include <chrono>
#include <fstream>
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
        }
        else {
            std::swap(array[i], array[2 * i + 1]);
            checktree(array, len, 2 * i + 1);
        }
    }
}

int main(int argc,char *argv[])
{
    int n;
    std::ifstream file;
    file.open(argv[1]);
    file >>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        file >>a[i];
    }
    file.close();//закончился скан данных a[n]- массив элементов,n- кол-во элементов
    int max_i=0;
    while(max_i*2+3<=n-1)
        max_i++; //определение последнего i
    auto t1= std::chrono::high_resolution_clock::now(); //часы
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
