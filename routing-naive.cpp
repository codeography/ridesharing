#include <bits/stdc++.h>


using namespace std;



class Point
{
public:
	int x,y;
	int dest;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Point(int x, int y, Point dest) {
		this->x = x;
		this->y = y;
		this->dest = abs(this->x-dest.x)+abs(this->y-dest.y);
	}

	int distance(Point P) {
		return abs(this->x-P.x)+abs(this->y-P.y);
	}
};


bool isSIRfeasible(vector<Point> v) {
	int d12, d23, d1D, d2D, d3D;
	d12=v[0].distance(v[1]);
	d23=v[1].distance(v[2]);
	d1D=v[0].distance(v[3]);
	d2D=v[1].distance(v[3]);
	d3D=v[2].distance(v[3]);

	if( ((d12+d2D-d1D)<=d2D/2) && ((d23+d3D-d2D)<=d3D/2) ) return true;

	return false;
}


int main() {
	vector<Point> P;

	srand(time(NULL));

	Point D(rand()%30,rand()%30);
	D.dest=0;

	cout << "Destination:" <<endl;
	cout<<"("<<D.x<<','<<D.y <<")"<<'\t'<<D.dest<< endl;
	cout<<endl<<"Passengers"<<endl;

	for(int i=0;i<10;i++){
		int x, y;
		x=rand()%30;
		y=rand()%30;

		Point p(x,y,D);

		P.push_back(p);
	}

	for(vector<Point>::iterator it=P.begin();it!=P.end();it++) {
		cout<<"("<<it->x<<','<<it->y <<")"<<'\t'<<it->dest<< endl;
	}


	vector<vector<Point> > o, sir;
	for(int i=0;i<10;i++){
	    for(int j=0;j<10;j++){
	        if(j==i)
	            continue;
	        for(int k=0;k<10;k++){
	            if(k==j ||k ==i)
	                continue;
	            vector<Point> t;
	            t.push_back(P[i]);
	            t.push_back(P[j]);
	            t.push_back(P[k]);
	            t.push_back(D);
	            o.push_back(t);
	        }
	    }
	}

	for(vector<vector<Point> >::iterator it=o.begin();it!=o.end();it++) {
		if(isSIRfeasible(*it)) sir.push_back(*it);
	}

	cout<<"All possible routes-"<<o.size()<<endl;
	cout<<"SIR feasible routes- "<<sir.size()<<endl;

	for(vector<vector<Point> >::iterator it=sir.begin();it!=sir.end();it++) {
		for(vector<Point>::iterator it1=(*it).begin();it1!=(*it).end();it1++) {
			cout<<"("<<it1->x<<','<<it1->y <<")"<<'\t';
		}
		cout<<endl;
	}


	return 0;

}