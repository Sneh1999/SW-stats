//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


#include <fstream>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>

using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int histogram(const char filename[], int histogram[10],
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

int histogram(const char filename[], int histogram[10],
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects) {

int value = 0;
int value1=0;
int count = 0 ;
int filelinenumber =1;
int counter=0;
int counter1=0;
int counter2=0;
int counter3=0;
int counter4=0;
int counter5=0;
int counter6 =0;
int counter7 =0;
int counter8=0;
int counter9=0;
rejects = new int[10];
for(int i=0;i<10;i++)
{
  rejects[i]=0;
}

const int maxLineLength = 100;
char line[maxLineLength];
std::ifstream infile;            // declare the file
infile.open(filename);
int index =0;
int fileline =1;
for(int i =0;i<10;i++)
{
  histogram[i]=0;
}

int State = 1;

if (!infile.is_open())
  return -1;

  bool done = false;
  int fileLineNumber = 0;


    while(!infile.eof())
      {
        char a;
         infile.get(a);



       if(a==' '||a=='\t')
       {

       }
      else  if(a=='\n')
       {
         if(value>=minAcceptableID&&value<=maxAcceptableID)
         {

         if(value1>100||value1<0)
         { count++;
           rejects[index]=fileline;
           index++;
         }
        if(value1>=0&&value1<=9)
         {
           counter++;
           histogram[0]=counter;
         }
         else if(value1>=10&&value1<=19)
         {
           counter1++;
           histogram[1]= counter1;
         }
         else if(value1>=20&&value1<=29)
         {
           counter2++;
           histogram[2]=counter2;
         }
         else if(value1>=30&&value1<=39)
         {
           counter3++;
           histogram[3]=counter3;
         }
         else if(value1>=40&&value1<=49)
         {
           counter4++;
           histogram[4]=counter4;
         }
         else if(value1>=50&&value1<=59)
         {
           counter5++;
           histogram[5]=counter5;
         }
         else if(value1>=60&&value1<=69)
         {
           counter6++;

           histogram[6]=counter6;
         }
         else if(value1>=70&&value1<=79)
         {
           counter7++;

           histogram[7]=counter7;
         }
         else if(value1>=80&&value1<=89)
         {
           counter8++;

           histogram[8]=counter8;
         }
         else if(value1>=90&&value1<=100)
         {
           counter9++;

           histogram[9]=counter9;
         }
       }




         if(count>10)
         return -1;

         State = 1;
         value1=0;
         value = 0;
         fileline++;





       }

       else if(a=='\0')
       {

         if(value1>100||value1<0)
         count++;


         if(count>10)
         return -1;
         if(count>10)
         return -1;
         State = 1;
         value1=0;
         value = 0;


       }



       else
       {
         switch(State)
         {

          case 1:
           switch(a)
           {

            default:

            value*= 10;
            unsigned int currentintvalue = a - '0';
            value += currentintvalue;
            State = 2;
            break;
             }
          break;

          case 2:
          switch(a)
          {
            case ',':
              State = 3;
              if(value<minAcceptableID)
              count++;
              if(count>10)
              return -1;
              if(value>maxAcceptableID)
              count++;
              if(value>maxAcceptableID||value<minAcceptableID)
              {
                rejects[index]=fileline;
                index++;
              }
              if(count>10)
              return -1;
              break;
           default:
          if((a>='0'&&a<='9'))

          {
            value*= 10;
           unsigned int currentintvalue = a - '0';
           value += currentintvalue;
           State = 2;

           }

         else
         return -1;
           break;
         }
         break;

        case 3:

        switch(a)
        {


          default:
          if((a>='0'&&a<='9'))

          {
            value1*= 10;
           unsigned int currentintvalue1 = a - '0';
           value1 += currentintvalue1;
           State = 3;

           }

         else
         return -1;
           break;
         }
     break;
     }
       }


}
if(value>=minAcceptableID&&value<=maxAcceptableID)
{
if(value1>100||value1<0)
{
  count++;
  rejects[index]=fileline;
  fileline++;
}
if(value1>=0&&value1<=9)
{
  counter++;
  histogram[0]=counter;
}
else if(value1>=10&&value1<=19)
{
  counter1++;
  histogram[1]= counter1;
}
else if(value1>=20&&value1<=29)
{
  counter2++;
  histogram[2]=counter2;
}
else if(value1>=30&&value1<=39)
{
  counter3++;
  histogram[3]=counter3;
}
else if(value1>=40&&value1<=49)
{
  counter4++;
  histogram[4]=counter4;
}
else if(value1>=50&&value1<=59)
{
  counter5++;
  histogram[5]=counter5;
}
else if(value1>=60&&value1<=69)
{
  counter6++;

  histogram[6]=counter6;
}
else if(value1>=70&&value1<=79)
{
  counter7++;

  histogram[7]=counter7;
}
else if(value1>=80&&value1<=89)
{
  counter8++;

  histogram[8]=counter8;
}
else if(value1>=90&&value1<=100)
{
  counter9++;

  histogram[9]=counter9;
}
}

return count;
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else
  cout<<retCode<<endl;


 for(int i=0;i<numBuckets;i++)
  {
    cout<<i<<buckets[i]<<endl;
  }
  for(int i =0;i<10;i++)
  {
    cout<<rejectedRecords[i];
  }
    return 0;
}

#endif
