#include <stdio.h>
#include <stdlib.h>

int findTriplets(int *array, int n, int k, int targetSum, int *used, int *triplets);

int main()
{
   int n = 0, k = 0, sum = 0, targetSum = 0;
   scanf("%d", &n);
   // Optimization check
   if (n % 3 != 0)
   {
      printf("It is impossible to solve this.\n");
      return 0;
   }
   else
   {
      k = n / 3;
   }
   int *array = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; ++i)
   {
      scanf("%d", (array + i));
   }
   // int array[15] = {2, 5, 3, 5, 4, 1, 2, 6, 2, 6, 2, 2};
   for (int i = 0; i < n; ++i)
   {
      sum += array[i];
   }
   // Optimization check
   if (sum % k != 0)
   {
      printf("It is impossible to solve this.\n");
      free(array);
      return 0;
   }
   else
   {
      targetSum = sum / k;
   }
   // int used[15] = {0};
   // int triplets[15] = {0};
   int *used = (int *)calloc(n, sizeof(int)); // Dynamic approach
   int *triplets = (int *)calloc(n, sizeof(int));

   int result = findTriplets(array, n, k, targetSum, used, triplets);

   printf("Target sum: %d\nK: %d\n", targetSum, k);
   if (result)
   {
      printf("It is possible to split the array into sub-arrays of 3 with equal sums:\n");
      for (int i = 0; i < k; i++)
      {
         printf("%d %d %d\n", array[triplets[i * 3]], array[triplets[i * 3 + 1]], array[triplets[i * 3 + 2]]); // Values
         // printf("%d %d %d\n", triplets[i * 3], triplets[i * 3 + 1], triplets[i * 3 + 2]); // Indexes
      }
   }
   else
   {
      printf("It is impossible to split the array into sub-arrays of 3 with equal sums.\n");
   }

   free(used);
   free(triplets);
   free(array);
}

int findTriplets(int *array, int n, int k, int targetSum, int *used, int *triplets)
{
   if (k == 0)
   {
      // All groups have been found, check if all numbers were used
      for (int i = 0; i < n; i++)
      {
         if (!used[i])
         {
            return 0;
         }
      }
      return 1;
   }
   for (int i = 0; i < n; i++)
   {
      if (!used[i]) // Check if the element has been used
      {
         used[i] = 1;
         int sum = array[i];
         for (int j = i + 1; j < n; j++)
         {
            if (!used[j])
            {
               used[j] = 1;
               sum += array[j];
               for (int l = j + 1; l < n; l++)
               {
                  if (!used[l])
                  {
                     used[l] = 1;
                     sum += array[l];
                     if (sum == targetSum)
                     {
                        // Found a group of triplets, continue search for remaining groups
                        triplets[(k - 1) * 3] = i;
                        triplets[(k - 1) * 3 + 1] = j;
                        triplets[(k - 1) * 3 + 2] = l;
                        int result = findTriplets(array, n, k - 1, targetSum, used, triplets);
                        if (result)
                        {
                           return 1;
                        }
                     }
                     used[l] = 0;
                     sum -= array[l];
                  }
               }
               used[j] = 0;
               sum -= array[j];
            }
         }
         used[i] = 0;
      }
   }
   return 0;
}
