//Name: Jose Reyes
//Date: May 19th, 2016
//
//CMPS 335
//Exam framework.
//Name this program lab8.cpp.
//Write code to perform a unit-test on a function.
//Function name: bodyShapeIndex().
//
//SBSI is can be a measure of health for some people.
//
//Range of data is from the following source...
//http://journals.plos.org/plosone/article?id=10.1371/journal.pone.0144639
//
//The SBSI formula has four input values.
//
//	                                      Average     SD
//	                                      ---------   --------
//	. body surface area (cm^2)            18074.000   2168.000
//	. vertical trunk circumference (cm)     174.924     11.908
//	. height (cm)                           167.726     10.102
//	. waist circumference (cm)               92.190     13.229
//
//The formula is:
//
//   (height^(7/4)) * (waistCircumference^(5/6))
//   --------------------------------------------
//   bodySurfaceArea * verticalTrunkCircumference
//
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

//Define floating-point standard
typedef double Flt;

//Test data

const double testdata[] = {
157, 	79, 	163, 	15906, 	0.102431072,
157, 	79, 	163, 	18074, 	0.102144331,
157, 	79, 	163, 	20242, 	0.080489509,
157, 	79, 	175, 	15906, 	0.083407227,
157, 	79, 	175, 	18074, 	0.083963005,
157, 	79, 	175, 	20242, 	0.074970228,
157, 	79, 	187, 	15906, 	0.089284838,
157, 	79, 	187, 	18074, 	0.078575005,
157, 	79, 	187, 	20242, 	0.070259304,
157, 	92, 	163, 	15906, 	0.116196238,
157, 	92, 	163, 	18074, 	0.102346352,
157, 	92, 	163, 	20242, 	0.091384644,
157, 	92, 	175, 	15906, 	0.118321639,
157, 	92, 	175, 	18074, 	0.105328316,
157, 	92, 	175, 	20242, 	0.085118268,
157, 	92, 	187, 	15906, 	0.101370517,
157, 	92, 	187, 	18074, 	0.089210991,
157, 	92, 	187, 	20242, 	0.079656133,
157, 	105, 	163, 	15906, 	0.129837524,
157, 	105, 	163, 	18074, 	0.114263343,
157, 	105, 	163, 	20242, 	0.102025277,
157, 	105, 	175, 	15906, 	0.120934380,
157, 	105, 	175, 	18074, 	0.106428142,
157, 	105, 	175, 	20242, 	0.095029258,
157, 	105, 	187, 	15906, 	0.113173885,
157, 	105, 	187, 	18074, 	0.099598529,
157, 	105, 	187, 	20242, 	0.088931124,
167, 	79, 	163, 	15906, 	0.114119839,
167, 	79, 	163, 	18074, 	0.100431015,
167, 	79, 	163, 	20242, 	0.089674447,
167, 	79, 	175, 	15906, 	0.106294479,
167, 	79, 	175, 	18074, 	0.093544317,
167, 	79, 	175, 	20242, 	0.083525342,
167, 	79, 	187, 	15906, 	0.099473443,
167, 	79, 	187, 	18074, 	0.087541473,
167, 	79, 	187, 	20242, 	0.078165427,
167, 	92, 	163, 	15906, 	0.129567207,
167, 	92, 	163, 	18074, 	0.114025451,
167, 	92, 	163, 	20242, 	0.101812864,
167, 	92, 	175, 	15906, 	0.120682599,
167, 	92, 	175, 	18074, 	0.106206563,
167, 	92, 	175, 	20242, 	0.094831411,
167, 	92, 	187, 	15906, 	0.112938261,
167, 	92, 	187, 	18074, 	0.099391168,
167, 	92, 	187, 	20242, 	0.088745973,
167, 	105, 	163, 	15906, 	0.144653737,
167, 	105, 	163, 	18074, 	0.127302332,
167, 	105, 	163, 	20242, 	0.113667737,
167, 	105, 	175, 	15906, 	0.134734624,
167, 	105, 	175, 	18074, 	0.118573029,
167, 	105, 	175, 	20242, 	0.105873378,
167, 	105, 	187, 	15906, 	0.126088552,
167, 	105, 	187, 	18074, 	0.110964064,
167, 	105, 	187, 	20242, 	0.099079365,
177, 	79, 	163, 	15906, 	0.126345722,
177, 	79, 	163, 	18074, 	0.111190387,
177, 	79, 	163, 	20242, 	0.099281448,
177, 	79, 	175, 	15906, 	0.117682016,
177, 	79, 	175, 	18074, 	0.103565904,
177, 	79, 	175, 	20242, 	0.092473577,
177, 	79, 	187, 	15906, 	0.110130229,
177, 	79, 	187, 	18074, 	0.096919963,
177, 	79, 	187, 	20242, 	0.086539444,
177, 	92, 	163, 	15906, 	0.143447997,
177, 	92, 	163, 	18074, 	0.126241222,
177, 	92, 	163, 	20242, 	0.112720277,
177, 	92, 	175, 	15906, 	0.133611563,
177, 	92, 	175, 	18074, 	0.117584681,
177, 	92, 	175, 	20242, 	0.104990887,
177, 	92, 	187, 	15906, 	0.125037559,
177, 	92, 	187, 	18074, 	0.110039140,
177, 	92, 	187, 	20242, 	0.098253503,
177, 	105, 	163, 	15906, 	0.160150777,
177, 	105, 	163, 	18074, 	0.140940481,
177, 	105, 	163, 	20242, 	0.125845186,
177, 	105, 	175, 	15906, 	0.139169009,
177, 	105, 	175, 	18074, 	0.121275991,
177, 	105, 	175, 	20242, 	0.117215802,
177, 	105, 	187, 	15906, 	0.139596666,
177, 	105, 	187, 	18074, 	0.122851863,
177, 	105, 	187, 	20242, 	0.109693932};


