/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout<< "Content-type: text/html\n\n"<<endl;
	cout<< "<style>" <<endl;
	cout<< "html{font-size:10 pt;}" <<endl;
	cout<<"body{ background-image: url(https://i1.wp.com/www.jbessentialfitness.co.uk/wp-content/uploads/2019/03/5-a-day_cmyk3_v_Variation_1.png?w=672&ssl=1);"
		<<"background-repeat:no-repeat; background-position:top right; "
		<<"background-attachment:scroll;}"<<endl;

	cout<<"</style> "<<endl;

cout<< "<html><body>"<<endl;


cout<< "<h1 align =\"center\" style=\"color:9B1650\">NUTRITIONAL ANALYZER </h1>"<<endl;
cout<< "<h2 style=\"font-family:Gerogia,serif\">Your tracked nutrition!!</h2>"<<endl;
cout<< "<h3 align =\"center\" style=\"color:9B1650\">Analyzer Chart</h3>"<<endl;

string a[2][6]={{"94011","banana","kale","chotu","500",".5"},{"4032","Apple","Sadey","motu","2","500"}};

cout<<" <table border=1 style=\"width:100%\" >"<<endl ;
cout<<" <tr>"<<endl;
cout<<" <th>PLU CODE</th> "<<endl;
cout<<" <th>Name</th> "<<endl;
cout<<" <th>Variety</th> "<<endl;
cout<<" <th>Size</th> "<<endl;
cout<<" <th>Weight Bought(lbs)</th> "<<endl;
cout<<" <th>Portions Count</th> "<<endl;
cout<<" </tr> "<<endl;

for(int i=0 ; i<2 ; i++)
{
cout<<"<tr>"<<endl; 
	for(int j=0 ;j<6 ; j++)
	{ 
		cout<<"<td>"<<a[i][j]<<"</td>"<<endl; 
	}

cout<<" </tr>"<<endl;
}

cout<< "</table>"<<endl;
int x=4,y=2;

cout<<"<h4 style= \"color: 9B1650\">Your nutrition has been completed for "<<x<<"days."<<endl;
if(y)
{
cout<<"<h4 style= \"color: 9B1650\">You still have "<<y<<"portions for the following day."<<endl;
}


cout<<"<h5 align = \"right\" style= \"color: 9B1650\">Thanks for using our Product.</h5>"<<endl;
cout<<"<h5 align = \"right\" style= \"color: 9B1650\">AB</h5>"<<endl;

cout<< "</body></html>";


return 0;
}
*/
