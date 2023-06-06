/*
 * Quicksum
*/

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
    string buffer;
    int size = 0, res = 0;
    while(getline(cin,buffer) && buffer != "#"){
        res = 0;
        size = buffer.length();
        for(int i = 0; i < size; i++){
            if(buffer[i] != ' ')
                res += (buffer[i] - 'A' + 1) * (i + 1);
        }
        cout << res << endl;
    }
    return 0;
}

/*
 * Sum of Consecutive Prime Number
 * POJ 2739
 *
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int mid = 0, leftindex = 0, rightindex = 0;
    int res = 0;
    int Primenums[10001], Primenum2[10001], index = 0, count = 0;
    // Init操作;
    for(int i = 0; i < 10001; i++){
        Primenums[i] = 0;
        Primenum2[i] = 0;
    }
    Primenums[0] = 1;
    Primenums[1] = 1;
    for(int i = 2; i < 10001; i++){
        if(Primenums[i] == 0){
            for(int j = 2 * i;j < 10001;j+=i){
                Primenums[j] = 1;
            }
        }
    }
    for(int i = 0; i < 10001; i++){
        if(Primenums[i] == 0){
            Primenum2[index] = i;
            index++;
        }
    }
    while(cin >> mid && mid != 0){
        for(int i = 0; Primenum2[i] <= mid; i++){
            res = 0;
            for(int j = i; Primenum2[j] <= mid; j++){
                res += Primenum2[j];
                if(res == mid)
                    count++;
            }
        }
        cout << count << endl;
		count = 0;
    }
    return 0;
}
*/


/*
 * ZOJ 2812, POJ 3094
 * 作业题上面的第三题: 
 * 
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
    string buffer;
    int size = 0, res = 0;
    while(getline(cin,buffer) && buffer != "#"){
        res = 0;
        size = buffer.length();
        for(int i = 0; i < size; i++){
            if(buffer[i] != ' ')
                res += (buffer[i] - 'A' + 1) * (i + 1);
        }
        cout << res << endl;
    }
    return 0;
}
*/

/*
 * ZOJ 1764, POJ 1581
 *
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv){
    int numbers, res[8], count = 0, QCount = 0, midcount = 0, midQCount = 0;
    string name,resname;
    cin >> numbers;
    while(numbers){
        cin >> name;
        count = QCount = 0;
        for(int n = 0; n <=7; n++)
            cin >> res[n];
        for(int m = 0; m < 7; m+=2){
            if((res[m+1] != 0))
                QCount++;
            if(res[m+1] != 0)
                count += ((res[m]-1)*20 + res[m+1]);
        }
        if(midQCount < QCount || ((midQCount == QCount) && (midcount > count)) ){
            resname = name;
            midcount = count;
            midQCount = QCount;
        }
        numbers--;
    }
    cout << resname << " " << midQCount << " " << midcount << endl;
    return 0;
}
*/

/*
 * POJ 3006
 *
 * ----------------------------
 *  这道题的思路，非常值得记录；
 * ----------------------------
 *
#include <iostream>
int isPrime(int x);
#define maxSize 1000002
using namespace std;
int main(int argc, char **argv){
    int nums[3], primnums[maxSize], flag = 1, count = 1, res = 0;
    // 在这里进行素数表的设计；
    primnums[0] = 1;
    primnums[1] = 1;
    for(int i = 2; i < maxSize; i++){
        primnums[i] = 0;
    }
    for(int i = 2; i < maxSize; i++){
        if(primnums[i] == 0){
            for(int j=2*i; j<maxSize; j+=i)
				primnums[j]=1;
        }
    }
    while(flag){
        cin >> nums[0];
        cin >> nums[1];
        cin >> nums[2];
        if(nums[0] == 0 && nums[1] == 0 && nums[2] == 0){
            break;
        }else{
            res = nums[0];
            while(nums[2] >= 1){
                if(primnums[res] == 0){
                    nums[2]--;
                }
                res += nums[1];
            }
        }
        cout << res - nums[1] << endl;
    }
    return 0;
}
*/


/*
 * poJ 2242, ZOJ 1090
 *
#include <iostream>
#define pi 3.141592653589793
using namespace std;
int main(int argc, char **argv){

    return 0;
}
*/
/**
#include <iostream>
using namespace std;
int sumNums(int* nums,int left,int right);
int main(int argc,char** argv){
int val = 0,count = 0,index = 0;
int primnums[10000]= { 0 };
int primnum = 2,nums = 0;
int rightindex = 0,leftindex = 0;
int xmax = 0,xmin = 0;
int sum = 0;
while(primnum < 10000){
    for(int m = 1; m <= primnum; m++){
        if(primnum %m ==0)
            nums++;
    }
    if(nums == 2){
        primnums[index]=primnum;
        index++;
    }
    nums = 0;
    primnum++;
}
while(cin >> val && val !=0){
    while(primnums[rightindex] < val){
        rightindex++;
    }
    xmax = rightindex;
    leftindex = xmin;
    while(leftindex >= xmin && rightindex <= xmax && leftindex <= rightindex){
        sum =sumNums(primnums,leftindex,rightindex);
        // cout << "sum: " << sum << endl;
        if(sum == val){
            count++;
            leftindex++;
            rightindex++;
            continue;
        }
        if(sum > val){
            rightindex--;
        }else{
            leftindex++;
            rightindex++;
            }
        }
        rightindex = 0;
        cout << count << endl;
        count =0;
    }
return 0;
}
int sumNums(int*nums,int left,int right){
    int res = 0;
    if(left == right)
        return nums[left];
    for(int m = left; m <= right; m++){
        res += nums[m];
    }
    return res;
}
*/

