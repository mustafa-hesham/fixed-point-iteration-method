//This code is written by Mustafa Hesham Mohamed to find the root of a function using fixed point iteration method.
//My student code at ISSR is 201800378.
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	double x0,accerror, apperror, result, resultcheckpt;
	int n, ite,iten, nancheck, converg = 0, diverg = 0;
	double e = 2.71828;
	string repeat;
	string xe;
	Repeat:
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
			else if(xe =="log"){
			termtype[i] = "log";
			cout <<"Please enter power of x"<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of x (Enter x if it's xlogx): "<<endl;
			cin>>xtrig;
			if(xtrig == "x"){
				termtype[i] = "xlog";
				cout <<"Please enter power of (x)logx "<<endl;
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
			cout <<"Please enter coefficient of sin (x) (Enter x if the term is x sin(x)): "<<endl;
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
	cout<<"Please enter maximum number of iterations: "<<endl;
	cin>>ite;
	double conv[ite];
	for (int q=0; q<ite; q++){
		result = 0;
		for (int s=0; s<n; s++){
			if (power[s] == e && termtype[s] =="euler"){
				result += coeff[s] * pow(power[s], (x0*xcoeff[s]));
			//	cout <<"The euler term is equal to "<<coeff[s] * pow(power[s], (x0*xcoeff[s]))<<endl;
				
			}
			if (termtype[s] =="xeuler"){
				result += coeff[s] * x0 *pow(power[s], (x0*xcoeff[s]));
				
			}
			
			if(power[s] != e && termtype[s] =="reg"){
			
			result += coeff[s] * pow(x0, power[s]);
		
			
			}
			if(termtype[s] =="pownum"){
			
			result += pow(power[s], (xcoeff[s]*x0));

			}
			if(termtype[s] =="log"){
			
			result += coeff[s] * power[s] * log(xcoeff[s]*x0);

			}
			if (termtype[s] == "sin"){
				double x0power = pow(x0, power[s]);
			result += coeff[s] * sin(xcoeff[s] * x0power);

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
			
			resultcheckpt = result;
			for (int y=0; y<n; y++){
			
			for (int r=0; r<n; r++){
				if (termtype[r] == "reg" && power[r] != 0 && r != nancheck){
						
				    	result -= coeff[r] * pow(x0, power[r]);
				    	result *= -1;
				    	result /= coeff[r];
						result = pow(result, (1/power[r]));

					if(!isnan(result)){
					r = n+2;
					y = n+2;
					}
					else if(isnan(result)){
							result = resultcheckpt;
							nancheck = r;
							
						}
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
				if(termtype[r] == "euler" && r != nancheck){
						result -= coeff[r] * pow(power[r], (x0*xcoeff[r]));
						result *= -1;
					//	cout<<"result eular term is: "<<result<<endl;
						result /= xcoeff[r];
						result = log(result);
					//	cout <<"The processed result is(euler):" <<result<<endl;
							if(!isnan(result)){
					r = n+2;
					y = n+2;
					}
					else if(isnan(result)){
							result = resultcheckpt;
							nancheck = r;
							
						}
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
	for (int r=0; r<n; r++){
				if (y>n) break;
				if(termtype[r] == "log" && r != nancheck){
					    result -= coeff[r] * power[r] * log(xcoeff[r]*x0);
					    result *= -1;
						result /= coeff[r];
						result  = pow(e, result);
							if(!isnan(result)){
					r = n+2;
					y = n+2;
					}
					else if(isnan(result)){
							result = resultcheckpt;
							nancheck = r;
							
						}
				}
			
	}
	
			}
			apperror = (result - x0)*100/result;
			if(apperror<0) apperror *= -1;
			conv[q] = apperror;
			
			cout <<"The g(x) is: "<<result<<endl;
			cout <<"The relative error is: "<<apperror<<"%"<<endl;
			if (q == 0) cout<<"No apparent convergence or divergence!"<<endl;
			if (conv[q] > conv[q-1] && q !=0) {
			cout<<"Diverging!"<<endl;
			diverg++;
		}
			if (conv[q] < conv[q-1] && q !=0) {
				cout<<"Converging!"<<endl;
				converg++;
			}
	        cout <<"--------------------------"<<endl;
	        iten = q+1;
	        	if (accerror>apperror) q = ite+2;
				
				x0 = result;
				
	}
	
	cout<<"The number of iterations is: "<<iten<<endl;
	cout<<"The root of this function is: "<<result<<endl;
	if (converg>diverg || converg == diverg) cout<<"\n\n\t\t\tThis function is convergent!"<<endl;
	if (converg<diverg && converg != diverg)  cout<<"\n\n\t\t\tThis function is divergent!"<<endl;
	cout<<"\n\n"<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"\n"<<endl;
	cout<<"Do you want to solve another problem? (Enter yes or y to repeat)"<<endl;
	cin>>repeat;
	if(repeat == "yes" || repeat == "y") goto Repeat;
	else exit(0);
}
