#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
  Description: Make histogram from input data file

  Author: Anyes Taffard
*/

const int debug         = 0;     //1: debug mode
const int NENTRIES      = 1000;  //Number of entries 
const int NBINS         = 30;    //Stores up to 30 bins
const int MAXLINELENGTH = 80;    //Maximum line length for printout

/* 
   Fill an array from a data file containing one column of read numbers
   Return the number of data read
*/
int readData(char fileName[], int aSize, double array[]);

/* 
   Fill a histogram using the data provided
   Return the bin contents -> bins[]
   and the values of the bin centers -> binCenters[]
*/
void fillHistogram(int bins[], double binCenters[], int nBins, 
		   double data[], int nData);

/*
  Print some statistics on the input array
  Mean
  Variance
  Sigma
*/
void printStats(double array[], int n);

/*
  Prints on screen a histogram using one bin per line
  and increasing bin coordinates
*/
void printHistogram(int bins[], int nBins, int maxLineLength);

/*
  Save Histogram content to a file for gnuplot
  Format BinCenter BinContent
*/
void saveHistogram(char fileName[], int bins[], double binCenters[], int nBins);

//
// Helper functions
//
//Min value of input array
double findMinimum(double array[], int n);
//Max value of input array
double findMaximum(double array[], int n);

//Moment of input array
// 1st moment: mean
// 2nd moment: variance
double getMoment(int k, double array[], int n);


//__________________________________________________
//__________________________________________________
int main(){ 
 
  double  rawData[NENTRIES];
  int     bins[NBINS];   
  double  binCenters[NBINS];   
  int     nRead=0;

  //Read data into array
  nRead = readData("histogram.dat", NENTRIES, rawData);
  if(nRead==0){
    printf("No data read\n");
    return -1;
  }

  //Fill histogram
  fillHistogram(bins,binCenters,NBINS,rawData,nRead);

  //Print histogram with a maximum line length of 80 to screen
  printHistogram(bins,NBINS,MAXLINELENGTH);

  //Print histogram statistics
  printStats(rawData, nRead);

  //Save histogram to file for gnuplot
  saveHistogram("histogram_ouput.dat",bins,binCenters,NBINS);

  return 0;
}

//__________________________________________________
int readData(char fileName[], int aSize,
	     double array[])
{
  int nRead = 0;

  FILE* fPtr;
  fPtr = fopen(fileName,"r"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);

  while( !feof(fPtr) && nRead<aSize ){
    fscanf(fPtr,"%lf ",&array[nRead++]);
  }
  
  printf("Read in %i numbers \n",nRead);
  fclose(fPtr);
  
  return nRead;
}
//__________________________________________________
void fillHistogram(int bins[], double binCenters[], int nBins, 
		   double data[], int nData)
{
  printf("nBins %i nData %i\n",nBins, nData);
  
  //Find range of input to determine lowest/highest bin boundary
  double minValue = findMinimum(data,nData);
  double maxValue = findMaximum(data,nData);
  printf("Range of values is [%lf, %lf] \n",
	 minValue,maxValue);
  
  //Round the min/max to closest lower/upper value
  minValue  = floor(minValue); //round down
  maxValue  = ceil(maxValue);  //round up
  double binWidth = (maxValue-minValue+1)/nBins;
  printf("Histogram range is [%lf, %lf] bin Width %lf \n",
	 minValue,maxValue,binWidth);
  
  //Zero the array that will contains the bin content
  memset(bins,0,sizeof(bins[0])*nBins);              //fast way to reset an array
  memset(binCenters,0,sizeof(binCenters[0])*nBins); 
  //Alternative slower way
  /*
  for(int i=0; i<nBins; i++){
    bins[i]=0;
    binCenters[i]=0;
  }
  */

  //Loop over the bins and fill the binCenter values
  for(int i=0; i<nBins; i++){
    binCenters[i] =  (minValue + binWidth/2.0)+(i*binWidth);
  }

  //Loop over the data array and fill the bin array
  int nFilled=0;
  for(int i=0; i<nData; i++){
    //find the bin where the data point belong
    int bin = (int) floor( (data[i]-minValue)/(maxValue-minValue) * nBins );
    if(bin >=0 && bin<nBins){
      bins[bin]++; //increment the bin content
      nFilled++;
    }
  }
  printf("Filled %d bins histogram with %d of %d data entries\n",
	 nBins,nFilled,nData);

}
//__________________________________________________
void printHistogram(int bins[], int nBins, int maxLineLength)
{

  //Find the bin with the max
  //Cannot re-use findMaximum since input array of int here !
  double maxBinContent = bins[0];
  for(int i=0; i<nBins; i++)
    if(bins[i]>maxBinContent) maxBinContent = bins[i];
  
  printf("Maximum bin content is %lf\n",maxBinContent);

  //Calculate scale factor so that max bin matches the max line length
  double scaleFactor  = maxLineLength/maxBinContent;
  printf("Scaling bin content by %f\n",scaleFactor);

  //Print each bins
  for(int i=0; i<nBins; i++){
    int lineLength = round(bins[i]*scaleFactor);
    //display the bin content
    for(int j=0; j<lineLength; j++){
      printf("o");
    }
    printf("\n"); //move to next line
  }

}
//__________________________________________________
void saveHistogram(char fileName[], int bins[], double binCenters[], int nBins)
{
  FILE* fPtr;
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);

  for(int i=0; i<nBins; i++){
    fprintf(fPtr,"%lf %i \n",binCenters[i],bins[i]);
  }
  
  fclose(fPtr);
}

//__________________________________________________
void printStats(double array[], int n)
{
  double mu1 = getMoment(1,array,n);
  double mu2 = getMoment(2,array,n);
  double sigma = sqrt(mu2-mu1*mu1);
  printf("mean = %lf, sigma = %lf\n",mu1, sigma);
}
//__________________________________________________
double findMinimum(double array[], int n)
{
  assert(n>0);
  double min = array[0];
  for(int i = 1; i < n; i++) {
    if(array[i] < min) {
      min = array[i];
    }
  }
  return min;
}
//__________________________________________________
double findMaximum(double array[], int n)
{
  assert(n>0);
  double max = array[0];
  for(int i = 1; i < n; i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }
  return max;
}
//__________________________________________________
double getMoment(int k, double array[], int n)
{
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += pow(array[i],k);
  }
  return sum/n;
}