/*
 * 习题第六题:
 *
#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.141592653589793
using namespace std;
double getlength(double * x, double *y ,double * z);
int main(int argc, char **argv){
    double points[3][2], rlen = 0, roundlen = 0;
    while(cin >> points[0][0]){
        for(int i = 1; i <= 5; i++){
            cin >> points[i/2][i%2];
        }
        rlen = getlength(points[0], points[1], points[2]);
        roundlen = rlen;
        roundlen *= 2;
        roundlen *= pi;
        cout << fixed << setprecision(2);
        cout << roundlen << endl;
    }
    return 0;
}
double getlength(double * x, double *y ,double * z){
    double k1 = 0.0, b1 = 0.0, k2 = 0.0, b2 = 0.0;
    double m = 0.0, n = 0.0, res = 0.0;
    k1 = x[1] - y[1];
    k2 = x[1] - z[1];
    if(k1 == 0 || k2 == 0){
        if(k1 == 0){
            m = (x[0] + y[0]) / 2.0;
            if(x[0] == z[0]){
                n = (x[1] + z[1]) / 2.0;
            }else{
                k2 = (x[0] - z[0]) / (z[1] - x[1]);
                b2 = (z[1] + x[1]) / 2.0 - k2 * (z[0] + x[0]) / 2.0;
                n = k2 * m + b2;
            }
        }
        else{
            m = (x[0] + z[0]) / 2.0;
            if(x[0] == y[0]){
                n = (x[1] + y[1]) / 2.0;
            }else{
                k1 = (x[0] - y[0]) / (y[1] - x[1]);
                b1 = (y[1] + x[1]) / 2.0 - k1 * (y[0] + x[0]) / 2.0;
                n = k1 * m + b1;
            }
        }
        res = sqrt(pow(m-x[0],2) + pow(n-x[1],2));
        return res;
    }
    if(x[0] == y[0] || x[0] == z[0]){
        if(x[0] == y[0]){
            n = (x[1] + y[1]) / 2.0;
            k1 = 0;
            b1 = n;
            k2 = (x[0] - z[0]) / (z[1] - x[1]);
            b2 = (z[1] + x[1]) / 2.0 - k2 * (z[0] + x[0]) / 2.0;
            m = (n - b2) / k2;
        }else{
            n = (x[1] + z[1]) / 2.0;
            k2 = 0;
            b2 = n;
            k1 = (x[0] - y[0]) / (y[1] - x[1]);
            b1 = (y[1] + x[1]) / 2.0 - k1 * (y[0] + x[0]) / 2.0;
            m = (n - b1) / k1;
        }
        res = sqrt(pow(m-x[0],2) + pow(n-x[1],2));
        return res;
    }
    k1 = (x[0] - y[0]) / (y[1] - x[1]);
    b1 = (y[1] + x[1]) / 2.0 - k1 * (y[0] + x[0]) / 2.0;
    k2 = (x[0] - z[0]) / (z[1] - x[1]);
    b2 = (z[1] + x[1]) / 2.0 - k2 * (z[0] + x[0]) / 2.0;
    m = (b2 - b1) / (k1 - k2);
    n = k1 * m + b1;
    res = sqrt(pow(m-x[0],2) + pow(n-x[1],2));
    return res;
}
*/


/*
 * 第7题：
 *POJ 2136
 *
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	vector<string> input(4);
	int Characters[26], Indexs[26], max = 0, index = 0, maxx = 0;
	for (int i = 0; i < 26; i++) {
		Characters[i] = 0;
		Indexs[i] = 1000;
	}
	int i = 0;
	while (i  < 4 && getline(cin,input[i])) {
		for (int j = 0; j < input[i].length(); j++) {
			if((input[i][j] - 'A' < 26) && (input[i][j] - 'A' >= 0))
				Characters[input[i][j] - 'A']++;
		}
			i++;
	}

	for (int i = 0; i < 26; i++) {
		if (max <= Characters[i]) {
			index = i;
			max = Characters[i];
		}
	}
	maxx = max;
	for (int i = 0; i < max; i++) {
 		for (int j = 0; j < 26; j++) {
			if (maxx == Characters[j]) {
				Indexs[j] = maxx;
				index = j;
			}
		}
		for (int m = 0; m <= index; m++) {
			if (Indexs[m] == maxx) {
					cout << "* "; 
				Characters[m]--;
			}
			else {
				cout << "  ";
			}
		}
		maxx--;
		cout << endl;
	}
	for (int i = 0; i < 25; i++) {
		cout << char(i + 'A') << " ";
	}
	cout << 'Z';
	return 0;
}
*/

