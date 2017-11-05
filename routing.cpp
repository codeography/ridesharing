#include <bits/stdc++.h>
using namespace std;
class Point{
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
};
struct paths{
    int dist;
    int pass[4];
};
bool vis[10];
vector<Point> P;
int dist(class Point p1,class Point p2){
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
int findmin(int k){
    int min=INT_MAX,it=0;
    for(int i=0,d;i<10;i++){
        if(!vis[i]){
            d=dist(P[k],P[i]);
     //   cout<<"---"<<d<<endl;
        if(d+P[i].dest<min){
            min=d+P[i].dest;
            it=i;
        }
        }
    }
    return it;
}

bool comp(struct paths a,struct paths b){
    return a.dist<b.dist;
}
int main() {

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
		if(x==D.x &&y==D.y){
		    i--;
		    continue;
		}
		Point p(x,y,D);
		P.push_back(p);
	}

	for(vector<Point>::iterator it=P.begin();it!=P.end();it++) {
		cout<<"("<<it->x<<','<<it->y <<")"<<'\t'<<it->dest<< endl;
	}
	paths o[10];
	for(int i=0;i<10;i++){
	    memset(vis,false,10);
	    vis[i]=true;
	    int n=3,j=i,k,d=0;
	    o[i].pass[0]=i;
	    while(n--){
	        k=findmin(j);
	        vis[k]=true;
	        d+=dist(P[j],P[k]);
	        o[i].pass[3-n]=k;
	        j=k;
	      //  cout<<k<<endl;
	    }
	    d+=dist(P[k],D);
	    o[i].dist=d;
	}
    
    sort(o,o+10,comp);
    for(int i=0;i<10;i++){
        cout<<o[i].dist<<endl;
        for(int j=0;j<4;j++)
            cout<<"--->"<<o[i].pass[j]<<"  ";
        cout<<endl;
    }
	return 0;

}