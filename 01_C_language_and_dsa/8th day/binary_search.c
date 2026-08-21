#include<stdio.h>
 
int main()
{
    int arr[100];
    int n,key;
    int low,mid,high;
    int found=0;

    printf("============================================\n");
    printf("           Binary Search                       \n");
    printf("=============================================\n");

    printf("enter the no of element  :");
    scanf("%d",&n);

    printf("enter the element in arrray in sorting order :\n");
    for(int i=0;i<n;i++)
    {
        printf("element : %d\n",i+1);
        scanf("%d\n",&arr[i]);
    }
    printf("enter element to search : \n");
    scanf("%d",&key);
    low=0;
    high=n-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            found=1;
            break;
        }
        else if(key<arr[mid])
        {
            high =mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(found)
    {
        printf("\nelement %d found at index %d",key,mid);
    }
    else
    {
        printf("\n element %d not found ",key);
    }
}