/*
 *  1.5.8 Ugly Numbers
 *
 *
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) {
	int mid = 0;
	int nums[15005], index = 2;
	int num1 = 1, num2 = 1, num3 = 1;
	nums[1] = 1;
	while (index < 15005) {
		nums[index] = min(nums[num1]*2,min(nums[num2]*3,nums[num3]*5));
		if (nums[index] == nums[num1] * 2)
			num1++;
		if (nums[index] == nums[num2] * 3)
			num2++;
		if (nums[index] == nums[num3] * 5)
			num3++;
		index++;
	}
	while(cin >> mid && mid != 0){
		cout << nums[mid] << endl;
	}
	return 0;
}
*/

/*
 * POJ 1833
 * 思考对应的三步走到底是一个怎样的过程;
 *
#include <iostream>
#include <algorithm>
using namespace std;
int compare(const void* e1,const void* e2){
    return *((int*)e1) - *((int*)e2);
}
int main(int argc, char **argv){
    int times = 0, index = 0, temp = 0, min = 1024, left = 0;
    int numslength = 0, queue = 0;
    int * nums = nullptr;
    cin >> times;
    while(times){
        cin >> numslength >> queue;
        nums = new int [numslength+1];
        for(int i = 1; i <= numslength; i++)
            cin >> nums[i];
        nums[0] = 1024;
        // 对于对应的点的排序操作:
        index = 0; 
        for(int i = 1; i <= queue; i++){
            for(int j = numslength; j > 1; j--){
                if(nums[j] > nums[j-1]){
                    index = j-1;
                    break;
                }
            }
            if(index == 0){
                for(int i = numslength; i >=1; i--)
                    cout << nums[i] << " ";
                cout << endl;
                continue;
            }
            min = index + 1;
            for(int j = index+1; j < numslength; j++){
                if(nums[index] < nums[j]){
                    if(nums[j] < nums[min])
                        min = j;
                }
            }
            temp = nums[min];
            nums[min] = nums[index];
            nums[index] = temp;
            qsort(nums+index+1,numslength-index,sizeof(int),compare);
            for(int i = 1; i<= numslength; i++)
                cout << nums[i] << " ";
            cout << endl;
        }        
        delete [] nums;
        times--;
    }
    return 0;
}
*/
// 在POJ上会被卡时间，卡掉；需要进行一次优化；

// 进行如下的自带的函数来实现的话，就会非常的清晰;
/**
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
	int m;
	cin>>m;
	while(m--) {
		int n,k;
		scanf("%d%d",&n,&k);
		int A[1026];
		for(int i = 0;i < n;i++)
			scanf("%d",&A[i]);
		while(k--) {
			next_permutation(A, A+n);}
		for(int i = 0; i < n;i++)
			printf("%d ",A[i]);
			printf("\n");
		
	}
	return 0;
}
*/



/**
#include <cstdio> 
#include <iostream> 
using namespace std;
int a[1025]={0};
void NextPermutation(int size){
    int flag=size - 1; 
    int temp;
    int i;
    while(a[flag-1] > a[flag] && flag != 0){
        flag--;
    }
    if(flag==0){
        for(int i = 0; i < size; i++)
            a[i] = i+1;
        return;
    }
    for(i = size -1; i >= flag; i--){
        if (a[i] > a[flag-1]){
            temp = a[flag - 1]; 
            a[flag - 1]= a[i];
            a[i]= temp; 
            break;
        }
    }
    while(size - 1 > flag){
        temp = a[size -1];
        a[size-1] = a[flag];
        a[flag] = temp;
        flag++;
        size--;
    }
}
int main(int argc, char ** argv){
    int times = 0, numslength = 0, queue = 0;
    cin >> times;
    while(times){
        cin >> numslength >> queue;
        for(int i = 0; i < numslength; i++)
            cin >> a[i];
        for(int i = 0; i < queue; i++){
            NextPermutation(numslength);
        }
        for(int i = 0; i < numslength; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
*/





/*
 * POJ 1019
 * 作业题第10题
 *
#include <iostream>
#include <cmath>
#define maxsize 31269
unsigned long long a[maxsize];
unsigned long long s[maxsize];
using namespace std;
void Init();
int handle(int x);
int main(int argc, char ** argv){
    int times = 0, pos = 0;
    Init();
    cin >> times;
    while(times > 0){
        cin >> pos;   
        cout << handle(pos) << endl;
        times--;
    }
    return 0;
}
void Init(){
    a[1] = 1;
    s[1] = 1;
    for(int i = 2; i < maxsize; i++){
        a[i] = a[i-1] + (int)log10(i) + 1;
        s[i] = s[i-1] + a[i];
    }
}
int handle(int x){
    int i = 1, po = 0, m = 1, mid = 0;
    string res;
    while(s[i] < x){
        i++;
    }
    mid = x - s[i-1];
    for(m = 1; po < mid; m++){
        po += (int)log10(m) + 1;
    }
    return (m-1) / (int)pow(10.0,po-mid) % 10;
}
*/
