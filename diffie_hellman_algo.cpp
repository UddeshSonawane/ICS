/*
Diffie Hellman Key Exchhange Algorithm

by Uddesh Sonawane
date 8th January, 2019

*) Alice and Bob agree on two large prime numbers p1 and p2. These two integers need not be kept secrete.
*) Alice chooses another large random number i.e., l1 and calculate 'A' such that A=(g=p2^l1)mod p1
*) Alice sends the number to Bob.
*) Bob independently chooses another large random number 'l2' and calculates 'B' such that B=(p2^l2)mod p1.
*) Bob sends the number 'B' to Alice.
*) Alice now computes the secrete key as K1=(B^ll)mod p1.
*) Bob now computes the secrete key K2 as K2=(A^l2)mod p1.

in this algorithm both K1 and K2 need to be same after calculation and absolutely they are same.
this whether (K1==K2) is checked with following code
*/

#include<iostream>
#include<cmath>
using namespace std;

int multiply(int num1, int num2)      // to find power of a number
{
	int result=1;
	for(int i=0;i<num2;i++)
	{
		result=result*num1;
	}
	return result;
}

int main()
{
	cout<<"\n********** Welcome Alice and Bob ******************";
	int p1, p2;   // two prime numbers
	
	cout<<"\nEnter first prime number : ";
	cin>>p1;
	cout<<"\nEnter second prime number : ";
	cin>>p2;
	
	int l1,l2;   // two random numbers
	int A, B;    // numbers to be sent to each other
	cout<<"\nAlice, enter random number : ";
	cin>>l1;
	int temp=multiply(p2,l1);
	cout<<"-----------"<<temp;
	A=temp%p1;
	
	cout<<"\nBob, enter random number : ";
	cin>>l2;
	int temp2=multiply(p2,l2);
	B=temp2%p1;
	
	int k1,k2;   // secrete keys generated on both the ends
	
	k1=multiply(B,l1)%p1;
	k2=multiply(A,l2)%p1;
	
	cout<<"\n********  Summary  **********";
	cout<<"\nTwo prime numbers             : "<<p1<<", "<<p2;
	cout<<"\nLarge number assumed by Alice : "<<l1;
	cout<<"\nNumber 'A' sent by Alice      : "<<A;
	cout<<"\nLarge number assumed by Bob   : "<<l2;
	cout<<"\nNumber 'B' sent by Bob        : "<<B;
	cout<<"\nKey calculated by Alice : K1  : "<<k1;
	cout<<"\nKey calculated by Bob : K2    : "<<k2;
	
	if(k1==k2)
	{
		cout<<"\n\nResult --> Both keys are equal";
	}
	else
		cout<<"\n\nResult --> Keys are not equal";

return 0;
}