//Structure to hold components of the SBSI furmula.
//h    height;
//wc   waist circumference;
//bsa  body surface area;
//vtc  vertical trunk circumference;
struct SBSI {
	Flt h;
	Flt wc;
	Flt bsa;
	Flt vtc;
};

Flt bodyShapeIndex(SBSI *sbsi);

int main(int argc, char *argv[])
{
	SBSI sbsi;
	//
	cout << "cs335 Surface-based body shape index calculator.\n";
	cout << endl;
	//Enter all 4 values via command line
    if (argc > 4) {
        sbsi.h = atof(argv[1]);
        sbsi.wc = atof(argv[2]); 
        sbsi.bsa = atof(argv[3]);
        sbsi.vtc = atof(argv[4]);
        printf("H, WC, BSA, and VTC\n");
        printf("%.2f %.2f %.2f %.2f\n", sbsi.h, sbsi.wc, sbsi.bsa, sbsi.vtc);
        Flt val = bodyShapeIndex(&sbsi);
		cout << "Thanks.\n";
		cout << "Your SBSI index is: " << val << endl;
    //Unit Test
    } else if (argc >= 2 && argc < 4) {
    	printf("Unit Test for SBSI Function\n");
    	double arr[5] = {};
    	int count = 0;
    	if (argc < 3) {
    		printf("No tolerance value was provided!\n");
    		return 1;
    	}
    	double tolerance = atof(argv[2]);
    	printf("Tolerance: %.3f\n\n", tolerance);
    	//
		cout << "H" << setw(6) << "WC" << setw(6) << "BSA" << setw(7) << "VTC";
		cout << setw(6) << "SBSI" << setw(15) << "Function" << endl;
		cout << "---" << setw(5) << "---" << setw(7) << "-----";
		cout << setw(5) << "---" << setw(11) << "---------";
		cout << setw(11) << "---------" << endl;
		//
    	for (int j = 0; j < 81; j++) {
	    	for (int i = 0; i < 5; i++) {
	    		arr[i] = testdata[j*5+i];
			}
			sbsi.h = arr[0];
			sbsi.wc = arr[1];
			sbsi.bsa = arr[3];
			sbsi.vtc = arr[2];
			Flt val = bodyShapeIndex(&sbsi);
			if (sbsi.wc < 100) {
	    		printf("%.0f  %.0f   %.0f  %.0f  %.7f  %.7f\n", 
	    			sbsi.h, sbsi.wc, sbsi.bsa, sbsi.vtc, arr[4], val);
	    	} else {
	    		printf("%.0f  %.0f  %.0f  %.0f  %.7f  %.7f\n", 
	    			sbsi.h, sbsi.wc, sbsi.bsa, sbsi.vtc, arr[4], val);
	    	}
	    	double diff = arr[4] - val;
	    	diff = fabs(diff);
	    	if (diff > tolerance) {
	    		count++;
	    	}
	    }
	    printf("\nBad Element Count: %d\nUnit Test Complete\n", count);
   	//Enter all 4 values manually
    } else {
        cout << "Input your 4 values now.\n";
        cout << " . height\n";
        cout << " . waist circumference\n";
        cout << " . body surface area\n";
        cout << " . vertical trunk circumference\n";
        cin >> sbsi.h >> sbsi.wc >> sbsi.bsa >> sbsi.vtc;
		Flt val = bodyShapeIndex(&sbsi);
		cout << "Thanks.\n";
		cout << "Your SBSI index is: " << val << endl;
    }
	cout << endl;
	return 0;
}

//------------------------------------------
//Do not modify this function on the exam.
//------------------------------------------
Flt bodyShapeIndex(SBSI *sbsi)
{
	// Calculate SBSI --- Surface-based Body Shape Index
	//    (height^(7/4)) * (waistCircumference^(5/6))
	//    --------------------------------------------
	//    bodySurfaceArea * verticalTrunkCircumference
	//
	Flt ret = 0.0;
	Flt p1 = 7.0 / 4.0;
	Flt p2 = 5.0 / 6.0;
	Flt n1 = pow(sbsi->h, p1);
	Flt n2 = pow(sbsi->wc, p2);
	Flt d1 = sbsi->bsa;
	Flt d2 = sbsi->vtc;
	Flt r1 = (n1 * n2);
	Flt r2 = (d1 * d2);
	if (r2 != 0.0)
		ret = (r1 / r2);
	return ret;
}
