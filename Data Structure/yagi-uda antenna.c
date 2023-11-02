// //This is a program for Yagi-Uda Antenna
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//     int f,a;
//     float d,g;
//     printf("Enter the frequency: \n");
//     scanf("%d",&f);

//     a=f*1e9;
//     d=(f*1e9)/(3e8);
//     g=d*1e1;

// printf("value of a=%d\n",a);
// printf("value of d=%f\n",d);
// printf("value of d=%f\n",g);

//     printf("Director value 1: %d\n",0.40*d);
//     printf("Director value 2: %d\n",0.43*d);
//     printf("Director value 3: %d\n",0.44*d);
//     printf("Director value 4: %d\n",0.45*d);

//     printf("Main: %d\n",0.46*d);
//     printf("Reflector: %d\n",0.475*d);


        
//     return 0;
// }

#include <stdio.h>
#include <math.h>

#define SPEED_OF_LIGHT 299792458.0  // Speed of light in meters per second

// Function to calculate the length of an antenna element
double calculateElementLength(double frequencyGHz, int elementNumber) {
    double frequency = frequencyGHz * 1e9; // Convert GHz to Hz
    double lengthFraction;

    if (elementNumber == 0) {
        lengthFraction = 0.48;  // Driven element
    } else if (elementNumber == 1) {
        lengthFraction = 0.46;  // Reflector
    } else {
        lengthFraction = 0.46;  // Directors
    }

    double wavelength = SPEED_OF_LIGHT / frequency;
    return lengthFraction * wavelength;
}

// Function to calculate the gain of an antenna element
double calculateElementGain(double elementLength, double wavelength) {
    double dipoleGain = 2.15;
    return dipoleGain * (elementLength / (0.5 * wavelength)); // Calculate gain for each element
}

int main() {
    double frequencyGHz;

    printf("Enter the frequency in GHz: ");
    scanf("%lf", &frequencyGHz);

    int numElements = 6;  // Total number of elements (1 driven, 1 reflector, 4 directors)
    double wavelength = SPEED_OF_LIGHT / (frequencyGHz * 1e9);

    printf("Yagi-Uda Antenna Parameters:\n");
    printf("Frequency: %.2lf GHz\n", frequencyGHz);
    printf("Number of Elements: %d\n", numElements);

    // Calculate and display parameters for each element
    for (int i = 0; i < numElements; i++) {
        double elementLength = calculateElementLength(frequencyGHz, i);
        double elementGain = calculateElementGain(elementLength, wavelength);
        
        if (i == 0) {
            printf("Driven Element Length: %.2lf meters\n", elementLength);
        } else if (i == 1) {
            printf("Reflector Element Length: %.2lf meters\n", elementLength);
        } else {
            printf("Director %d Length: %.2lf meters, Gain: %.2lf dBi\n", i - 1, elementLength, elementGain);
        }
    }

    return 0;
}


