#include <iostream>
#include <vector>
using namespace std;

class Sapxep
{
private:
    int n;
    vector<int> Arr;
public:
    void findSort(int n, vector<int> Arr) {
        for (int i=0;i<=n-1;i++) {
            for (int j=1;j<=n;j++) {
                if (Arr[i] < Arr[j]) {
                    int swap = Arr[i];
                    Arr[i] = Arr[j];
                    Arr[j] = swap;
                }
            }
        }
    }

    void showSort(int n, vector<int> Arr) {
        for (int i=0;i<n;i++) {
            cout << Arr[i]<<" ";
        }
    }
};

void getVector(int n, vector<int> arr) {
    for (int i=0;i<n;i++) {
        int currentN;
        cin >> currentN;
        arr.push_back(currentN);
    }
}


int main() {
    int n;
    vector<int> arr;
    cout<<"Nhap n: ";
    cin>>n;
    getVector(n, arr);

    Sapxep sapxep1;
    sapxep1.findSort(n, arr);
    sapxep1.showSort(n, arr);

    return 0;
}