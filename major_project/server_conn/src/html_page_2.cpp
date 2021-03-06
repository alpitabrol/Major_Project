#include<string>
#include<iostream>
using namespace std;

void html_page(int count, string second_page_info[20][7], int days_to_go,
		int portions_to_go) {

	cout << "Content-type: text/html\n\n" << endl;
	cout << "<style>" << endl;
	cout << "html{font-size:10 pt;}" << endl;
	cout
			<< "body{ background-image: url(https://images.pexels.com/photos/616404/pexels-photo-616404.jpeg?auto=compress&cs=tinysrgb&dpr=3&h=750&w=1260);"
			<< "background-repeat:no-repeat;  " //<<endl;
			<< " background-size:cover;height:100%;width:100%}" << endl;

	cout << ".loginform label{display: block; color: #999;}" << endl;
	cout << ".cf :before," << endl;
	cout << ".loginform {width:410px;margin:20px auto;padding:25px;"
			<< "background-color:#FFF8DC;border-radius:5px;"
			<< "box-shadow:0px 0px 5px 0px #DEB887;inset 0px 1px 0px 0px rgba(250,250,250,0.5);"
			<< "border:1px solid rgba(0,0,0,0.3);}" << endl;
	cout << "</style> " << endl;

	cout << "<html><body>" << endl;

	//cout<<"<div style=\"opacity:0.3;\"><background: url(https://www.sidebysidehub.co.uk/mediacache/f03a/5607/f3b2/78ce/be6b/416e/a0aa/f07c/f765.jpg) alt=\" \" /></div>";
	//cout<< "<h1 align =\"center\" style=\"color:9B1650\">NUTRITIONAL ANALYZER </h1>"<<endl;
	cout
			<< "<h1 class=\"loginform cf\"align=\"center\" style=\"color: FireBrick;\"><font size=\"5\">NUTRITIONAL TRACKER 1.0</font> </h1>"
			<< endl;
	cout
			<< "<h2 style=\"font-family:Gerogia,serif\">Your tracked nutrition!!</h2>"
			<< endl;
	cout << "<h3 align =\"center\" style=\"color:9B1650\">Analyzer Chart</h3>"
			<< endl;

	cout << " <table border=1 style=\"width:100%\" >" << endl;
	cout
			<< "<caption align = \"center\" style= \"color: 9B16500\">A Portion: Pieces counted as 1 portion. Count: Consumable Portions we have</caption>"
			<< endl;
	cout << " <tr>" << endl;
	cout << " <th>PLU CODE</th> " << endl;
	cout << " <th>Name</th> " << endl;
	cout << " <th>Variety</th> " << endl;
	cout << " <th>Size</th> " << endl;
	cout << " <th>Weight Bought(lbs)</th> " << endl;
	cout << " <th>A Portion</th>" << endl;
	cout << " <th>Count</th> " << endl;
	cout << " </tr> " << endl;

	for (int i = 0; i < count; i++) {
		cout << "<tr>" << endl;
		for (int j = 0; j < 7; j++) {
			cout << "<td>" << second_page_info[i][j] << "</td>" << endl;
		}

		cout << " </tr>" << endl;
	}

	cout << "</table>" << endl;

	cout
			<< "<h3 style= \"color: Blue\">Wow, Your nutrition has been completed for "
			<< days_to_go << " days. ";
	if (portions_to_go) {
		cout << "You still have " << portions_to_go
				<< " portions for the following day.";
	}
	cout << "</h3>" << endl;

	cout
			<< "<h5 align = \"right\" style= \"color: 9B1650\"><font size=\"4\">Thanks for using our Product.</font></h5>"
			<< endl;
	cout << "<h6 align = \"right\" style= \"color: 9B1650\">AB</h6>" << endl;

	cout << "</body></html>";

}
