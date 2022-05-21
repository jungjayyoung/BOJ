#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Person{

    string name;
    int day;
    int month;
    int year;
};

bool cmp(Person &a, Person &b){

    if (a.year != b.year) {

        return a.year < b.year;
    } else if (a.month != b.month) {

        return a.month < b.month;
    } else if (a.day != b.day) {

        return a.day < b.day;
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    Person person[101];

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> person[i].name >> person[i].day >> person[i].month >> person[i].year;

    }

    sort(person, person + n, cmp);

    cout << person[n - 1].name << "\n";
    cout << person[0].name;


    return 0;
}