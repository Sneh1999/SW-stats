//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include<float.h>
#include <stdlib.h>
#include<math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn) {


        if(windowSize==0)
				{
					return -2;
				}
				if(windowSize>=size)
				{
					return 2;
				}

				if(windowSize<0)
				{
					return -1;
				}
				if(windowSize==1)
				{
					return 4;
				}

			   SWMinimum(dataset,size,currentSample,windowSize,min);

				 SWAverage(dataset,size,currentSample,windowSize,avg);

				 SWMaximum(dataset,size,currentSample,windowSize,max);

				 SWSmplStdDev(dataset,size,currentSample,windowSize,smplSD);

				  SWMedian(dataset,size,currentSample,windowSize,mdn);



	return 0;
}


int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum) {
float min;
int i;
int j;
float a[size+windowSize-1];
					for(j=0;j<windowSize-1;j++)
					{
					  a[j]=dataset[0];
					}

					for(i=windowSize-1,j=0;j<size ;i++,j++)
					{
					  a[i]=dataset[j];
					}

					min = FLT_MAX;


          int d = (currentSample+(windowSize-1));

					for(i= d ;i>=currentSample;i--)
	 			 {
	 					 if(min>a[i])
	 					 {
	 						 min = a[i];	 					 }
	 			 }


  minimum = min;
 return 0;


				}

int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average) {


					float sum=0;
					float avg;


					int i;
					int j;


					float a[size + windowSize -1];
										for(j=0;j<windowSize-1;j++)
										{
										  a[j]=dataset[0];
										}

										for(i=windowSize-1,j=0;j<size ;i++,j++)
										{
										  a[i]=dataset[j];
										}




					          int d = (currentSample+(windowSize-1));

										for(i= d ;i>=currentSample;i--)
						 			 {
						 					 sum+=a[i];
						 			 }
               avg = sum/windowSize;
							 average = avg;
							 return 0;
						 }

int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum) {

					float max;

					 max = -FLT_MAX;

 					int i;
 					int j;


 					float a[100];
 										for(j=0;j<windowSize-1;j++)
 										{
 										  a[j]=dataset[0];
 										}

 										for(i=windowSize-1,j=0;j<size ;i++,j++)
 										{
 										  a[i]=dataset[j];
 										}




 					          int d = (currentSample+(windowSize-1));

 										for(i= d ;i>=currentSample;i--)
 						 			 {
 						 					 if(max<a[i])
 						 					 {
 						 						 max= a[i];
 						 					 }
 						 			 }

									 maximum = max;

									 return 0;

}

int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev) {


			 double sum1=0;
			 float sd;
      float avg;
			float sum =0;
			 int k = windowSize-1;

			 int i;
			 int j;


			 float a[100];
								 for(j=0;j<windowSize-1;j++)
								 {
									 a[j]=dataset[0];
								 }

								 for(i=windowSize-1,j=0;j<size ;i++,j++)
								 {
									 a[i]=dataset[j];
								 }


							 if(currentSample==0)
							 {
								 smplStdDev =0;
								 return 0;
							 }
             int d = (currentSample+(windowSize-1));
							 float b[windowSize];

						 for(i=currentSample + (windowSize-1),j=0;i>=d-(windowSize-1);i--,j++)
						 {
							 b[j]=a[i];
						 }
							 for(i=0;i<windowSize;i++)
							 {
								 sum+= b[i];
							 }

							 avg = sum/windowSize;

								 for(i= 0;i<windowSize;i++)
								 {
									 sum1+=(b[i]-avg)*(b[i]-avg);
									 }
									 smplStdDev = sqrt(sum1/k);

								  return 0;
}

int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median)
			 {

				 int p = size + (windowSize-1);
			   float a[p];
				 int i;
				 int j;
				 int s =  windowSize;
				 float mdn;
                  for(j=0;j<windowSize-1;j++)
									 {
										 a[j]=dataset[0];
									 }

									 for(i=windowSize-1,j=0;j<size ;i++,j++)
									 {
										 a[i]=dataset[j];
									 }

								if(currentSample==0)
								{
								   median = a[0];
									 return 0;
								}

								  int d = (currentSample+(windowSize-1));
									float b[windowSize];

								for(i=currentSample + (windowSize-1),j=0;i>=d-(windowSize-1);i--,j++)
								{
									b[j]=a[i];
								}


      for(i=0;i<windowSize;i++)
			   {

			     for(j=i+1;j<windowSize;j++)
			     {
			       if(b[i]>=b[j])
			       {
                float help;
			          help = b[i];
			          b[i] = b[j];
			          b[j] = help;


			       }
			     }

			   }

			     int k = windowSize/2;

			     if(size%2==0)
			     {
			       median = (b[k-1] + b[k])/2;
			     }
			     if(!(s%2==0))
			     {
			       median = b[k];
			     }


			 return 0;


}



//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  int size = 5;
  float dataset[] = {1,2,3,4,5};
  int windowSize = 2;
  int currentSample = 0;
  float min=0;
  float avg=0;
  float max=0;
  float smplSD=0;
  float median=0;

  cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }


    ++currentSample;
  }
  return 0;
}

#endif
