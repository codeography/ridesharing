#include <bits/stdc++.h>


using namespace std;

int distance(pair<int, int> p1, pair<int, int> p2) {
	return (abs(p1.first-p2.first)+abs(p1.second-p2.second));
}

int compare(pair<pair<int, int>, int > a, pair<pair<int, int>, int > b) {
	return a.second<b.second;
}


int main() {
	vector<pair<pair<int, int>, int> > p;
	

	srand(time(NULL));

	int x,y,md;


	pair<int,int> c(rand()%30,rand()%30), d(rand()%30,rand()%30);

	for(int i=0;i<10;i++) {
		x=rand()%30;
		y=rand()%30;
		pair<int, int> pt(x,y);
		md= ::distance(pt,c);
		pair<pair<int, int>, int> p1(pt,md);
		p.push_back(p1);
		//cout << "(" << x << ", " <<y<<")" <<endl;
	}

	sort(p.begin(),p.end(),compare);

	cout<<"cab"<<endl;
	cout<<"("<<c.first<<","<<c.second<<")"<<endl;


	cout<<"passengers"<<endl;
	for(int i=0;i<p.size();i++) {
		cout<<"(" << (p[i].first).first << "," << (p[i].first).second << ")" << "\t- " << p[i].second << endl;
	}

	cout<<"destination"<<endl;

	cout<<endl<<"("<<d.first<<","<<d.second<<")"<<endl;

	for(int i=30;i>=0;i--) {
		for(int j=0;j<30;j++) {
			bool passenger=false;
			if(j==c.first && i==c.second) cout << "C  ";
			else {
			for(int k=0;k<p.size();k++) {
				pair<int,int> q(j,i);
				if( q == p[k].first) {
					cout << "P  ";
					passenger=true;
				}
			}
			if(!passenger) cout << ".  ";
			}
			
	}
	cout<<endl;
	}



	
}

