#include <stdio.h>
#include <algorithm>
using namespace std;
int u[3001],v[3001];
struct edge
{
	int x1, x2, y1, y2;
	inline bool operator < (const edge &temp) const
	{
		return x1 < temp.x1 || (x1 == temp.x1 && y1 < temp.y1) || (x1 == temp.x1 && y1 == temp.y1 && x2 < temp.x2) || (x1 == temp.x1 && y1 == temp.y1 && x2 == temp.x2 && y2 < temp.y2);
	}
}arr[3001];
int ccw(edge fir, int x, int y)
{
	int cou;

	cou = (fir.x1*fir.y2 + fir.x2*y + x*fir.y1) - (fir.x2*fir.y1 + x*fir.y2 + fir.x1*y);
	if (cou < 0)
		return -1;
	else if (cou > 0)
		return 1;
	else
		return 0;
}
int boxcheck(edge fir, edge sec)
{
	if (max(fir.x1, fir.x2) < min(sec.x1, sec.x2) || max(sec.x1, sec.x2) < min(fir.x1, fir.x2) || max(fir.y1, fir.y2) < min(sec.y1, sec.y2) || max(sec.y1, sec.y2) < min(fir.y1, fir.y2))
		return 0;
	else
		return 1;
}
int main()
{
	int n, i, j, k, x, y,fir,sec,a,b,thr,maxa,group;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		u[i] = i;
        v[i]=1;
		scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
		if (arr[i].x1 > arr[i].x2)
		{
			swap(arr[i].x1, arr[i].x2);
			swap(arr[i].y1, arr[i].y2);
		}
		else if (arr[i].x1 == arr[i].x2 && arr[i].y1 > arr[i].y2)
		{
			swap(arr[i].x1, arr[i].x2);
			swap(arr[i].y1, arr[i].y2);
		}
	}
	sort(arr + 1, arr + n + 1);

	for (i = 1; i <n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			 fir = ccw(arr[i], arr[j].x1, arr[j].y1)*ccw(arr[i], arr[j].x2, arr[j].y2);
			 sec = ccw(arr[j], arr[i].x1, arr[i].y1)*ccw(arr[j], arr[i].x2, arr[i].y2);
			 if (fir <= 0 && sec <= 0)
			 {
				 thr = boxcheck(arr[i], arr[j]);
				 if (thr == 1)
				 {
					a = u[i];
					while (a != u[a])
						a = u[a];
					b = u[j];
					while (b != u[b])
						b = u[b];
					if (a < b)
					{
						u[b] = a;
						v[a]+=v[b];
                        v[b]=0;
					}
					else if(a>b)
					{
						u[a] = b;
						v[b]+=v[a];
                        v[a]=0;
					}
				 }
			 }
		}
	}
	group = 0;
	maxa = 0;
	for (i = 1; i <= n; i++)
	{
		if (u[i] == i)
		{
			group++;
			maxa = max(v[i], maxa);
		}
	}
	printf("%d\n%d", group, maxa);
	return 0;
}