#include<bits/stdc++.h>
using namespace std;
#define N 30010
#define A 1000010
//#define BLOCK 174
#define M 200010

int answer;
struct query
{
int l,r,ind;
}Q[M];
int ans[M];
int a[N];
int cnt[A];
int BLOCK;
bool cmp(query f,query s)
{
    if((f.l/BLOCK)!=(s.l/BLOCK))
    return (f.l/BLOCK)<(s.l/BLOCK);
    else
    return f.r<s.r;
}
int main()
{
    int n,q;
    cin>>n;
    BLOCK=(int)sqrt(n);
    for(int i=0;i<n;i++)
    cin>>a[i];

     cin>>q;
     for(int i=0;i<q;i++)
     {
        cin>>Q[i].l>>Q[i].r;
        Q[i].ind=i;
        Q[i].l--;
        Q[i].r--;
      }
        sort(Q,Q+q,cmp);
        int cl=0,cr=-1;
        for(int i=0;i<q;i++)
        {
        int l=Q[i].l,r=Q[i].r;
       
        while(cl>l)
        {
            cl--;
            cnt[a[cl]]++;
            if(cnt[a[cl]]==1)
            answer++;
        }
        while(cr<r)
        {
            cr++;
            cnt[a[cr]]++;
            if(cnt[a[cr]]==1)
            answer++;
        }
        while(cl<l)
        {
            cnt[a[cl]]--;
            if(cnt[a[cl]]==0)
            answer--;
            cl++;
        }
        while(cr>r)
        {
            cnt[a[cr]]--;
            if(cnt[a[cr]]==0)
            answer--;
            cr--;
        }
            ans[Q[i].ind]=answer;
        }

        for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;

}
