#include <omp.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
		
	vector<int>a(200),b(200),c(200,0);
	int count = 0;
	double time = omp_get_wtime();
	
	#pragma omp parallel 
	{
		#pragma omp for nowait
		for(int i=0;i<200;i++)
			a[i] = i;
		
		#pragma omp for nowait
		for(int i=0;i<200;i++)
			b[i] = 200 - i;
	}
	
	#pragma omp parallel for reduction(+: count) schedule(dynamic,400)
	for(int i=0;i<200;i++) {
		c[i] = a[i] + b[i];
		count++;
	}
	

	for(int i=0;i<200;i++)
		printf("%d ",c[i]);
		
	printf("\n \n %d No of times loop executed",count);
	printf("\n Using %d no of threads and %f execution time",omp_get_max_threads(),omp_get_wtime() - time);
	
}
