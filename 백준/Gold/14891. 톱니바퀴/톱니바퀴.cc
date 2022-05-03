#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> a;
deque<int> b;
deque<int> c;
deque<int> d;

void clock_turn(deque<int> &d){

    int tmp = d.back();
    d.push_front(tmp);
    d.pop_back();

}
void rclock_turn(deque<int> &d){
    int tmp = d.front();
    d.push_back(tmp);
    d.pop_front();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 0; i < 4; i++) {

        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (i == 0) {
                a.push_back(str[j] - '0');
            } else if (i == 1) {
                b.push_back(str[j] - '0');
            }else if (i == 2) {
                c.push_back(str[j] - '0');
            }else if (i == 3) {
                d.push_back(str[j] - '0');
            }

        }

    }
    int order;
    cin >>order;
    while (order--) {

        int num, dir;
        bool is_a = false;
        bool is_b = false;
        bool is_c = false;
        bool is_d = false;
        cin >> num >> dir;

        //a[2] : b[6] : b[2] : c[6] : c[2] : d[6]

        if (num == 1) {
            is_a = true;

            if (a[2] != b[6]) {
                is_b = true;
            }

            if (is_b && b[2] != c[6]) {
                is_c = true;
            }

            if (is_c && c[2] != d[6]) {
                is_d = true;
            }


            if (dir == 1) {
                if (is_a) {
                    clock_turn(a);
                }
                if (is_b) {
                    rclock_turn(b);
                }

                if (is_c) {
                    clock_turn(c);
                }
                if (is_d) {
                    rclock_turn(d);
                }

            } else if (dir == -1) {
                if (is_a) {
                    rclock_turn(a);

                }
                if (is_b) {
                    clock_turn(b);
                }

                if (is_c) {
                    rclock_turn(c);
                }
                if (is_d) {
                    clock_turn(d);
                }


            }

//a[2] : b[6] : b[2] : c[6] : c[2] : d[6]
        } else if (num == 2) {
            is_b = true;

            if (a[2] != b[6]) {
                is_a = true;
            }

            if (b[2] != c[6]) {
                is_c = true;
            }

            if (is_c && c[2] != d[6]) {
                is_d = true;
            }


            if (dir == 1) {
                if (is_a) {

                    rclock_turn(a);
                }
                if (is_b) {
                    clock_turn(b);

                }

                if (is_c) {
                    rclock_turn(c);

                }
                if (is_d) {
                    clock_turn(d);

                }

            } else if (dir == -1) {
                if (is_a) {
                    clock_turn(a);
                }
                if (is_b) {
                    rclock_turn(b);
                }

                if (is_c) {
                    clock_turn(c);
                }
                if (is_d) {
                    rclock_turn(d);
                }

            }
//a[2] : b[6] : b[2] : c[6] : c[2] : d[6]
        } else if (num == 3) {
            is_c = true;

            if (b[2] != c[6]) {
                is_b = true;
            }

            if (c[2] != d[6]) {
                is_d = true;
            }

            if (is_b && a[2] != b[6]) {
                is_a = true;
            }


            if (dir == 1) {
                if (is_a) {
                    clock_turn(a);
                }
                if (is_b) {
                    rclock_turn(b);
                }
                if (is_c) {
                    clock_turn(c);
                }
                if (is_d) {
                    rclock_turn(d);
                }
            } else if (dir == -1) {
                if (is_a) {
                    rclock_turn(a);
                }
                if (is_b) {
                    clock_turn(b);
                }

                if (is_c) {
                    rclock_turn(c);
                }
                if (is_d) {
                    clock_turn(d);
                }
            }


//a[2] : b[6] : b[2] : c[6] : c[2] : d[6]
        } else if (num == 4) {
            is_d = true;

            if (c[2] != d[6]) {
                is_c = true;
            }
            if (is_c && b[2] != c[6]) {
                is_b = true;
            }

            if (is_b && a[2] != b[6]) {
                is_a = true;
            }


            if (dir == 1) {

                if (is_a) {
                    rclock_turn(a);
                }
                if (is_b) {
                    clock_turn(b);
                }

                if (is_c) {
                    rclock_turn(c);
                }
                if (is_d) {
                    clock_turn(d);
                }

            } else if (dir == -1) {
                if (is_a) {
                    clock_turn(a);
                }
                if (is_b) {
                    rclock_turn(b);
                }

                if (is_c) {
                    clock_turn(c);
                }
                if (is_d) {
                    rclock_turn(d);
                }
            }

        }

    }

    int sum = 0;

    if (a[0] == 1) {
        sum += 1;
    }

    if (b[0] == 1) {
        sum += 2;
    }

    if(c[0] == 1) {
        sum += 4;
    }

    if (d[0] == 1) {
        sum += 8;
    }

    cout << sum;

    return 0;
}