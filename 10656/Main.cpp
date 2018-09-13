#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>


using namespace std;
queue<int> xq;
queue<int> yq;

char crossword[60][60];
int num_hint = 0;
int n, m;

void print_plate()
{
	printf("%d\n", num_hint);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			printf("%c", crossword[j][i]);
		}
		printf("\n");
	}

}

int main()
{

	int check = 0;

	scanf(" %d %d", &n, &m);



	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf(" %c", &crossword[j][i]);
		}
	}




	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			check = 0;

			if (crossword[j][i] == '.') // ÇöÀç ºóÄ­
			{
				if (crossword[j - 1][i] == '#' || j == 0) //¿À¸¥ÂÊ °Ë»ç
				{
					if (crossword[j + 1][i] == '.')
					{
						if (crossword[j + 2][i] == '.')
						{
							xq.push(j);
							yq.push(i);

							num_hint++;
							check = 1;
						}
					}
				}

				if (crossword[j][i - 1] == '#' || i == 0)
				{
					if (crossword[j][i + 1] == '.')
					{

						if (crossword[j][i + 2] == '.')
						{

							if (check == 0)
							{

								xq.push(j);
								yq.push(i);
								num_hint++;
							}


						}
					}
				}


			}
			else if (crossword[j][i] == '#')
			{

			}
			else
			{

			}



		}
	}


	printf("%d\n", num_hint);
	while (xq.size())
	{
		printf("%d %d\n", yq.front() + 1, xq.front() + 1);
		xq.pop();
		yq.pop();
	}



	return 0;
}


