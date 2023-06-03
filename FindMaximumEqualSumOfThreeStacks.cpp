//https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1
int maxEqualSum(int n1,int n2,int n3,vector<int> &S1,vector<int> &S2,vector<int> &S3)
    {
        int sum1=0,sum2=0,sum3=0;
         for(int i=0;i<n1;i++)
         sum1 += S1[i];
         for(int i=0;i<n2;i++)
         sum2 += S2[i];
         for(int i=0;i<n3;i++)
         sum3 += S3[i];
         int i=0,j=0,k=0;
         while(i<n1 && j<n2 && k<n3)
         {
             if(sum1==sum2 && sum2==sum3)
             return sum1;
             int mi = min(sum1,min(sum2,sum3));
             if(sum1>mi)
             {
                 sum1 -= S1[i];
                 i++;
             }
             if(sum2>mi)
             {
                 sum2 -= S2[j];
                 j++;
             }
             if(sum3>mi)
             {
                 sum3 -= S3[k];
                 k++;
             }
         }
         return 0;
    }
