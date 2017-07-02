#include<stdio.h>
#include<stdlib.h>
void CheapestPriceBase(int number);/* Find Cheapest Price Base */
int price[36];  /* 0~9 represent numbrer ,11~35 represent alphebat*/
int testPrice[35]; /* Price base on each base */  /* Base : 2~ 36 */
int main(){
    int nCase,i,testCase,n,j;
    scanf("%d",&nCase);
    for(j=0;j<nCase;j++){
        for(i=0;i<36;i++)scanf("%d",&price[i]);/* read price table */
        scanf("%d",&testCase);
        printf("Case %d:\n",j+1);
        for(i=1;i<=testCase;i++){
            scanf("%d",&n);
            CheapestPriceBase(n);
        }
        if(j<nCase-1)printf("\n");
    }
return 0;
}
void CheapestPriceBase(int n){
    /* Calculate  price in each base  and find mininum*/
    int i,base,test,cheapest;
    cheapest = 2000000001;
    for(i=2;i<=36;i++){
        test = n;
        testPrice[i-2]=0;/* Initialization */
        for(base=i;test>0;test/=base)/* Calculate Price */
            testPrice[i-2] += price[test%base];
        if(cheapest>testPrice[i-2]) /* Find Cheapest*/
            cheapest=testPrice[i-2];
    }
    /* Check if each price is cheapest and print it*/
    printf("Cheapest base(s) for number %d:",n);
    for(i=0;i<35;i++)
        if(cheapest==testPrice[i])printf(" %d",i+2);
    printf("\n");
}

