#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
// CP_Lab_01_CE001
int main()
{
   DIR *files;
   FILE *res;
   struct dirent *dir;
   char folder[100];
   res = fopen("result.txt", "w+");
   printf("Enter folder name: ");
   scanf("%s", folder);
   files = opendir(folder);
   if (files)
   {
      int j = 0, temp;
      int scores[100][2];
      while ((dir = readdir(files)) != NULL)
      {
         int i = 0;
         char f[100], l[20] = {'C', 'P', '_', 'L', 'a', 'b', '_', '0', '1', '_', 'C', 'E'};
         while (dir->d_name[i] != '\0')
         {
            f[i] = dir->d_name[i];
            i++;
         }
         if (f[0] == '.')
         {
            continue;
         }
         if (f[0] == 'C' && f[1] == 'P' && f[2] == '_' && f[3] == 'L' && f[4] == 'a' && f[5] == 'b' && f[6] == '_' && f[7] == '0' && f[8] == '1' && f[9] == '_' && f[10] == 'C' && f[11] == 'E' && f[12] >= 48 && f[12] <= 57 && f[13] >= 48 && f[13] <= 57)
         {
            if (f[14] >= 49 && f[14] <= 57)
            {
               printf("Match found:%s\n", dir->d_name);
               scores[j][1] = 1;
            }
            else if (f[13] >= 49 && f[13] <= 57 && f[14] >= 48 && f[14] <= 57)
            {
               scores[j][1] = 1;
               printf("Match found:%s\n", dir->d_name);
            }
            else
            {
               printf("Match not found:%s\n", dir->d_name);
               scores[j][1] = 0;
            }
         }
         else
         {
            scores[j][1] = 0;
            printf("Match not found:%s\n", dir->d_name);
         }
         i = 0;
         while (f[i] != '.')
         {
            i++;
         }
         scores[j][0] = atoi(&f[i - 3]);
         j++;
      }
      printf("\ncontent to file written succesfully !\n\n");
      printf("Reading files\n");
      for (int k = 0; k < j; k++)
      {
         for (int l = k + 1; l < j; l++)
         {
            if (scores[k][0] > scores[l][0])
            {
               temp = scores[k][0];
               scores[k][0] = scores[l][0];
               scores[l][0] = temp;

               temp = scores[k][1];
               scores[k][1] = scores[l][1];
               scores[l][1] = temp;
            }
         }
      }
      for (int k = 0; k < j; k++)
      {
         printf("roll_no = %d\tscore = %d\n", scores[k][0], scores[k][1]);
         fprintf(res, "roll_no = %d\tscore = %d\n", scores[k][0], scores[k][1]);
      }

      closedir(files);
   }
   fclose(res);
   return (0);
}
