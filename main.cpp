#include <iostream>
#include <fstream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include <chrono>
#include<math.h>
using namespace std;
class searcher
{
public:
    string word1;
    vector<string> ko;
    int count=0;
    void load_data()
    {
        fstream f("20000.txt");
        if(f.is_open())
        {
            while (getline(f,word1))
            {
                ko.push_back(word1);

            }
            f.close();
        }
        else
        {
            cout << "file not open"<<"\n";
        }
    }
    int linear_search(vector<string> ko3,string word2)
    {
        auto starttime=std::chrono::steady_clock::now();
        int noc=0;
        int index=-1;
        for(int i=0;i<ko3.size();i++)
        {
            noc++;
            if(word2==ko3[i])
            {
                index=i;
                break;
            }
        }
        auto endtime=std::chrono::steady_clock::now();
        double ms=double(std::chrono::duration_cast<std::chrono::microseconds> (endtime-starttime).count());
        cout<<"time linear: "<<ms<<endl;
        cout<<"number of comparisons linear: "<<noc<<endl;
        return index;
    }
    int binary__search(vector<string> ko4,string word2)
    {
        auto starttime=std::chrono::steady_clock::now();
        int index=-1;
        int noc=0;
        int r=ko4.size()-1,l=0,m=0;
        while(l<=r)
        {
            noc++;
            m=(r+l)/2;
            if(word2==ko4[m])
            {
               index=m;
               break;
            }
            else if(word2>ko4[m])
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        auto endtime=std::chrono::steady_clock::now();
        double ms=double(std::chrono::duration_cast<std::chrono::microseconds> (endtime-starttime).count());
        cout<<"time binary: "<<ms<<endl;
        cout<<"number of comparisons binary: "<<noc<<endl;
        return index;
    }
    void testPerformance(int size,int min,int max,int type,int type2)
    {

        vector<string> ko2;
        int m=0;
        int p=0;
        for(int i=0; i<size; i++)
        {
            ko2.push_back(ko[(rand() % (max-min+1)+min)]);
        }
        cout<<++count<<" test"<<endl;
        if(type2==3)
        {
            p=linear_search(ko2,"oooooo");
            cout<<"index: "<<p<<endl;
            if(type==1)
            {
                for(int i=0; i<ko2.size()-1; i++)
                {
                    m=i;
                    for(int j=i; j<ko2.size(); j++)
                    {
                        if(ko2[m]>ko2[j])
                        {
                            m=j;
                        }
                    }
                    swap(ko2[i],ko2[m]);
                }
            }
            else
            {
                for(int i=0; i<ko2.size()-1; i++)
                {
                    for(int j=ko2.size()-1; j>i; j--)
                    {
                        if(ko2[j]<ko2[j-1])
                        {
                            swap(ko2[j],ko2[j-1]);
                        }
                    }
                }

            }
            p=binary__search(ko2,"oooooo");
            cout<<"index: "<<p<<endl;
        }
        else if(type2==4)
        {
            max=ko2.size()-1;
            min=0;
            string word33=ko2[rand() % (max-min+1)+min];
            cout<<"index: "<<linear_search(ko2,word33)<<endl;
            if(type==1)
            {
                for(int i=0; i<ko2.size()-1; i++)
                {
                    m=i;
                    for(int j=i; j<ko2.size(); j++)
                    {
                        if(ko2[m]>ko2[j])
                        {
                            m=j;
                        }
                    }
                    swap(ko2[i],ko2[m]);
                }
            }
            else
            {
                for(int i=0; i<ko2.size()-1; i++)
                {
                    for(int j=ko2.size()-1; j>i; j--)
                    {
                        if(ko2[j]<ko2[j-1])
                        {
                            swap(ko2[j],ko2[j-1]);
                        }
                    }
                }

            }
            cout<<"index: "<<binary__search(ko2,word33)<<endl;
        }
        for(int i=0; i<size; i++)
        {
            ko2.pop_back();
        }
    }
};
int main()
{
    int type,size=0, max=0, min=0,p,m;
    string word2;
    searcher o;
    o.load_data();
    int choice;
    do
    {
           cout<<"[1] linear search "<<endl<<"[2] binary search "<<endl<<"[3] test performance worst "<<endl<<"[4] test performance average"<<endl;
           cin>>choice;
    }while(choice<=0 ||choice>4);
    if(choice==1)
    {
            cout<<"Enter word: ";
            cin>>word2;
            p=o.linear_search(o.ko,word2);
            if(p!=-1)
            {
                cout<<"word index: "<<p<<endl;
            }
            else
            {
                cout<<"word not found in random words: "<<p<<endl;
            }
    }
    else if(choice==2)
    {
        do
        {
            cout<<"which sort(1- selection , 2- bubble): ";
            cin>>type;
        }
        while(type<=0 ||type>2);
        if(type==1)
        {
            for(int i=0; i<o.ko.size()-1; i++)
            {
                m=i;
                for(int j=i; j<o.ko.size(); j++)
                {
                    if(o.ko[m]>o.ko[j])
                    {
                        m=j;
                    }
                }
                swap(o.ko[i],o.ko[m]);
            }
        }
        else
        {
            for(int i=0; i<o.ko.size()-1; i++)
            {
                for(int j=o.ko.size()-1; j>i; j--)
                {
                    if(o.ko[j]<o.ko[j-1])
                    {
                        swap(o.ko[j],o.ko[j-1]);
                    }
                }
            }

        }
        cout<<"Enter word: ";
        cin>>word2;
        p=o.binary__search(o.ko,word2);
        if(p!=-1)
        {
            cout<<"word index: "<<p<<endl;
        }
        else
        {
            cout<<"word not found in random words: "<<p<<endl;
        }
    }
    else if(choice==3)
    {
        do
        {
            cout<<"which sort(1- selection , 2- bubble): ";
            cin>>type;
        }
        while(type<=0 ||type>2);
        for(int j=0; j<10; j++)
        {

            size+=50;
            cout<<"when size: "<<size<<endl;
            min+=100;
            max+=500;
            o.testPerformance(size,min,max,type,3);

        }
        o.count=0;
        size=0;
        max=0;
        min=0;
    }
    else if(choice==4)
    {
        do
        {
            cout<<"which sort(1- selection , 2- bubble): ";
            cin>>type;
        }
        while(type<=0 ||type>2);
        for(int j=0; j<10; j++)
        {
            size+=50;
            cout<<"when size: "<<size<<endl;
            min+=100;
            max+=500;
            o.testPerformance(size,min,max,type,4);
        }
        o.count=0;
        size=0;
        min=0;
        max=0;
    }
    return 0;
}
