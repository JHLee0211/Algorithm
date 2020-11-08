#include <string>
#include <iostream>

using namespace std;

// boj_11656_접미사배열
int main()
{
	string s;
	cin>>s;

	int len = s.size();
	string arr[len];

	for(int i=0; i<len; i++){
		arr[i]=s.substr(i);
	}

	for(int i=0; i<len-1; i++){
		for(int j=i+1; j<len; j++){
			string temp;
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	for(int i=0; i<len; i++){
		cout<<arr[i]<<endl;
	}

    return 0;
}
