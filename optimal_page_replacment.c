#include <stdio.h>
int main()
{
    int frm_no, pg_no, frm[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos,
        max, faults = 0;
    printf("No. of frm: ");
    scanf("%d", &frm_no);

    printf("Enter number of pages: ");
    scanf("%d", &pg_no);

    printf("Enter page reference string: ");

    for (i = 0; i < pg_no; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < frm_no; ++i)
    {
        frm[i] = -1;
    }

    for (i = 0; i < pg_no; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < frm_no; ++j)
        {
            if (frm[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < frm_no; ++j)
            {
                if (frm[j] == -1)
                {
                    faults++;
                    frm[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < frm_no; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < pg_no; ++k)
                {
                    if (frm[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < frm_no; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < frm_no; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frm[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < frm_no; ++j)
        {
            printf("%d\t", frm[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}