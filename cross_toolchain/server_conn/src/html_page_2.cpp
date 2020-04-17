#include<string>
#include<iostream>
using namespace std;

void html_page(int count,string second_page_info[20][7],int days_to_go, int portions_to_go)
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

	cout<<" <table border=1 style=\"width:100%\" >"<<endl ;
	cout<<" <tr>"<<endl;
	cout<<" <th>PLU CODE</th> "<<endl;
	cout<<" <th>Name</th> "<<endl;
	cout<<" <th>Variety</th> "<<endl;
	cout<<" <th>Size</th> "<<endl;
	cout<<" <th>Weight Bought(lbs)</th> "<<endl;
	cout<<" <th>Pieces In A Portion</th>"<<endl;
	cout<<" <th>Portions Count</th> "<<endl;
	cout<<" </tr> "<<endl;

	for(int i=0 ; i<count ; i++)
	{
	cout<<"<tr>"<<endl;
		for(int j=0 ;j<7 ; j++)
		{
			cout<<"<td>"<<second_page_info[i][j]<<"</td>"<<endl;
		}

	cout<<" </tr>"<<endl;
	}

	cout<< "</table>"<<endl;


	cout<<"<h3 style= \"color: 9B1650\">Your nutrition has been completed for "<<days_to_go<<" days.</h3>"<<endl;
	if(portions_to_go)
	{
	cout<<"<h3 style= \"color: 9B1650\">You still have "<<portions_to_go<<" portions for the following day.</h3>"<<endl;
	}


	cout<<"<h5 align = \"right\" style= \"color: 9B1650\">Thanks for using our Product.</h5>"<<endl;
	cout<<"<h5 align = \"right\" style= \"color: 9B1650\">AB</h5>"<<endl;

	cout<< "</body></html>";



}
