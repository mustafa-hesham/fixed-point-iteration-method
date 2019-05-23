//This code is written by Mustafa Hesham to find the root of a function using fixed point iteration method.
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	double x0,accerror, apperror, result;
	int n, ite,iten;
	double e = 2.71828;
	string xe;
	cout<<"Please enter number of terms: "<<endl;
	cin>>n;
	double coeff[n];
	double power[n];
	double xcoeff[n];
	string termtype[n];
	string xtrig;
	cout<<"Please enter X0: "<<endl;
	cin>>x0;
	for (int i=0; i<n; i++) {
		cout<<"Please enter coefficient number "<<i+1<<" (Enter 1 if it is a trigonometric function term)"<<endl;
		cin>>coeff[i];
		cout<<"Please enter power number "<<i+1<<" (Enter x if it is the power of a number, or a trigonometric function, or e for euler number):"<<endl;
		cin>>xe;
		if(xe == "x") {
		//	coeff[i] = 1;
			termtype[i] ="pownum";
			cout <<"Please enter the number: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of x: "<<endl;
			cin>>xcoeff[i];
		}
		else if(xe =="e"){
			termtype[i] = "euler";
			power[i] = e;
			cout <<"Please enter coefficient of x (Enter x if the term is xe^x): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xeuler";
				cout <<"Please enter coefficient of xe^(x): "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "sin") {
		//	coeff[i] = 1;
			termtype[i] ="sin";
			cout <<"Please enter the power of sin x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of sin x (Enter x if the term is x sin(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xsin";
				cout <<"Please enter coefficient of x sin x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "cos") {
		//	coeff[i] = 1;
			termtype[i] ="cos";
			cout <<"Please enter the power of cos x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of cos x (Enter x if the term is x cos(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xcos";
				cout <<"Please enter coefficient of x cos x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else if(xe == "tan") {
		//	coeff[i] = 1;
			termtype[i] ="tan";
			cout <<"Please enter the power of tan x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of tan x (Enter x if the term is x tan(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xtan";
				cout <<"Please enter coefficient of x tan x: "<<endl;
				cin>>xcoeff[i];
			}
			else {
				istringstream iss1 (xtrig);
		    	iss1>>xcoeff[i];
			}
		}
		else{
			termtype[i] = "reg";
			istringstream iss (xe);
			iss>>power[i];
			xcoeff[i] = 0;
	}
}
	cout<<"Please enter the accepted error (percent): "<<endl;
	cin>>accerror;
	cout<<"Please enter maximum number iterations: "<<endl;
	cin>>ite;
	for (int q=0; q<ite; q++){
		result = 0;
		for (int s=0; s<n; s++){
			if (power[s] == e && termtype[s] =="euler"){
				result += coeff[s] * pow(power[s], (x0*xcoeff[s]));
				
			}
			if (termtype[s] =="xeuler"){
				result += coeff[s] * x0 *pow(power[s], (x0*xcoeff[s]));
			//	cout <<"The xeuler term is: "<<coeff[s] * x0 *pow(power[s], (x0*xcoeff[s]))<<endl;
				
			}
			
			if(power[s] != e && termtype[s] =="reg"){
			
			result += coeff[s] * pow(x0, power[s]);
		
			
			}
			if(termtype[s] =="pownum"){
			
			result += pow(power[s], (xcoeff[s]*x0));
			
			
			}
			if (termtype[s] == "sin"){
			result += coeff[s] * xcoeff[s]* sin(pow(x0, power[s]));
			
			
			}
			if (termtype[s] == "xsin"){
	
			result += coeff[s] * xcoeff[s]* x0 * sin(pow(x0, power[s]));
			
			
			}
			if (termtype[s] == "cos"){
			result += coeff[s] * xcoeff[s]* cos(pow(x0, power[s]));
			
			}
			if (termtype[s] == "xcos"){
	
			result += coeff[s] * xcoeff[s]* x0 * cos(pow(x0, power[s]));
			
			
			}
				if (termtype[s] == "tan"){
			result += coeff[s] * xcoeff[s]* tan(pow(x0, power[s]));
			
			
			}
			if (termtype[s] == "xtan"){
	
			result += coeff[s] * xcoeff[s]* x0 * tan(pow(x0, power[s]));
			
			
			}
			}
			
		  // cout <<"The initial result is: " <<result<<endl;
			for (int y=0; y<n; y++){
			
			for (int r=0; r<n; r++){
				if (termtype[r] == "reg" && power[r] != 0){
				    	result -= coeff[r] * pow(x0, power[r]);
				    	result *= -1;
				    //	cout<<"result regular term is: "<<result<<endl;
						result /= coeff[r];
						result = pow(result, (1/power[r]));
					//	cout <<"The processed result is:" <<result<<endl;
						r = n+2;
						y = n+2;
				}
			}
			
			for (int r=0; r<n; r++){
				if (y>n) break;
				if(termtype[r] == "ponum"){
					result -= pow(x0, power[r]);
					result *= -1;
				//	cout<<"result power term is: "<<result<<endl;
					result  /=log(xcoeff[r]);
				//	cout <<"The processed result is:" <<result<<endl;
					r = n+2;
					y = n+2;
				}
			}
			for (int r=0; r<n; r++){
				if (y>n) break;
				if(termtype[r] == "euler"){
						result -= coeff[r] * pow(power[r], (x0*xcoeff[r]));
						result *= -1;
					//	cout<<"result eular term is: "<<result<<endl;
						result = log(result);
						result /= xcoeff[r];
					//	cout <<"The processed result is(euler):" <<result<<endl;
							r = n+2;
							y = n+2;
				}
			
	}
				for (int r=0; r<n; r++){
				if (y>n) break;
				if(termtype[r] == "xeuler"){
				//		cout<<"The result before processing: "<<result<<endl;
					    result -= coeff[r] * x0 *pow(power[r], (x0*xcoeff[r]));
					    result *= -1;
						result /= coeff[r] * pow(power[r], (x0*xcoeff[r]));
				//		cout <<"The processed result is:" <<result<<endl;
							r = n+2;
							y = n+2;
				}
			
	}
	
			}
			apperror = (result - x0)*100/result;
			if(apperror<0) apperror *= -1;
			cout <<"The g(x) is: "<<result<<endl;
			cout <<"The relative error is: "<<apperror<<"%"<<endl;
	        cout <<"--------------------------"<<endl;
	        iten = q+1;
	        	if (accerror>apperror) q = ite+2;
				
				x0 = result;
				
	}
	
	cout<<"The number of iterations is: "<<iten<<endl;
	cout<<"The root of this function is: "<<result<<endl;
}
