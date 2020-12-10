#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include "stdio.h"
int main(int argc,char *argv[])
{
    int n;
    FILE *file;
    if ((file=fopen(argv[1],"r"))==NULL) {
        std::cout << "Error opening file " << argv[1];
        return 0;
    }
    fscanf(file,"%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        fscanf(file,"%d",&a[i]);
    }
    fclose(file);//закончился скан данных a[n]- массив элементов,n- кол-во элементов
    int i=1,p=1,flag=1,o=0;
    int *s;
    s=new int[n];
    s[0]=1;
    while(flag)
    {
        flag=0;
        if (p*2<=n)
        {
            s[i]=p*2;
            i++;
            o++;
        }
        if (p*3<=n)
        {
            s[i]=p*3;
            i++;
            o++;
        }
        if (p*6<=n) {
            p *= 6;
            s[i] = p;
            i++;
            flag += 1;
            o++;
        }
    }
    auto t1= std::chrono::high_resolution_clock::now(); //часы
    for (int i=o;i>=0;i--) {
    int step=s[i];
        for (int l = 0; l < step; l++) {
        int flags = 1;
            while (flags) {
            flags = 1;
                for (int j = l; j < n - step; j+=step) {
                    if (a[j] > a[j + step]) {
                        a[j] ^= a[j + step] ^= a[j] ^= a[j + step];
                        flags++;
                    }
                }
            flags--;
            }
        }
    }
    auto t2=std::chrono::high_resolution_clock::now();//часы
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);//часы
    std::cout<<n<<"\r";
    std::cout<<duration.count()<<"\r";//часы
    for (int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
    return 0;
}
