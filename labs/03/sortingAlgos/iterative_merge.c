// adapted from:        http://www.cosc.canterbury.ac.nz/tad.takaoka/cosc229/imerge.c

#include <stdio.h>
#include <math.h>
int i,n,t,k,q;
int a[10000000],b[10000000];
int merge(l,r,u)
  int l,r,u;
{ int i,j,k;
  i=l; j=r; k=l;
  while (i<r && j<u) { 
    if (a[i]<=a[j]) {b[k]=a[i]; i++;} 
    else {b[k]=a[j]; j++;}
    k++;
  }
  while (i<r) { 
    b[k]=a[i]; i++; k++;
  }
  while (j<u) { 
    b[k]=a[j]; j++; k++;
  }
  for (k=l; k<u; k++) { 
    a[k]=b[k]; 
  }
}
sort()
{ int k,u;
  k=1;
  while (k<n) {
    i=1;
    while (i+k<=n) {
      u=i+k*2;
      if (u>n) u=n+1;
      merge(i,i+k,u);
      i=i+k*2;
    }
    k=k*2;
  }
}
main()
{
    n = 100;
    for (i=1;i<=n;i++) a[i]=n-i;
    sort();
  
}
