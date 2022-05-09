#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

struct student{

    string name;
    int kor;
    int mat;
    int eng;

};

bool cmp(const student &a,const student &b){

    if(a.kor != b.kor)
        return a.kor > b.kor;
    else if(a.eng != b.eng)
        return a.eng < b.eng;
    else if(a.mat != b.mat)
        return a.mat > b.mat;
    else
        return a.name < b.name;


}
student a[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);



    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i].name >> a[i].kor >>a[i].eng >> a[i].mat;
    }

    sort(a,a+n,cmp);

    for(int i=0;i<n;i++){
        cout << a[i].name << "\n";
    }






    return 0;
}
