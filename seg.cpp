#include<iostream>
#include<vector>

using namespace std;

void seg(vector<int>& nums) {

    for(int x=2;x<=nums.size();x<<=1){
        int t=x/2;
        for(int y=x-1;y<nums.size();y+=x){
            nums[y]+=nums[y-t];
        }
    }
}

int at(vector<int>& nums,int index){
    int ans=0,p=1;
    while(index&p){
        ans+=nums[index-1];
        index&=~p;
        p<<=1;
    }
    index|=p;
    return nums[index-1]-ans;
}
    
void update(vector<int>& nums,int index, int val) {
    val-=at(nums,index);
    
    int p=1;index++;
    while(index<=nums.size()){
        nums[index-1]+=val;
        while(!(index&p))
            p<<=1;
        index+=p;
    }
}
    
int sumRange(vector<int>& nums,int left, int right) {
    int ans=0,p=1;
    right++;
    while(right>0){
        if(right&p){
            ans+=nums[right-1];
            right&=~p;
        }
        p<<=1;
    }
    p=1;
    while(left>0){
        if(left&p){
            ans-=nums[left-1];
            left&=~p;
        }
        p<<=1;
    }
return ans;
}


int main(){
	vector<int> arr(6);
	arr={1,2,3,4,5,6};
	
	seg(arr);
  
	cout<<sumRange(arr,0,5)<<"\n";
  
	update(arr,5,7);
  
	cout<<sumRange(arr,0,5)<<"\n";

return 0;
}
